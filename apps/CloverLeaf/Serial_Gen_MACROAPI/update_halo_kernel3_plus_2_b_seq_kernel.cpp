//
// auto-generated by ops.py on 2013-11-05 12:16
//

#include "lib.h"
//user function
#include "update_halo_kernel.h"

// host stub function
void ops_par_loop_update_halo_kernel3_plus_2_b(char const *name, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {

  char *p_a[2];
  int  offs[2][2];
  int  count[dim];

  ops_arg args[2] = { arg0, arg1};


  offs[0][0] = 1;  //unit step in x dimension
  offs[0][1] = ops_offs_set(range[0],range[2]+1, args[0]) - ops_offs_set(range[1],range[2], args[0]);
  if (args[0].stencil->stride[0] == 0) {
    offs[0][0] = 0;
    offs[0][1] = args[0].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[0].stencil->stride[1] == 0) {
    offs[0][0] = 1;
    offs[0][1] = -( range[1] - range[0] );
  }

  offs[1][0] = 1;  //unit step in x dimension
  offs[1][1] = ops_offs_set(range[0],range[2]+1, args[1]) - ops_offs_set(range[1],range[2], args[1]);
  if (args[1].stencil->stride[0] == 0) {
    offs[1][0] = 0;
    offs[1][1] = args[1].dat->block_size[0];
  }
  //stride in x as y stride is 0
  else if (args[1].stencil->stride[1] == 0) {
    offs[1][0] = 1;
    offs[1][1] = -( range[1] - range[0] );
  }

  int off0_1 = offs[0][0];
  int off0_2 = offs[0][1];
  int dat0 = args[0].dat->size;
  int off1_1 = offs[1][0];
  int off1_2 = offs[1][1];
  int dat1 = args[1].dat->size;

  //set up initial pointers
  p_a[0] = &args[0].data[
  + args[0].dat->size * args[0].dat->block_size[0] * ( range[2] * 1 - args[0].dat->offset[1] )
  + args[0].dat->size * ( range[0] * 1 - args[0].dat->offset[0] ) ];

  p_a[1] = &args[1].data[
  + args[1].dat->size * args[1].dat->block_size[0] * ( range[2] * 1 - args[1].dat->offset[1] )
  + args[1].dat->size * ( range[0] * 1 - args[1].dat->offset[0] ) ];


  xdim0 = args[0].dat->block_size[0];
  xdim1 = args[1].dat->block_size[0];

  for ( int n_y=range[2]; n_y<range[3]; n_y++ ){
    for ( int n_x=range[0]; n_x<range[0]+(range[1]-range[0])/4; n_x++ ){
      //call kernel function, passing in pointers to data -vectorised
      #pragma simd
      for ( int i=0; i<4; i++ ){
        update_halo_kernel3_plus_2_b(  (double *)p_a[0]+ i*1, (double *)p_a[1]+ i*1 );

      }

      //shift pointers to data x direction
      p_a[0]= p_a[0] + (dat0 * off0_1)*4;
      p_a[1]= p_a[1] + (dat1 * off1_1)*4;
    }

    for ( int n_x=range[0]+((range[1]-range[0])/4)*4; n_x<range[1]; n_x++ ){
      //call kernel function, passing in pointers to data - remainder
      update_halo_kernel3_plus_2_b(  (double *)p_a[0], (double *)p_a[1] );


      //shift pointers to data x direction
      p_a[0]= p_a[0] + (dat0 * off0_1);
      p_a[1]= p_a[1] + (dat1 * off1_1);
    }

    //shift pointers to data y direction
    p_a[0]= p_a[0] + (dat0 * off0_2);
    p_a[1]= p_a[1] + (dat1 * off1_2);
  }
}
