//
// auto-generated by ops.py
//
__constant__ int dims_poisson_kernel_update [2][3];
static int dims_poisson_kernel_update_h [2][3] = {0};

//user function


__global__ void ops_poisson_kernel_update(
double* __restrict u2_p,
double* __restrict u_p,
int bounds_0_l, int bounds_0_u, int bounds_1_l, int bounds_1_u,
int bounds_2_l, int bounds_2_u) {



  int n_2 = bounds_2_l + blockDim.z * blockIdx.z + threadIdx.z;
  int n_1 = bounds_1_l + blockDim.y * blockIdx.y + threadIdx.y;
  int n_0 = bounds_0_l + blockDim.x * blockIdx.x + threadIdx.x;

  if (n_0 < bounds_0_u && n_1 < bounds_1_u && n_2 < bounds_2_u) {
    const ACC<double> u2(dims_poisson_kernel_update[0][0], dims_poisson_kernel_update[0][1], u2_p + n_0 + n_1 * dims_poisson_kernel_update[0][0] + n_2 * dims_poisson_kernel_update[0][0] * dims_poisson_kernel_update[0][1]);
    ACC<double> u(dims_poisson_kernel_update[1][0], dims_poisson_kernel_update[1][1], u_p + n_0 + n_1 * dims_poisson_kernel_update[1][0] + n_2 * dims_poisson_kernel_update[1][0] * dims_poisson_kernel_update[1][1]);
    
  u(0,0) = u2(0,0);

  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_poisson_kernel_update(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
const int blockidx_start = 0; const int blockidx_end = block->count;
#ifdef OPS_BATCHED
const int batch_size = block->count;
#endif
#else
void ops_par_loop_poisson_kernel_update_execute(const char *name, ops_block block, int blockidx_start, int blockidx_end, int dim, int *range, int nargs, ops_arg* args) {
  #ifdef OPS_BATCHED
  const int batch_size = OPS_BATCH_SIZE;
  #endif
  ops_arg arg0 = args[0];
  ops_arg arg1 = args[1];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  #ifndef OPS_LAZY
  ops_arg args[2] = { arg0, arg1};


  #endif

  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,2,range,1)) return;
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(1,"poisson_kernel_update");
    OPS_instance::getOPSInstance()->OPS_kernels[1].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "poisson_kernel_update");
  #endif


  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #ifdef OPS_MPI
  int arg_idx[2];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 2,block, range, start, end, arg_idx) < 0) return;
  #endif


  #ifdef OPS_BATCHED
  const int bounds_0_l = OPS_BATCHED == 0 ? 0 : start[(OPS_BATCHED>0)+-1];
  const int bounds_0_u = OPS_BATCHED == 0 ? MIN(batch_size,block->count-blockidx_start) : end[(OPS_BATCHED>0)+-1];
  const int bounds_1_l = OPS_BATCHED == 1 ? 0 : start[(OPS_BATCHED>1)+0];
  const int bounds_1_u = OPS_BATCHED == 1 ? MIN(batch_size,block->count-blockidx_start) : end[(OPS_BATCHED>1)+0];
  const int bounds_2_l = OPS_BATCHED == 2 ? 0 : start[(OPS_BATCHED>2)+1];
  const int bounds_2_u = OPS_BATCHED == 2 ? MIN(batch_size,block->count-blockidx_start) : end[(OPS_BATCHED>2)+1];
  #else
  const int bounds_0_l = start[0];
  const int bounds_0_u = end[0];
  const int bounds_1_l = start[1];
  const int bounds_1_u = end[1];
  const int bounds_2_l = 0;
  const int bounds_2_u = blockidx_end-blockidx_start;
  #endif
  if (args[0].dat->size[0] != dims_poisson_kernel_update_h[0][0] || args[0].dat->size[1] != dims_poisson_kernel_update_h[0][1] || args[0].dat->size[2] != dims_poisson_kernel_update_h[0][2] || args[1].dat->size[0] != dims_poisson_kernel_update_h[1][0] || args[1].dat->size[1] != dims_poisson_kernel_update_h[1][1] || args[1].dat->size[2] != dims_poisson_kernel_update_h[1][2]) {
    dims_poisson_kernel_update_h[0][0] = args[0].dat->size[0];
    dims_poisson_kernel_update_h[0][1] = args[0].dat->size[1];
    dims_poisson_kernel_update_h[0][2] = args[0].dat->size[2];
    dims_poisson_kernel_update_h[1][0] = args[1].dat->size[0];
    dims_poisson_kernel_update_h[1][1] = args[1].dat->size[1];
    dims_poisson_kernel_update_h[1][2] = args[1].dat->size[2];
    cutilSafeCall(cudaMemcpyToSymbol( dims_poisson_kernel_update, dims_poisson_kernel_update_h, sizeof(dims_poisson_kernel_update)));
  }

  //set up initial pointers
  double * __restrict__ u2_p = (double *)(args[0].data_d + args[0].dat->base_offset + blockidx_start * args[0].dat->batch_offset);

  double * __restrict__ u_p = (double *)(args[1].data_d + args[1].dat->base_offset + blockidx_start * args[1].dat->batch_offset);



  int x_size = MAX(0,bounds_0_u-bounds_0_l);
  int y_size = MAX(0,bounds_1_u-bounds_1_l);
  int z_size = MAX(0,bounds_2_u-bounds_2_l);

  dim3 grid( (x_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_x+ 1, (y_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_y + 1, (z_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_z+1);
  dim3 tblock(MIN(OPS_instance::getOPSInstance()->OPS_block_size_x, x_size), MIN(OPS_instance::getOPSInstance()->OPS_block_size_y, y_size),MIN(OPS_instance::getOPSInstance()->OPS_block_size_z, z_size));



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_device(args, 2);
  ops_halo_exchanges(args,2,range);
  ops_H_D_exchanges_device(args, 2);
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    OPS_instance::getOPSInstance()->OPS_kernels[1].mpi_time += __t1-__t2;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    ops_poisson_kernel_update<<<grid, tblock >>> (  u2_p, u_p,         bounds_0_l, bounds_0_u, bounds_1_l, bounds_1_u,
         bounds_2_l, bounds_2_u);

  cutilSafeCall(cudaGetLastError());

  if (OPS_instance::getOPSInstance()->OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
  }

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    OPS_instance::getOPSInstance()->OPS_kernels[1].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 2);
  ops_set_halo_dirtybit3(&args[1],range);
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    OPS_instance::getOPSInstance()->OPS_kernels[1].mpi_time += __t1-__t2;
    OPS_instance::getOPSInstance()->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_instance::getOPSInstance()->OPS_kernels[1].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_poisson_kernel_update(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 1;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 1;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 2;
  desc->args = (ops_arg*)malloc(2*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->function = ops_par_loop_poisson_kernel_update_execute;
  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(1,"poisson_kernel_update");
  }
  ops_enqueue_kernel(desc);
}
#endif
