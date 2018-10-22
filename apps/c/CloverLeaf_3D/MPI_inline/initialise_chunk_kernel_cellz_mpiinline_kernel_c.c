//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_initialise_chunk_kernel_cellz;
int ydim0_initialise_chunk_kernel_cellz;
int xdim1_initialise_chunk_kernel_cellz;
int ydim1_initialise_chunk_kernel_cellz;
int xdim2_initialise_chunk_kernel_cellz;
int ydim2_initialise_chunk_kernel_cellz;

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 0 + x + (n_y * 0 + (y)) * xdim0_initialise_chunk_kernel_cellz +       \
   (n_z * 1 + (z)) * xdim0_initialise_chunk_kernel_cellz *                     \
       ydim0_initialise_chunk_kernel_cellz)
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 0 + x + (n_y * 0 + (y)) * xdim1_initialise_chunk_kernel_cellz +       \
   (n_z * 1 + (z)) * xdim1_initialise_chunk_kernel_cellz *                     \
       ydim1_initialise_chunk_kernel_cellz)
#define OPS_ACC2(x, y, z)                                                      \
  (n_x * 0 + x + (n_y * 0 + (y)) * xdim2_initialise_chunk_kernel_cellz +       \
   (n_z * 1 + (z)) * xdim2_initialise_chunk_kernel_cellz *                     \
       ydim2_initialise_chunk_kernel_cellz)
// user function

void initialise_chunk_kernel_cellz_c_wrapper(const double *restrict vertexz,
                                             double *restrict cellz,
                                             double *restrict celldz,
                                             int x_size, int y_size,
                                             int z_size) {
#pragma omp parallel for
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {

        double d_z = (grid.zmax - grid.zmin) / (double)grid.z_cells;
        cellz[OPS_ACC1(0, 0, 0)] =
            0.5 * (vertexz[OPS_ACC0(0, 0, 0)] + vertexz[OPS_ACC0(0, 0, 1)]);
        celldz[OPS_ACC2(0, 0, 0)] = d_z;
      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
