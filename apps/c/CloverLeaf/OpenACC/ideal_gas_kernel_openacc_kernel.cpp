//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim0_ideal_gas_kernel;
int xdim0_ideal_gas_kernel_h = -1;
extern int xdim1_ideal_gas_kernel;
int xdim1_ideal_gas_kernel_h = -1;
extern int xdim2_ideal_gas_kernel;
int xdim2_ideal_gas_kernel_h = -1;
extern int xdim3_ideal_gas_kernel;
int xdim3_ideal_gas_kernel_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void ideal_gas_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size, int y_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_ideal_gas_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[4] = { arg0, arg1, arg2, arg3};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,4,range,8)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,8,"ideal_gas_kernel");
    block->instance->OPS_kernels[8].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block

  int start[2];
  int end[2];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  int arg_idx[2];
  int arg_idx_base[2];
  #ifdef OPS_MPI
  if (compute_ranges(args, 4,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  for ( int n=0; n<2; n++ ){
    arg_idx_base[n] = arg_idx[n];
  }

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;


  //set up initial pointers
  int base0 = args[0].dat->base_offset + (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0 + (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  int base1 = args[1].dat->base_offset + (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1 + (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  int base2 = args[2].dat->base_offset + (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2 + (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  int base3 = args[3].dat->base_offset + (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3 + (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif


  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  //initialize global variable with the dimension of dats
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];
  if (xdim0 != xdim0_ideal_gas_kernel_h || xdim1 != xdim1_ideal_gas_kernel_h || xdim2 != xdim2_ideal_gas_kernel_h || xdim3 != xdim3_ideal_gas_kernel_h) {
    xdim0_ideal_gas_kernel = xdim0;
    xdim0_ideal_gas_kernel_h = xdim0;
    xdim1_ideal_gas_kernel = xdim1;
    xdim1_ideal_gas_kernel_h = xdim1;
    xdim2_ideal_gas_kernel = xdim2;
    xdim2_ideal_gas_kernel_h = xdim2;
    xdim3_ideal_gas_kernel = xdim3;
    xdim3_ideal_gas_kernel_h = xdim3;
  }

  //Halo Exchanges

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 4);
  #else
  ops_H_D_exchanges_host(args, 4);
  #endif
  ops_halo_exchanges(args,4,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 4);
  #else
  ops_H_D_exchanges_host(args, 4);
  #endif
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[8].mpi_time += t2-t1;
  }

  ideal_gas_kernel_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    x_size, y_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[8].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 4);
  #else
  ops_set_dirtybit_host(args, 4);
  #endif
  ops_set_halo_dirtybit3(&args[2],range);
  ops_set_halo_dirtybit3(&args[3],range);

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[8].mpi_time += t2-t1;
    block->instance->OPS_kernels[8].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[8].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[8].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[8].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}
