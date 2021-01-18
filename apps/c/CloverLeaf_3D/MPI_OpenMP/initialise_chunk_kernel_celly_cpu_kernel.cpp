//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_celly(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
#else
void ops_par_loop_initialise_chunk_kernel_celly_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[3] = { arg0, arg1, arg2};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,3,range,7)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,7,"initialise_chunk_kernel_celly");
    block->instance->OPS_kernels[7].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "initialise_chunk_kernel_celly");
  #endif


  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if defined(OPS_MPI) && !defined(OPS_LAZY)
  int arg_idx[3];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 3,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_initialise_chunk_kernel_celly = args[0].dat->size[0];
  int ydim0_initialise_chunk_kernel_celly = args[0].dat->size[1];
  int xdim1_initialise_chunk_kernel_celly = args[1].dat->size[0];
  int ydim1_initialise_chunk_kernel_celly = args[1].dat->size[1];
  int xdim2_initialise_chunk_kernel_celly = args[2].dat->size[0];
  int ydim2_initialise_chunk_kernel_celly = args[2].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ vertexy_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ celly_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ celldy_p = (double *)(args[2].data + base2);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 3);
  ops_halo_exchanges(args,3,range);
  ops_H_D_exchanges_host(args, 3);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[7].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef __INTEL_COMPILER
      #pragma loop_count(10000)
      #pragma omp simd
      #elif defined(__clang__)
      #pragma clang loop vectorize(assume_safety)
      #elif defined(__GNUC__)
      #pragma GCC ivdep
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        const ACC<double> vertexy(xdim0_initialise_chunk_kernel_celly, ydim0_initialise_chunk_kernel_celly, vertexy_p + n_x*0 + n_y * xdim0_initialise_chunk_kernel_celly*1 + n_z * xdim0_initialise_chunk_kernel_celly * ydim0_initialise_chunk_kernel_celly*0);
        ACC<double> celly(xdim1_initialise_chunk_kernel_celly, ydim1_initialise_chunk_kernel_celly, celly_p + n_x*0 + n_y * xdim1_initialise_chunk_kernel_celly*1 + n_z * xdim1_initialise_chunk_kernel_celly * ydim1_initialise_chunk_kernel_celly*0);
        ACC<double> celldy(xdim2_initialise_chunk_kernel_celly, ydim2_initialise_chunk_kernel_celly, celldy_p + n_x*0 + n_y * xdim2_initialise_chunk_kernel_celly*1 + n_z * xdim2_initialise_chunk_kernel_celly * ydim2_initialise_chunk_kernel_celly*0);
        
  double d_y = (grid.ymax - grid.ymin)/(double)grid.y_cells;
  celly(0,0,0)  = 0.5*( vertexy(0,0,0) + vertexy(0,1,0) );
  celldy(0,0,0)  = d_y;
  if(celldy(0,0,0) < 0) {


  }

      }
    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[7].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 3);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[2],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[7].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg2);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_celly(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 7;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 7;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 3;
  desc->args = (ops_arg *)ops_malloc(3 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->function = ops_par_loop_initialise_chunk_kernel_celly_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,7,"initialise_chunk_kernel_celly");
  }
  ops_enqueue_kernel(desc);
}
#endif
