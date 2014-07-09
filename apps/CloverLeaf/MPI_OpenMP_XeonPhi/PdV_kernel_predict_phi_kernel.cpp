//
// auto-generated by ops.py on 2014-07-09 17:28
//

#include "./MPI_OpenMP_XeonPhi/clover_leaf_common.h"

extern int xdim0_PdV_kernel_predict;
extern int xdim1_PdV_kernel_predict;
extern int xdim2_PdV_kernel_predict;
extern int xdim3_PdV_kernel_predict;
extern int xdim4_PdV_kernel_predict;
extern int xdim5_PdV_kernel_predict;
extern int xdim6_PdV_kernel_predict;
extern int xdim7_PdV_kernel_predict;
extern int xdim8_PdV_kernel_predict;
extern int xdim9_PdV_kernel_predict;
extern int xdim10_PdV_kernel_predict;
extern int xdim11_PdV_kernel_predict;

#ifdef __cplusplus
extern "C" {
#endif
void PdV_kernel_predict_c_wrapper(
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
  double *p_a11,
  int x_size, int y_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_PdV_kernel_predict(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11) {

  ops_arg args[12] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11};

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
  ops_timing_realloc(5,"PdV_kernel_predict");
  ops_timers_core(&c2,&t2);

  if (OPS_kernels[5].count == 0) {
    xdim0_PdV_kernel_predict = args[0].dat->block_size[0]*args[0].dat->dim;
    xdim1_PdV_kernel_predict = args[1].dat->block_size[0]*args[1].dat->dim;
    xdim2_PdV_kernel_predict = args[2].dat->block_size[0]*args[2].dat->dim;
    xdim3_PdV_kernel_predict = args[3].dat->block_size[0]*args[3].dat->dim;
    xdim4_PdV_kernel_predict = args[4].dat->block_size[0]*args[4].dat->dim;
    xdim5_PdV_kernel_predict = args[5].dat->block_size[0]*args[5].dat->dim;
    xdim6_PdV_kernel_predict = args[6].dat->block_size[0]*args[6].dat->dim;
    xdim7_PdV_kernel_predict = args[7].dat->block_size[0]*args[7].dat->dim;
    xdim8_PdV_kernel_predict = args[8].dat->block_size[0]*args[8].dat->dim;
    xdim9_PdV_kernel_predict = args[9].dat->block_size[0]*args[9].dat->dim;
    xdim10_PdV_kernel_predict = args[10].dat->block_size[0]*args[10].dat->dim;
    xdim11_PdV_kernel_predict = args[11].dat->block_size[0]*args[11].dat->dim;
  }

  int dat0 = args[0].dat->size;
  int dat1 = args[1].dat->size;
  int dat2 = args[2].dat->size;
  int dat3 = args[3].dat->size;
  int dat4 = args[4].dat->size;
  int dat5 = args[5].dat->size;
  int dat6 = args[6].dat->size;
  int dat7 = args[7].dat->size;
  int dat8 = args[8].dat->size;
  int dat9 = args[9].dat->size;
  int dat10 = args[10].dat->size;
  int dat11 = args[11].dat->size;


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

  int base6 = dat6 * 1 * 
    (start_add[0] * args[6].stencil->stride[0] - args[6].dat->offset[0]);
  base6 = base6+ dat6 *
    args[6].dat->block_size[0] *
    (start_add[1] * args[6].stencil->stride[1] - args[6].dat->offset[1]);
  double *p_a6 = (double *)((char *)args[6].data + base6);

  int base7 = dat7 * 1 * 
    (start_add[0] * args[7].stencil->stride[0] - args[7].dat->offset[0]);
  base7 = base7+ dat7 *
    args[7].dat->block_size[0] *
    (start_add[1] * args[7].stencil->stride[1] - args[7].dat->offset[1]);
  double *p_a7 = (double *)((char *)args[7].data + base7);

  int base8 = dat8 * 1 * 
    (start_add[0] * args[8].stencil->stride[0] - args[8].dat->offset[0]);
  base8 = base8+ dat8 *
    args[8].dat->block_size[0] *
    (start_add[1] * args[8].stencil->stride[1] - args[8].dat->offset[1]);
  double *p_a8 = (double *)((char *)args[8].data + base8);

  int base9 = dat9 * 1 * 
    (start_add[0] * args[9].stencil->stride[0] - args[9].dat->offset[0]);
  base9 = base9+ dat9 *
    args[9].dat->block_size[0] *
    (start_add[1] * args[9].stencil->stride[1] - args[9].dat->offset[1]);
  double *p_a9 = (double *)((char *)args[9].data + base9);

  int base10 = dat10 * 1 * 
    (start_add[0] * args[10].stencil->stride[0] - args[10].dat->offset[0]);
  base10 = base10+ dat10 *
    args[10].dat->block_size[0] *
    (start_add[1] * args[10].stencil->stride[1] - args[10].dat->offset[1]);
  double *p_a10 = (double *)((char *)args[10].data + base10);

  int base11 = dat11 * 1 * 
    (start_add[0] * args[11].stencil->stride[0] - args[11].dat->offset[0]);
  base11 = base11+ dat11 *
    args[11].dat->block_size[0] *
    (start_add[1] * args[11].stencil->stride[1] - args[11].dat->offset[1]);
  double *p_a11 = (double *)((char *)args[11].data + base11);


  ops_H_D_exchanges(args, 12);
  ops_halo_exchanges(args,12,range);

  ops_timers_core(&c1,&t1);
  OPS_kernels[5].mpi_time += t1-t2;

  PdV_kernel_predict_c_wrapper(
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
    p_a11,
    x_size, y_size);

  ops_timers_core(&c2,&t2);
  OPS_kernels[5].time += t2-t1;
  ops_set_dirtybit_host(args, 12);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[8],range);
  ops_set_halo_dirtybit3(&args[11],range);

  //Update kernel record
  OPS_kernels[5].count++;
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg5);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg6);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg7);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg8);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg9);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg10);
  OPS_kernels[5].transfer += ops_compute_transfer(dim, range, &arg11);
}
