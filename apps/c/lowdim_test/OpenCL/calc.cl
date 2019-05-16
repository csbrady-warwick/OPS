//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5
#define ZERO_double 0.0;
#define INFINITY_double INFINITY;
#define ZERO_float 0.0f;
#define INFINITY_float INFINITY;
#define ZERO_int 0;
#define INFINITY_int INFINITY;
#define ZERO_uint 0;
#define INFINITY_uint INFINITY;
#define ZERO_ll 0;
#define INFINITY_ll INFINITY;
#define ZERO_ull 0;
#define INFINITY_ull INFINITY;
#define ZERO_bool 0;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6


#define OPS_ACC0(x,y,z) (x+xdim0_calc*(y)+xdim0_calc*ydim0_calc*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_calc*(y)+xdim1_calc*ydim1_calc*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_calc*(y)+xdim2_calc*ydim2_calc*(z))
#define OPS_ACC3(x,y,z) (x+xdim3_calc*(y)+xdim3_calc*ydim3_calc*(z))
#define OPS_ACC4(x,y,z) (x+xdim4_calc*(y)+xdim4_calc*ydim4_calc*(z))
#define OPS_ACC5(x,y,z) (x+xdim5_calc*(y)+xdim5_calc*ydim5_calc*(z))
#define OPS_ACC6(x,y,z) (x+xdim6_calc*(y)+xdim6_calc*ydim6_calc*(z))


//user function
void calc(__global double * restrict dat3D,const __global double * restrict dat2D_xy,const __global double * restrict dat2D_yz,
const __global double * restrict dat2D_xz,const __global double * restrict dat1D_x,const __global double * restrict dat1D_y,const __global double * restrict dat1D_z)


{
  dat3D[OPS_ACC0(0,0,0)] = dat2D_xy[OPS_ACC1(0,0,0)] +
                           dat2D_yz[OPS_ACC2(0,0,0)] +
                           dat2D_xz[OPS_ACC3(0,0,0)] +
                           dat1D_x[OPS_ACC4(0,0,0)] +
                           dat1D_y[OPS_ACC5(0,0,0)] +
                           dat1D_z[OPS_ACC6(0,0,0)];
}



__kernel void ops_calc(
__global double* restrict arg0,
__global const double* restrict arg1,
__global const double* restrict arg2,
__global const double* restrict arg3,
__global const double* restrict arg4,
__global const double* restrict arg5,
__global const double* restrict arg6,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int base5,
const int base6,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    calc(&arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_calc + idx_z * 1*1 * xdim0_calc * ydim0_calc],
              &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_calc + idx_z * 0*1 * xdim1_calc * ydim1_calc],
              &arg2[base2 + idx_x * 0*1 + idx_y * 1*1 * xdim2_calc + idx_z * 1*1 * xdim2_calc * ydim2_calc],
              &arg3[base3 + idx_x * 1*1 + idx_y * 0*1 * xdim3_calc + idx_z * 1*1 * xdim3_calc * ydim3_calc],
              &arg4[base4 + idx_x * 1*1 + idx_y * 0*1 * xdim4_calc + idx_z * 0*1 * xdim4_calc * ydim4_calc],
              &arg5[base5 + idx_x * 0*1 + idx_y * 1*1 * xdim5_calc + idx_z * 0*1 * xdim5_calc * ydim5_calc],
              &arg6[base6 + idx_x * 0*1 + idx_y * 0*1 * xdim6_calc + idx_z * 1*1 * xdim6_calc * ydim6_calc]);
  }

}
