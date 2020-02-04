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

inline void advec_mom_kernel1_y_nonvector(const ptr_double node_flux,
  const ptr_double node_mass_pre,
  ptr_double mom_flux,
  const ptr_double celldy,
  const ptr_double vel1) {





  double sigma, wind, width;
  double vdiffuw, vdiffdw, auw, adw, limiter;
  int upwind, donor, downwind, dif;
  double advec_vel_temp;

  if( (OPS_ACCS(node_flux, 0,0)) < 0.0) {
    upwind = 2;
    donor = 1;
    downwind = 0;
    dif = donor;
  } else {
    upwind = -1;
    donor = 0;
    downwind = 1;
    dif = upwind;
  }

  sigma = fabs(OPS_ACCS(node_flux, 0,0))/OPS_ACCS(node_mass_pre, 0,donor);
  width = OPS_ACCS(celldy, 0,0);
  vdiffuw = OPS_ACCS(vel1, 0,donor) - OPS_ACCS(vel1, 0,upwind);
  vdiffdw = OPS_ACCS(vel1, 0,downwind) - OPS_ACCS(vel1, 0,donor);
  limiter = 0.0;
  if(vdiffuw*vdiffdw > 0.0) {
    auw = fabs(vdiffuw);
    adw = fabs(vdiffdw);
    wind = 1.0;
    if(vdiffdw <= 0.0) wind = -1.0;
    limiter=wind*MIN(width*((2.0-sigma)*adw/width+(1.0+sigma)*auw/OPS_ACCS(celldy, 0,dif))/6.0,MIN(auw,adw));
  }
  advec_vel_temp= OPS_ACCS(vel1, 0,donor) + (1.0 - sigma) * limiter;
  OPS_ACCS(mom_flux, 0,0) = advec_vel_temp * OPS_ACCS(node_flux, 0,0);
}


__kernel void ops_advec_mom_kernel1_y_nonvector(
__global const double* restrict arg0,
__global const double* restrict arg1,
__global double* restrict arg2,
__global const double* restrict arg3,
__global const double* restrict arg4,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int size0,
const int size1 ){


  int idx_y = get_global_id(1);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1) {
    const ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_advec_mom_kernel1_y_nonvector], xdim0_advec_mom_kernel1_y_nonvector};
    const ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_advec_mom_kernel1_y_nonvector], xdim1_advec_mom_kernel1_y_nonvector};
    ptr_double ptr2 = { &arg2[base2 + idx_x * 1*1 + idx_y * 1*1 * xdim2_advec_mom_kernel1_y_nonvector], xdim2_advec_mom_kernel1_y_nonvector};
    const ptr_double ptr3 = { &arg3[base3 + idx_x * 0*1 + idx_y * 1*1 * xdim3_advec_mom_kernel1_y_nonvector], xdim3_advec_mom_kernel1_y_nonvector};
    const ptr_double ptr4 = { &arg4[base4 + idx_x * 1*1 + idx_y * 1*1 * xdim4_advec_mom_kernel1_y_nonvector], xdim4_advec_mom_kernel1_y_nonvector};
    advec_mom_kernel1_y_nonvector(ptr0,
                     ptr1,
                     ptr2,
                     ptr3,
                     ptr4);
  }

}
