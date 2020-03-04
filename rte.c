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
	
	MPI_Init(&argc, &argv);
}

void my_pe()	{


}

int my_pe(){
	return shmem_my_pe();
}

int n_pes()	{
	return shmem_n_pes();
}

void finalize(){
	shemem_finalize();
}


