#include "comms.h"
#include "rte.h"
#include <stdio.h>

int main(int argc, char **argv){
	comms_init();
	
	char* dest = comms_malloc(11*sizeof(char));
	char* source = argv[1];
	comms_put(dest, source, 11, 0);
	printf("Data written in memory externally: %s\n", dest);
	
	/*the content of dest is now expected to be in the shared memory*/
	/*dest can now become the source for get operations*/
	char* dest2 = comms_malloc(11*sizeof(char));
	comms_get(dest2, dest, 5, 0);
	printf("Data fetched from memory externally %s\n", dest2);
	
	comms_finalize();
	
}
