//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_advec_cell_kernel1_zdir;
int ydim0_advec_cell_kernel1_zdir;
int xdim1_advec_cell_kernel1_zdir;
int ydim1_advec_cell_kernel1_zdir;
int xdim2_advec_cell_kernel1_zdir;
int ydim2_advec_cell_kernel1_zdir;
int xdim3_advec_cell_kernel1_zdir;
int ydim3_advec_cell_kernel1_zdir;
int xdim4_advec_cell_kernel1_zdir;
int ydim4_advec_cell_kernel1_zdir;
int xdim5_advec_cell_kernel1_zdir;
int ydim5_advec_cell_kernel1_zdir;


#define OPS_ACC0(x,y,z) (n_x*1+n_y*xdim0_advec_cell_kernel1_zdir*1+n_z*xdim0_advec_cell_kernel1_zdir*ydim0_advec_cell_kernel1_zdir*1+x+xdim0_advec_cell_kernel1_zdir*(y)+xdim0_advec_cell_kernel1_zdir*ydim0_advec_cell_kernel1_zdir*(z))
#define OPS_ACC1(x,y,z) (n_x*1+n_y*xdim1_advec_cell_kernel1_zdir*1+n_z*xdim1_advec_cell_kernel1_zdir*ydim1_advec_cell_kernel1_zdir*1+x+xdim1_advec_cell_kernel1_zdir*(y)+xdim1_advec_cell_kernel1_zdir*ydim1_advec_cell_kernel1_zdir*(z))
#define OPS_ACC2(x,y,z) (n_x*1+n_y*xdim2_advec_cell_kernel1_zdir*1+n_z*xdim2_advec_cell_kernel1_zdir*ydim2_advec_cell_kernel1_zdir*1+x+xdim2_advec_cell_kernel1_zdir*(y)+xdim2_advec_cell_kernel1_zdir*ydim2_advec_cell_kernel1_zdir*(z))
#define OPS_ACC3(x,y,z) (n_x*1+n_y*xdim3_advec_cell_kernel1_zdir*1+n_z*xdim3_advec_cell_kernel1_zdir*ydim3_advec_cell_kernel1_zdir*1+x+xdim3_advec_cell_kernel1_zdir*(y)+xdim3_advec_cell_kernel1_zdir*ydim3_advec_cell_kernel1_zdir*(z))
#define OPS_ACC4(x,y,z) (n_x*1+n_y*xdim4_advec_cell_kernel1_zdir*1+n_z*xdim4_advec_cell_kernel1_zdir*ydim4_advec_cell_kernel1_zdir*1+x+xdim4_advec_cell_kernel1_zdir*(y)+xdim4_advec_cell_kernel1_zdir*ydim4_advec_cell_kernel1_zdir*(z))
#define OPS_ACC5(x,y,z) (n_x*1+n_y*xdim5_advec_cell_kernel1_zdir*1+n_z*xdim5_advec_cell_kernel1_zdir*ydim5_advec_cell_kernel1_zdir*1+x+xdim5_advec_cell_kernel1_zdir*(y)+xdim5_advec_cell_kernel1_zdir*ydim5_advec_cell_kernel1_zdir*(z))

//user function



void advec_cell_kernel1_zdir_c_wrapper(
  double * restrict pre_vol,
  double * restrict post_vol,
  const double * restrict volume,
  const double * restrict vol_flux_x,
  const double * restrict vol_flux_y,
  const double * restrict vol_flux_z,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        

  pre_vol[OPS_ACC0(0,0,0)] = volume[OPS_ACC2(0,0,0)] +
                         ( vol_flux_x[OPS_ACC3(1,0,0)] - vol_flux_x[OPS_ACC3(0,0,0)] +
                           vol_flux_y[OPS_ACC4(0,1,0)] - vol_flux_y[OPS_ACC4(0,0,0)] +
                           vol_flux_z[OPS_ACC5(0,0,1)] - vol_flux_z[OPS_ACC5(0,0,0)]);
  post_vol[OPS_ACC1(0,0,0)] = pre_vol[OPS_ACC0(0,0,0)] - ( vol_flux_z[OPS_ACC5(0,0,1)] - vol_flux_z[OPS_ACC5(0,0,0)]);


      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5

