all:
	gcc dump_mmio_regs.c include/nva/gpu.c include/nva/nva.c include/nva/chipset.c include/nva/regspace.c -o dump_mmio_regs -lpciaccess 

clean:
	rm -rf dump_mmio_regs
