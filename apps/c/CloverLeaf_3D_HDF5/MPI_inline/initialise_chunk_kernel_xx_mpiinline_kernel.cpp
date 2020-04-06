//
// auto-generated by ops.py
//

extern int xdim0_initialise_chunk_kernel_xx;
int xdim0_initialise_chunk_kernel_xx_h = -1;
extern int ydim0_initialise_chunk_kernel_xx;
int ydim0_initialise_chunk_kernel_xx_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void initialise_chunk_kernel_xx_c_wrapper(
  int *p_a0,
  int *p_a1,
  int arg_idx0, int arg_idx1, int arg_idx2,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_initialise_chunk_kernel_xx(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {

  ops_arg args[2] = { arg0, arg1};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,2,range,0)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,0,"initialise_chunk_kernel_xx");
    block->instance->OPS_kernels[0].count++;
  }

  //compute localy allocated range for the sub-block
  int start[3];
  int end[3];
  int arg_idx[3];

  #ifdef OPS_MPI
  if (compute_ranges(args, 2,block, range, start, end, arg_idx) < 0) return;
  #else
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];

  //Timing
  double t1,t2,c1,c2;
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
  }

  if (xdim0 != xdim0_initialise_chunk_kernel_xx_h || ydim0 != ydim0_initialise_chunk_kernel_xx_h) {
    xdim0_initialise_chunk_kernel_xx = xdim0;
    xdim0_initialise_chunk_kernel_xx_h = xdim0;
    ydim0_initialise_chunk_kernel_xx = ydim0;
    ydim0_initialise_chunk_kernel_xx_h = ydim0;
  }



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset + (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0+ (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  base0 = base0+ (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    start[2] * args[0].stencil->stride[2];
  int *p_a0 = (int *)(args[0].data + base0);

  int *p_a1 = NULL;



  ops_H_D_exchanges_host(args, 2);
  ops_halo_exchanges(args,2,range);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[0].mpi_time += t1-t2;
  }

  initialise_chunk_kernel_xx_c_wrapper(
    p_a0,
    p_a1,
    arg_idx[0], arg_idx[1], arg_idx[2],
    x_size, y_size, z_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[0].time += t2-t1;
  }
  ops_set_dirtybit_host(args, 2);
  ops_set_halo_dirtybit3(&args[0],range);

  //Update kernel record
  if (block->instance->OPS_diags > 1) {
    block->instance->OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
