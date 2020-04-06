//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#include "user_types.h"
#define OPS_2D
#define OPS_API 2
#define OPS_NO_GLOBALS
#include "ops_macros.h"
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

//user function

void tea_leaf_cheby_init_kernel(ptr_double w,
  ptr_double r,
  const ptr_double Kx,
  const ptr_double Ky,
  const ptr_double u,
  const ptr_double u0,
  const double *rx,
  const double *ry) {
	OPS_ACCS(w, 0,0) = (1.0
        + (*ry)*(OPS_ACCS(Ky, 0, 1) + OPS_ACCS(Ky, 0,0))
        + (*rx)*(OPS_ACCS(Kx, 1, 0) + OPS_ACCS(Kx, 0,0)))*OPS_ACCS(u, 0,0)
        - (*ry)*(OPS_ACCS(Ky, 0, 1) *OPS_ACCS(u, 0, 1) + OPS_ACCS(Ky, 0,0)*OPS_ACCS(u, 0, -1))
        - (*rx)*(OPS_ACCS(Kx, 1, 0) *OPS_ACCS(u, 1, 0) + OPS_ACCS(Kx, 0,0)*OPS_ACCS(u, -1, 0));
    OPS_ACCS(r, 0,0) = OPS_ACCS(u0, 0,0) - OPS_ACCS(w, 0,0);
}


__kernel void ops_tea_leaf_cheby_init_kernel(
__global double* restrict arg0,
__global double* restrict arg1,
__global const double* restrict arg2,
__global const double* restrict arg3,
__global const double* restrict arg4,
__global const double* restrict arg5,
const double arg6,
const double arg7,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int base5,
const int size0,
const int size1 ){


  int idx_y = get_global_id(1);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1) {
    ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_tea_leaf_cheby_init_kernel], xdim0_tea_leaf_cheby_init_kernel};
    ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_tea_leaf_cheby_init_kernel], xdim1_tea_leaf_cheby_init_kernel};
    const ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1 + idx_y * 1*1 * xdim2_tea_leaf_cheby_init_kernel], xdim2_tea_leaf_cheby_init_kernel};
    const ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1 + idx_y * 1*1 * xdim3_tea_leaf_cheby_init_kernel], xdim3_tea_leaf_cheby_init_kernel};
    const ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1 + idx_y * 1*1 * xdim4_tea_leaf_cheby_init_kernel], xdim4_tea_leaf_cheby_init_kernel};
    const ptr_double ptr5 = { &arg5[base5 + idx_x * 1*1 + idx_y * 1*1 * xdim5_tea_leaf_cheby_init_kernel], xdim5_tea_leaf_cheby_init_kernel};
    tea_leaf_cheby_init_kernel(ptr0,
                               ptr1,
                               ptr2,
                               ptr3,
                               ptr4,
                               ptr5,
                               &arg6,
                               &arg7);
  }

}
