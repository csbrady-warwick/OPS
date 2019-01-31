//
// auto-generated by ops.py
//



void ops_init_backend();
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define OPS_3D
#define OPS_SOA
#include  "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_multidim_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_multidim_copy_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );

void ops_par_loop_multidim_reduce_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg );



//#include "multidim_kernel.h"
//#include "multidim_print_kernel.h"
//#include "multidim_copy_kernel.h"
//#include "multidim_reduce_kernel.h"

int main(int argc, const char **argv)
{

  int x_cells = 4;
  int y_cells = 4;
  int z_cells = 4;


  ops_init(argc,argv,1);
  ops_init_backend();
  OPS_instance::getOPSInstance()->OPS_soa = 1;


  ops_block grid3D = ops_decl_block(3, "grid3D");

  int s3D_00[]         = {0,0,0};
  int s3D_7p[]         = {0,0,0, 1,0,0, -1,0,0, 0,1,0, 0,-1,0, 0,0,1, 0,0,-1};
  ops_stencil S3D_00 = ops_decl_stencil( 3, 1, s3D_00, "00");
  ops_stencil S3D_7p = ops_decl_stencil( 3, 7, s3D_7p, "000:100:-100:010:0-10:001:00-1");


  int d_p[3] = {1,1,1};
  int d_m[3] = {-1,-1,-1};
  int size[3] = {x_cells, y_cells, z_cells};
  int base[3] = {0,0,0};
  double* temp = NULL;

  ops_dat dat0    = ops_decl_dat(grid3D, 3, size, base, d_m, d_p, temp, "double", "dat0");
  ops_dat dat1    = ops_decl_dat(grid3D, 3, size, base, d_m, d_p, temp, "double", "dat1");

  ops_halo_group halos0;
  {
    int halo_iter[] = {1,4,4};
    int base_from[] = {3,0,0};
    int base_to[] = {-1,0,0};
    int dir[] = {1,2,3};
    ops_halo h0 = ops_decl_halo(dat0, dat0, halo_iter, base_from, base_to, dir, dir);
    base_from[0] = 0; base_to[0] = 4;
    ops_halo h1 = ops_decl_halo(dat0, dat0, halo_iter, base_from, base_to, dir, dir);
    ops_halo grp[] = {h0,h1};
    halos0 = ops_decl_halo_group(2,grp);
  }


  double reduct_result[3] = {0.0, 0.0, 0.0};
  ops_reduction reduct_dat1 = ops_decl_reduction_handle(3*sizeof(double), "double", "reduct_dat1");

  ops_partition("3D_BLOCK_DECOMPSE");

  double ct0, ct1, et0, et1;
  ops_timers(&ct0, &et0);

  int iter_range[] = {0,4,0,4,0,4};
  ops_par_loop_multidim_kernel("multidim_kernel", grid3D, 3, iter_range,
               ops_arg_dat(dat0, 3, S3D_00, "double", OPS_WRITE),
               ops_arg_idx());
  ops_par_loop_multidim_copy_kernel("multidim_copy_kernel", grid3D, 3, iter_range,
               ops_arg_dat(dat0, 3, S3D_7p, "double", OPS_READ),
               ops_arg_dat(dat1, 3, S3D_00, "double", OPS_WRITE));
  ops_halo_transfer(halos0);




  ops_par_loop_multidim_reduce_kernel("multidim_reduce_kernel", grid3D, 3, iter_range,
               ops_arg_dat(dat1, 3, S3D_00, "double", OPS_READ),
               ops_arg_reduce(reduct_dat1, 3, "double", OPS_INC));

  ops_reduction_result(reduct_dat1, reduct_result);

  ops_timers(&ct1, &et1);
  ops_print_dat_to_txtfile(dat0, "multidim.dat");


  ops_printf("\nTotal Wall time %lf\n",et1-et0);
  double result_diff=fabs((100.0*((reduct_result[0]+reduct_result[1]+reduct_result[2])/(3*96.000000)))-100.0);
  ops_printf("Reduction result = %lf, %lf, %lf\n", reduct_result[0],reduct_result[1], reduct_result[2]);
  ops_printf("Result is within %3.15E %% of the expected result\n",result_diff);

  if(result_diff < 0.0000000000001) {
    ops_printf("This run is considered PASSED\n");
  }
  else {
    ops_printf("This test is considered FAILED\n");
  }

  ops_exit();
}
