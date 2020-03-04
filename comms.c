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

using namespace std;

/*put char buffer into the shared memory*/
void put(char* dest, char* source, size_t nelems, int pe){
	
	/*ftok to generate unique key*/
	key_t key = ftok("shmfile", 65);

	/*shmget returns an identifier in shmid*/
	int shmid = shmget(key, 1024, 0666|IPC_CREAT);

	/*shmat to attach shared memory*/
	dest = (char*) shmat(shmid, (void*)0,0);
	
	for (int i = 0; i < nelems; i++)
                dest[i] = source[i];

	printf("Data written in memory internally: %s\n", dest);
}


/*fetch char buffer from the shared memory*/
void get(char *dest, char* source, size_t nelems, int pe){

        /*ftok to generate unique key*/
        key_t key = ftok("shmfile", 65);

        /*shmget returns an identifier in shmid*/
        int shmid = shmget(key, 1024, 0666|IPC_CREAT);

        /*shmat to attach shared memory*/
        source = (char*)shmat(shmid, (void*)0,0); 

	dest = source;
	int i = 0;
	for (int i = 0; i < nelems; i++)
		dest[i] = source[i];	
	 printf("Data read from memory internally: %s\n", dest);

        /*detach from shared memory*/
          shmdt(source);

	/*destroy the shared memory*/
	shmctl(shmid, IPC_RMID, NULL);

}


