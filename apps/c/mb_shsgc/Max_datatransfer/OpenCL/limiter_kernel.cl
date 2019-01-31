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

void limiter_kernel(const ptrm_double al, ptrm_double tht, ptrm_double gt,
                    const double del2) {

  double aalm, aal, all, ar, gtt;
  for (int m = 0; m < 3; m++) {
    aalm = fabs(OPS_ACCM(al, m, -1));
    aal = fabs(OPS_ACCM(al, m, 0));
    OPS_ACCM(tht, m, 0) = fabs(aal - aalm) / (aal + aalm + del2);
    all = OPS_ACCM(al, m, -1);
    ar = OPS_ACCM(al, m, 0);
    gtt = all * (ar * ar + del2) + ar * (all * all + del2);
    OPS_ACCM(gt, m, 0) = gtt / (ar * ar + all * all + 2.00 * del2);
  }
}

__kernel void ops_limiter_kernel(__global const double *restrict arg0,
                                 __global double *restrict arg1,
                                 __global double *restrict arg2,
                                 const double del2, const int base0,
                                 const int base1, const int base2,
                                 const int size0) {

  int idx_x = get_global_id(0);

  if (idx_x < size0) {
#ifdef OPS_SOA
    const ptrm_double ptr0 = {&arg0[base0 + idx_x * 1 * 3],
                              xdim0_limiter_kernel};
#else
    const ptrm_double ptr0 = {&arg0[base0 + idx_x * 1 * 3], 3};
#endif
#ifdef OPS_SOA
    ptrm_double ptr1 = {&arg1[base1 + idx_x * 1 * 3], xdim1_limiter_kernel};
#else
    ptrm_double ptr1 = {&arg1[base1 + idx_x * 1 * 3], 3};
#endif
#ifdef OPS_SOA
    ptrm_double ptr2 = {&arg2[base2 + idx_x * 1 * 3], xdim2_limiter_kernel};
#else
    ptrm_double ptr2 = {&arg2[base2 + idx_x * 1 * 3], 3};
#endif
    limiter_kernel(ptr0, ptr1, ptr2, del2);
  }
}
