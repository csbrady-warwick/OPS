//
// auto-generated by ops.py
//


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define OPS_3D
#include  "ops_lib_core.h"

//
// ops_par_loop declarations
//

void ops_par_loop_accelerate_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );



#include "data.h"
#include "definitions.h"

//#include "accelerate_kernel.h"

void accelerate()
{
  error_condition = 0;

  int x_min = field.x_min;
  int x_max = field.x_max;
  int y_min = field.y_min;
  int y_max = field.y_max;
  int z_min = field.z_min;
  int z_max = field.z_max;

  int rangexyz_inner_plus1[] = {x_min,x_max+1,y_min,y_max+1,z_min,z_max+1,};

  ops_par_loop_accelerate_kernel("accelerate_kernel", clover_grid, 3, rangexyz_inner_plus1,
               ops_arg_dat(density0, 1, S3D_000_fM1M1M1, "double", OPS_READ),
               ops_arg_dat(volume, 1, S3D_000_fM1M1M1, "double", OPS_READ),
               ops_arg_dat(work_array1, 1, S3D_000, "double", OPS_WRITE),
               ops_arg_dat(xvel0, 1, S3D_000, "double", OPS_READ),
               ops_arg_dat(xvel1, 1, S3D_000, "double", OPS_INC),
               ops_arg_dat(xarea, 1, S3D_000_f0M1M1, "double", OPS_READ),
               ops_arg_dat(pressure, 1, S3D_000_fM1M1M1, "double", OPS_READ),
               ops_arg_dat(yvel0, 1, S3D_000, "double", OPS_READ),
               ops_arg_dat(yvel1, 1, S3D_000, "double", OPS_INC),
               ops_arg_dat(yarea, 1, S3D_000_fM10M1, "double", OPS_READ),
               ops_arg_dat(viscosity, 1, S3D_000_fM1M1M1, "double", OPS_READ),
               ops_arg_dat(zvel0, 1, S3D_000, "double", OPS_READ),
               ops_arg_dat(zvel1, 1, S3D_000, "double", OPS_INC),
               ops_arg_dat(zarea, 1, S3D_000_fM1M10, "double", OPS_READ));
}
