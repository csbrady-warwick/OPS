//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64 : enable

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

#undef OPS_ACC0

#define OPS_ACC0(x) (x)

// user function
void gridgen_kernel(__global double *restrict x, const int *restrict id,
                    const double dx, const double xt)

{

  x[OPS_ACC0(0)] = xt + id[0] * dx;
}

__kernel void ops_gridgen_kernel(__global double *restrict arg0,
                                 const double dx, const double xt,
                                 const int base0, int arg_idx0,
                                 const int size0) {

  int idx_x = get_global_id(0);

  int arg_idx[1];
  arg_idx[0] = arg_idx0 + idx_x;
  if (idx_x < size0) {
    gridgen_kernel(&arg0[base0 + idx_x * 1 * 1], arg_idx, dx, xt);
  }
}
