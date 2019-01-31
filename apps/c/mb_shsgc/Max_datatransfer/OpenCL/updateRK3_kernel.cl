//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64 : enable

#define OPS_1D
#define OPS_API 2
#define OPS_NO_GLOBALS
#include "ops_macros.h"
#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a, b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) ((a > b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a, b) ((b < 0.0) ? (a * (-1)) : (a))
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

// user function

void updateRK3_kernel(ptr_double rho_new, ptr_double rhou_new,
                      ptr_double rhoE_new, ptr_double rho_old,
                      ptr_double rhou_old, ptr_double rhoE_old,
                      ptr_double rho_res, ptr_double rhou_res,
                      ptr_double rhoE_res, const double *a1, const double *a2,
                      const double dt) {

  OPS_ACCS(rho_new, 0) =
      OPS_ACCS(rho_old, 0) + dt * a1[0] * (-OPS_ACCS(rho_res, 0));
  OPS_ACCS(rhou_new, 0) =
      OPS_ACCS(rhou_old, 0) + dt * a1[0] * (-OPS_ACCS(rhou_res, 0));
  OPS_ACCS(rhoE_new, 0) =
      OPS_ACCS(rhoE_old, 0) + dt * a1[0] * (-OPS_ACCS(rhoE_res, 0));

  OPS_ACCS(rho_old, 0) =
      OPS_ACCS(rho_old, 0) + dt * a2[0] * (-OPS_ACCS(rho_res, 0));
  OPS_ACCS(rhou_old, 0) =
      OPS_ACCS(rhou_old, 0) + dt * a2[0] * (-OPS_ACCS(rhou_res, 0));
  OPS_ACCS(rhoE_old, 0) =
      OPS_ACCS(rhoE_old, 0) + dt * a2[0] * (-OPS_ACCS(rhoE_res, 0));
  OPS_ACCS(rho_res, 0) = 0;
  OPS_ACCS(rhou_res, 0) = 0;
  OPS_ACCS(rhoE_res, 0) = 0;
}

__kernel void ops_updateRK3_kernel(
    __global double *restrict arg0, __global double *restrict arg1,
    __global double *restrict arg2, __global double *restrict arg3,
    __global double *restrict arg4, __global double *restrict arg5,
    __global double *restrict arg6, __global double *restrict arg7,
    __global double *restrict arg8, const double arg9, const double arg10,
    const double dt, const int base0, const int base1, const int base2,
    const int base3, const int base4, const int base5, const int base6,
    const int base7, const int base8, const int size0) {

  int idx_x = get_global_id(0);

  if (idx_x < size0) {
    ptr_double ptr0 = {&arg0[base0 + idx_x * 1 * 1]};
    ptr_double ptr1 = {&arg1[base1 + idx_x * 1 * 1]};
    ptr_double ptr2 = {&arg2[base2 + idx_x * 1 * 1]};
    ptr_double ptr3 = {&arg3[base3 + idx_x * 1 * 1]};
    ptr_double ptr4 = {&arg4[base4 + idx_x * 1 * 1]};
    ptr_double ptr5 = {&arg5[base5 + idx_x * 1 * 1]};
    ptr_double ptr6 = {&arg6[base6 + idx_x * 1 * 1]};
    ptr_double ptr7 = {&arg7[base7 + idx_x * 1 * 1]};
    ptr_double ptr8 = {&arg8[base8 + idx_x * 1 * 1]};
    updateRK3_kernel(ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6, ptr7, ptr8,
                     &arg9, &arg10, dt);
  }
}
