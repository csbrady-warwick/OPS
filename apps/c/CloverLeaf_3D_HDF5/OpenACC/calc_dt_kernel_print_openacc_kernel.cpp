//
// auto-generated by ops.py
//

extern int xdim0_calc_dt_kernel_print;
int xdim0_calc_dt_kernel_print_h = -1;
extern int ydim0_calc_dt_kernel_print;
int ydim0_calc_dt_kernel_print_h = -1;
extern int xdim1_calc_dt_kernel_print;
int xdim1_calc_dt_kernel_print_h = -1;
extern int ydim1_calc_dt_kernel_print;
int ydim1_calc_dt_kernel_print_h = -1;
extern int xdim2_calc_dt_kernel_print;
int xdim2_calc_dt_kernel_print_h = -1;
extern int ydim2_calc_dt_kernel_print;
int ydim2_calc_dt_kernel_print_h = -1;
extern int xdim3_calc_dt_kernel_print;
int xdim3_calc_dt_kernel_print_h = -1;
extern int ydim3_calc_dt_kernel_print;
int ydim3_calc_dt_kernel_print_h = -1;
extern int xdim4_calc_dt_kernel_print;
int xdim4_calc_dt_kernel_print_h = -1;
extern int ydim4_calc_dt_kernel_print;
int ydim4_calc_dt_kernel_print_h = -1;
extern int xdim5_calc_dt_kernel_print;
int xdim5_calc_dt_kernel_print_h = -1;
extern int ydim5_calc_dt_kernel_print;
int ydim5_calc_dt_kernel_print_h = -1;
extern int xdim6_calc_dt_kernel_print;
int xdim6_calc_dt_kernel_print_h = -1;
extern int ydim6_calc_dt_kernel_print;
int ydim6_calc_dt_kernel_print_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void calc_dt_kernel_print_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_calc_dt_kernel_print(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,8,range,100)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,100,"calc_dt_kernel_print");
    block->instance->OPS_kernels[100].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block

  int start[3];
  int end[3];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  int arg_idx[3];
  int arg_idx_base[3];
  #ifdef OPS_MPI
  if (compute_ranges(args, 8,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  for ( int n=0; n<3; n++ ){
    arg_idx_base[n] = arg_idx[n];
  }

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;
  int dat6 = args[6].dat->elem_size;

  #ifdef OPS_MPI
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data + ((ops_reduction)args[7].data)->size * block->index);
  #else
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data);
  #endif

  //set up initial pointers
  int base0 = args[0].dat->base_offset + (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0 + (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  base0 = base0 + (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    start[2] * args[0].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  int base1 = args[1].dat->base_offset + (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1 + (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  base1 = base1 + (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    start[2] * args[1].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  int base2 = args[2].dat->base_offset + (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2 + (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  base2 = base2 + (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    start[2] * args[2].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  int base3 = args[3].dat->base_offset + (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3 + (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  base3 = base3 + (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    start[2] * args[3].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif

  int base4 = args[4].dat->base_offset + (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) * start[0] * args[4].stencil->stride[0];
  base4 = base4 + (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    start[1] * args[4].stencil->stride[1];
  base4 = base4 + (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    start[2] * args[4].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a4 = (double *)((char *)args[4].data_d + base4);
  #else
  double *p_a4 = (double *)((char *)args[4].data + base4);
  #endif

  int base5 = args[5].dat->base_offset + (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) * start[0] * args[5].stencil->stride[0];
  base5 = base5 + (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    start[1] * args[5].stencil->stride[1];
  base5 = base5 + (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    start[2] * args[5].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a5 = (double *)((char *)args[5].data_d + base5);
  #else
  double *p_a5 = (double *)((char *)args[5].data + base5);
  #endif

  int base6 = args[6].dat->base_offset + (block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) * start[0] * args[6].stencil->stride[0];
  base6 = base6 + (block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
    args[6].dat->size[0] *
    start[1] * args[6].stencil->stride[1];
  base6 = base6 + (block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    start[2] * args[6].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a6 = (double *)((char *)args[6].data_d + base6);
  #else
  double *p_a6 = (double *)((char *)args[6].data + base6);
  #endif

  double *p_a7 = arg7h;

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  //initialize global variable with the dimension of dats
  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];
  int xdim3 = args[3].dat->size[0];
  int ydim3 = args[3].dat->size[1];
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];
  int xdim5 = args[5].dat->size[0];
  int ydim5 = args[5].dat->size[1];
  int xdim6 = args[6].dat->size[0];
  int ydim6 = args[6].dat->size[1];
  if (xdim0 != xdim0_calc_dt_kernel_print_h || ydim0 != ydim0_calc_dt_kernel_print_h || xdim1 != xdim1_calc_dt_kernel_print_h || ydim1 != ydim1_calc_dt_kernel_print_h || xdim2 != xdim2_calc_dt_kernel_print_h || ydim2 != ydim2_calc_dt_kernel_print_h || xdim3 != xdim3_calc_dt_kernel_print_h || ydim3 != ydim3_calc_dt_kernel_print_h || xdim4 != xdim4_calc_dt_kernel_print_h || ydim4 != ydim4_calc_dt_kernel_print_h || xdim5 != xdim5_calc_dt_kernel_print_h || ydim5 != ydim5_calc_dt_kernel_print_h || xdim6 != xdim6_calc_dt_kernel_print_h || ydim6 != ydim6_calc_dt_kernel_print_h) {
    xdim0_calc_dt_kernel_print = xdim0;
    xdim0_calc_dt_kernel_print_h = xdim0;
    ydim0_calc_dt_kernel_print = ydim0;
    ydim0_calc_dt_kernel_print_h = ydim0;
    xdim1_calc_dt_kernel_print = xdim1;
    xdim1_calc_dt_kernel_print_h = xdim1;
    ydim1_calc_dt_kernel_print = ydim1;
    ydim1_calc_dt_kernel_print_h = ydim1;
    xdim2_calc_dt_kernel_print = xdim2;
    xdim2_calc_dt_kernel_print_h = xdim2;
    ydim2_calc_dt_kernel_print = ydim2;
    ydim2_calc_dt_kernel_print_h = ydim2;
    xdim3_calc_dt_kernel_print = xdim3;
    xdim3_calc_dt_kernel_print_h = xdim3;
    ydim3_calc_dt_kernel_print = ydim3;
    ydim3_calc_dt_kernel_print_h = ydim3;
    xdim4_calc_dt_kernel_print = xdim4;
    xdim4_calc_dt_kernel_print_h = xdim4;
    ydim4_calc_dt_kernel_print = ydim4;
    ydim4_calc_dt_kernel_print_h = ydim4;
    xdim5_calc_dt_kernel_print = xdim5;
    xdim5_calc_dt_kernel_print_h = xdim5;
    ydim5_calc_dt_kernel_print = ydim5;
    ydim5_calc_dt_kernel_print_h = ydim5;
    xdim6_calc_dt_kernel_print = xdim6;
    xdim6_calc_dt_kernel_print_h = xdim6;
    ydim6_calc_dt_kernel_print = ydim6;
    ydim6_calc_dt_kernel_print_h = ydim6;
  }

  //Halo Exchanges

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 8);
  #else
  ops_H_D_exchanges_host(args, 8);
  #endif
  ops_halo_exchanges(args,8,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 8);
  #else
  ops_H_D_exchanges_host(args, 8);
  #endif
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[100].mpi_time += t2-t1;
  }

  calc_dt_kernel_print_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    p_a6,
    p_a7,
    x_size, y_size, z_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[100].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 8);
  #else
  ops_set_dirtybit_host(args, 8);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[100].mpi_time += t2-t1;
    block->instance->OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}
