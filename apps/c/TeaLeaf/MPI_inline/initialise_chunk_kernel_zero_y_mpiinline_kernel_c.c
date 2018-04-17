//
// auto-generated by ops.py
//
#include "./MPI_inline/tea_leaf_common.h"

int xdim0_initialise_chunk_kernel_zero_y;

#define OPS_ACC0(x, y)                                                         \
  (n_x * 0 + n_y * xdim0_initialise_chunk_kernel_zero_y * 1 + x +              \
   xdim0_initialise_chunk_kernel_zero_y * (y))

// user function

void initialise_chunk_kernel_zero_y_c_wrapper(double *restrict var, int x_size,
                                              int y_size) {
#pragma omp parallel for
  for (int n_y = 0; n_y < y_size; n_y++) {
    for (int n_x = 0; n_x < x_size; n_x++) {

      *var = 0.0;
    }
  }
}
#undef OPS_ACC0