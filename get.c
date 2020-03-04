#include "comms.h"
int main(){
	char* source;
	char* dest;
	get(dest, source, 2, 0);
	printf("Data fetched from memory externally %s\n", dest);
}
