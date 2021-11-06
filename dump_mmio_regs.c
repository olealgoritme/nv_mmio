#include <stdio.h>
#include <unistd.h>
#include "include/nva/nva.h"
#include "include/ampere/ga100/dev_boot.h"

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

struct pmc_enable {
    // bits 0-8
    int bit00_unk0;
    int bit01_pppp;
    int bit02_pxbar;
    int bit03_pmfb;
    int bit04_pmedia;
    int bit05_pring;
    int bit06_pcopy0;
    int bit07_pcopy1;
    int bit08_pfifo;

    // bits 9-11
    int bit09_unk1;
    int bit10_unk2;
    int bit11_unk3;

    // bits 12-18
    int bit12_pgrahph;
    int bit13_pdaemon;
    int bit14_psec;
    int bit15_pvdec;
    int bit16_ptimer;
    int bit17_ppdec;
    int bit18_pvenc;

    // bit 19
    int bit19_unk4;

    // bits 20-21
    int bit20_pbfb;
    int bit21_pcopy2;

    // bits 22-25
    int bit22_unk5;
    int bit23_unk6;
    int bit24_unk7;
    int bit25_unk8;

    // bits 26-31
    int bit26_zpw;
    int bit27_blg;
    int bit28_pcounter;
    int bit29_pffb;
    int bit30_pdisplay;
    int bit31_isohub;
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

void PMC_ENABLE (uint32_t value,
                 struct pmc_enable *enable) {

    enable->bit00_unk0     = (value >> 0) & 1;
    enable->bit01_pppp     = (value >> 1) & 1;
    enable->bit02_pxbar    = (value >> 2) & 1;
    enable->bit03_pmfb     = (value >> 3) & 1;
    enable->bit04_pmedia   = (value >> 4) & 1;
    enable->bit05_pring    = (value >> 5) & 1;
    enable->bit06_pcopy0   = (value >> 6) & 1;
    enable->bit07_pcopy1   = (value >> 7) & 1;
    enable->bit08_pfifo    = (value >> 8) & 1;
    enable->bit09_unk1     = (value >> 9) & 1;
    enable->bit10_unk2     = (value >> 10) & 1;
    enable->bit11_unk3     = (value >> 11) & 1;
    enable->bit12_pgrahph  = (value >> 12) & 1;
    enable->bit13_pdaemon  = (value >> 13) & 1;
    enable->bit14_psec     = (value >> 14) & 1;
    enable->bit15_pvdec    = (value >> 15) & 1;
    enable->bit16_ptimer   = (value >> 16) & 1;
    enable->bit17_ppdec    = (value >> 17) & 1;
    enable->bit18_pvenc    = (value >> 18) & 1;
    enable->bit19_unk4     = (value >> 19) & 1;
    enable->bit20_pbfb     = (value >> 20) & 1;
    enable->bit21_pcopy2   = (value >> 21) & 1;
    enable->bit22_unk5     = (value >> 22) & 1;
    enable->bit23_unk6     = (value >> 23) & 1;
    enable->bit24_unk7     = (value >> 24) & 1;
    enable->bit25_unk8     = (value >> 25) & 1;
    enable->bit26_zpw      = (value >> 26) & 1;
    enable->bit27_blg      = (value >> 27) & 1;
    enable->bit28_pcounter = (value >> 28) & 1;
    enable->bit29_pffb     = (value >> 29) & 1;
    enable->bit30_pdisplay = (value >> 30) & 1;
    enable->bit31_isohub   = (value >> 31) & 1;
}

int main(int argc, char **argv) {
    int c;
    int i;
    int cnum = 0;
    int mask = 0;

    uint32_t write_value = 0;
    uint32_t write_addr = 0;

    if (nva_init()) {
            fprintf (stderr, "PCI init failure!\n");
            return 1;
    }

    while ((c = getopt (argc, argv, "c:b:m:w")) != -1)
    switch (c) {
            case 'c':
                    sscanf(optarg, "%d", &cnum);
                    break;
            case 'b':
                    mask |= NVIDIA_MMIO_MASK_PBUS;
                    break;
            case 'm':
                    mask |= NVIDIA_MMIO_MASK_PMC;
                    break;
            case 'w':
                    sscanf(optarg, "%ul %ul", &write_addr, &write_value);
                    fprintf (stdout, "0x%x 0x%x.\n", write_addr, write_value);
                    break;
            default:
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
    } else {
        fprintf(stdout, "Card Number: %d\n", cnum);
    }

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
            printf("\t------------------------------\n");

            struct pmc_new_id new_id;
            PMC_NEW_ID(pmc_boot_42, &new_id);

            printf("\t(0xA00) NEW_ID gpu id   : 0x%03x\n",  new_id.gpu_id);
            printf("\t(0xA00) NEW_ID device id: 0x%02x\n",  new_id.device_id);
            printf("\t(0xA00) NEW_ID stepping : 0x%02x\n",  new_id.stepping);
            printf("\t------------------------------\n\n");
            
            struct pmc_enable enable_decoded;
            PMC_ENABLE(pmc_enable, &enable_decoded);
            print_bits(pmc_enable);

            printf("\tUNK0     : %d\n",   enable_decoded.bit00_unk0     );
            printf("\tPPPP     : %d\n",   enable_decoded.bit01_pppp     );
            printf("\tPXBAR    : %d\n",   enable_decoded.bit02_pxbar    );
            printf("\tPMFB     : %d\n",   enable_decoded.bit03_pmfb     );
            printf("\tPMEDIA   : %d\n",   enable_decoded.bit04_pmedia   );
            printf("\tPRING    : %d\n",   enable_decoded.bit05_pring    );
            printf("\tPCOPY0   : %d\n",   enable_decoded.bit06_pcopy0   );
            printf("\tPCOPY1   : %d\n",   enable_decoded.bit07_pcopy1   );
            printf("\tPFIFO    : %d\n",   enable_decoded.bit08_pfifo    );
            printf("\tUNK1     : %d\n",   enable_decoded.bit09_unk1     );
            printf("\tUNK2     : %d\n",   enable_decoded.bit10_unk2     );
            printf("\tUNK3     : %d\n",   enable_decoded.bit11_unk3     );
            printf("\tPGRAHPH  : %d\n",   enable_decoded.bit12_pgrahph  );
            printf("\tPDAEMON  : %d\n",   enable_decoded.bit13_pdaemon  );
            printf("\tPSEC     : %d\n",   enable_decoded.bit14_psec     );
            printf("\tPVDEC    : %d\n",   enable_decoded.bit15_pvdec    );
            printf("\tPTIMER   : %d\n",   enable_decoded.bit16_ptimer   );
            printf("\tPPDEC    : %d\n",   enable_decoded.bit17_ppdec    );
            printf("\tPVENC    : %d\n",   enable_decoded.bit18_pvenc    );
            printf("\tUNK4     : %d\n",   enable_decoded.bit19_unk4     );
            printf("\tPBFB     : %d\n",   enable_decoded.bit20_pbfb     );
            printf("\tPCOPY2   : %d\n",   enable_decoded.bit21_pcopy2   );
            printf("\tUNK5     : %d\n",   enable_decoded.bit22_unk5     );
            printf("\tUNK6     : %d\n",   enable_decoded.bit23_unk6     );
            printf("\tUNK7     : %d\n",   enable_decoded.bit24_unk7     );
            printf("\tUNK8     : %d\n",   enable_decoded.bit25_unk8     );
            printf("\tZPW      : %d\n",   enable_decoded.bit26_zpw      );
            printf("\tBLG      : %d\n",   enable_decoded.bit27_blg      );
            printf("\tPCOUNTER : %d\n",   enable_decoded.bit28_pcounter );
            printf("\tPFFB     : %d\n",   enable_decoded.bit29_pffb     );
            printf("\tPDISPLAY : %d\n",   enable_decoded.bit30_pdisplay );
            printf("\tISOHUB   : %d\n",   enable_decoded.bit31_isohub   );
            

    }

    /*
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
    */

    return 0;
}
