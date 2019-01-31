//
// auto-generated by ops.py
//
__constant__ int dims_multidim_reduce_kernel [2][3];
static int dims_multidim_reduce_kernel_h [2][3] = {0};

//user function
__device__

void multidim_reduce_kernel_gpu(const ACC<double> &val,
  double *redu_dat1) {

  redu_dat1[0] = redu_dat1[0] + val(0,0,0,0);
  redu_dat1[1] = redu_dat1[1] + val(1,0,0,0);
  redu_dat1[2] = redu_dat1[2] + val(2,0,0,0);
}



__global__ void ops_multidim_reduce_kernel(
double* __restrict arg0,
double* __restrict arg1,
int size0,
int size1,
int size2 ){

  double arg1_l[3];
  for (int d=0; d<3; d++) arg1_l[d] = ZERO_double;

  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1+ idx_y * 1* dims_multidim_reduce_kernel[0][0] + idx_z * 1 * dims_multidim_reduce_kernel[0][0] * dims_multidim_reduce_kernel[0][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ACC<double> argp0(3, dims_multidim_reduce_kernel[0][0], dims_multidim_reduce_kernel[0][1], dims_multidim_reduce_kernel[0][2], arg0);
    multidim_reduce_kernel_gpu(argp0,
                   arg1_l);
  }
  for (int d=0; d<3; d++)
    ops_reduction_cuda<OPS_INC>(&arg1[d+(blockIdx.x + blockIdx.y*gridDim.x + blockIdx.z*gridDim.x*gridDim.y)*3],arg1_l[d]);

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_multidim_reduce_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
#else
void ops_par_loop_multidim_reduce_kernel_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  int *range = desc->range;
  #ifdef OPS_MPI
  ops_block block = desc->block;
  #endif
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[2] = { arg0, arg1};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,2,range,2)) return;
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(2,"multidim_reduce_kernel");
    OPS_instance::getOPSInstance()->OPS_kernels[2].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];

  #ifdef OPS_MPI
  int arg_idx[3];
  #endif
  #ifdef OPS_MPI
  #ifdef OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = sb->decomp_disp[n]+start[n];
  }
  #else
  if (compute_ranges(args, 2,block, range, start, end, arg_idx) < 0) return;
  #endif
  #else
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif
  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int zdim0 = args[0].dat->size[2];

  if (xdim0 != dims_multidim_reduce_kernel_h[0][0] || ydim0 != dims_multidim_reduce_kernel_h[0][1] || zdim0 != dims_multidim_reduce_kernel_h[0][2]) {
    dims_multidim_reduce_kernel_h[0][0] = xdim0;
    dims_multidim_reduce_kernel_h[0][1] = ydim0;
    dims_multidim_reduce_kernel_h[0][2] = zdim0;
    cutilSafeCall(cudaMemcpyToSymbol( dims_multidim_reduce_kernel, dims_multidim_reduce_kernel_h, sizeof(dims_multidim_reduce_kernel)));
  }


  #ifdef OPS_MPI
  double *arg1h = (double *)(((ops_reduction)args[1].data)->data + ((ops_reduction)args[1].data)->size * block->index);
  #else
  double *arg1h = (double *)(((ops_reduction)args[1].data)->data);
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  dim3 grid( (x_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_x+ 1, (y_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_y + 1, (z_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_z +1);
  dim3 tblock(OPS_instance::getOPSInstance()->OPS_block_size_x,OPS_instance::getOPSInstance()->OPS_block_size_y,OPS_instance::getOPSInstance()->OPS_block_size_z);

  int nblocks = ((x_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_x+ 1)*((y_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_y + 1)*((z_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_z +1);
  int maxblocks = nblocks;
  int reduct_bytes = 0;
  int reduct_size = 0;

  reduct_bytes += ROUND_UP(maxblocks*3*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*3);

  reallocReductArrays(reduct_bytes);
  reduct_bytes = 0;

  arg1.data = OPS_instance::getOPSInstance()->OPS_reduct_h + reduct_bytes;
  arg1.data_d = OPS_instance::getOPSInstance()->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<3; d++) ((double *)arg1.data)[d+b*3] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*3*sizeof(double));


  mvReductArraysToDevice(reduct_bytes);
  int dat0 = (OPS_instance::getOPSInstance()->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);

  char *p_a[2];

  //set up initial pointers
  int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    (start[2] * args[0].stencil->stride[2]);
  p_a[0] = (char *)args[0].data_d + base0;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 2);
  ops_halo_exchanges(args,2,range);
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_instance::getOPSInstance()->OPS_kernels[2].mpi_time += t2-t1;
  }

  int nshared = 0;
  int nthread = OPS_instance::getOPSInstance()->OPS_block_size_x*OPS_instance::getOPSInstance()->OPS_block_size_y*OPS_instance::getOPSInstance()->OPS_block_size_z;

  nshared = MAX(nshared,sizeof(double)*3);

  nshared = MAX(nshared*nthread,reduct_size*nthread);

  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    ops_multidim_reduce_kernel<<<grid, tblock, nshared >>> (  (double *)p_a[0], (double *)arg1.data_d,x_size, y_size, z_size);

  cutilSafeCall(cudaGetLastError());

  mvReductArraysToHost(reduct_bytes);
  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<3; d++ ){
      arg1h[d] = arg1h[d] + ((double *)arg1.data)[d+b*3];
    }
  }
  arg1.data = (char *)arg1h;

  if (OPS_instance::getOPSInstance()->OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_instance::getOPSInstance()->OPS_kernels[2].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 2);
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_instance::getOPSInstance()->OPS_kernels[2].mpi_time += t2-t1;
    OPS_instance::getOPSInstance()->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_multidim_reduce_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 2;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 2;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 2;
  desc->args = (ops_arg*)malloc(2*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->function = ops_par_loop_multidim_reduce_kernel_execute;
  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(2,"multidim_reduce_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
