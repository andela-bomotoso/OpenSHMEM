/*******************************************OpenSHMEM*******************************
 * *	GitHub.com: 	https://github.com/andela-bomotoso/OpenSHMEM
 * *	Author: 		Bukola Grace Omotoso
 * *	Email:			bgo2e@mtmail.mtsu.edu
 * *	Description: 	A partial implementation of the OpenSHMEM 1.4 Specification
 * *	Date:			3rd March 2020
 * ************************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
using namespace std;

/*initialize openshmem*/
void init(){
	
	MPI_Init(NULL, NULL);
}

/*get PE number*/

int my_pe(){
	return shmem_my_pe();
}

/*get the number of PEs*/
int n_pes()	{
	return shmem_n_pes();
}

/*clean up all resources*/
void finalize(){
	shmem_finalize();
}


