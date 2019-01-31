//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#define OPS_1D
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

//user function

void save_kernel(ptr_double rho_old,
  ptr_double rhou_old,
  ptr_double rhoE_old,
  const ptr_double rho_new,
  const ptr_double rhou_new,
  const ptr_double rhoE_new) {
      OPS_ACCS(rho_old, 0)=OPS_ACCS(rho_new, 0);
      OPS_ACCS(rhou_old, 0)=OPS_ACCS(rhou_new, 0);
      OPS_ACCS(rhoE_old, 0)=OPS_ACCS(rhoE_new, 0);
}


__kernel void ops_save_kernel(
__global double* restrict arg0,
__global double* restrict arg1,
__global double* restrict arg2,
__global const double* restrict arg3,
__global const double* restrict arg4,
__global const double* restrict arg5,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int base5,
const int size0 ){


  int idx_x = get_global_id(0);

  if (idx_x < size0) {
    ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1], };
    ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1], };
    ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1], };
    const ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1], };
    const ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1], };
    const ptr_double ptr5 = { &arg5[base5 + idx_x * 1*1], };
    save_kernel(ptr0,
                ptr1,
                ptr2,
                ptr3,
                ptr4,
                ptr5);
  }

}
