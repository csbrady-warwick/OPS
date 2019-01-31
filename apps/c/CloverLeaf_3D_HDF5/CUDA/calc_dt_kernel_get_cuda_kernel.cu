//
// auto-generated by ops.py
//
__constant__ int dims_calc_dt_kernel_get [6][2];
static int dims_calc_dt_kernel_get_h [6][2] = {0};

//user function
__device__

void calc_dt_kernel_get_gpu(const ACC<double>& cellx,
  const ACC<double>& celly,
  double* xl_pos,
  double* yl_pos,
  const ACC<double> &cellz,
  double *zl_pos) {
  *xl_pos = cellx(0,0,0);
  *yl_pos = celly(0,0,0);
  *zl_pos = cellz(0,0,0);
}



__global__ void ops_calc_dt_kernel_get(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
double* __restrict arg4,
double* __restrict arg5,
int size0,
int size1,
int size2 ){

  double arg2_l[1];
  double arg3_l[1];
  double arg5_l[1];
  for (int d=0; d<1; d++) arg2_l[d] = ZERO_double;
  for (int d=0; d<1; d++) arg3_l[d] = ZERO_double;
  for (int d=0; d<1; d++) arg5_l[d] = ZERO_double;

  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 0*1 * dims_calc_dt_kernel_get[0][0] + idx_z * 0*1 * dims_calc_dt_kernel_get[0][0] * dims_calc_dt_kernel_get[0][1];
  arg1 += idx_x * 0*1 + idx_y * 1*1 * dims_calc_dt_kernel_get[1][0] + idx_z * 0*1 * dims_calc_dt_kernel_get[1][0] * dims_calc_dt_kernel_get[1][1];
  arg4 += idx_x * 0*1 + idx_y * 0*1 * dims_calc_dt_kernel_get[4][0] + idx_z * 1*1 * dims_calc_dt_kernel_get[4][0] * dims_calc_dt_kernel_get[4][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ACC<double> argp0(dims_calc_dt_kernel_get[0][0], dims_calc_dt_kernel_get[0][1], arg0);
    const ACC<double> argp1(dims_calc_dt_kernel_get[1][0], dims_calc_dt_kernel_get[1][1], arg1);
    const ACC<double> argp4(dims_calc_dt_kernel_get[4][0], dims_calc_dt_kernel_get[4][1], arg4);
    calc_dt_kernel_get_gpu(argp0,
                   argp1,
                   arg2_l,
                   arg3_l,
                   argp4,
                   arg5_l);
  }
  for (int d=0; d<1; d++)
    ops_reduction_cuda<OPS_INC>(&arg2[d+(blockIdx.x + blockIdx.y*gridDim.x + blockIdx.z*gridDim.x*gridDim.y)*1],arg2_l[d]);
  for (int d=0; d<1; d++)
    ops_reduction_cuda<OPS_INC>(&arg3[d+(blockIdx.x + blockIdx.y*gridDim.x + blockIdx.z*gridDim.x*gridDim.y)*1],arg3_l[d]);
  for (int d=0; d<1; d++)
    ops_reduction_cuda<OPS_INC>(&arg5[d+(blockIdx.x + blockIdx.y*gridDim.x + blockIdx.z*gridDim.x*gridDim.y)*1],arg5_l[d]);

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_calc_dt_kernel_get(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
#else
void ops_par_loop_calc_dt_kernel_get_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  int *range = desc->range;
  #ifdef OPS_MPI
  ops_block block = desc->block;
  #endif
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,6,range,99)) return;
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(99,"calc_dt_kernel_get");
    OPS_instance::getOPSInstance()->OPS_kernels[99].count++;
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
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #endif
  #else
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif
  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];

  if (xdim0 != dims_calc_dt_kernel_get_h[0][0] || ydim0 != dims_calc_dt_kernel_get_h[0][1] || xdim1 != dims_calc_dt_kernel_get_h[1][0] || ydim1 != dims_calc_dt_kernel_get_h[1][1] || xdim4 != dims_calc_dt_kernel_get_h[4][0] || ydim4 != dims_calc_dt_kernel_get_h[4][1]) {
    dims_calc_dt_kernel_get_h[0][0] = xdim0;
    dims_calc_dt_kernel_get_h[0][1] = ydim0;
    dims_calc_dt_kernel_get_h[1][0] = xdim1;
    dims_calc_dt_kernel_get_h[1][1] = ydim1;
    dims_calc_dt_kernel_get_h[4][0] = xdim4;
    dims_calc_dt_kernel_get_h[4][1] = ydim4;
    cutilSafeCall(cudaMemcpyToSymbol( dims_calc_dt_kernel_get, dims_calc_dt_kernel_get_h, sizeof(dims_calc_dt_kernel_get)));
  }


  #ifdef OPS_MPI
  double *arg2h = (double *)(((ops_reduction)args[2].data)->data + ((ops_reduction)args[2].data)->size * block->index);
  #else
  double *arg2h = (double *)(((ops_reduction)args[2].data)->data);
  #endif
  #ifdef OPS_MPI
  double *arg3h = (double *)(((ops_reduction)args[3].data)->data + ((ops_reduction)args[3].data)->size * block->index);
  #else
  double *arg3h = (double *)(((ops_reduction)args[3].data)->data);
  #endif
  #ifdef OPS_MPI
  double *arg5h = (double *)(((ops_reduction)args[5].data)->data + ((ops_reduction)args[5].data)->size * block->index);
  #else
  double *arg5h = (double *)(((ops_reduction)args[5].data)->data);
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

  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);

  reallocReductArrays(reduct_bytes);
  reduct_bytes = 0;

  arg2.data = OPS_instance::getOPSInstance()->OPS_reduct_h + reduct_bytes;
  arg2.data_d = OPS_instance::getOPSInstance()->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg2.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));

  arg3.data = OPS_instance::getOPSInstance()->OPS_reduct_h + reduct_bytes;
  arg3.data_d = OPS_instance::getOPSInstance()->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg3.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));

  arg5.data = OPS_instance::getOPSInstance()->OPS_reduct_h + reduct_bytes;
  arg5.data_d = OPS_instance::getOPSInstance()->OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<1; d++) ((double *)arg5.data)[d+b*1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));


  mvReductArraysToDevice(reduct_bytes);
  int dat0 = (OPS_instance::getOPSInstance()->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_instance::getOPSInstance()->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat4 = (OPS_instance::getOPSInstance()->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);

  char *p_a[6];

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

  int base1 = args[1].dat->base_offset + 
           dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    (start[2] * args[1].stencil->stride[2]);
  p_a[1] = (char *)args[1].data_d + base1;

  int base4 = args[4].dat->base_offset + 
           dat4 * 1 * (start[0] * args[4].stencil->stride[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    (start[2] * args[4].stencil->stride[2]);
  p_a[4] = (char *)args[4].data_d + base4;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 6);
  ops_halo_exchanges(args,6,range);
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_instance::getOPSInstance()->OPS_kernels[99].mpi_time += t2-t1;
  }

  int nshared = 0;
  int nthread = OPS_instance::getOPSInstance()->OPS_block_size_x*OPS_instance::getOPSInstance()->OPS_block_size_y*OPS_instance::getOPSInstance()->OPS_block_size_z;

  nshared = MAX(nshared,sizeof(double)*1);
  nshared = MAX(nshared,sizeof(double)*1);
  nshared = MAX(nshared,sizeof(double)*1);

  nshared = MAX(nshared*nthread,reduct_size*nthread);

  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    ops_calc_dt_kernel_get<<<grid, tblock, nshared >>> (  (double *)p_a[0], (double *)p_a[1],
         (double *)arg2.data_d, (double *)arg3.data_d,
         (double *)p_a[4], (double *)arg5.data_d,x_size, y_size, z_size);

  cutilSafeCall(cudaGetLastError());

  mvReductArraysToHost(reduct_bytes);
  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg2h[d] = arg2h[d] + ((double *)arg2.data)[d+b*1];
    }
  }
  arg2.data = (char *)arg2h;

  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg3h[d] = arg3h[d] + ((double *)arg3.data)[d+b*1];
    }
  }
  arg3.data = (char *)arg3h;

  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
      arg5h[d] = arg5h[d] + ((double *)arg5.data)[d+b*1];
    }
  }
  arg5.data = (char *)arg5h;

  if (OPS_instance::getOPSInstance()->OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_instance::getOPSInstance()->OPS_kernels[99].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 6);
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_instance::getOPSInstance()->OPS_kernels[99].mpi_time += t2-t1;
    OPS_instance::getOPSInstance()->OPS_kernels[99].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_instance::getOPSInstance()->OPS_kernels[99].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_instance::getOPSInstance()->OPS_kernels[99].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_calc_dt_kernel_get(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 99;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 99;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 6;
  desc->args = (ops_arg*)malloc(6*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->args[3] = arg3;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->function = ops_par_loop_calc_dt_kernel_get_execute;
  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(99,"calc_dt_kernel_get");
  }
  ops_enqueue_kernel(desc);
}
#endif
