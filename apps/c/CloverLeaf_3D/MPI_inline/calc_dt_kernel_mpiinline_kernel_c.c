//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_calc_dt_kernel;
int ydim0_calc_dt_kernel;
int xdim1_calc_dt_kernel;
int ydim1_calc_dt_kernel;
int xdim2_calc_dt_kernel;
int ydim2_calc_dt_kernel;
int xdim3_calc_dt_kernel;
int ydim3_calc_dt_kernel;
int xdim4_calc_dt_kernel;
int ydim4_calc_dt_kernel;
int xdim5_calc_dt_kernel;
int ydim5_calc_dt_kernel;
int xdim6_calc_dt_kernel;
int ydim6_calc_dt_kernel;
int xdim7_calc_dt_kernel;
int ydim7_calc_dt_kernel;
int xdim8_calc_dt_kernel;
int ydim8_calc_dt_kernel;
int xdim9_calc_dt_kernel;
int ydim9_calc_dt_kernel;
int xdim10_calc_dt_kernel;
int ydim10_calc_dt_kernel;
int xdim11_calc_dt_kernel;
int ydim11_calc_dt_kernel;
int xdim12_calc_dt_kernel;
int ydim12_calc_dt_kernel;
int xdim13_calc_dt_kernel;
int ydim13_calc_dt_kernel;


#define OPS_ACC0(x,y,z) (n_x*1+n_y*xdim0_calc_dt_kernel*0+n_z*xdim0_calc_dt_kernel*ydim0_calc_dt_kernel*0+x+xdim0_calc_dt_kernel*(y)+xdim0_calc_dt_kernel*ydim0_calc_dt_kernel*(z))
#define OPS_ACC1(x,y,z) (n_x*0+n_y*xdim1_calc_dt_kernel*1+n_z*xdim1_calc_dt_kernel*ydim1_calc_dt_kernel*0+x+xdim1_calc_dt_kernel*(y)+xdim1_calc_dt_kernel*ydim1_calc_dt_kernel*(z))
#define OPS_ACC2(x,y,z) (n_x*1+n_y*xdim2_calc_dt_kernel*1+n_z*xdim2_calc_dt_kernel*ydim2_calc_dt_kernel*1+x+xdim2_calc_dt_kernel*(y)+xdim2_calc_dt_kernel*ydim2_calc_dt_kernel*(z))
#define OPS_ACC3(x,y,z) (n_x*1+n_y*xdim3_calc_dt_kernel*1+n_z*xdim3_calc_dt_kernel*ydim3_calc_dt_kernel*1+x+xdim3_calc_dt_kernel*(y)+xdim3_calc_dt_kernel*ydim3_calc_dt_kernel*(z))
#define OPS_ACC4(x,y,z) (n_x*1+n_y*xdim4_calc_dt_kernel*1+n_z*xdim4_calc_dt_kernel*ydim4_calc_dt_kernel*1+x+xdim4_calc_dt_kernel*(y)+xdim4_calc_dt_kernel*ydim4_calc_dt_kernel*(z))
#define OPS_ACC5(x,y,z) (n_x*1+n_y*xdim5_calc_dt_kernel*1+n_z*xdim5_calc_dt_kernel*ydim5_calc_dt_kernel*1+x+xdim5_calc_dt_kernel*(y)+xdim5_calc_dt_kernel*ydim5_calc_dt_kernel*(z))
#define OPS_ACC6(x,y,z) (n_x*1+n_y*xdim6_calc_dt_kernel*1+n_z*xdim6_calc_dt_kernel*ydim6_calc_dt_kernel*1+x+xdim6_calc_dt_kernel*(y)+xdim6_calc_dt_kernel*ydim6_calc_dt_kernel*(z))
#define OPS_ACC7(x,y,z) (n_x*1+n_y*xdim7_calc_dt_kernel*1+n_z*xdim7_calc_dt_kernel*ydim7_calc_dt_kernel*1+x+xdim7_calc_dt_kernel*(y)+xdim7_calc_dt_kernel*ydim7_calc_dt_kernel*(z))
#define OPS_ACC8(x,y,z) (n_x*1+n_y*xdim8_calc_dt_kernel*1+n_z*xdim8_calc_dt_kernel*ydim8_calc_dt_kernel*1+x+xdim8_calc_dt_kernel*(y)+xdim8_calc_dt_kernel*ydim8_calc_dt_kernel*(z))
#define OPS_ACC9(x,y,z) (n_x*1+n_y*xdim9_calc_dt_kernel*1+n_z*xdim9_calc_dt_kernel*ydim9_calc_dt_kernel*1+x+xdim9_calc_dt_kernel*(y)+xdim9_calc_dt_kernel*ydim9_calc_dt_kernel*(z))
#define OPS_ACC10(x,y,z) (n_x*1+n_y*xdim10_calc_dt_kernel*1+n_z*xdim10_calc_dt_kernel*ydim10_calc_dt_kernel*1+x+xdim10_calc_dt_kernel*(y)+xdim10_calc_dt_kernel*ydim10_calc_dt_kernel*(z))
#define OPS_ACC11(x,y,z) (n_x*0+n_y*xdim11_calc_dt_kernel*0+n_z*xdim11_calc_dt_kernel*ydim11_calc_dt_kernel*1+x+xdim11_calc_dt_kernel*(y)+xdim11_calc_dt_kernel*ydim11_calc_dt_kernel*(z))
#define OPS_ACC12(x,y,z) (n_x*1+n_y*xdim12_calc_dt_kernel*1+n_z*xdim12_calc_dt_kernel*ydim12_calc_dt_kernel*1+x+xdim12_calc_dt_kernel*(y)+xdim12_calc_dt_kernel*ydim12_calc_dt_kernel*(z))
#define OPS_ACC13(x,y,z) (n_x*1+n_y*xdim13_calc_dt_kernel*1+n_z*xdim13_calc_dt_kernel*ydim13_calc_dt_kernel*1+x+xdim13_calc_dt_kernel*(y)+xdim13_calc_dt_kernel*ydim13_calc_dt_kernel*(z))

//user function



void calc_dt_kernel_c_wrapper(
  const double * restrict celldx,
  const double * restrict celldy,
  const double * restrict soundspeed,
  const double * restrict viscosity,
  const double * restrict density0,
  const double * restrict xvel0,
  const double * restrict xarea,
  const double * restrict volume,
  const double * restrict yvel0,
  const double * restrict yarea,
  double * restrict dt_min,
  const double * restrict celldz,
  const double * restrict zvel0,
  const double * restrict zarea,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        

  double div, ds, dtut, dtvt, dtct, dtwt, dtdivt, cc, dv1, dv2, du1, du2, dw1, dw2;

  ds = MIN(MIN(celldx[OPS_ACC0(0,0,0)], celldy[OPS_ACC1(0,0,0)]), celldz[OPS_ACC11(0,0,0)]);
  ds = 1.0/(ds*ds);

  cc = soundspeed[OPS_ACC2(0,0,0)] * soundspeed[OPS_ACC2(0,0,0)];
  cc = cc + 2.0 * viscosity[OPS_ACC3(0,0,0)]/density0[OPS_ACC4(0,0,0)];

  dtct=ds*cc;
  dtct = dtc_safe*1.0/MAX(sqrt(dtct),g_small);

  du1=(xvel0[OPS_ACC5(0,0,0)]+xvel0[OPS_ACC5(0,1,0)]+xvel0[OPS_ACC5(0,0,1)]+xvel0[OPS_ACC5(0,1,1)])*xarea[OPS_ACC6(0,0,0)];
  du2=(xvel0[OPS_ACC5(1,0,0)]+xvel0[OPS_ACC5(1,1,0)]+xvel0[OPS_ACC5(1,0,1)]+xvel0[OPS_ACC5(1,1,1)])*xarea[OPS_ACC6(0,0,0)];

  dtut = dtu_safe * 4.0 * volume[OPS_ACC7(0,0,0)]/MAX(MAX(fabs(du1), fabs(du2)), 1.0e-5 * volume[OPS_ACC7(0,0,0)]);

  dv1=(yvel0[OPS_ACC8(0,0,0)]+yvel0[OPS_ACC8(1,0,0)]+yvel0[OPS_ACC8(0,0,1)]+yvel0[OPS_ACC8(1,0,1)])*yarea[OPS_ACC9(0,0,0)];
  dv2=(yvel0[OPS_ACC8(0,1,0)]+yvel0[OPS_ACC8(1,1,0)]+yvel0[OPS_ACC8(0,1,1)]+yvel0[OPS_ACC8(1,1,1)])*yarea[OPS_ACC9(0,0,0)];

  dtvt = dtv_safe * 4.0 * volume[OPS_ACC7(0,0,0)]/MAX(MAX(fabs(dv1),fabs(dv2)), 1.0e-5 * volume[OPS_ACC7(0,0,0)]);

  dw1=(zvel0[OPS_ACC12(0,0,0)]+zvel0[OPS_ACC12(0,1,0)]+zvel0[OPS_ACC12(1,0,0)]+zvel0[OPS_ACC12(1,1,0)])*zarea[OPS_ACC13(0,0,0)];
  dw2=(zvel0[OPS_ACC12(0,0,1)]+zvel0[OPS_ACC12(0,1,1)]+zvel0[OPS_ACC12(1,0,1)]+zvel0[OPS_ACC12(1,1,1)])*zarea[OPS_ACC13(0,0,0)];

  dtwt = dtw_safe * 4.0 * volume[OPS_ACC7(0,0,0)]/MAX(MAX(fabs(dw1),fabs(dw2)), 1.0e-5 * volume[OPS_ACC7(0,0,0)]);

  div = du2-du1+dv2-dv1+dw2-dw1;
  dtdivt=dtdiv_safe*4.0*(volume[OPS_ACC7(0,0,0)])/MAX(volume[OPS_ACC7(0,0,0)]*1.0e-05,fabs(div));

  dt_min[OPS_ACC10(0,0,0)] = MIN(MIN(MIN(dtct, dtut), MIN(dtvt, dtdivt)),dtwt);

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
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10
#undef OPS_ACC11
#undef OPS_ACC12
#undef OPS_ACC13

