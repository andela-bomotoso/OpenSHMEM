#include <stdio.h>
void comms_init();
void comms_finalize();
void comms_put(char* dest, char* source, size_t nelems, int pe);
void comms_get(char* dest, char* source, size_t nelems, int pe);
void comms_int_put(int* dest, int* source, size_t nelems, int pe);
void comms_int_get(int* dest, int* source, size_t nelems, int pe);
void* comms_malloc(size_t bytes);
