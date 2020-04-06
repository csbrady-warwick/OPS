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
#define OPS_3D
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

void reset_field_kernel1(ptr_double density0,
  const ptr_double density1,
  ptr_double energy0,
  const ptr_double energy1) {

  OPS_ACCS(density0, 0,0,0)  = OPS_ACCS(density1, 0,0,0) ;
  OPS_ACCS(energy0, 0,0,0)  = OPS_ACCS(energy1, 0,0,0) ;

}


__kernel void ops_reset_field_kernel1(
__global double* restrict arg0,
__global const double* restrict arg1,
__global double* restrict arg2,
__global const double* restrict arg3,
const int base0,
const int base1,
const int base2,
const int base3,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_reset_field_kernel1 + idx_z * 1*1 * xdim0_reset_field_kernel1 * ydim0_reset_field_kernel1], xdim0_reset_field_kernel1, ydim0_reset_field_kernel1};
    const ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_reset_field_kernel1 + idx_z * 1*1 * xdim1_reset_field_kernel1 * ydim1_reset_field_kernel1], xdim1_reset_field_kernel1, ydim1_reset_field_kernel1};
    ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1 + idx_y * 1*1 * xdim2_reset_field_kernel1 + idx_z * 1*1 * xdim2_reset_field_kernel1 * ydim2_reset_field_kernel1], xdim2_reset_field_kernel1, ydim2_reset_field_kernel1};
    const ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1 + idx_y * 1*1 * xdim3_reset_field_kernel1 + idx_z * 1*1 * xdim3_reset_field_kernel1 * ydim3_reset_field_kernel1], xdim3_reset_field_kernel1, ydim3_reset_field_kernel1};
    reset_field_kernel1(ptr0,
                       ptr1,
                       ptr2,
                       ptr3);
  }

}
