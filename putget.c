#include <stdio.h>
#include "shmem.h"
int main(void)
{
int source[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
static int dest[10];
comms_init();
int me = shmem_my_pe();
if (me == 0) /* put 10 words into dest on PE 1 */
comms_put(dest, source, 10, 1);
char* dest2 = comms_malloc(10*sizeof(int));
dest2 = comms_get(dest2, dest, 5, 0);
//shmem_barrier_all(); /* sync sender and receiver */
printf("dest[0] on PE %d is %ld\n", me, dest2[0]);
comms_finalize();
return 0;
}

