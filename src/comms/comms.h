#include <stdio.h>
void comms_init();
void comms_finalize();
void comms_int_put(int* dest, int* source, size_t nelems, int pe);
void comms_int_get(int* dest, int* source, size_t nelems, int pe);
void comms_int_put_nbi(int *dest, const int *source, size_t nelems, int pe);
void comms_int_get_nbi(int *dest, const int *source, size_t nelems, int pe);
void shmem_putmem(void *dest, const void *source, size_t nelems, int pe);
void shmem_getmem(void *dest, const void *source, size_t nelems, int pe);
void* comms_malloc(size_t bytes);
