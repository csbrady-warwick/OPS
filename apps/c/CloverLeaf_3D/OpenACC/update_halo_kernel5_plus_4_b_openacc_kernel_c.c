//
// auto-generated by ops.py
//
#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

int xdim0_update_halo_kernel5_plus_4_b;
int ydim0_update_halo_kernel5_plus_4_b;
int xdim1_update_halo_kernel5_plus_4_b;
int ydim1_update_halo_kernel5_plus_4_b;


#undef OPS_ACC0
#undef OPS_ACC1


#define OPS_ACC0(x,y,z) (x+xdim0_update_halo_kernel5_plus_4_b*(y)+xdim0_update_halo_kernel5_plus_4_b*ydim0_update_halo_kernel5_plus_4_b*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_update_halo_kernel5_plus_4_b*(y)+xdim1_update_halo_kernel5_plus_4_b*ydim1_update_halo_kernel5_plus_4_b*(z))

//user function

inline void update_halo_kernel5_plus_4_b(double *vol_flux_z, double *mass_flux_z, const int* fields) {
  if((*fields) & FIELD_VOL_FLUX_Z) vol_flux_z[OPS_ACC0(0,0,0)] = vol_flux_z[OPS_ACC0(0,-4,0)];
  if((*fields) & FIELD_MASS_FLUX_Z) mass_flux_z[OPS_ACC1(0,0,0)] = mass_flux_z[OPS_ACC1(0,-4,0)];
}


#undef OPS_ACC0
#undef OPS_ACC1



void update_halo_kernel5_plus_4_b_c_wrapper(
  double *p_a0,
  double *p_a1,
  int p_a2,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1)
  #pragma acc loop
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        update_halo_kernel5_plus_4_b(  p_a0 + n_x*1*1 + n_y*xdim0_update_halo_kernel5_plus_4_b*1*1 + n_z*xdim0_update_halo_kernel5_plus_4_b*ydim0_update_halo_kernel5_plus_4_b*1*1,
           p_a1 + n_x*1*1 + n_y*xdim1_update_halo_kernel5_plus_4_b*1*1 + n_z*xdim1_update_halo_kernel5_plus_4_b*ydim1_update_halo_kernel5_plus_4_b*1*1,
           &p_a2 );

      }
    }
  }
}
