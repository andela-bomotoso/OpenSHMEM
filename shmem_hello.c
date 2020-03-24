#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int pe, size;

    rte_init();
    pe = rte_my_pe();
    size = rte_n_pes();
    printf("Hello world from %d of %d\n" ,pe, size);
    rte_finalize();
    return 0;
}
