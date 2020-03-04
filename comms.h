#include <stdio.h>
extern void comms_init();
extern void comms_finalize();
extern void put(char* dest, char* source, size_t nelems, int pe);
extern void get(char* dest, char* source, size_t nelems, int pe);
