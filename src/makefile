
all:	helloworld barrier
test: 	test.c comms.c rte.c comms.h rte.h
	mpicc test.c comms.c rte.c -o test

helloworld:	../test_examples/helloworld.c comms/comms.c rte/rte.c shmem/shmem.c comms/comms.h rte/rte.h shmem/shmem.h
		mpicc ../test_examples/helloworld.c comms/comms.c rte/rte.c shmem/shmem.c -o helloworld

barrier:	../test_examples/barrier.c comms/comms.c rte/rte.c shmem/shmem.c comms/comms.h rte/rte.h shmem/shmem.h
		mpicc ../test_examples/barrier.c comms/comms.c rte/rte.c shmem/shmem.c -o barrier

