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

inline void advec_mom_kernel_post_pre_advec_x(ptr_double node_mass_post,
  const ptr_double post_vol,
  const ptr_double density1,
  ptr_double node_mass_pre,
  const ptr_double node_flux) {

  OPS_ACCS(node_mass_post, 0,0,0) = 0.125 * ( OPS_ACCS(density1, 0,-1,0) * OPS_ACCS(post_vol, 0,-1,0) +
                                              OPS_ACCS(density1, 0,0,0)   * OPS_ACCS(post_vol, 0,0,0)   +
                                              OPS_ACCS(density1, -1,-1,0) * OPS_ACCS(post_vol, -1,-1,0) +
                                              OPS_ACCS(density1, -1,0,0)  * OPS_ACCS(post_vol, -1,0,0) +
                                              OPS_ACCS(density1, 0,-1,-1) * OPS_ACCS(post_vol, 0,-1,-1) +
                                              OPS_ACCS(density1, 0,0,-1)   * OPS_ACCS(post_vol, 0,0,-1)   +
                                              OPS_ACCS(density1, -1,-1,-1) * OPS_ACCS(post_vol, -1,-1,-1) +
                                              OPS_ACCS(density1, -1,0,-1)  * OPS_ACCS(post_vol, -1,0,-1)  );

  OPS_ACCS(node_mass_pre, 0,0,0) = OPS_ACCS(node_mass_post, 0,0,0) - OPS_ACCS(node_flux, -1,0,0) + OPS_ACCS(node_flux, 0,0,0);

}


__kernel void ops_advec_mom_kernel_post_pre_advec_x(
__global double* restrict arg0,
__global const double* restrict arg1,
__global const double* restrict arg2,
__global double* restrict arg3,
__global const double* restrict arg4,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_advec_mom_kernel_post_pre_advec_x + idx_z * 1*1 * xdim0_advec_mom_kernel_post_pre_advec_x * ydim0_advec_mom_kernel_post_pre_advec_x], xdim0_advec_mom_kernel_post_pre_advec_x, ydim0_advec_mom_kernel_post_pre_advec_x};
    const ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_advec_mom_kernel_post_pre_advec_x + idx_z * 1*1 * xdim1_advec_mom_kernel_post_pre_advec_x * ydim1_advec_mom_kernel_post_pre_advec_x], xdim1_advec_mom_kernel_post_pre_advec_x, ydim1_advec_mom_kernel_post_pre_advec_x};
    const ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1 + idx_y * 1*1 * xdim2_advec_mom_kernel_post_pre_advec_x + idx_z * 1*1 * xdim2_advec_mom_kernel_post_pre_advec_x * ydim2_advec_mom_kernel_post_pre_advec_x], xdim2_advec_mom_kernel_post_pre_advec_x, ydim2_advec_mom_kernel_post_pre_advec_x};
    ptr_double ptr3 = { &arg3[base3 + idx_x * 1*1 + idx_y * 1*1 * xdim3_advec_mom_kernel_post_pre_advec_x + idx_z * 1*1 * xdim3_advec_mom_kernel_post_pre_advec_x * ydim3_advec_mom_kernel_post_pre_advec_x], xdim3_advec_mom_kernel_post_pre_advec_x, ydim3_advec_mom_kernel_post_pre_advec_x};
    const ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1 + idx_y * 1*1 * xdim4_advec_mom_kernel_post_pre_advec_x + idx_z * 1*1 * xdim4_advec_mom_kernel_post_pre_advec_x * ydim4_advec_mom_kernel_post_pre_advec_x], xdim4_advec_mom_kernel_post_pre_advec_x, ydim4_advec_mom_kernel_post_pre_advec_x};
    advec_mom_kernel_post_pre_advec_x(ptr0,
                     ptr1,
                     ptr2,
                     ptr3,
                     ptr4);
  }

}
