#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#define KEY_EVENT_FIFO 0x0600

void *map_addr;
int mem_fd;

void key_event(int fd)
{
    uint8_t scancode;

    read(fd, &scancode, sizeof(scancode));
    printf("Scan Code: 0x%02x\n", scancode);
}

int main(int argc, char **argv)
{
    int fd;
    uint32_t mmap_size = getpagesize();
    uint32_t mmap_mask = mmap_size-1;
    void *key_addr;

    if ((mem_fd = open("/dev/mem", O_RDWR)) < 0) {
        perror("Unable to open /dev/mem");
        exit(-1);
    }

    map_addr = mmap(NULL, mmap_size,
                    PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, KEY_EVENT_FIFO & ~mmap_mask);

    if (map_addr == MAP_FAILED) {
        perror("Unable to mmap file");
        exit(-1);
    }

    key_addr = map_addr + (KEY_EVENT_FIFO & mmap_mask);

    fcntl(0, F_SETFL, O_NONBLOCK);
    if ((fd = open("/dev/input/event0", O_RDONLY)) < 0) {
        perror("Unable to open input device");
        exit(-1);
    }

    while(1) {
        if ( (*((uint8_t*)key_addr) & 0x02) == 0 ) {
            key_event(fd);
        }
        usleep(50);
    }

    return 0;
}