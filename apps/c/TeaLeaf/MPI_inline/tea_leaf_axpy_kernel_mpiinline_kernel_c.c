//
// auto-generated by ops.py
//
#include "./MPI_inline/tea_leaf_common.h"

int xdim0_tea_leaf_axpy_kernel;
int xdim1_tea_leaf_axpy_kernel;

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim0_tea_leaf_axpy_kernel)
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim1_tea_leaf_axpy_kernel)
// user function

void tea_leaf_axpy_kernel_c_wrapper(double *restrict u,
                                    const double *restrict p,
                                    const double *restrict alpha, int x_size,
                                    int y_size) {
#pragma omp parallel for
  for (int n_y = 0; n_y < y_size; n_y++) {
    for (int n_x = 0; n_x < x_size; n_x++) {

      u[OPS_ACC0(0, 0)] = u[OPS_ACC0(0, 0)] + (*alpha) * p[OPS_ACC1(0, 0)];
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
