//
// auto-generated by ops.py
//
#include "./MPI_inline/laplace2d_common.h"

int xdim0_apply_stencil;
int xdim1_apply_stencil;

#define OPS_ACC0(x, y) (n_x * 1 + x + (n_y * 1 + (y)) * xdim0_apply_stencil)
#define OPS_ACC1(x, y) (n_x * 1 + x + (n_y * 1 + (y)) * xdim1_apply_stencil)
// user function

void apply_stencil_c_wrapper(const double *restrict A, double *restrict Anew,
                             double *restrict error_g, int x_size, int y_size) {
  double error_0 = error_g[0];
#pragma omp parallel for reduction(max : error_0)
  for (int n_y = 0; n_y < y_size; n_y++) {
    for (int n_x = 0; n_x < x_size; n_x++) {
      double error[1];
      error[0] = error_g[0];

      Anew[OPS_ACC1(0, 0)] = 0.25f * (A[OPS_ACC0(1, 0)] + A[OPS_ACC0(-1, 0)] +
                                      A[OPS_ACC0(0, -1)] + A[OPS_ACC0(0, 1)]);
      *error = fmax(*error, fabs(Anew[OPS_ACC1(0, 0)] - A[OPS_ACC0(0, 0)]));

      error_0 = MAX(error_0, error[0]);
    }
  }
  error_g[0] = error_0;
}
#undef OPS_ACC0
#undef OPS_ACC1
