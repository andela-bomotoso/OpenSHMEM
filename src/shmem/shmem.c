/*******************************************OpenSHMEM*******************************
*	GitHub.com: 	https://github.com/andela-bomotoso/OpenSHMEM
*	Author: 		Bukola Grace Omotoso
*	Email:			bgo2e@mtmail.mtsu.edu
*	Description: 	A partial implementation of the OpenSHMEM 1.4 Specification
*	Date:			Feb 2020
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> 
#include "shmem.h"
	/* LIBRARY SETUP/QUERYING*/

	/*	shmem_init
	 *	A collective operation that allocates and initializes 
	 *  the resources used by the OpenSHMEM library
	 * */
	void shmem_init(){
		comms_init();
	}
	
	/*	shmem_my_pe
	 * 	Returns the number of the calling PE
	 * */
	int shmem_my_pe(){
		return rte_my_pe();
	}

	/*	shmem_n_pes
     * 	Returns the number of PEs in a program
     * */
    	int shmem_n_pes(){
		return rte_n_pes();
	}

	/*	shmem_finalize
     * 	A collective operation that releases all resources used by the OpenSHMEM library. 
	 *	This only terminates the OpenSHMEM portion of a program, not the entire program.
     * */
    	void shmem_finalize(){
		comms_finalize();
	}

	/* REMOTE MEMORY ACCESS*/

	/*shmem_put
	 *	The put routines provide a method for copying data from a contiguous local data object 
	 *	to a data object on a specified PE
	 **/
	void shmem_int_put(int *dest, const int *source, size_t nelems, int pe){
		comms_int_put(dest, source, nelems, pe);

	}

	
    /*shmem_get
     *  Copies data from a specified PE
     **/
    	void shmem_int_get(int *dest, const int *source, size_t nelems, int pe){
		 comms_int_get(dest, source, nelems, pe);
	}


	/*	shmem_put_nbi
	 *	The nonblocking put routines provide a method for copying data from a contiguous local data 
	 *	object to a data object on a specified PE.
     **/
    void shmem_put_nbi(int *dest, const int *source, size_t nelems, int pe){


    }


    /*shmem_get_nbi
     *  The nonblocking get routines provide a method for copying data from a contiguous remote 
	 *	data object on the specified PE to the local data object.
     **/
    void shmem_get_nbi(int *dest, const int *source, size_t nelems, int pe){


    }

   /*  shmem_putmem
     *  The nonblocking put routines provide a method for copying data from a contiguous local data
     *  object to a data object on a specified PE.
     **/
    void shmem_putmem(void *dest, const void *source, size_t nelems, int pe){

    }


    /*shmem_getmem
     *  The nonblocking get routines provide a method for copying data from a contiguous remote
     *  data object on the specified PE to the local data object.
     **/
    void shmem_getmem(void *dest, const void *source, size_t nelems, int pe){



    }


	/* COLLECTIVES*/

	/*	shmem_barrier_all
	 * 	Registers the arrival of a PE at a barrier and blocks the PE until all other PEs arrive 
	 *	at the barrier and all local updates and remote memory updates on the default context 
     *	are completed
	 **/
	 void shmem_barrier_all(void){


	}


    /*	shmem_sync_all
	 * 	Registers the arrival of a PE at a barrier and suspends PE execution until 
	 *	all other PEs arrive at the barrier.
	 **/
	 void shmem_sync_all(void){

	}


	/* MEMORY MANAGEMENT*/

	/*	shmem_malloc()
	 *	Collective symmetric heap memory management routines.
	 **/
	void* shmem_malloc(size_t size){
		comms_malloc(size);
	}


	/* MEMORY ORDERING*/
	
	/* 	shmem_quiet
	 *  Waits for completion of all outstanding Put, AMO, memory store, 
	 *	and nonblocking Put and Get routines to symmetric data objects issued by a PE.
	 **/
	void shmem_quiet(void){

	}

	
	
