/*
 * based on pcimem / pcimem2 from busybox
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/mman.h>

#define PRINT_ERROR                                                      \
                do {                                                     \
                fprintf(stderr, "Error at line %d, file %s (%d) [%s]\n", \
                __LINE__, __FILE__, errno, strerror(errno)); exit(1);    \
                } while(0)

int main(int argc, char **argv) {
    int fd;
    void *map_base, *virt_addr;
    uint64_t read_result, writeval, prev_read_result = 0;
    off_t offset, base_offset;

    int access_type = 'w';
    int items_count = 1;
    int verbose = 1;
    int read_result_dupped = 0;
    int type_width;
    int i;
    int map_size = 4096UL;
    char *PHYS_MEM_FILE = "/dev/mem";

    if(argc < 2) {
        // ./mem 0xc8000000 w = reads 32bits
        // ./mem 0xc8000000 d = reads 64bits
        // ./mem 0xc8000000 w*10 = reads (32bits * 10) PS! For zsh use "w*10"
        // ./mem 0xc8000000 w 0x1337 = writes 16bits (0x1337) to specified address
        fprintf(stderr, "Trixxing with PHYS_MEM\n"
                "\tUsage:\t%s phys_mem_addr type[*count] [data]\n"
                "\toffset  : offset into pci memory region to act upon\n"
                "\ttype    : read size: [b]yte, [h]alfword, [w]ord, [d]ouble-word\n"
                "\t*count  : number of blocks to read: w*10 reads (32bits * 10)\n"
                "\tdata    : data to be written\n\n",
                argv[0]);
        exit(1);
    }
    // arg1
    offset = strtoul(argv[1], 0, 0);

    // arg2
    if(argc > 2) {
        access_type = tolower(argv[2][0]);
        if (argv[2][1] == '*')
                items_count = strtoul(argv[2]+2, 0, 0);
    }

    switch(access_type) {
        case 'b':
                type_width = 1;
                break;
        case 'h':
                type_width = 2;
                break;
        case 'w':
                type_width = 4;
                break;
        case 'd':
                type_width = 8;
                break;
        default:
                fprintf(stderr, "Illegal data type '%c'.\n", access_type);
                exit(2);
    }

    if((fd = open(PHYS_MEM_FILE, O_RDWR | O_SYNC)) == -1) PRINT_ERROR;
    printf("%s opened.\n", PHYS_MEM_FILE);
    printf("Offset is 0x%x, page size is %ld\n", (int) offset, sysconf(_SC_PAGE_SIZE));
    fflush(stdout);

    base_offset = offset & ~(sysconf(_SC_PAGE_SIZE)-1);
    if (offset + items_count*type_width - base_offset > map_size)
    map_size = offset + items_count*type_width - base_offset;

    /* Map one page */
    printf("mmap(%d, %d, 0x%x, 0x%x, %d, 0x%x)\n", 0, map_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (int) offset);

    map_base = mmap(0, map_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, base_offset);
    if(map_base == (void *) -1) PRINT_ERROR;
    printf("PCI Memory mapped to address 0x%08lx.\n", (unsigned long) map_base);
    fflush(stdout);

    for (i = 0; i < items_count; i++) {

    virt_addr = map_base + offset + i*type_width - base_offset;
    switch(access_type) {
        case 'b':
                read_result = *((uint8_t *) virt_addr);
                break;
        case 'h':
                read_result = *((uint16_t *) virt_addr);
                break;
        case 'w':
                read_result = *((uint32_t *) virt_addr);
                break;
        case 'd':
                read_result = *((uint64_t *) virt_addr);
                break;
    }

    if (verbose)
    printf("Value at offset 0x%X (%p): 0x%0*lX\n", (int) offset + i*type_width, virt_addr, type_width*2, read_result);
    else {
    if (read_result != prev_read_result || i == 0) {
        printf("0x%04X: 0x%0*lX\n", (int)(offset + i*type_width), type_width*2, read_result);
        read_result_dupped = 0;
    } else {
        if (!read_result_dupped)
            printf("...\n");
        read_result_dupped = 1;
    }
    }

    prev_read_result = read_result;

    }

    fflush(stdout);

    // arg3
    if(argc > 3) {
        writeval = strtoull(argv[3], NULL, 0);
        switch(access_type) {
                case 'b':
                        *((uint8_t *) virt_addr) = writeval;
                        read_result = *((uint8_t *) virt_addr);
                        break;
                case 'h':
                        *((uint16_t *) virt_addr) = writeval;
                        read_result = *((uint16_t *) virt_addr);
                        break;
                case 'w':
                        *((uint32_t *) virt_addr) = writeval;
                        read_result = *((uint32_t *) virt_addr);
                        break;
                case 'd':
                        *((uint64_t *) virt_addr) = writeval;
                        read_result = *((uint64_t *) virt_addr);
                        break;
        }
        printf("Wrote 0x%0*lX; readback 0x%*lX\n", type_width,
                writeval, type_width, read_result);
        fflush(stdout);
    }

    if(munmap(map_base, map_size) == -1) PRINT_ERROR;
    close(fd);
    return 0;
}
