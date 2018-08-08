//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_update_halo_kernel5_plus_4_right;
int ydim0_update_halo_kernel5_plus_4_right;
int xdim1_update_halo_kernel5_plus_4_right;
int ydim1_update_halo_kernel5_plus_4_right;


#define OPS_ACC0(x,y,z) (n_x*1+n_y*xdim0_update_halo_kernel5_plus_4_right*1+n_z*xdim0_update_halo_kernel5_plus_4_right*ydim0_update_halo_kernel5_plus_4_right*1+x+xdim0_update_halo_kernel5_plus_4_right*(y)+xdim0_update_halo_kernel5_plus_4_right*ydim0_update_halo_kernel5_plus_4_right*(z))
#define OPS_ACC1(x,y,z) (n_x*1+n_y*xdim1_update_halo_kernel5_plus_4_right*1+n_z*xdim1_update_halo_kernel5_plus_4_right*ydim1_update_halo_kernel5_plus_4_right*1+x+xdim1_update_halo_kernel5_plus_4_right*(y)+xdim1_update_halo_kernel5_plus_4_right*ydim1_update_halo_kernel5_plus_4_right*(z))

//user function



void update_halo_kernel5_plus_4_right_c_wrapper(
  double * restrict vol_flux_z,
  double * restrict mass_flux_z,
  const int * restrict fields,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        
  if((*fields) & FIELD_VOL_FLUX_Z) vol_flux_z[OPS_ACC0(0,0,0)] = (vol_flux_z[OPS_ACC0(-4,0,0)]);
  if((*fields) & FIELD_MASS_FLUX_Z) mass_flux_z[OPS_ACC1(0,0,0)] = (mass_flux_z[OPS_ACC1(-4,0,0)]);

      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1

