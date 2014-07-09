//
// auto-generated by ops.py on 2014-07-09 17:28
//

#include "./MPI_OpenMP_XeonPhi/clover_leaf_common.h"

extern int xdim0_field_summary_kernel;
extern int xdim1_field_summary_kernel;
extern int xdim2_field_summary_kernel;
extern int xdim3_field_summary_kernel;
extern int xdim4_field_summary_kernel;
extern int xdim5_field_summary_kernel;

#ifdef __cplusplus
extern "C" {
#endif
void field_summary_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  int x_size, int y_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_field_summary_kernel(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10) {

  ops_arg args[11] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10};

  sub_block_list sb = OPS_sub_block_list[Block->index];
  //compute localy allocated range for the sub-block
  int start_add[2];
  int end_add[2];
  for ( int n=0; n<2; n++ ){
    start_add[n] = sb->istart[n];end_add[n] = sb->iend[n]+1;
    if (start_add[n] >= range[2*n]) {
      start_add[n] = 0;
    }
    else {
      start_add[n] = range[2*n] - start_add[n];
    }
    if (end_add[n] >= range[2*n+1]) {
      end_add[n] = range[2*n+1] - sb->istart[n];
    }
    else {
      end_add[n] = sb->sizes[n];
    }
  }


  int x_size = MAX(0,end_add[0]-start_add[0]);
  int y_size = MAX(0,end_add[1]-start_add[1]);


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(70,"field_summary_kernel");
  ops_timers_core(&c2,&t2);

  if (OPS_kernels[70].count == 0) {
    xdim0_field_summary_kernel = args[0].dat->block_size[0]*args[0].dat->dim;
    xdim1_field_summary_kernel = args[1].dat->block_size[0]*args[1].dat->dim;
    xdim2_field_summary_kernel = args[2].dat->block_size[0]*args[2].dat->dim;
    xdim3_field_summary_kernel = args[3].dat->block_size[0]*args[3].dat->dim;
    xdim4_field_summary_kernel = args[4].dat->block_size[0]*args[4].dat->dim;
    xdim5_field_summary_kernel = args[5].dat->block_size[0]*args[5].dat->dim;
  }

  int dat0 = args[0].dat->size;
  int dat1 = args[1].dat->size;
  int dat2 = args[2].dat->size;
  int dat3 = args[3].dat->size;
  int dat4 = args[4].dat->size;
  int dat5 = args[5].dat->size;


  //set up initial pointers
  int base0 = dat0 * 1 * 
    (start_add[0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0+ dat0 *
    args[0].dat->block_size[0] *
    (start_add[1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  double *p_a0 = (double *)((char *)args[0].data + base0);

  int base1 = dat1 * 1 * 
    (start_add[0] * args[1].stencil->stride[0] - args[1].dat->offset[0]);
  base1 = base1+ dat1 *
    args[1].dat->block_size[0] *
    (start_add[1] * args[1].stencil->stride[1] - args[1].dat->offset[1]);
  double *p_a1 = (double *)((char *)args[1].data + base1);

  int base2 = dat2 * 1 * 
    (start_add[0] * args[2].stencil->stride[0] - args[2].dat->offset[0]);
  base2 = base2+ dat2 *
    args[2].dat->block_size[0] *
    (start_add[1] * args[2].stencil->stride[1] - args[2].dat->offset[1]);
  double *p_a2 = (double *)((char *)args[2].data + base2);

  int base3 = dat3 * 1 * 
    (start_add[0] * args[3].stencil->stride[0] - args[3].dat->offset[0]);
  base3 = base3+ dat3 *
    args[3].dat->block_size[0] *
    (start_add[1] * args[3].stencil->stride[1] - args[3].dat->offset[1]);
  double *p_a3 = (double *)((char *)args[3].data + base3);

  int base4 = dat4 * 1 * 
    (start_add[0] * args[4].stencil->stride[0] - args[4].dat->offset[0]);
  base4 = base4+ dat4 *
    args[4].dat->block_size[0] *
    (start_add[1] * args[4].stencil->stride[1] - args[4].dat->offset[1]);
  double *p_a4 = (double *)((char *)args[4].data + base4);

  int base5 = dat5 * 1 * 
    (start_add[0] * args[5].stencil->stride[0] - args[5].dat->offset[0]);
  base5 = base5+ dat5 *
    args[5].dat->block_size[0] *
    (start_add[1] * args[5].stencil->stride[1] - args[5].dat->offset[1]);
  double *p_a5 = (double *)((char *)args[5].data + base5);

  double *p_a6 = (double *)args[6].data;

  double *p_a7 = (double *)args[7].data;

  double *p_a8 = (double *)args[8].data;

  double *p_a9 = (double *)args[9].data;

  double *p_a10 = (double *)args[10].data;


  ops_H_D_exchanges(args, 11);
  ops_halo_exchanges(args,11,range);

  ops_timers_core(&c1,&t1);
  OPS_kernels[70].mpi_time += t1-t2;

  field_summary_kernel_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    p_a6,
    p_a7,
    p_a8,
    p_a9,
    p_a10,
    x_size, y_size);
  *(double *)args[6].data = *p_a6;
  *(double *)args[7].data = *p_a7;
  *(double *)args[8].data = *p_a8;
  *(double *)args[9].data = *p_a9;
  *(double *)args[10].data = *p_a10;

  ops_timers_core(&c2,&t2);
  OPS_kernels[70].time += t2-t1;
  ops_mpi_reduce(&arg6,(double *)args[6].data);
  ops_mpi_reduce(&arg7,(double *)args[7].data);
  ops_mpi_reduce(&arg8,(double *)args[8].data);
  ops_mpi_reduce(&arg9,(double *)args[9].data);
  ops_mpi_reduce(&arg10,(double *)args[10].data);
  ops_timers_core(&c1,&t1);
  OPS_kernels[70].mpi_time += t1-t2;
  ops_set_dirtybit_host(args, 11);

  //Update kernel record
  OPS_kernels[70].count++;
  OPS_kernels[70].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[70].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[70].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[70].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[70].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[70].transfer += ops_compute_transfer(dim, range, &arg5);
}
