#include <stdio.h>
#include <unistd.h>
#include "nva/nva.h"
#include "ampere/ga100/dev_boot.h"

#define print_bits(x)                                            \
  do {                                                           \
    unsigned a__ = (x);                                          \
    size_t bits__ = sizeof(x) * 8;                               \
    printf(#x ": ");                                             \
    while (bits__--) putchar(a__ &(1U << bits__) ? '1' : '0');   \
    putchar('\n');                                               \
  } while (0)

enum {
    NVIDIA_MMIO_MASK_PMC        = 0x00000FFF,
    NVIDIA_MMIO_MASK_PBUS       = 0x00001FFF,
    NVIDIA_MASK_ALL             = 0x0000FFFF,
};

struct pmc_new_id {
    uint8_t device_id;
    uint8_t stepping;
    uint16_t gpu_id;
};

struct pmc_id {
    uint8_t stepping;
    uint8_t device_id;
    uint16_t gpu_id;
};

void PMC_NEW_ID (uint32_t value,
                 struct pmc_new_id *new_id) {
    new_id->device_id  = (value << 0) >> 0;
    new_id->stepping   = (value << 0) >> 12;
    new_id->gpu_id     = (value << 0) >> 20;
}

void PMC_ID (uint32_t value,
                 struct pmc_id *id) {
    id->stepping   = (value << 0) >> 0;
    id->device_id  = (value << 0) >> 12;
    id->gpu_id     = (value << 0) >> 20;
}

int main(int argc, char **argv) {
    int c;
    int i;
    int cnum = 0;
    int mask = 0;

    if (nva_init()) {
            fprintf (stderr, "PCI init failure!\n");
            return 1;
    }

    while ((c = getopt (argc, argv, "c:mbrFDR")) != -1)
    switch (c) {
            case 'c':
                    sscanf(optarg, "%d", &cnum);
                    break;
            case 'm':
                    mask |= NVIDIA_MMIO_MASK_PMC;
                    break;
            case 'b':
                    mask |= NVIDIA_MMIO_MASK_PBUS;
                    break;
    }

    if (!mask)
            mask = NVIDIA_MASK_ALL;

    if (cnum >= nva_cardsnum) {
            if (nva_cardsnum)
                    fprintf (stderr, "No such card.\n");
            else
                    fprintf (stderr, "No cards found.\n");
            return 1;
    }

    // nva_wr32(cnum, 0x0, 0x172000a1);
    
    if (mask & NVIDIA_MMIO_MASK_PMC) {
            uint32_t pmc_boot_0  = nva_rd32(cnum, NV_PMC_BOOT_0);
            uint32_t pmc_boot_1  = nva_rd32(cnum, NV_PMC_BOOT_1);
            uint32_t pmc_boot_2  = nva_rd32(cnum, NV_PMC_BOOT_2);
            uint32_t pmc_boot_42 = nva_rd32(cnum, NV_PMC_BOOT_42);
            uint32_t pmc_enable  = nva_rd32(cnum, NV_PMC_ENABLE);
            printf("PMC:\n");
            printf("\tNV_PMC_BOOT_0   : 0x%08x\n",  pmc_boot_0);
            printf("\tNV_PMC_BOOT_1   : 0x%08x\n",  pmc_boot_1);
            printf("\tNV_PMC_BOOT_2   : 0x%08x\n",  pmc_boot_2);
            printf("\tNV_PMC_BOOT_42  : 0x%08x\n",  pmc_boot_42);
            printf("\tNV_PMC_ENABLE   : 0x%08x\n",  pmc_enable);

            struct pmc_id id;
            PMC_ID(pmc_boot_0, &id);
            printf("\t------------------------------\n");
            printf("\t(0x0) ID gpu id   : 0x%03x\n",  id.gpu_id);
            printf("\t(0x0) ID device id: 0x%02x\n",  id.device_id);
            printf("\t(0x0) ID stepping : 0x%02x\n",  id.stepping);

            struct pmc_new_id new_id;
            PMC_NEW_ID(pmc_boot_42, &new_id);
            printf("\t------------------------------\n");
            printf("\t(0xA00) NEW_ID gpu id   : 0x%03x\n",  new_id.gpu_id);
            printf("\t(0xA00) NEW_ID device id: 0x%02x\n",  new_id.device_id);
            printf("\t(0xA00) NEW_ID stepping : 0x%02x\n",  new_id.stepping);

    }

    if (mask & NVIDIA_MMIO_MASK_PBUS) {
            printf("PBUS:\n");
            printf("\tUNK1200: %08x\n", nva_rd32(cnum, 0x1200));
            printf("\tUNK1400: %08x\n", nva_rd32(cnum, 0x1400));
            printf("\tPCI_0:\n");
            for (i = 0; i < 16; i++)
                    printf("\t\t%02x: %08x\n", i * 4, nva_rd32(cnum, 0x1800 + i * 4));
            printf("\tPCI_1:\n");
            for (i = 0; i < 16; i++)
                    printf("\t\t%02x: %08x\n", i * 4, nva_rd32(cnum, 0x1900 + i * 4));
    }

    return 0;
}
