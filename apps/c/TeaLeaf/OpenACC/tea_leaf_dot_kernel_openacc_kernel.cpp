//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim0_tea_leaf_dot_kernel;
int xdim0_tea_leaf_dot_kernel_h = -1;
extern int xdim1_tea_leaf_dot_kernel;
int xdim1_tea_leaf_dot_kernel_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void tea_leaf_dot_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  int x_size, int y_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_tea_leaf_dot_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[3] = { arg0, arg1, arg2};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,3,range,18)) return;
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(18,"tea_leaf_dot_kernel");
    OPS_instance::getOPSInstance()->OPS_kernels[18].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute localy allocated range for the sub-block

  int start[2];
  int end[2];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  int arg_idx[2];
  int arg_idx_base[2];
  #ifdef OPS_MPI
  if (compute_ranges(args, 3,block, range, start, end, arg_idx) < 0) return;
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

  #ifdef OPS_MPI
  double *arg2h = (double *)(((ops_reduction)args[2].data)->data + ((ops_reduction)args[2].data)->size * block->index);
  #else
  double *arg2h = (double *)(((ops_reduction)args[2].data)->data);
  #endif

  //set up initial pointers
  int base0 = args[0].dat->base_offset + (OPS_instance::getOPSInstance()->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0 + (OPS_instance::getOPSInstance()->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  int base1 = args[1].dat->base_offset + (OPS_instance::getOPSInstance()->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1 + (OPS_instance::getOPSInstance()->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  double *p_a2 = arg2h;

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  //initialize global variable with the dimension of dats
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  if (xdim0 != xdim0_tea_leaf_dot_kernel_h || xdim1 != xdim1_tea_leaf_dot_kernel_h) {
    xdim0_tea_leaf_dot_kernel = xdim0;
    xdim0_tea_leaf_dot_kernel_h = xdim0;
    xdim1_tea_leaf_dot_kernel = xdim1;
    xdim1_tea_leaf_dot_kernel_h = xdim1;
  }

  //Halo Exchanges

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 3);
  #else
  ops_H_D_exchanges_host(args, 3);
  #endif
  ops_halo_exchanges(args,3,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 3);
  #else
  ops_H_D_exchanges_host(args, 3);
  #endif
  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_instance::getOPSInstance()->OPS_kernels[18].mpi_time += t2-t1;
  }

  tea_leaf_dot_kernel_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    x_size, y_size);

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_instance::getOPSInstance()->OPS_kernels[18].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 3);
  #else
  ops_set_dirtybit_host(args, 3);
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_instance::getOPSInstance()->OPS_kernels[18].mpi_time += t2-t1;
    OPS_instance::getOPSInstance()->OPS_kernels[18].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_instance::getOPSInstance()->OPS_kernels[18].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}
