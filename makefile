test: 	test.c comms.c rte.c comms.h rte.h
	mpicc test.c comms.c rte.c -o test
	
