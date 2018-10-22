//
// auto-generated by ops.py
//
#include "./MPI_inline/tea_leaf_common.h"

int xdim0_tea_leaf_common_init_diag_init_kernel;
int xdim1_tea_leaf_common_init_diag_init_kernel;
int xdim2_tea_leaf_common_init_diag_init_kernel;

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim0_tea_leaf_common_init_diag_init_kernel)
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim1_tea_leaf_common_init_diag_init_kernel)
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 + x + (n_y * 1 + (y)) * xdim2_tea_leaf_common_init_diag_init_kernel)
// user function

void tea_leaf_common_init_diag_init_kernel_c_wrapper(double *restrict Mi,
                                                     const double *restrict Kx,
                                                     const double *restrict Ky,
                                                     const double *restrict rx,
                                                     const double *restrict ry,
                                                     int x_size, int y_size) {
#pragma omp parallel for
  for (int n_y = 0; n_y < y_size; n_y++) {
    for (int n_x = 0; n_x < x_size; n_x++) {

      Mi[OPS_ACC0(0, 0)] =
          1.0 / (1.0 + (*ry) * (Ky[OPS_ACC2(0, 1)] + Ky[OPS_ACC2(0, 0)]) +
                 (*rx) * (Kx[OPS_ACC1(1, 0)] + Kx[OPS_ACC1(0, 0)]));
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
