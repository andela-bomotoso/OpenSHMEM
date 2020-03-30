#include <stdio.h>
#include <stdlib.h>
#include <shmem.h>

int main(void) {
    int pe, size;

    shmem_init();
    pe = shmem_my_pe();
    size = shmem_n_pes();
    printf("Hello world from %d of %d\n" ,pe, size);
    shmem_finalize();
    return 0;
}
