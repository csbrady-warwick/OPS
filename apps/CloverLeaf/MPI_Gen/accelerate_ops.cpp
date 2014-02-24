//
// auto-generated by ops.py on 2014-02-24 14:21
//



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#include  "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_accelerate_kernel_stepbymass(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_accelerate_kernelx1(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_accelerate_kernely1(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_accelerate_kernelx2(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_accelerate_kernely2(char const *, ops_block, int , int*,
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

  int x_cells = grid->x_cells;
  int y_cells = grid->y_cells;
  int x_min = field->x_min;
  int x_max = field->x_max;
  int y_min = field->y_min;
  int y_max = field->y_max;

  int rangexy_inner_plus1[] = {x_min,x_max+1,y_min,y_max+1};

  ops_par_loop_accelerate_kernel_stepbymass("accelerate_kernel_stepbymass", clover_grid, 2, rangexy_inner_plus1,
               ops_arg_dat(density0, S2D_00_M10_0M1_M1M1, "double", OPS_READ),
               ops_arg_dat(volume, S2D_00_M10_0M1_M1M1, "double", OPS_READ),
               ops_arg_dat(work_array1, S2D_00, "double", OPS_WRITE));

  ops_par_loop_accelerate_kernelx1("accelerate_kernelx1", clover_grid, 2, rangexy_inner_plus1,
               ops_arg_dat(xvel0, S2D_00, "double", OPS_READ),
               ops_arg_dat(xvel1, S2D_00, "double", OPS_WRITE),
               ops_arg_dat(work_array1, S2D_00, "double", OPS_READ),
               ops_arg_dat(xarea, S2D_00_0M1, "double", OPS_READ),
               ops_arg_dat(pressure, S2D_00_M10_0M1_M1M1, "double", OPS_READ));

  ops_par_loop_accelerate_kernely1("accelerate_kernely1", clover_grid, 2, rangexy_inner_plus1,
               ops_arg_dat(yvel0, S2D_00, "double", OPS_READ),
               ops_arg_dat(yvel1, S2D_00, "double", OPS_WRITE),
               ops_arg_dat(work_array1, S2D_00, "double", OPS_READ),
               ops_arg_dat(yarea, S2D_00_M10, "double", OPS_READ),
               ops_arg_dat(pressure, S2D_00_M10_0M1_M1M1, "double", OPS_READ));

  ops_par_loop_accelerate_kernelx2("accelerate_kernelx2", clover_grid, 2, rangexy_inner_plus1,
               ops_arg_dat(xvel1, S2D_00, "double", OPS_RW),
               ops_arg_dat(work_array1, S2D_00, "double", OPS_READ),
               ops_arg_dat(xarea, S2D_00_0M1, "double", OPS_READ),
               ops_arg_dat(viscosity, S2D_00_M10_0M1_M1M1, "double", OPS_READ));

  ops_par_loop_accelerate_kernely2("accelerate_kernely2", clover_grid, 2, rangexy_inner_plus1,
               ops_arg_dat(yvel1, S2D_00, "double", OPS_RW),
               ops_arg_dat(work_array1, S2D_00, "double", OPS_READ),
               ops_arg_dat(yarea, S2D_00_M10, "double", OPS_READ),
               ops_arg_dat(viscosity, S2D_00_M10_0M1_M1M1, "double", OPS_READ));

}
