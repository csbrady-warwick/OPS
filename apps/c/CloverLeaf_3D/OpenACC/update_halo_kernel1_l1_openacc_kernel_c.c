//
// auto-generated by ops.py
//
#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

int xdim0_update_halo_kernel1_l1;
int ydim0_update_halo_kernel1_l1;
int xdim1_update_halo_kernel1_l1;
int ydim1_update_halo_kernel1_l1;
int xdim2_update_halo_kernel1_l1;
int ydim2_update_halo_kernel1_l1;
int xdim3_update_halo_kernel1_l1;
int ydim3_update_halo_kernel1_l1;
int xdim4_update_halo_kernel1_l1;
int ydim4_update_halo_kernel1_l1;
int xdim5_update_halo_kernel1_l1;
int ydim5_update_halo_kernel1_l1;
int xdim6_update_halo_kernel1_l1;
int ydim6_update_halo_kernel1_l1;


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6


#define OPS_ACC0(x,y,z) (x+xdim0_update_halo_kernel1_l1*(y)+xdim0_update_halo_kernel1_l1*ydim0_update_halo_kernel1_l1*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_update_halo_kernel1_l1*(y)+xdim1_update_halo_kernel1_l1*ydim1_update_halo_kernel1_l1*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_update_halo_kernel1_l1*(y)+xdim2_update_halo_kernel1_l1*ydim2_update_halo_kernel1_l1*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_update_halo_kernel1_l1*(y)+xdim3_update_halo_kernel1_l1*ydim3_update_halo_kernel1_l1*(z))
#define OPS_ACC4(x,y,z) (x+xdim4_update_halo_kernel1_l1*(y)+xdim4_update_halo_kernel1_l1*ydim4_update_halo_kernel1_l1*(z))
#define OPS_ACC5(x,y,z) (x+xdim5_update_halo_kernel1_l1*(y)+xdim5_update_halo_kernel1_l1*ydim5_update_halo_kernel1_l1*(z))
#define OPS_ACC6(x,y,z) (x+xdim6_update_halo_kernel1_l1*(y)+xdim6_update_halo_kernel1_l1*ydim6_update_halo_kernel1_l1*(z))

//user function

inline void update_halo_kernel1_l1(double *density0, double *density1,
                          double *energy0, double *energy1,
                          double *pressure, double *viscosity,
                          double *soundspeed , const int* fields) {
  if((*fields) & FIELD_DENSITY0) density0[OPS_ACC0(0,0,0)] = density0[OPS_ACC0(1,0,0)];
  if((*fields) & FIELD_DENSITY1) density1[OPS_ACC1(0,0,0)] = density1[OPS_ACC1(1,0,0)];
  if((*fields) & FIELD_ENERGY0) energy0[OPS_ACC2(0,0,0)] = energy0[OPS_ACC2(1,0,0)];
  if((*fields) & FIELD_ENERGY1) energy1[OPS_ACC3(0,0,0)] = energy1[OPS_ACC3(1,0,0)];
  if((*fields) & FIELD_PRESSURE) pressure[OPS_ACC4(0,0,0)] = pressure[OPS_ACC4(1,0,0)];
  if((*fields) & FIELD_VISCOSITY) viscosity[OPS_ACC5(0,0,0)] = viscosity[OPS_ACC5(1,0,0)];
  if((*fields) & FIELD_SOUNDSPEED) soundspeed[OPS_ACC6(0,0,0)] = soundspeed[OPS_ACC6(1,0,0)];

}


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6



void update_halo_kernel1_l1_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  int p_a7,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6)
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
        update_halo_kernel1_l1(  p_a0 + n_x*1*1 + n_y*xdim0_update_halo_kernel1_l1*1*1 + n_z*xdim0_update_halo_kernel1_l1*ydim0_update_halo_kernel1_l1*1*1,
           p_a1 + n_x*1*1 + n_y*xdim1_update_halo_kernel1_l1*1*1 + n_z*xdim1_update_halo_kernel1_l1*ydim1_update_halo_kernel1_l1*1*1,
           p_a2 + n_x*1*1 + n_y*xdim2_update_halo_kernel1_l1*1*1 + n_z*xdim2_update_halo_kernel1_l1*ydim2_update_halo_kernel1_l1*1*1,
           p_a3 + n_x*1*1 + n_y*xdim3_update_halo_kernel1_l1*1*1 + n_z*xdim3_update_halo_kernel1_l1*ydim3_update_halo_kernel1_l1*1*1,
           p_a4 + n_x*1*1 + n_y*xdim4_update_halo_kernel1_l1*1*1 + n_z*xdim4_update_halo_kernel1_l1*ydim4_update_halo_kernel1_l1*1*1,
           p_a5 + n_x*1*1 + n_y*xdim5_update_halo_kernel1_l1*1*1 + n_z*xdim5_update_halo_kernel1_l1*ydim5_update_halo_kernel1_l1*1*1,
           p_a6 + n_x*1*1 + n_y*xdim6_update_halo_kernel1_l1*1*1 + n_z*xdim6_update_halo_kernel1_l1*ydim6_update_halo_kernel1_l1*1*1,
           &p_a7 );

      }
    }
  }
}
