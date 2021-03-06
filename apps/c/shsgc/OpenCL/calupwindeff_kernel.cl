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

//user function

void calupwindeff_kernel(const ptrm_double  cmp,
  const ptrm_double gt,
  const ptrm_double  cf,
  const ptrm_double  al,
  const ptrm_double  ep2,
  const ptrm_double  r,
  ptrm_double  eff) {

		double e1 = (OPS_ACCM(cmp, 0,0) * (OPS_ACCM(gt, 0,0) + OPS_ACCM(gt, 0,1)) - OPS_ACCM(cf, 0,0) * OPS_ACCM(al, 0,0)) * OPS_ACCM(ep2, 0,0);
		double e2 = (OPS_ACCM(cmp, 1,0) * (OPS_ACCM(gt, 1,0) + OPS_ACCM(gt, 1,1)) - OPS_ACCM(cf, 1,0) * OPS_ACCM(al, 1,0)) * OPS_ACCM(ep2, 1,0);
		double e3 = (OPS_ACCM(cmp, 2,0) * (OPS_ACCM(gt, 2,0) + OPS_ACCM(gt, 2,1)) - OPS_ACCM(cf, 2,0) * OPS_ACCM(al, 2,0)) * OPS_ACCM(ep2, 2,0);

		OPS_ACCM(eff, 0,0)=e1 * OPS_ACCM(r, 0,0) + e2 * OPS_ACCM(r, 1,0) + e3 * OPS_ACCM(r, 2,0);
		OPS_ACCM(eff, 1,0)=e1 * OPS_ACCM(r, 3,0) + e2 * OPS_ACCM(r, 4,0) + e3 * OPS_ACCM(r, 5,0);
		OPS_ACCM(eff, 2,0)=e1 * OPS_ACCM(r, 6,0) + e2 * OPS_ACCM(r, 7,0) + e3 * OPS_ACCM(r, 8,0);
}


__kernel void ops_calupwindeff_kernel(
__global const double* restrict arg0,
__global const double* restrict arg1,
__global const double* restrict arg2,
__global const double* restrict arg3,
__global const double* restrict arg4,
__global const double* restrict arg5,
__global double* restrict arg6,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int base5,
const int base6,
const int size0 ){


  int idx_x = get_global_id(0);

  if (idx_x < size0) {
    #ifdef OPS_SOA
    const ptrm_double ptr0 = { &arg0[base0 + idx_x * 1*3], xdim0_calupwindeff_kernel};
    #else
    const ptrm_double ptr0 = { &arg0[base0 + idx_x * 1*3], 3};
    #endif
    #ifdef OPS_SOA
    const ptrm_double ptr1 = { &arg1[base1 + idx_x * 1*3], xdim1_calupwindeff_kernel};
    #else
    const ptrm_double ptr1 = { &arg1[base1 + idx_x * 1*3], 3};
    #endif
    #ifdef OPS_SOA
    const ptrm_double ptr2 = { &arg2[base2 + idx_x * 1*3], xdim2_calupwindeff_kernel};
    #else
    const ptrm_double ptr2 = { &arg2[base2 + idx_x * 1*3], 3};
    #endif
    #ifdef OPS_SOA
    const ptrm_double ptr3 = { &arg3[base3 + idx_x * 1*3], xdim3_calupwindeff_kernel};
    #else
    const ptrm_double ptr3 = { &arg3[base3 + idx_x * 1*3], 3};
    #endif
    #ifdef OPS_SOA
    const ptrm_double ptr4 = { &arg4[base4 + idx_x * 1*3], xdim4_calupwindeff_kernel};
    #else
    const ptrm_double ptr4 = { &arg4[base4 + idx_x * 1*3], 3};
    #endif
    #ifdef OPS_SOA
    const ptrm_double ptr5 = { &arg5[base5 + idx_x * 1*9], xdim5_calupwindeff_kernel};
    #else
    const ptrm_double ptr5 = { &arg5[base5 + idx_x * 1*9], 9};
    #endif
    #ifdef OPS_SOA
    ptrm_double ptr6 = { &arg6[base6 + idx_x * 1*3], xdim6_calupwindeff_kernel};
    #else
    ptrm_double ptr6 = { &arg6[base6 + idx_x * 1*3], 3};
    #endif
    calupwindeff_kernel(ptr0,
                        ptr1,
                        ptr2,
                        ptr3,
                        ptr4,
                        ptr5,
                        ptr6);
  }

}
