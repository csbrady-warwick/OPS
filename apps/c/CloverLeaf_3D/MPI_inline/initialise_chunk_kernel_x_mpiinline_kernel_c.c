//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_initialise_chunk_kernel_x;
int ydim0_initialise_chunk_kernel_x;
int xdim1_initialise_chunk_kernel_x;
int ydim1_initialise_chunk_kernel_x;
int xdim2_initialise_chunk_kernel_x;
int ydim2_initialise_chunk_kernel_x;

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 0 + (y)) * xdim0_initialise_chunk_kernel_x +           \
   (n_z * 0 + (z)) * xdim0_initialise_chunk_kernel_x *                         \
       ydim0_initialise_chunk_kernel_x)
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 0 + (y)) * xdim1_initialise_chunk_kernel_x +           \
   (n_z * 0 + (z)) * xdim1_initialise_chunk_kernel_x *                         \
       ydim1_initialise_chunk_kernel_x)
#define OPS_ACC2(x, y, z)                                                      \
  (n_x * 1 + x + (n_y * 0 + (y)) * xdim2_initialise_chunk_kernel_x +           \
   (n_z * 0 + (z)) * xdim2_initialise_chunk_kernel_x *                         \
       ydim2_initialise_chunk_kernel_x)
// user function

void initialise_chunk_kernel_x_c_wrapper(double *restrict vertexx,
                                         const int *restrict xx,
                                         double *restrict vertexdx, int x_size,
                                         int y_size, int z_size) {
#pragma omp parallel for
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {

        int x_min = field.x_min - 2;

        double min_x, d_x;
        d_x = (grid.xmax - grid.xmin) / (double)grid.x_cells;
        min_x = grid.xmin + d_x * field.left;

        vertexx[OPS_ACC0(0, 0, 0)] =
            min_x + d_x * (xx[OPS_ACC1(0, 0, 0)] - x_min);
        vertexdx[OPS_ACC2(0, 0, 0)] = (double)d_x;
      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
