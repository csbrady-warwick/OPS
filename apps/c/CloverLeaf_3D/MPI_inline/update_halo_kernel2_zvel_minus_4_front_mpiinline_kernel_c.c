//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_update_halo_kernel2_zvel_minus_4_front;
int ydim0_update_halo_kernel2_zvel_minus_4_front;
int xdim1_update_halo_kernel2_zvel_minus_4_front;
int ydim1_update_halo_kernel2_zvel_minus_4_front;

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 + x +                                                               \
   (n_y * 1 + (y)) * xdim0_update_halo_kernel2_zvel_minus_4_front +            \
   (n_z * 1 + (z)) * xdim0_update_halo_kernel2_zvel_minus_4_front *            \
       ydim0_update_halo_kernel2_zvel_minus_4_front)
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 + x +                                                               \
   (n_y * 1 + (y)) * xdim1_update_halo_kernel2_zvel_minus_4_front +            \
   (n_z * 1 + (z)) * xdim1_update_halo_kernel2_zvel_minus_4_front *            \
       ydim1_update_halo_kernel2_zvel_minus_4_front)
// user function

void update_halo_kernel2_zvel_minus_4_front_c_wrapper(
    double *restrict zvel0, double *restrict zvel1, const int *restrict fields,
    int x_size, int y_size, int z_size) {
#pragma omp parallel for
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {

        if (fields[FIELD_ZVEL0] == 1)
          zvel0[OPS_ACC0(0, 0, 0)] = -zvel0[OPS_ACC0(0, 0, -4)];
        if (fields[FIELD_ZVEL1] == 1)
          zvel1[OPS_ACC1(0, 0, 0)] = -zvel1[OPS_ACC1(0, 0, -4)];
      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
