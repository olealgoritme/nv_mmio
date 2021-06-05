all:
	gcc dump_mmio_regs.c nva/gpu.c nva/nva.c nva/chipset.c nva/regspace.c -o dump_mmio_regs -lpciaccess 

clean:
	rm -rf dump_mmio_regs
