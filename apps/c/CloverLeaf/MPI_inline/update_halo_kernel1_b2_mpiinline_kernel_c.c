//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_update_halo_kernel1_b2;
int xdim1_update_halo_kernel1_b2;
int xdim2_update_halo_kernel1_b2;
int xdim3_update_halo_kernel1_b2;
int xdim4_update_halo_kernel1_b2;
int xdim5_update_halo_kernel1_b2;
int xdim6_update_halo_kernel1_b2;


#define OPS_ACC0(x,y) (n_x*1+n_y*xdim0_update_halo_kernel1_b2*1+x+xdim0_update_halo_kernel1_b2*(y))
#define OPS_ACC1(x,y) (n_x*1+n_y*xdim1_update_halo_kernel1_b2*1+x+xdim1_update_halo_kernel1_b2*(y))
#define OPS_ACC2(x,y) (n_x*1+n_y*xdim2_update_halo_kernel1_b2*1+x+xdim2_update_halo_kernel1_b2*(y))
#define OPS_ACC3(x,y) (n_x*1+n_y*xdim3_update_halo_kernel1_b2*1+x+xdim3_update_halo_kernel1_b2*(y))
#define OPS_ACC4(x,y) (n_x*1+n_y*xdim4_update_halo_kernel1_b2*1+x+xdim4_update_halo_kernel1_b2*(y))
#define OPS_ACC5(x,y) (n_x*1+n_y*xdim5_update_halo_kernel1_b2*1+x+xdim5_update_halo_kernel1_b2*(y))
#define OPS_ACC6(x,y) (n_x*1+n_y*xdim6_update_halo_kernel1_b2*1+x+xdim6_update_halo_kernel1_b2*(y))

//user function



void update_halo_kernel1_b2_c_wrapper(
  double * restrict density0,
  double * restrict density1,
  double * restrict energy0,
  double * restrict energy1,
  double * restrict pressure,
  double * restrict viscosity,
  double * restrict soundspeed,
  const int * restrict fields,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      
  if((*fields) & FIELD_DENSITY0) density0[OPS_ACC0(0,0)] = density0[OPS_ACC0(0,3)];
  if((*fields) & FIELD_DENSITY1) density1[OPS_ACC1(0,0)] = density1[OPS_ACC1(0,3)];
  if((*fields) & FIELD_ENERGY0) energy0[OPS_ACC2(0,0)] = energy0[OPS_ACC2(0,3)];
  if((*fields) & FIELD_ENERGY1) energy1[OPS_ACC3(0,0)] = energy1[OPS_ACC3(0,3)];
  if((*fields) & FIELD_PRESSURE) pressure[OPS_ACC4(0,0)] = pressure[OPS_ACC4(0,3)];
  if((*fields) & FIELD_VISCOSITY) viscosity[OPS_ACC5(0,0)] = viscosity[OPS_ACC5(0,3)];
  if((*fields) & FIELD_SOUNDSPEED) soundspeed[OPS_ACC6(0,0)] = soundspeed[OPS_ACC6(0,3)];


    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6

