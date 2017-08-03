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
#include "user_types.h"

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
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

#define OPS_ACC0(x, y) (x + xdim0_field_summary_kernel * (y))
#define OPS_ACC1(x, y) (x + xdim1_field_summary_kernel * (y))
#define OPS_ACC2(x, y) (x + xdim2_field_summary_kernel * (y))
#define OPS_ACC3(x, y) (x + xdim3_field_summary_kernel * (y))

// user function
void field_summary_kernel(const __global double *restrict volume,
                          const __global double *restrict density,
                          const __global double *restrict energy,
                          const __global double *restrict u,
                          double *restrict vol, double *restrict mass,
                          double *restrict ie, double *restrict temp)

{

  double cell_vol, cell_mass;

  cell_vol = volume[OPS_ACC0(0, 0)];
  cell_mass = cell_vol * density[OPS_ACC1(0, 0)];
  *vol = *vol + cell_vol;
  *mass = *mass + cell_mass;
  *ie = *ie + cell_mass * energy[OPS_ACC2(0, 0)];
  *temp = *temp + cell_mass * u[OPS_ACC3(0, 0)];
}

__kernel void ops_field_summary_kernel(
    __global const double *restrict arg0, __global const double *restrict arg1,
    __global const double *restrict arg2, __global const double *restrict arg3,
    __global double *restrict arg4, __local double *scratch4, int r_bytes4,
    __global double *restrict arg5, __local double *scratch5, int r_bytes5,
    __global double *restrict arg6, __local double *scratch6, int r_bytes6,
    __global double *restrict arg7, __local double *scratch7, int r_bytes7,
    const int base0, const int base1, const int base2, const int base3,
    const int size0, const int size1) {

  arg4 += r_bytes4;
  double arg4_l[1];
  arg5 += r_bytes5;
  double arg5_l[1];
  arg6 += r_bytes6;
  double arg6_l[1];
  arg7 += r_bytes7;
  double arg7_l[1];
  for (int d = 0; d < 1; d++)
    arg4_l[d] = ZERO_double;
  for (int d = 0; d < 1; d++)
    arg5_l[d] = ZERO_double;
  for (int d = 0; d < 1; d++)
    arg6_l[d] = ZERO_double;
  for (int d = 0; d < 1; d++)
    arg7_l[d] = ZERO_double;

  int idx_y = get_global_id(1);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1) {
    field_summary_kernel(&arg0[base0 + idx_x * 1 * 1 +
                               idx_y * 1 * 1 * xdim0_field_summary_kernel],
                         &arg1[base1 + idx_x * 1 * 1 +
                               idx_y * 1 * 1 * xdim1_field_summary_kernel],
                         &arg2[base2 + idx_x * 1 * 1 +
                               idx_y * 1 * 1 * xdim2_field_summary_kernel],
                         &arg3[base3 + idx_x * 1 * 1 +
                               idx_y * 1 * 1 * xdim3_field_summary_kernel],
                         arg4_l, arg5_l, arg6_l, arg7_l);
  }
  int group_index = get_group_id(0) + get_group_id(1) * get_num_groups(0) +
                    get_group_id(2) * get_num_groups(0) * get_num_groups(1);
  for (int d = 0; d < 1; d++)
    reduce_double(arg4_l[d], scratch4, &arg4[group_index * 1 + d], OPS_INC);
  for (int d = 0; d < 1; d++)
    reduce_double(arg5_l[d], scratch5, &arg5[group_index * 1 + d], OPS_INC);
  for (int d = 0; d < 1; d++)
    reduce_double(arg6_l[d], scratch6, &arg6[group_index * 1 + d], OPS_INC);
  for (int d = 0; d < 1; d++)
    reduce_double(arg7_l[d], scratch7, &arg7[group_index * 1 + d], OPS_INC);
}