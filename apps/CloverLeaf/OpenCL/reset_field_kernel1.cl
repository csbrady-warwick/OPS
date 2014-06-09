//
// auto-generated by ops.py on 2014-06-09 11:20
//


#pragma OPENCL EXTENSION cl_khr_fp64:enable

#include "user_types.h"
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
#define OPS_ACC0(x,y) (x+xdim0_reset_field_kernel1*(y))
#define OPS_ACC1(x,y) (x+xdim1_reset_field_kernel1*(y))
#define OPS_ACC2(x,y) (x+xdim2_reset_field_kernel1*(y))
#define OPS_ACC3(x,y) (x+xdim3_reset_field_kernel1*(y))


//user function
void reset_field_kernel1( __global double *density0, __global double *density1, __global double *energy0, 
__global double *energy1, 
  int xdim0_reset_field_kernel1,
int xdim1_reset_field_kernel1,
int xdim2_reset_field_kernel1,
int xdim3_reset_field_kernel1)

  {

  density0[OPS_ACC0(0,0)]  = density1[OPS_ACC1(0,0)] ;
  energy0[OPS_ACC2(0,0)]  = energy1[OPS_ACC3(0,0)] ;

}



 #undef OPS_ACC0
 #undef OPS_ACC1
 #undef OPS_ACC2
 #undef OPS_ACC3


 __kernel void ops_reset_field_kernel1(
 __global double* arg0,
 __global double* arg1,
 __global double* arg2,
 __global double* arg3,
 int xdim0_reset_field_kernel1,
 int xdim1_reset_field_kernel1,
 int xdim2_reset_field_kernel1,
 int xdim3_reset_field_kernel1,
 const int base0,
 const int base1,
 const int base2,
 const int base3,
 int size0,
 int size1 ){


   int idx_y = get_global_id(1);
   int idx_x = get_global_id(0);

   if (idx_x < size0 && idx_y < size1) {
     reset_field_kernel1(&arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_reset_field_kernel1],
                        &arg1[base1 + idx_x * 1 + idx_y * 1 * xdim1_reset_field_kernel1],
                        &arg2[base2 + idx_x * 1 + idx_y * 1 * xdim2_reset_field_kernel1],
                        &arg3[base3 + idx_x * 1 + idx_y * 1 * xdim3_reset_field_kernel1],
                        
                        xdim0_reset_field_kernel1,
                        xdim1_reset_field_kernel1,
                        xdim2_reset_field_kernel1,
                        xdim3_reset_field_kernel1);
   }

 }
