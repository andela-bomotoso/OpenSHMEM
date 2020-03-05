#include "comms.h"
#include "rte.h"
#include <stdio.h>

int main(int argc, char **argv){
	comms_init();
	
	char* dest;
	char* source = argv[1];
	comms_put(dest, source, 5, 0);
	printf("Data written in memory externally: %s\n", dest);
	
	/*the content of dest is now expected to be in the shared memory*/
	/*dest can now become the source for get operations*/
	char* dest2;
	comms_get(dest2, dest, 2, 0);
	printf("Data fetched from memory externally %s\n", dest2);

	comms_finalize();
	
}
