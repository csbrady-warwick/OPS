//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_initialise_chunk_kernel_z;
extern int ydim0_initialise_chunk_kernel_z;
extern int xdim1_initialise_chunk_kernel_z;
extern int ydim1_initialise_chunk_kernel_z;
extern int xdim2_initialise_chunk_kernel_z;
extern int ydim2_initialise_chunk_kernel_z;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 0 * 1 + n_y * xdim0_initialise_chunk_kernel_z * 0 * 1 +               \
   n_z * xdim0_initialise_chunk_kernel_z * ydim0_initialise_chunk_kernel_z *   \
       1 +                                                                     \
   x + xdim0_initialise_chunk_kernel_z * (y) +                                 \
   xdim0_initialise_chunk_kernel_z * ydim0_initialise_chunk_kernel_z * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 0 * 1 + n_y * xdim1_initialise_chunk_kernel_z * 0 * 1 +               \
   n_z * xdim1_initialise_chunk_kernel_z * ydim1_initialise_chunk_kernel_z *   \
       1 +                                                                     \
   x + xdim1_initialise_chunk_kernel_z * (y) +                                 \
   xdim1_initialise_chunk_kernel_z * ydim1_initialise_chunk_kernel_z * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (n_x * 0 * 1 + n_y * xdim2_initialise_chunk_kernel_z * 0 * 1 +               \
   n_z * xdim2_initialise_chunk_kernel_z * ydim2_initialise_chunk_kernel_z *   \
       1 +                                                                     \
   x + xdim2_initialise_chunk_kernel_z * (y) +                                 \
   xdim2_initialise_chunk_kernel_z * ydim2_initialise_chunk_kernel_z * (z))

// user function

void initialise_chunk_kernel_z_c_wrapper(double *p_a0, int *p_a1, double *p_a2,
                                         int x_size, int y_size, int z_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for
#endif
  for (int i = 0; i < y_size * x_size * z_size; i++) {
    const int id =
        omp_get_num_threads() * omp_get_team_num() + omp_get_thread_num();
    const int n_x = id % x_size;
    const int n_y = (id / x_size) % y_size;
    const int n_z = id / (x_size * y_size);
    double *vertexz = p_a0;

    const int *zz = p_a1;

    double *vertexdz = p_a2;

    int z_min = field.z_min - 2;

    double min_z, d_z;
    d_z = (grid.zmax - grid.zmin) / (double)grid.z_cells;
    min_z = grid.zmin + d_z * field.back;

    vertexz[OPS_ACC0(0, 0, 0)] = min_z + d_z * (zz[OPS_ACC1(0, 0, 0)] - z_min);
    vertexdz[OPS_ACC2(0, 0, 0)] = (double)d_z;
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2