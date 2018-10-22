//
// auto-generated by ops.py//

// header
#define OPS_ACC_MD_MACROS
#define OPS_2D
#include "ops_lib_cpp.h"

#include "ops_cuda_reduction.h"
#include "ops_cuda_rt_support.h"

#include <cuComplex.h>

#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
// global constants
__constant__ int imax;
__constant__ int jmax;
__constant__ double pi;

void ops_init_backend() {}

void ops_decl_const_char(int dim, char const *type, int size, char *dat,
                         char const *name) {
  if (!strcmp(name, "imax")) {
    cutilSafeCall(cudaMemcpyToSymbol(imax, dat, dim * size));
  } else if (!strcmp(name, "jmax")) {
    cutilSafeCall(cudaMemcpyToSymbol(jmax, dat, dim * size));
  } else if (!strcmp(name, "pi")) {
    cutilSafeCall(cudaMemcpyToSymbol(pi, dat, dim * size));
  } else {
    printf("error: unknown const name\n");
    exit(1);
  }
}

// user kernel files
#include "apply_stencil_cuda_kernel.cu"
#include "copy_cuda_kernel.cu"
#include "left_bndcon_cuda_kernel.cu"
#include "right_bndcon_cuda_kernel.cu"
#include "set_zero_cuda_kernel.cu"
