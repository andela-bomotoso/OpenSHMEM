/*******************************************OpenSHMEM*******************************
 * *	GitHub.com: 	https://github.com/andela-bomotoso/OpenSHMEM
 * *	Author: 		Bukola Grace Omotoso
 * *	Email:			bgo2e@mtmail.mtsu.edu
 * *	Description: 	A partial implementation of the OpenSHMEM 1.4 Specification
 * *	Date:			3rd March 2020
 * ************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
//using namespace std;

/*initialize openshmem*/
void rte_init(){
	
	MPI_Init(NULL, NULL);
}

/*get PE number*/

int rte_my_pe(){
	int me;
	MPI_Comm_rank(MPI_COMM_WORLD, &me);
	return me;
}

/*get the number of PEs*/
int rte_n_pes()	{
	int npes;
	MPI_Comm_size(MPI_COMM_WORLD, &npes); 
	return npes;
}

/*clean up all resources*/
void rte_finalize(){
	MPI_Finalize();
}


