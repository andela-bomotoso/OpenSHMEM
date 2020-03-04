#include "comms.h"
#include <stdio.h>
int main(int argc, char **argv){
	char* dest;
	char* source = argv[1];
	put(dest, source, 7, 0);
	printf("Data written in memory externally: %s\n", dest);
}
