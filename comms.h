#include <stdio.h>
extern void comms_init();
extern void comms_finalize();
extern void comms_put(char* dest, char* source, size_t nelems, int pe);
extern void comms_get(char* dest, char* source, size_t nelems, int pe);
extern void* shmem_malloc(size_t bytes);
