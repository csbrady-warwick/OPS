CC       = g++
MPICC    = mpic++
OMPFLAGS = -Ofast -lm -std=c++11

BIN =  laplace2d laplace2d_mpi

all: $(BIN)

laplace2d: laplace2d_step6.cpp Makefile
	$(CC) $(CCFLAGS) -I$(OPS_INSTALL_PATH)/c/include $(OMPFLAGS) -o $@ laplace2d_step6.cpp -L$(OPS_INSTALL_PATH)/c/lib/$(OPS_COMPILER) -lops_seq

laplace2d_mpi: laplace2d_step6.cpp Makefile
	$(MPICC) -DOPS_MPI $(CCFLAGS) -I$(OPS_INSTALL_PATH)/c/include $(OMPFLAGS) -o $@ laplace2d_step6.cpp -L$(OPS_INSTALL_PATH)/c/lib/$(OPS_COMPILER) -lops_mpi

clean:
	$(RM) $(BIN)

