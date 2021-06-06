#include "nva.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <pciaccess.h>

int nva_wr(struct nva_regspace *regspace, uint32_t addr, uint64_t val) {
	void *rawbase = 0;
	size_t rawlen;
	void *raw;
	int i;
	uint32_t vgaio;
	uint32_t vgabase;
	switch (regspace->type) {
		case NVA_REGSPACE_BAR0:
			rawbase = regspace->card->bar0;
			rawlen = regspace->card->bar0len;
			goto raw;
		case NVA_REGSPACE_BAR1:
			rawbase = regspace->card->bar1;
			rawlen = regspace->card->bar1len;
			if (!regspace->card->hasbar1)
				return NVA_ERR_NOSPC;
			goto raw;
		case NVA_REGSPACE_BAR2:
			rawbase = regspace->card->bar2;
			rawlen = regspace->card->bar2len;
			if (!regspace->card->hasbar2)
				return NVA_ERR_NOSPC;
			goto raw;
		case NVA_REGSPACE_RAWMEM:
			rawbase = regspace->card->rawmem;
			rawlen = 0x100000;
		raw:
			if (!rawbase)
				return NVA_ERR_MAP;
			if (addr > rawlen - regspace->regsz)
				return NVA_ERR_RANGE;
			raw = (uint8_t *)rawbase + addr;
			switch (regspace->regsz) {
				case 1:
					*(volatile uint8_t *)raw = val;
					return 0;
				case 2:
					*(volatile uint16_t *)raw = val;
					return 0;
				case 4:
					*(volatile uint32_t *)raw = val;
					return 0;
				case 8:
					*(volatile uint64_t *)raw = val;
					return 0;
				default:
					return NVA_ERR_REGSZ;
			}
		case NVA_REGSPACE_IOBAR:
			if (!regspace->card->iobar)
				return NVA_ERR_NOSPC;
			if (addr > regspace->card->iobarlen - regspace->regsz)
				return NVA_ERR_RANGE;
			switch (regspace->regsz) {
				case 1:
					pci_io_write8(regspace->card->iobar, addr, val);
					return 0;
				case 2:
					pci_io_write16(regspace->card->iobar, addr, val);
					return 0;
				case 4:
					pci_io_write32(regspace->card->iobar, addr, val);
					return 0;
				default:
					return NVA_ERR_REGSZ;
			}
		case NVA_REGSPACE_RAWIO:
			if (!regspace->card->rawio)
				return NVA_ERR_NOSPC;
			if (addr > 0x10000 - regspace->regsz)
				return NVA_ERR_RANGE;
			switch (regspace->regsz) {
				case 1:
					pci_io_write8(regspace->card->rawio, addr, val);
					return 0;
				case 2:
					pci_io_write16(regspace->card->rawio, addr, val);
					return 0;
				case 4:
					pci_io_write32(regspace->card->rawio, addr, val);
					return 0;
				default:
					return NVA_ERR_REGSZ;
			}
		case NVA_REGSPACE_PDAC:
			if (regspace->card->chipset.chipset != 0x01)
				return NVA_ERR_NOSPC;
			if (addr > 0x10000 - regspace->regsz)
				return NVA_ERR_RANGE;
			if (regspace->regsz > 8)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x609010, addr & 0xff);
			nva_wr32(regspace->cnum, 0x609014, addr >> 8);
			for (i = 0; i < regspace->regsz; i++)
				nva_wr32(regspace->cnum, 0x609018, (val >> i * 8) & 0xff);
			return 0;
		case NVA_REGSPACE_EEPROM:
			if (regspace->card->chipset.chipset != 0x01)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 1)
				return NVA_ERR_REGSZ;
			if (addr >= 0x80)
				return NVA_ERR_RANGE;
			while (nva_rd32(regspace->cnum, 0x60a400) & 0x10000000);
			nva_wr32(regspace->cnum, 0x60a400, 0x1000000 | addr << 8 | (val & 0xff));
			while (nva_rd32(regspace->cnum, 0x60a400) & 0x10000000);
			return 0;
		case NVA_REGSPACE_VGA_CR:
			vgaio = 0x3d4;
			if (addr >= 0x100)
				return NVA_ERR_RANGE;
			goto vga;
		case NVA_REGSPACE_VGA_SR:
			vgaio = 0x3c4;
			if (addr >= 8)
				return NVA_ERR_RANGE;
			goto vga;
		case NVA_REGSPACE_VGA_GR:
			vgaio = 0x3ce;
			if (addr >= 0x10)
				return NVA_ERR_RANGE;
			goto vga;
		case NVA_REGSPACE_VGA_AR:
			vgaio = 0x3c0;
			if (addr >= 0x20)
				return NVA_ERR_RANGE;
			goto vga;
		vga:
			if (regspace->regsz != 1)
				return NVA_ERR_REGSZ;
			if (regspace->card->chipset.card_type == 0x01) {
				vgabase = 0x6d0000;
				if (regspace->idx != 0)
					return NVA_ERR_NOSPC;
			} else if (regspace->card->chipset.card_type < 0x50) {
				if (vgaio == 0x3c4 || vgaio == 0x3ce)
					vgabase = 0x0c0000;
				else
					vgabase = 0x601000;
				if (regspace->idx > 2)
					return NVA_ERR_NOSPC;
				if ((regspace->card->chipset.chipset < 0x17 || regspace->card->chipset.chipset == 0x1a || regspace->card->chipset.chipset == 0x20) && regspace->idx == 1)
					return NVA_ERR_NOSPC;
				vgabase += regspace->idx * 0x2000;
			} else {
				vgabase = 0x601000;
				if (regspace->idx != 0)
					return NVA_ERR_NOSPC;
			}
			if (vgaio == 0x3c0) {
				nva_rd8(regspace->cnum, vgabase + 0x3da);
				uint8_t idx = nva_rd8(regspace->cnum, vgabase + 0x3c0);
				nva_rd8(regspace->cnum, vgabase + 0x3da);
				nva_wr8(regspace->cnum, vgabase + 0x3c0, addr);
				nva_wr8(regspace->cnum, vgabase + 0x3c0, val);
				nva_wr8(regspace->cnum, vgabase + 0x3c0, idx);
			} else {
				uint8_t idx = nva_rd8(regspace->cnum, vgabase + vgaio);
				nva_wr8(regspace->cnum, vgabase + vgaio, addr);
				nva_wr8(regspace->cnum, vgabase + vgaio + 1, val);
				nva_wr8(regspace->cnum, vgabase + vgaio, idx);
			}
			return 0;
		case NVA_REGSPACE_VGA_ST:
			if (regspace->card->chipset.chipset < 0x41)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 1)
				return NVA_ERR_REGSZ;
			uint32_t vstbase = 0x1380;
			if (regspace->card->chipset.card_type >= 0x50)
				vstbase = 0x619e40;
			uint32_t savepos = nva_rd32(regspace->cnum, vstbase+0xc);
			uint32_t savecfg = nva_rd32(regspace->cnum, vstbase+0x8);
			nva_wr32(regspace->cnum, vstbase+0xc, addr);
			nva_wr32(regspace->cnum, vstbase+0x8, 7);
			nva_wr32(regspace->cnum, vstbase+0x0, val);
			nva_wr32(regspace->cnum, vstbase+0x8, savecfg);
			nva_wr32(regspace->cnum, vstbase+0xc, savepos);
			return 0;
		case NVA_REGSPACE_DPRAM:
			if (regspace->card->chipset.chipset == 0x34) {
				if (regspace->regsz != 4)
					return NVA_ERR_REGSZ;
				nva_wr32(regspace->cnum, 0x400bb0, addr);
				nva_wr32(regspace->cnum, 0x400bb4, val);
				return 0;
			}
			if (regspace->card->chipset.card_type < 4 || regspace->card->chipset.card_type >= 0x20)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x400828, addr);
			nva_wr32(regspace->cnum, 0x40082c, val);
			return 0;
		case NVA_REGSPACE_PIPE:
			if (regspace->card->chipset.card_type < 0x10 || regspace->card->chipset.card_type >= 0x50)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x400f50, addr);
			nva_wr32(regspace->cnum, 0x400f54, val);
			return 0;
		case NVA_REGSPACE_RDI:
			if (regspace->card->chipset.chipset == 0x17 || regspace->card->chipset.chipset == 0x18 || regspace->card->chipset.chipset == 0x1f) {
				if (regspace->regsz != 4)
					return NVA_ERR_REGSZ;
				nva_wr32(regspace->cnum, 0x400a08, addr);
				nva_wr32(regspace->cnum, 0x400a0c, val);
				return 0;
			}
			if (regspace->card->chipset.card_type < 0x20 || regspace->card->chipset.card_type >= 0x50)
				return NVA_ERR_NOSPC;
			nva_wr32(regspace->cnum, 0x400750, addr);
			nva_wr32(regspace->cnum, 0x400754, val);
			return 0;
		case NVA_REGSPACE_RDIB:
			if (regspace->card->chipset.card_type < 0x20 || regspace->card->chipset.card_type >= 0x50)
				return NVA_ERR_NOSPC;
			nva_wr32(regspace->cnum, 0x400750, addr);
			nva_wr32(regspace->cnum, 0x400758, val);
			return 0;
		case NVA_REGSPACE_VCOMP_CODE:
			if (regspace->card->chipset.chipset != 0xaf)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x1c17c8, addr);
			nva_wr32(regspace->cnum, 0x1c17cc, val);
			return 0;
		case NVA_REGSPACE_VCOMP_REG:
			if (regspace->card->chipset.chipset != 0xaf)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 8)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x1c17d0, addr/8);
			nva_wr32(regspace->cnum, 0x1c17d4, val);
			nva_wr32(regspace->cnum, 0x1c17d8, val >> 32);
			return 0;
		case NVA_REGSPACE_MACRO_CODE:
			if (regspace->card->chipset.chipset < 0xc0)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x40986c, 0x10);
			nva_wr32(regspace->cnum, 0x409ffc, 2);
			nva_wr32(regspace->cnum, 0x409928, 0xc);
			while (nva_rd32(regspace->cnum, 0x409928));
			nva_wr32(regspace->cnum, 0x40993c, 0xf);
			nva_wr32(regspace->cnum, 0x409928, 0xa);
			while (nva_rd32(regspace->cnum, 0x409928));
			nva_wr32(regspace->cnum, 0x40991c, 0x1);
			nva_wr32(regspace->cnum, 0x409928, 0x1);
			while (nva_rd32(regspace->cnum, 0x409928));
			for (i = 0; i < addr; i+=4) {
				nva_wr32(regspace->cnum, 0x409928, 0x6);
				while (nva_rd32(regspace->cnum, 0x409928));
			}
			nva_wr32(regspace->cnum, 0x409918, val);
			nva_wr32(regspace->cnum, 0x409928, 0x7);
			while (nva_rd32(regspace->cnum, 0x409928));
			return 0;
		case NVA_REGSPACE_XT:
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x1700, 0x30);
			nva_wr32(regspace->cnum, 0x700004, addr);
			nva_wr32(regspace->cnum, 0x700008, val);
			nva_wr32(regspace->cnum, 0x70000, 1);
			while (nva_rd32(regspace->cnum, 0x70000));
			nva_wr32(regspace->cnum, 0x700000, 2);
			while (nva_rd32(regspace->cnum, 0x700000));
			return 0;
		default:
			return NVA_ERR_NOSPC;
	}
}

int nva_rd(struct nva_regspace *regspace, uint32_t addr, uint64_t *val) {
	void *rawbase = 0;
	size_t rawlen;
	void *raw;
	int i;
	uint32_t vgaio;
	uint32_t vgabase;
	switch (regspace->type) {
		case NVA_REGSPACE_BAR0:
			rawbase = regspace->card->bar0;
			rawlen = regspace->card->bar0len;
			goto raw;
		case NVA_REGSPACE_BAR1:
			rawbase = regspace->card->bar1;
			rawlen = regspace->card->bar1len;
			goto raw;
		case NVA_REGSPACE_BAR2:
			rawbase = regspace->card->bar2;
			rawlen = regspace->card->bar2len;
			goto raw;
		case NVA_REGSPACE_RAWMEM:
			rawbase = regspace->card->rawmem;
			rawlen = 0x100000;
		raw:
			if (!rawbase)
				return NVA_ERR_MAP;
			if (addr > rawlen - regspace->regsz)
				return NVA_ERR_RANGE;
			raw = (uint8_t *)rawbase + addr;
			switch (regspace->regsz) {
				case 1:
					*val = *(volatile uint8_t *)raw;
					return 0;
				case 2:
					*val = *(volatile uint16_t *)raw;
					return 0;
				case 4:
					*val = *(volatile uint32_t *)raw;
					return 0;
				case 8:
					*val = *(volatile uint64_t *)raw;
					return 0;
				default:
					return NVA_ERR_REGSZ;
			}
		case NVA_REGSPACE_IOBAR:
			if (!regspace->card->iobar)
				return NVA_ERR_NOSPC;
			if (addr > regspace->card->iobarlen - regspace->regsz)
				return NVA_ERR_RANGE;
			switch (regspace->regsz) {
				case 1:
					*val = pci_io_read8(regspace->card->iobar, addr);
					return 0;
				case 2:
					*val = pci_io_read16(regspace->card->iobar, addr);
					return 0;
				case 4:
					*val = pci_io_read32(regspace->card->iobar, addr);
					return 0;
				default:
					return NVA_ERR_REGSZ;
			}
		case NVA_REGSPACE_RAWIO:
			if (!regspace->card->rawio)
				return NVA_ERR_NOSPC;
			if (addr > 0x10000 - regspace->regsz)
				return NVA_ERR_RANGE;
			switch (regspace->regsz) {
				case 1:
					*val = pci_io_read8(regspace->card->rawio, addr);
					return 0;
				case 2:
					*val = pci_io_read16(regspace->card->rawio, addr);
					return 0;
				case 4:
					*val = pci_io_read32(regspace->card->rawio, addr);
					return 0;
				default:
					return NVA_ERR_REGSZ;
			}
		case NVA_REGSPACE_PDAC:
			if (regspace->card->chipset.chipset != 0x01)
				return NVA_ERR_NOSPC;
			if (addr > 0x10000 - regspace->regsz)
				return NVA_ERR_RANGE;
			if (regspace->regsz > 8)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x609010, addr & 0xff);
			nva_wr32(regspace->cnum, 0x609014, addr >> 8);
			*val = 0;
			for (i = 0; i < regspace->regsz; i++)
				*val |= (uint64_t)(nva_rd32(regspace->cnum, 0x609018) & 0xff) << i * 8;
			return 0;
		case NVA_REGSPACE_EEPROM:
			if (regspace->card->chipset.chipset != 0x01)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 1)
				return NVA_ERR_REGSZ;
			if (addr >= 0x80)
				return NVA_ERR_RANGE;
			while (nva_rd32(regspace->cnum, 0x60a400) & 0x10000000);
			nva_wr32(regspace->cnum, 0x60a400, 0x2000000 | addr << 8);
			while (nva_rd32(regspace->cnum, 0x60a400) & 0x10000000);
			*val = nva_rd32(regspace->cnum, 0x60a400) & 0xff;
			return 0;
		case NVA_REGSPACE_VGA_CR:
			vgaio = 0x3d4;
			if (addr >= 0x100)
				return NVA_ERR_RANGE;
			goto vga;
		case NVA_REGSPACE_VGA_SR:
			vgaio = 0x3c4;
			if (addr >= 8)
				return NVA_ERR_RANGE;
			goto vga;
		case NVA_REGSPACE_VGA_GR:
			vgaio = 0x3ce;
			if (addr >= 0x10)
				return NVA_ERR_RANGE;
			goto vga;
		case NVA_REGSPACE_VGA_AR:
			vgaio = 0x3c0;
			if (addr >= 0x20)
				return NVA_ERR_RANGE;
			goto vga;
		vga:
			if (regspace->regsz != 1)
				return NVA_ERR_REGSZ;
			if (regspace->card->chipset.card_type == 0x01) {
				vgabase = 0x6d0000;
				if (regspace->idx != 0)
					return NVA_ERR_NOSPC;
			} else if (regspace->card->chipset.card_type < 0x50) {
				if (vgaio == 0x3c4 || vgaio == 0x3ce)
					vgabase = 0x0c0000;
				else
					vgabase = 0x601000;
				if (regspace->idx > 2)
					return NVA_ERR_NOSPC;
				if ((regspace->card->chipset.chipset < 0x17 || regspace->card->chipset.chipset == 0x1a || regspace->card->chipset.chipset == 0x20) && regspace->idx == 1)
					return NVA_ERR_NOSPC;
				vgabase += regspace->idx * 0x2000;
			} else {
				vgabase = 0x601000;
				if (regspace->idx != 0)
					return NVA_ERR_NOSPC;
			}
			if (vgaio == 0x3c0) {
				nva_rd8(regspace->cnum, vgabase + 0x3da);
				uint8_t idx = nva_rd8(regspace->cnum, vgabase + 0x3c0);
				nva_rd8(regspace->cnum, vgabase + 0x3da);
				nva_wr8(regspace->cnum, vgabase + 0x3c0, addr);
				*val = nva_rd8(regspace->cnum, vgabase + 0x3c1);
				nva_rd8(regspace->cnum, vgabase + 0x3da);
				nva_wr8(regspace->cnum, vgabase + 0x3c0, idx);
			} else {
				uint8_t idx = nva_rd8(regspace->cnum, vgabase + vgaio);
				nva_wr8(regspace->cnum, vgabase + vgaio, addr);
				*val = nva_rd8(regspace->cnum, vgabase + vgaio + 1);
				nva_wr8(regspace->cnum, vgabase + vgaio, idx);
			}
			return 0;
		case NVA_REGSPACE_VGA_ST:
			if (regspace->card->chipset.chipset < 0x41)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 1)
				return NVA_ERR_REGSZ;
			uint32_t vstbase = 0x1380;
			if (regspace->card->chipset.card_type >= 0x50)
				vstbase = 0x619e40;
			uint32_t savepos = nva_rd32(regspace->cnum, vstbase+0xc);
			uint32_t savecfg = nva_rd32(regspace->cnum, vstbase+0x8);
			nva_wr32(regspace->cnum, vstbase+0xc, addr+1);
			nva_wr32(regspace->cnum, vstbase+0x8, 7);
			*val = nva_rd32(regspace->cnum, vstbase+0x0);
			nva_wr32(regspace->cnum, vstbase+0x8, savecfg);
			nva_wr32(regspace->cnum, vstbase+0xc, savepos);
			return 0;
		case NVA_REGSPACE_DPRAM:
			if (regspace->card->chipset.chipset == 0x34) {
				if (regspace->regsz != 4)
					return NVA_ERR_REGSZ;
				nva_wr32(regspace->cnum, 0x400bb0, addr);
				*val = nva_rd32(regspace->cnum, 0x400bb4);
				return 0;
			}
			if (regspace->card->chipset.card_type < 4 || regspace->card->chipset.card_type >= 0x20)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x400828, addr);
			*val = nva_rd32(regspace->cnum, 0x40082c);
			return 0;
		case NVA_REGSPACE_PIPE:
			if (regspace->card->chipset.card_type < 0x10 || regspace->card->chipset.card_type >= 0x50)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x400f50, addr);
			*val = nva_rd32(regspace->cnum, 0x400f54);
			return 0;
		case NVA_REGSPACE_RDI:
			if (regspace->card->chipset.chipset == 0x17 || regspace->card->chipset.chipset == 0x18 || regspace->card->chipset.chipset == 0x1f) {
				if (regspace->regsz != 4)
					return NVA_ERR_REGSZ;
				nva_wr32(regspace->cnum, 0x400a08, addr);
				*val = nva_rd32(regspace->cnum, 0x400a0c);
				return 0;
			}
			if (regspace->card->chipset.card_type < 0x20 || regspace->card->chipset.card_type >= 0x50)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x400750, addr);
			*val = nva_rd32(regspace->cnum, 0x400754);
			return 0;
		case NVA_REGSPACE_RDIB:
			if (regspace->card->chipset.card_type < 0x20 || regspace->card->chipset.card_type >= 0x50)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x400750, addr);
			*val = nva_rd32(regspace->cnum, 0x400758);
			return 0;
		case NVA_REGSPACE_VCOMP_CODE:
			if (regspace->card->chipset.chipset != 0xaf)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x1c17c8, addr);
			*val = nva_rd32(regspace->cnum, 0x1c17cc);
			return 0;
		case NVA_REGSPACE_VCOMP_REG:
			if (regspace->card->chipset.chipset != 0xaf)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 8)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x1c17d0, addr/8);
			*val = nva_rd32(regspace->cnum, 0x1c17d4);
			*val |= (uint64_t)nva_rd32(regspace->cnum, 0x1c17d8) << 32;
			return 0;
		case NVA_REGSPACE_MACRO_CODE:
			if (regspace->card->chipset.chipset < 0xc0)
				return NVA_ERR_NOSPC;
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x40986c, 0x10);
			nva_wr32(regspace->cnum, 0x409ffc, 2);
			nva_wr32(regspace->cnum, 0x409928, 0xc);
			while (nva_rd32(regspace->cnum, 0x409928));
			nva_wr32(regspace->cnum, 0x40993c, 0xf);
			nva_wr32(regspace->cnum, 0x409928, 0xa);
			while (nva_rd32(regspace->cnum, 0x409928));
			nva_wr32(regspace->cnum, 0x40991c, 0x1);
			nva_wr32(regspace->cnum, 0x409928, 0x1);
			while (nva_rd32(regspace->cnum, 0x409928));
			for (i = 0; i < addr; i+=4) {
				nva_wr32(regspace->cnum, 0x409928, 0x6);
				while (nva_rd32(regspace->cnum, 0x409928));
			}
			nva_wr32(regspace->cnum, 0x409928, 0x6);
			while (nva_rd32(regspace->cnum, 0x409928));
			*val = nva_rd32(regspace->cnum, 0x409918);
			return 0;
		case NVA_REGSPACE_XT:
			if (regspace->regsz != 4)
				return NVA_ERR_REGSZ;
			nva_wr32(regspace->cnum, 0x1700, 0x30);
			nva_wr32(regspace->cnum, 0x700004, addr);
			nva_wr32(regspace->cnum, 0x70000, 1);
			while (nva_rd32(regspace->cnum, 0x70000));
			nva_wr32(regspace->cnum, 0x700000, 1);
			while (nva_rd32(regspace->cnum, 0x700000));
			*val = nva_rd32(regspace->cnum, 0x700004);
			return 0;
		default:
			return NVA_ERR_NOSPC;
	}
}

int nva_rstype(const char *name) {
	if (!strcmp(name, "bar0"))
		return NVA_REGSPACE_BAR0;
	if (!strcmp(name, "mmio"))
		return NVA_REGSPACE_BAR0;
	if (!strcmp(name, "bar1"))
		return NVA_REGSPACE_BAR1;
	if (!strcmp(name, "fb"))
		return NVA_REGSPACE_BAR1;
	if (!strcmp(name, "bar2"))
		return NVA_REGSPACE_BAR2;
	if (!strcmp(name, "bar3"))
		return NVA_REGSPACE_BAR2;
	if (!strcmp(name, "ramin"))
		return NVA_REGSPACE_BAR2;
	if (!strcmp(name, "iobar"))
		return NVA_REGSPACE_IOBAR;
	if (!strcmp(name, "rawmem"))
		return NVA_REGSPACE_RAWMEM;
	if (!strcmp(name, "rawio"))
		return NVA_REGSPACE_RAWIO;
	if (!strcmp(name, "pdac"))
		return NVA_REGSPACE_PDAC;
	if (!strcmp(name, "eeprom"))
		return NVA_REGSPACE_EEPROM;
	if (!strcmp(name, "cr"))
		return NVA_REGSPACE_VGA_CR;
	if (!strcmp(name, "sr"))
		return NVA_REGSPACE_VGA_SR;
	if (!strcmp(name, "gr"))
		return NVA_REGSPACE_VGA_GR;
	if (!strcmp(name, "ar"))
		return NVA_REGSPACE_VGA_AR;
	if (!strcmp(name, "cr"))
		return NVA_REGSPACE_VGA_CR;
	if (!strcmp(name, "vst"))
		return NVA_REGSPACE_VGA_ST;
	if (!strcmp(name, "dpram"))
		return NVA_REGSPACE_DPRAM;
	if (!strcmp(name, "pipe"))
		return NVA_REGSPACE_PIPE;
	if (!strcmp(name, "rdi"))
		return NVA_REGSPACE_RDI;
	if (!strcmp(name, "rdib"))
		return NVA_REGSPACE_RDIB;
	if (!strcmp(name, "vcomp_code"))
		return NVA_REGSPACE_VCOMP_CODE;
	if (!strcmp(name, "vcomp_reg"))
		return NVA_REGSPACE_VCOMP_REG;
	if (!strcmp(name, "macro_code"))
		return NVA_REGSPACE_MACRO_CODE;
	if (!strcmp(name, "xt"))
		return NVA_REGSPACE_XT;
	return NVA_REGSPACE_UNKNOWN;
}

int nva_rsdefsz(struct nva_regspace *regspace) {
	switch (regspace->type) {
		case NVA_REGSPACE_BAR0:
		case NVA_REGSPACE_BAR1:
		case NVA_REGSPACE_BAR2:
		case NVA_REGSPACE_IOBAR:
		case NVA_REGSPACE_DPRAM:
		case NVA_REGSPACE_PIPE:
		case NVA_REGSPACE_RDI:
		case NVA_REGSPACE_RDIB:
		case NVA_REGSPACE_VCOMP_CODE:
		case NVA_REGSPACE_MACRO_CODE:
		case NVA_REGSPACE_XT:
			return 4;
		case NVA_REGSPACE_VCOMP_REG:
			return 8;
		default:
			return 1;
	}
}

int nva_rsunitsz(struct nva_regspace *regspace) {
	switch (regspace->type) {
		case NVA_REGSPACE_DPRAM:
			return 4;
		case NVA_REGSPACE_RDI:
		case NVA_REGSPACE_RDIB:
			if (regspace->card->chipset.chipset == 0x17 || regspace->card->chipset.chipset == 0x18 || regspace->card->chipset.chipset == 0x1f) {
				return 4;
			}
			return 1;
		default:
			return 1;
	}
}

char nva_rserrc(enum nva_err err) {
	switch (err) {
		case NVA_ERR_RANGE:
			return 'R';
		case NVA_ERR_REGSZ:
			return 'B';
		case NVA_ERR_NOSPC:
			return 'S';
		case NVA_ERR_MAP:
			return 'M';
		default:
			abort();
	}
}

void nva_rsprint(struct nva_regspace *regspace, enum nva_err err, uint64_t val) {
	if (err) {
		int k;
		char ec = nva_rserrc(err);
		printf(" ");
		for (k = 0; k < regspace->regsz; k++)
			printf("%c%c", ec, ec);
	} else {
		switch (regspace->regsz) {
			case 1:
				printf (" %02"PRIx64, val);
				break;
			case 2:
				printf (" %04"PRIx64, val);
				break;
			case 4:
				printf (" %08"PRIx64, val);
				break;
			case 8:
				printf (" %016"PRIx64, val);
				break;
		}
	}
}
