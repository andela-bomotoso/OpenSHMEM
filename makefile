all:	test helloworld putget
test: 	test.c comms.c rte.c comms.h rte.h
	mpicc test.c comms.c rte.c -o test

helloworld:	helloworld.c comms.c rte.c shmem.c comms.h rte.h shmem.h
		mpicc helloworld.c comms.c rte.c shmem.c -o helloworld

putget:		putget.c comms.c rte.c shmem.c comms.h rte.h shmem.h
		mpicc putget.c comms.c rte.c shmem.c -o putget
