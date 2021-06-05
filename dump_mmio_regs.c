#include "nva/nva.h"
#include <stdio.h>
#include <unistd.h>

enum {
	NV01_MASK_PMC		= 0x0001,
	NV01_MASK_PBUS		= 0x0002,
	NV01_MASK_ALL		= 0x0fff,
};

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
                        mask |= NV01_MASK_PMC;
                        break;
                case 'b':
                        mask |= NV01_MASK_PBUS;
                        break;
        }

	if (!mask)
		mask = NV01_MASK_ALL;

	if (cnum >= nva_cardsnum) {
		if (nva_cardsnum)
			fprintf (stderr, "No such card.\n");
		else
			fprintf (stderr, "No cards found.\n");
		return 1;
	}

	if (mask & NV01_MASK_PMC) {
		printf("PMC:\n");
		printf("\tID: %08x\n",     nva_rd32(cnum, 0x0));
		printf("\tBOOT_2: %08x\n", nva_rd32(cnum, 0x8));
		printf("\tENABLE: %08x\n", nva_rd32(cnum, 0x200));
		printf("\tNEW_ID: %08x\n", nva_rd32(cnum, 0xa00));
	}
	

	if (mask & NV01_MASK_PBUS) {
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
