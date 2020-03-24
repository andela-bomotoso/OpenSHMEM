all:	test hello
test: 	test.c comms.c rte.c comms.h rte.h
	mpicc test.c comms.c rte.c -o test

hello:	shmem_hello.c comms.c rte.c comms.h rte.h
	mpicc shmem_hello.c comms.c rte.c -o hello
