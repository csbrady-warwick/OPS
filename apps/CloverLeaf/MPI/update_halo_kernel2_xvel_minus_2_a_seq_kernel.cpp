//
// auto-generated by ops.py on 2014-03-14 17:44
//

//user function
#include "update_halo_kernel.h"

// host stub function
void ops_par_loop_update_halo_kernel2_xvel_minus_2_a(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {

  char *p_a[3];
  int  offs[3][2];
  ops_arg args[3] = { arg0, arg1, arg2};


  sub_block_list sb = OPS_sub_block_list[block->index];
  //compute localy allocated range for the sub-block
  int ndim = sb->ndim;
  int start[ndim*3];
  int end[ndim*3];

  int s[ndim];
  int e[ndim];

  for ( int n=0; n<ndim; n++ ){
    s[n] = sb->istart[n];e[n] = sb->iend[n]+1;
    if (s[n] >= range[2*n]) {
      s[n] = 0;
    }
    else {
      s[n] = range[2*n] - s[n];
    }
    if (e[n] >= range[2*n+1]) {
      e[n] = range[2*n+1] - sb->istart[n];
    }
    else {
      e[n] = sb->sizes[n];
    }
  }

  for ( int i=0; i<3; i++ ){
    for ( int n=0; n<ndim; n++ ){
      start[i*ndim+n] = s[n];
      end[i*ndim+n]   = e[n];
    }
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "update_halo_kernel2_xvel_minus_2_a");
  #endif

  offs[0][0] = args[0].stencil->stride[0]*1;  //unit step in x dimension
  offs[0][1] = off2D(1, &start[0*2],
  &end[0*2],args[0].dat->block_size, args[0].stencil->stride);

  offs[1][0] = args[1].stencil->stride[0]*1;  //unit step in x dimension
  offs[1][1] = off2D(1, &start[1*2],
  &end[1*2],args[1].dat->block_size, args[1].stencil->stride);



  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(49,"update_halo_kernel2_xvel_minus_2_a");
  ops_timers_core(&c2,&t2);

  int off0_1 = offs[0][0];
  int off0_2 = offs[0][1];
  int dat0 = args[0].dat->size;
  int off1_1 = offs[1][0];
  int off1_2 = offs[1][1];
  int dat1 = args[1].dat->size;

  int max0[ndim]; int min0[ndim];
  for ( int n=0; n<ndim; n++ ){
    max0[n] = 0;min0[n] = 0;
  }
  for ( int p=0; p<args[0].stencil->points; p++ ){
    for ( int n=0; n<ndim; n++ ){
      max0[n] = MAX(max0[n],args[0].stencil->stencil[ndim*p + n]) * ((range[2*n+1]-range[2*n]) == 1 ? 0 : 1);
      min0[n] = MIN(min0[n],args[0].stencil->stencil[ndim*p + n]) * ((range[2*n+1]-range[2*n]) == 1 ? 0 : 1);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base0 = dat0 * 1 * 
  (start[ndim+0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0  + dat0 * args[0].dat->block_size[0] * 
  (start[ndim+1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  p_a[0] = (char *)args[0].data + base0;
  ops_exchange_halo2(&args[0],max0,min0);

  int max1[ndim]; int min1[ndim];
  for ( int n=0; n<ndim; n++ ){
    max1[n] = 0;min1[n] = 0;
  }
  for ( int p=0; p<args[1].stencil->points; p++ ){
    for ( int n=0; n<ndim; n++ ){
      max1[n] = MAX(max1[n],args[1].stencil->stencil[ndim*p + n]) * ((range[2*n+1]-range[2*n]) == 1 ? 0 : 1);
      min1[n] = MIN(min1[n],args[1].stencil->stencil[ndim*p + n]) * ((range[2*n+1]-range[2*n]) == 1 ? 0 : 1);
    }
  }
  //set up initial pointers and exchange halos if nessasary
  int base1 = dat1 * 1 * 
  (start[ndim+0] * args[1].stencil->stride[0] - args[1].dat->offset[0]);
  base1 = base1  + dat1 * args[1].dat->block_size[0] * 
  (start[ndim+1] * args[1].stencil->stride[1] - args[1].dat->offset[1]);
  p_a[1] = (char *)args[1].data + base1;
  ops_exchange_halo2(&args[1],max1,min1);

  p_a[2] = (char *)args[2].data;




  ops_timers_core(&c1,&t1);
  OPS_kernels[49].mpi_time += t1-t2;

  xdim0 = args[0].dat->block_size[0];
  xdim1 = args[1].dat->block_size[0];

  int n_x;
  for ( int n_y=s[1]; n_y<e[1]; n_y++ ){
    for( n_x=s[0]; n_x<s[0]+((e[0]-s[0])/SIMD_VEC)*SIMD_VEC; n_x+=SIMD_VEC ) {
      //call kernel function, passing in pointers to data -vectorised
      #pragma simd
      for ( int i=0; i<SIMD_VEC; i++ ){
        update_halo_kernel2_xvel_minus_2_a(  (double *)p_a[0]+ i*1, (double *)p_a[1]+ i*1, (int *)p_a[2] );

      }

      //shift pointers to data x direction
      p_a[0]= p_a[0] + (dat0 * off0_1)*SIMD_VEC;
      p_a[1]= p_a[1] + (dat1 * off1_1)*SIMD_VEC;
    }

    for ( int n_x=s[0]+((e[0]-s[0])/SIMD_VEC)*SIMD_VEC; n_x<e[0]; n_x++ ){
        //call kernel function, passing in pointers to data - remainder
        update_halo_kernel2_xvel_minus_2_a(  (double *)p_a[0], (double *)p_a[1], (int *)p_a[2] );


        //shift pointers to data x direction
        p_a[0]= p_a[0] + (dat0 * off0_1);
        p_a[1]= p_a[1] + (dat1 * off1_1);
      }

      //shift pointers to data y direction
      p_a[0]= p_a[0] + (dat0 * off0_2);
      p_a[1]= p_a[1] + (dat1 * off1_2);
    }
    ops_timers_core(&c2,&t2);
    OPS_kernels[49].time += t2-t1;
    ops_set_halo_dirtybit(&args[0]);
    ops_set_halo_dirtybit(&args[1]);

    //Update kernel record
    OPS_kernels[49].count++;
    OPS_kernels[49].transfer += ops_compute_transfer(dim, range, &arg0);
    OPS_kernels[49].transfer += ops_compute_transfer(dim, range, &arg1);
  }
