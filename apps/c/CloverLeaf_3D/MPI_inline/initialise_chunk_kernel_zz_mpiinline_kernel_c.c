//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_initialise_chunk_kernel_zz;
int ydim0_initialise_chunk_kernel_zz;

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 0 + x + (n_y * 0 + (y)) * xdim0_initialise_chunk_kernel_zz +          \
   (n_z * 1 + (z)) * xdim0_initialise_chunk_kernel_zz *                        \
       ydim0_initialise_chunk_kernel_zz)
// user function

void initialise_chunk_kernel_zz_c_wrapper(int *restrict zz, int *restrict idx,
                                          int arg_idx0, int arg_idx1,
                                          int arg_idx2, int x_size, int y_size,
                                          int z_size) {
#pragma omp parallel for
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {
        int idx[] = {arg_idx0 + n_x, arg_idx1 + n_y, arg_idx2 + n_z};

        zz[OPS_ACC0(0, 0, 0)] = idx[2] - 2;
      }
    }
  }
}
#undef OPS_ACC0
