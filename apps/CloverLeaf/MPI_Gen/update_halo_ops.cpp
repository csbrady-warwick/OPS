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

void ops_par_loop_update_halo_kernel1_b2(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel_b1(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel_t2(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel_t1(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel1_l2(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel1_l1(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel1_r2(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel1_r1(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_xvel_plus_4_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_xvel_plus_2_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_xvel_plus_4_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_xvel_plus_2_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_xvel_minus_4_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_xvel_minus_2_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_xvel_minus_4_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_xvel_minus_2_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_yvel_minus_4_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_yvel_minus_2_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_yvel_minus_4_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_yvel_minus_2_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_yvel_plus_4_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_yvel_plus_2_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_yvel_plus_4_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel2_yvel_plus_2_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel3_plus_4_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel3_plus_2_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel3_plus_4_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel3_plus_2_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel3_minus_4_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel3_minus_2_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel3_minus_4_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel3_minus_2_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel4_minus_4_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel4_minus_2_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel4_minus_4_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel4_minus_2_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel4_plus_4_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel4_plus_2_a(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel4_plus_4_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_update_halo_kernel4_plus_2_b(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );



#include "data.h"
#include "definitions.h"

//#include  "update_halo_kernel.h"

void update_halo(int* fields, int depth)
{

  int x_cells = grid->x_cells;
  int y_cells = grid->y_cells;
  int x_min = field->x_min;
  int x_max = field->x_max;
  int y_min = field->y_min;
  int y_max = field->y_max;





  int rangexy_b2a[] = {x_min-depth,x_max+depth,y_min-2,y_min-1};
  if(depth ==2)
  ops_par_loop_update_halo_kernel1_b2("update_halo_kernel1", clover_grid, 2, rangexy_b2a,
               ops_arg_dat(density0, S2D_00_0P3, "double", OPS_RW),
               ops_arg_dat(density1, S2D_00_0P3, "double", OPS_RW),
               ops_arg_dat(energy0, S2D_00_0P3, "double", OPS_RW),
               ops_arg_dat(energy1, S2D_00_0P3, "double", OPS_RW),
               ops_arg_dat(pressure, S2D_00_0P3, "double", OPS_RW),
               ops_arg_dat(viscosity, S2D_00_0P3, "double", OPS_RW),
               ops_arg_dat(soundspeed, S2D_00_0P3, "double", OPS_RW));

  int rangexy_b1a[] = {x_min-depth,x_max+depth,y_min-1,y_min};
  ops_par_loop_update_halo_kernel_b1("update_halo_kernel1", clover_grid, 2, rangexy_b1a,
               ops_arg_dat(density0, S2D_00_0P1, "double", OPS_RW),
               ops_arg_dat(density1, S2D_00_0P1, "double", OPS_RW),
               ops_arg_dat(energy0, S2D_00_0P1, "double", OPS_RW),
               ops_arg_dat(energy1, S2D_00_0P1, "double", OPS_RW),
               ops_arg_dat(pressure, S2D_00_0P1, "double", OPS_RW),
               ops_arg_dat(viscosity, S2D_00_0P1, "double", OPS_RW),
               ops_arg_dat(soundspeed, S2D_00_0P1, "double", OPS_RW));

  int rangexy_t2a[] = {x_min-depth,x_max+depth,y_max+1,y_max+2};
  if(depth ==2)
  ops_par_loop_update_halo_kernel_t2("update_halo_kernel1", clover_grid, 2, rangexy_t2a,
               ops_arg_dat(density0, S2D_00_0M3, "double", OPS_RW),
               ops_arg_dat(density1, S2D_00_0M3, "double", OPS_RW),
               ops_arg_dat(energy0, S2D_00_0M3, "double", OPS_RW),
               ops_arg_dat(energy1, S2D_00_0M3, "double", OPS_RW),
               ops_arg_dat(pressure, S2D_00_0M3, "double", OPS_RW),
               ops_arg_dat(viscosity, S2D_00_0M3, "double", OPS_RW),
               ops_arg_dat(soundspeed, S2D_00_0M3, "double", OPS_RW));

  int rangexy_t1a[] = {x_min-depth,x_max+depth,y_max,y_max+1};
  ops_par_loop_update_halo_kernel_t1("update_halo_kernel1", clover_grid, 2, rangexy_t1a,
               ops_arg_dat(density0, S2D_00_0M1, "double", OPS_RW),
               ops_arg_dat(density1, S2D_00_0M1, "double", OPS_RW),
               ops_arg_dat(energy0, S2D_00_0M1, "double", OPS_RW),
               ops_arg_dat(energy1, S2D_00_0M1, "double", OPS_RW),
               ops_arg_dat(pressure, S2D_00_0M1, "double", OPS_RW),
               ops_arg_dat(viscosity, S2D_00_0M1, "double", OPS_RW),
               ops_arg_dat(soundspeed, S2D_00_0M1, "double", OPS_RW));

  int rangexy_l2a[] = {x_min-2,x_min-1,y_min-depth,y_max+depth};
  if(depth ==2)
  ops_par_loop_update_halo_kernel1_l2("update_halo_kernel", clover_grid, 2, rangexy_l2a,
               ops_arg_dat(density0, S2D_00_P30, "double", OPS_RW),
               ops_arg_dat(density1, S2D_00_P30, "double", OPS_RW),
               ops_arg_dat(energy0, S2D_00_P30, "double", OPS_RW),
               ops_arg_dat(energy1, S2D_00_P30, "double", OPS_RW),
               ops_arg_dat(pressure, S2D_00_P30, "double", OPS_RW),
               ops_arg_dat(viscosity, S2D_00_P30, "double", OPS_RW),
               ops_arg_dat(soundspeed, S2D_00_P30, "double", OPS_RW));

  int rangexy_l1a[] = {x_min-1,x_min,y_min-depth,y_max+depth};
  ops_par_loop_update_halo_kernel1_l1("update_halo_kernel", clover_grid, 2, rangexy_l1a,
               ops_arg_dat(density0, S2D_00_P10, "double", OPS_RW),
               ops_arg_dat(density1, S2D_00_P10, "double", OPS_RW),
               ops_arg_dat(energy0, S2D_00_P10, "double", OPS_RW),
               ops_arg_dat(energy1, S2D_00_P10, "double", OPS_RW),
               ops_arg_dat(pressure, S2D_00_P10, "double", OPS_RW),
               ops_arg_dat(viscosity, S2D_00_P10, "double", OPS_RW),
               ops_arg_dat(soundspeed, S2D_00_P10, "double", OPS_RW));

  int rangexy_r2a[] = {x_max+1,x_max+2,y_min-depth,y_max+depth};

  if(depth ==2)
  ops_par_loop_update_halo_kernel1_r2("update_halo_kernel", clover_grid, 2, rangexy_r2a,
               ops_arg_dat(density0, S2D_00_M30, "double", OPS_RW),
               ops_arg_dat(density1, S2D_00_M30, "double", OPS_RW),
               ops_arg_dat(energy0, S2D_00_M30, "double", OPS_RW),
               ops_arg_dat(energy1, S2D_00_M30, "double", OPS_RW),
               ops_arg_dat(pressure, S2D_00_M30, "double", OPS_RW),
               ops_arg_dat(viscosity, S2D_00_M30, "double", OPS_RW),
               ops_arg_dat(soundspeed, S2D_00_M30, "double", OPS_RW));

  int rangexy_r1a[] = {x_max,x_max+1,y_min-depth,y_max+depth};
  ops_par_loop_update_halo_kernel1_r1("update_halo_kernel", clover_grid, 2, rangexy_r1a,
               ops_arg_dat(density0, S2D_00_M10, "double", OPS_RW),
               ops_arg_dat(density1, S2D_00_M10, "double", OPS_RW),
               ops_arg_dat(energy0, S2D_00_M10, "double", OPS_RW),
               ops_arg_dat(energy1, S2D_00_M10, "double", OPS_RW),
               ops_arg_dat(pressure, S2D_00_M10, "double", OPS_RW),
               ops_arg_dat(viscosity, S2D_00_M10, "double", OPS_RW),
               ops_arg_dat(soundspeed, S2D_00_M10, "double", OPS_RW));




  int rangexy_b2b[] = {x_min-depth,x_max+1+depth,y_min-2,y_min-1};
  if(depth == 2)
  ops_par_loop_update_halo_kernel2_xvel_plus_4_a("update_halo_kernel2_xvel_plus_4_a", clover_grid, 2, rangexy_b2b,
               ops_arg_dat(xvel0, S2D_00_0P4, "double", OPS_RW),
               ops_arg_dat(xvel1, S2D_00_0P4, "double", OPS_RW));

  int rangexy_b1b[] = {x_min-depth,x_max+1+depth,y_min-1,y_min};
  ops_par_loop_update_halo_kernel2_xvel_plus_2_a("update_halo_kernel2_xvel_plus_2_a", clover_grid, 2, rangexy_b1b,
               ops_arg_dat(xvel0, S2D_00_0P2, "double", OPS_RW),
               ops_arg_dat(xvel1, S2D_00_0P2, "double", OPS_RW));

  int rangexy_t2b[] = {x_min-depth,x_max+1+depth,y_max+2,y_max+3};
  if(depth == 2)
  ops_par_loop_update_halo_kernel2_xvel_plus_4_b("update_halo_kernel2_xvel_plus_4_b", clover_grid, 2, rangexy_t2b,
               ops_arg_dat(xvel0, S2D_00_0M4, "double", OPS_RW),
               ops_arg_dat(xvel1, S2D_00_0M4, "double", OPS_RW));

  int rangexy_t1b[] = {x_min-depth,x_max+1+depth,y_max+1,y_max+2};
  ops_par_loop_update_halo_kernel2_xvel_plus_2_b("update_halo_kernel2_xvel_plus_2_b", clover_grid, 2, rangexy_t1b,
               ops_arg_dat(xvel0, S2D_00_0M2, "double", OPS_RW),
               ops_arg_dat(xvel1, S2D_00_0M2, "double", OPS_RW));

  int rangexy_l2b[] = {x_min-2,x_min-1,y_min-depth,y_max+1+depth};
  if(depth ==2)
  ops_par_loop_update_halo_kernel2_xvel_minus_4_a("update_halo_kernel2_xvel_minus_4_a", clover_grid, 2, rangexy_l2b,
               ops_arg_dat(xvel0, S2D_00_P40, "double", OPS_RW),
               ops_arg_dat(xvel1, S2D_00_P40, "double", OPS_RW));

  int rangexy_l1b[] = {x_min-1,x_min,y_min-depth,y_max+1+depth};
  ops_par_loop_update_halo_kernel2_xvel_minus_2_a("update_halo_kernel2_xvel_minus_2_a", clover_grid, 2, rangexy_l1b,
               ops_arg_dat(xvel0, S2D_00_P20, "double", OPS_RW),
               ops_arg_dat(xvel1, S2D_00_P20, "double", OPS_RW));


  int rangexy_r2b[] = {x_max+2,x_max+3,y_min-depth,y_max+1+depth};
  if(depth ==2)
  ops_par_loop_update_halo_kernel2_xvel_minus_4_b("update_halo_kernel2_xvel_minus_4_b", clover_grid, 2, rangexy_r2b,
               ops_arg_dat(xvel0, S2D_00_M40, "double", OPS_RW),
               ops_arg_dat(xvel1, S2D_00_M40, "double", OPS_RW));

  int rangexy_r1b[] = {x_max+1,x_max+2,y_min-depth,y_max+1+depth};
  ops_par_loop_update_halo_kernel2_xvel_minus_2_b("update_halo_kernel2_xvel_minus_2_b", clover_grid, 2, rangexy_r1b,
               ops_arg_dat(xvel0, S2D_00_M20, "double", OPS_RW),
               ops_arg_dat(xvel1, S2D_00_M20, "double", OPS_RW));





  if(depth == 2)
  ops_par_loop_update_halo_kernel2_yvel_minus_4_a("update_halo_kernel2_yvel_minus_4_a", clover_grid, 2, rangexy_b2b,
               ops_arg_dat(yvel0, S2D_00_0P4, "double", OPS_RW),
               ops_arg_dat(yvel1, S2D_00_0P4, "double", OPS_RW));

  ops_par_loop_update_halo_kernel2_yvel_minus_2_a("update_halo_kernel2_yvel_minus_2_a", clover_grid, 2, rangexy_b1b,
               ops_arg_dat(yvel0, S2D_00_0P2, "double", OPS_RW),
               ops_arg_dat(yvel1, S2D_00_0P2, "double", OPS_RW));

  if(depth == 2)
  ops_par_loop_update_halo_kernel2_yvel_minus_4_b("update_halo_kernel2_yvel_minus_4_b", clover_grid, 2, rangexy_t2b,
               ops_arg_dat(yvel0, S2D_00_0M4, "double", OPS_RW),
               ops_arg_dat(yvel1, S2D_00_0M4, "double", OPS_RW));

  ops_par_loop_update_halo_kernel2_yvel_minus_2_b("update_halo_kernel2_yvel_minus_2_b", clover_grid, 2, rangexy_t1b,
               ops_arg_dat(yvel0, S2D_00_0M2, "double", OPS_RW),
               ops_arg_dat(yvel1, S2D_00_0M2, "double", OPS_RW));

  if(depth ==2)
  ops_par_loop_update_halo_kernel2_yvel_plus_4_a("update_halo_kernel2_yvel_plus_4_a", clover_grid, 2, rangexy_l2b,
               ops_arg_dat(yvel0, S2D_00_P40, "double", OPS_RW),
               ops_arg_dat(yvel1, S2D_00_P40, "double", OPS_RW));

  ops_par_loop_update_halo_kernel2_yvel_plus_2_a("update_halo_kernel2_yvel_plus_2_a", clover_grid, 2, rangexy_l1b,
               ops_arg_dat(yvel0, S2D_00_P20, "double", OPS_RW),
               ops_arg_dat(yvel1, S2D_00_P20, "double", OPS_RW));

  if(depth ==2)
  ops_par_loop_update_halo_kernel2_yvel_plus_4_b("update_halo_kernel2_yvel_plus_4_b", clover_grid, 2, rangexy_r2b,
               ops_arg_dat(yvel0, S2D_00_M40, "double", OPS_RW),
               ops_arg_dat(yvel1, S2D_00_M40, "double", OPS_RW));

  ops_par_loop_update_halo_kernel2_yvel_plus_2_b("update_halo_kernel2_yvel_plus_2_b", clover_grid, 2, rangexy_r1b,
               ops_arg_dat(yvel0, S2D_00_M20, "double", OPS_RW),
               ops_arg_dat(yvel1, S2D_00_M20, "double", OPS_RW));





  int rangexy_b2c[] = {x_min-depth,x_max+1+depth,y_min-2,y_min-1};
  if(depth ==2)
  ops_par_loop_update_halo_kernel3_plus_4_a("update_halo_kernel3_plus_4_a", clover_grid, 2, rangexy_b2c,
               ops_arg_dat(vol_flux_x, S2D_00_0P4, "double", OPS_RW),
               ops_arg_dat(mass_flux_x, S2D_00_0P4, "double", OPS_RW));

  int rangexy_b1c[] = {x_min-depth,x_max+1+depth,y_min-1,y_min};
  ops_par_loop_update_halo_kernel3_plus_2_a("update_halo_kernel3_plus_2_a", clover_grid, 2, rangexy_b1c,
               ops_arg_dat(vol_flux_x, S2D_00_0P2, "double", OPS_RW),
               ops_arg_dat(mass_flux_x, S2D_00_0P2, "double", OPS_RW));

  int rangexy_t2c[] = {x_min-depth,x_max+1+depth,y_max+1,y_max+2};
  if(depth ==2)
  ops_par_loop_update_halo_kernel3_plus_4_b("update_halo_kernel3_plus_4_b", clover_grid, 2, rangexy_t2c,
               ops_arg_dat(vol_flux_x, S2D_00_0M4, "double", OPS_RW),
               ops_arg_dat(mass_flux_x, S2D_00_0M4, "double", OPS_RW));

  int rangexy_t1c[] = {x_min-depth,x_max+1+depth,y_max,y_max+1};
  ops_par_loop_update_halo_kernel3_plus_2_b("update_halo_kernel3_plus_2_b", clover_grid, 2, rangexy_t1c,
               ops_arg_dat(vol_flux_x, S2D_00_0M2, "double", OPS_RW),
               ops_arg_dat(mass_flux_x, S2D_00_0M2, "double", OPS_RW));

  int rangexy_l2c[] = {x_min-2,x_min-1,y_min-depth,y_max+depth};
  if(depth ==2)
  ops_par_loop_update_halo_kernel3_minus_4_a("update_halo_kernel3_minus_4_a", clover_grid, 2, rangexy_l2c,
               ops_arg_dat(vol_flux_x, S2D_00_P40, "double", OPS_RW),
               ops_arg_dat(mass_flux_x, S2D_00_P40, "double", OPS_RW));

  int rangexy_l1c[] = {x_min-1,x_min,y_min-depth,y_max+depth};
  ops_par_loop_update_halo_kernel3_minus_2_a("update_halo_kernel3_minus_2_a", clover_grid, 2, rangexy_l1c,
               ops_arg_dat(vol_flux_x, S2D_00_P20, "double", OPS_RW),
               ops_arg_dat(mass_flux_x, S2D_00_P20, "double", OPS_RW));

  int rangexy_r2c[] = {x_max+2,x_max+3,y_min-depth,y_max+depth};
  if(depth ==2)
  ops_par_loop_update_halo_kernel3_minus_4_b("update_halo_kernel3_minus_4_b", clover_grid, 2, rangexy_r2c,
               ops_arg_dat(vol_flux_x, S2D_00_M40, "double", OPS_RW),
               ops_arg_dat(mass_flux_x, S2D_00_M40, "double", OPS_RW));

  int rangexy_r1c[] = {x_max+1,x_max+2,y_min-depth,y_max+depth};
  ops_par_loop_update_halo_kernel3_minus_2_b("update_halo_kernel3_minus_2_b", clover_grid, 2, rangexy_r1c,
               ops_arg_dat(vol_flux_x, S2D_00_M20, "double", OPS_RW),
               ops_arg_dat(mass_flux_x, S2D_00_M20, "double", OPS_RW));




  int rangexy_b2d[] = {x_min-depth,x_max+depth,y_min-2,y_min-1};
  if(depth ==2)
  ops_par_loop_update_halo_kernel4_minus_4_a("update_halo_kernel4_minus_4_a", clover_grid, 2, rangexy_b2d,
               ops_arg_dat(vol_flux_y, S2D_00_0P4, "double", OPS_RW),
               ops_arg_dat(mass_flux_y, S2D_00_0P4, "double", OPS_RW));

  int rangexy_b1d[] = {x_min-depth,x_max+depth,y_min-1,y_min};
  ops_par_loop_update_halo_kernel4_minus_2_a("update_halo_kernel4_minus_2_a", clover_grid, 2, rangexy_b1d,
               ops_arg_dat(vol_flux_y, S2D_00_0P2, "double", OPS_RW),
               ops_arg_dat(mass_flux_y, S2D_00_0P2, "double", OPS_RW));

  int rangexy_t2d[] = {x_min-depth,x_max+depth,y_max+2,y_max+3};
  if(depth ==2)
  ops_par_loop_update_halo_kernel4_minus_4_b("update_halo_kernel4_minus_4_b", clover_grid, 2, rangexy_t2d,
               ops_arg_dat(vol_flux_y, S2D_00_0M4, "double", OPS_RW),
               ops_arg_dat(mass_flux_y, S2D_00_0M4, "double", OPS_RW));

  int rangexy_t1d[] = {x_min-depth,x_max+depth,y_max+1,y_max+2};
  ops_par_loop_update_halo_kernel4_minus_2_b("update_halo_kernel4_minus_2_b", clover_grid, 2, rangexy_t1d,
               ops_arg_dat(vol_flux_y, S2D_00_0M2, "double", OPS_RW),
               ops_arg_dat(mass_flux_y, S2D_00_0M2, "double", OPS_RW));

  int rangexy_l2d[] = {x_min-2,x_min-1,y_min-depth,y_max+1+depth};
  if(depth ==2)
  ops_par_loop_update_halo_kernel4_plus_4_a("update_halo_kernel4_plus_4_a", clover_grid, 2, rangexy_l2d,
               ops_arg_dat(vol_flux_y, S2D_00_P40, "double", OPS_RW),
               ops_arg_dat(mass_flux_y, S2D_00_P40, "double", OPS_RW));

  int rangexy_l1d[] = {x_min-1,x_min,y_min-depth,y_max+1+depth};
  ops_par_loop_update_halo_kernel4_plus_2_a("update_halo_kernel4_plus_2_a", clover_grid, 2, rangexy_l1d,
               ops_arg_dat(vol_flux_y, S2D_00_P20, "double", OPS_RW),
               ops_arg_dat(mass_flux_y, S2D_00_P20, "double", OPS_RW));

  int rangexy_r2d[] = {x_max+1,x_max+2,y_min-depth,y_max+1+depth};
  if(depth ==2)
  ops_par_loop_update_halo_kernel4_plus_4_b("update_halo_kernel4_plus_4_b", clover_grid, 2, rangexy_r2d,
               ops_arg_dat(vol_flux_y, S2D_00_M40, "double", OPS_RW),
               ops_arg_dat(mass_flux_y, S2D_00_M40, "double", OPS_RW));

  int rangexy_r1d[] = {x_max,x_max+1,y_min-depth,y_max+1+depth};
  ops_par_loop_update_halo_kernel4_plus_2_b("update_halo_kernel4_plus_2_b", clover_grid, 2, rangexy_r1d,
               ops_arg_dat(vol_flux_y, S2D_00_M20, "double", OPS_RW),
               ops_arg_dat(mass_flux_y, S2D_00_M20, "double", OPS_RW));

}
