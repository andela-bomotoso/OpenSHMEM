/*******************************************OpenSHMEM*******************************
 * *	GitHub.com: 	https://github.com/andela-bomotoso/OpenSHMEM
 * *	Author: 		Bukola Grace Omotoso
 * *	Email:			bgo2e@mtmail.mtsu.edu
 * *	Description: 	A partial implementation of the OpenSHMEM 1.4 Specification
 * *	Date:			3rd March 2020
 * ************************************************************************************/

//#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void** shm_buffer;
void* buffer_head;
int shmid;

void* mybuffer;
void comms_init()	{

	rte_init();
        int pe = rte_my_pe();
        int npes = rte_n_pes();
	shm_buffer = malloc(npes*sizeof(void*));
	/*ftok to generate unique key*/
        key_t key = ftok("shmfile",pe);
        /*shmget returns an identifier in shmid*/
        shmid = shmget(key, 1024, 0666|IPC_CREAT);
	 /*shmat to attach shared memory*/
        shm_buffer[pe] = mybuffer = shmat(shmid, (void**)0,0);
	buffer_head = mybuffer;
}
/*put char buffer into the shared memory*/
void comms_put(char* dest, char* source, size_t nelems, int pe){	
	int offset = (size_t)dest - (size_t)mybuffer;

	/*Copy the source into shmem buffer*/
	memcpy(shm_buffer[pe]+offset,   (void*)source,  sizeof(char)*nelems);
		
	printf("Data written in memory internally: %s\n", dest);
}

/*put int buffer into shared memory*/
void comms_int_put(int* dest, int* source, size_t nelems, int pe){
        int offset = (size_t)dest - (size_t)mybuffer;

        /*Copy the source into shmem buffer*/
        memcpy(shm_buffer[pe]+offset,   (void*)source,  sizeof(int)*nelems);
}

/*fetch char buffer from the shared memory*/
void comms_get(char* dest, char* source, size_t nelems, int pe){
	
	int offset = (size_t)source - (size_t)mybuffer;
	
	/*copy source into dest*/
	memcpy((void*)dest,  (void*)shm_buffer[pe]+offset, sizeof(char)*nelems);
	
        printf("Data read from memory internally: %s\n", dest);
}

/*fetch char buffer from the shared memory*/
void comms_int_get(int* dest, int* source, size_t nelems, int pe){

        int offset = (size_t)source - (size_t)mybuffer;
        /*copy source into dest*/
        memcpy((void*)dest,  (void*)shm_buffer[pe]+offset, sizeof(int)*nelems);
}

void* comms_malloc(size_t bytes){
	void* addr = buffer_head;
	buffer_head += bytes;
	return addr;
}

void comms_finalize()	{

        /*detach from shared memory*/
          shmdt(shm_buffer);

	/*destroy the shared memory*/
	shmctl(shmid, IPC_RMID, NULL);
	rte_finalize();
}


