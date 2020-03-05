/*******************************************OpenSHMEM*******************************
 * *	GitHub.com: 	https://github.com/andela-bomotoso/OpenSHMEM
 * *	Author: 		Bukola Grace Omotoso
 * *	Email:			bgo2e@mtmail.mtsu.edu
 * *	Description: 	A partial implementation of the OpenSHMEM 1.4 Specification
 * *	Date:			3rd March 2020
 * ************************************************************************************/

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
void* shm_buffer;
int shmid;


void comms_init()	{
	/*ftok to generate unique key*/
        key_t key = ftok("shmfile", 65);
        /*shmget returns an identifier in shmid*/
        shmid = shmget(key, 1024, 0666|IPC_CREAT);
	 /*shmat to attach shared memory*/
        shm_buffer = shmat(shmid, (void*)0,0);
	
}
/*put char buffer into the shared memory*/
void comms_put(char* dest, char* source, size_t nelems, int pe){
	
	/*Copy the source into shmem buffer*/
	 memcpy(shm_buffer,  (void *)source,  sizeof(source));

	/*Copy source into dest*/
	memcpy((void*)dest, (void*)source,  nelems);
		
	printf("Data written in memory internally: %s\n", dest);
}


/*fetch char buffer from the shared memory*/
void comms_get(char* dest, char* source, size_t nelems, int pe){
	
	/*copy source into dest*/
	memcpy((void*)dest,  (void*)source,  nelems);
	
	printf("Data read from memory internally: %s\n", dest);
}

void comms_finalize()	{

        /*detach from shared memory*/
          shmdt(shm_buffer);

	/*destroy the shared memory*/
	shmctl(shmid, IPC_RMID, NULL);

}


