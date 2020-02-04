//
// auto-generated by ops.py
//
__constant__ int dims_calc_dt_kernel_print [8][2];
static int dims_calc_dt_kernel_print_h [8][2] = {0};

//user function
__device__

void calc_dt_kernel_print_gpu(const ACC<double> &xvel0,
  const ACC<double> &yvel0,
  const ACC<double> &zvel0,
  const ACC<double> &density0,
  const ACC<double> &energy0,
  const ACC<double> &pressure,
  const ACC<double> &soundspeed,
  double *output) {
  output[0] = xvel0(0,0,0);
  output[1] = yvel0(0,0,0);
  output[2] = zvel0(0,0,0);
  output[3] = xvel0(1,0,0);
  output[4] = yvel0(1,0,0);
  output[5] = zvel0(0,0,0);
  output[6] = xvel0(1,1,0);
  output[7] = yvel0(1,1,0);
  output[8] = zvel0(0,0,0);
  output[9] = xvel0(0,1,0);
  output[10] = yvel0(0,1,0);
  output[11] = zvel0(0,0,0);
  output[12] = xvel0(0,0,1);
  output[13] = yvel0(0,0,1);
  output[14] = zvel0(0,0,1);
  output[15] = xvel0(1,0,1);
  output[16] = yvel0(1,0,1);
  output[17] = zvel0(0,0,1);
  output[18] = xvel0(1,1,1);
  output[19] = yvel0(1,1,1);
  output[20] = zvel0(0,0,1);
  output[21] = xvel0(0,1,1);
  output[22] = yvel0(0,1,1);
  output[23] = zvel0(0,0,1);
  output[24] = density0(0,0,0);
  output[25] = energy0(0,0,0);
  output[26] = pressure(0,0,0);
  output[27] = soundspeed(0,0,0);

}



__global__ void ops_calc_dt_kernel_print(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
double* __restrict arg4,
double* __restrict arg5,
double* __restrict arg6,
double* __restrict arg7,
int size0,
int size1,
int size2 ){

  double arg7_l[28];
  for (int d=0; d<28; d++) arg7_l[d] = ZERO_double;

  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_calc_dt_kernel_print[0][0] + idx_z * 1*1 * dims_calc_dt_kernel_print[0][0] * dims_calc_dt_kernel_print[0][1];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_calc_dt_kernel_print[1][0] + idx_z * 1*1 * dims_calc_dt_kernel_print[1][0] * dims_calc_dt_kernel_print[1][1];
  arg2 += idx_x * 1*1 + idx_y * 1*1 * dims_calc_dt_kernel_print[2][0] + idx_z * 1*1 * dims_calc_dt_kernel_print[2][0] * dims_calc_dt_kernel_print[2][1];
  arg3 += idx_x * 1*1 + idx_y * 1*1 * dims_calc_dt_kernel_print[3][0] + idx_z * 1*1 * dims_calc_dt_kernel_print[3][0] * dims_calc_dt_kernel_print[3][1];
  arg4 += idx_x * 1*1 + idx_y * 1*1 * dims_calc_dt_kernel_print[4][0] + idx_z * 1*1 * dims_calc_dt_kernel_print[4][0] * dims_calc_dt_kernel_print[4][1];
  arg5 += idx_x * 1*1 + idx_y * 1*1 * dims_calc_dt_kernel_print[5][0] + idx_z * 1*1 * dims_calc_dt_kernel_print[5][0] * dims_calc_dt_kernel_print[5][1];
  arg6 += idx_x * 1*1 + idx_y * 1*1 * dims_calc_dt_kernel_print[6][0] + idx_z * 1*1 * dims_calc_dt_kernel_print[6][0] * dims_calc_dt_kernel_print[6][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    const ACC<double> argp0(dims_calc_dt_kernel_print[0][0], dims_calc_dt_kernel_print[0][1], arg0);
    const ACC<double> argp1(dims_calc_dt_kernel_print[1][0], dims_calc_dt_kernel_print[1][1], arg1);
    const ACC<double> argp2(dims_calc_dt_kernel_print[2][0], dims_calc_dt_kernel_print[2][1], arg2);
    const ACC<double> argp3(dims_calc_dt_kernel_print[3][0], dims_calc_dt_kernel_print[3][1], arg3);
    const ACC<double> argp4(dims_calc_dt_kernel_print[4][0], dims_calc_dt_kernel_print[4][1], arg4);
    const ACC<double> argp5(dims_calc_dt_kernel_print[5][0], dims_calc_dt_kernel_print[5][1], arg5);
    const ACC<double> argp6(dims_calc_dt_kernel_print[6][0], dims_calc_dt_kernel_print[6][1], arg6);
    calc_dt_kernel_print_gpu(argp0, argp1, argp2, argp3,
                   argp4, argp5, argp6, arg7_l);
  }
  for (int d=0; d<28; d++)
    ops_reduction_cuda<OPS_INC>(&arg7[d+(blockIdx.x + blockIdx.y*gridDim.x + blockIdx.z*gridDim.x*gridDim.y)*28],arg7_l[d]);

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_calc_dt_kernel_print(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
#else
void ops_par_loop_calc_dt_kernel_print_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  #if OPS_MPI
  ops_block block = desc->block;
  #endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  ops_arg arg6 = desc->args[6];
  ops_arg arg7 = desc->args[7];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,8,range,100)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(100,"calc_dt_kernel_print");
    OPS_kernels[100].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  #ifdef OPS_MPI
  int arg_idx[3];
  #endif
  #ifdef OPS_MPI
  if (compute_ranges(args, 8,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif
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

  if (xdim0 != dims_calc_dt_kernel_print_h[0][0] || ydim0 != dims_calc_dt_kernel_print_h[0][1] || xdim1 != dims_calc_dt_kernel_print_h[1][0] || ydim1 != dims_calc_dt_kernel_print_h[1][1] || xdim2 != dims_calc_dt_kernel_print_h[2][0] || ydim2 != dims_calc_dt_kernel_print_h[2][1] || xdim3 != dims_calc_dt_kernel_print_h[3][0] || ydim3 != dims_calc_dt_kernel_print_h[3][1] || xdim4 != dims_calc_dt_kernel_print_h[4][0] || ydim4 != dims_calc_dt_kernel_print_h[4][1] || xdim5 != dims_calc_dt_kernel_print_h[5][0] || ydim5 != dims_calc_dt_kernel_print_h[5][1] || xdim6 != dims_calc_dt_kernel_print_h[6][0] || ydim6 != dims_calc_dt_kernel_print_h[6][1]) {
    dims_calc_dt_kernel_print_h[0][0] = xdim0;
    dims_calc_dt_kernel_print_h[0][1] = ydim0;
    dims_calc_dt_kernel_print_h[1][0] = xdim1;
    dims_calc_dt_kernel_print_h[1][1] = ydim1;
    dims_calc_dt_kernel_print_h[2][0] = xdim2;
    dims_calc_dt_kernel_print_h[2][1] = ydim2;
    dims_calc_dt_kernel_print_h[3][0] = xdim3;
    dims_calc_dt_kernel_print_h[3][1] = ydim3;
    dims_calc_dt_kernel_print_h[4][0] = xdim4;
    dims_calc_dt_kernel_print_h[4][1] = ydim4;
    dims_calc_dt_kernel_print_h[5][0] = xdim5;
    dims_calc_dt_kernel_print_h[5][1] = ydim5;
    dims_calc_dt_kernel_print_h[6][0] = xdim6;
    dims_calc_dt_kernel_print_h[6][1] = ydim6;
    cutilSafeCall(cudaMemcpyToSymbol( dims_calc_dt_kernel_print, dims_calc_dt_kernel_print_h, sizeof(dims_calc_dt_kernel_print)));
  }


  #if defined(OPS_LAZY) && !defined(OPS_MPI)
  ops_block block = desc->block;
  #endif
  #ifdef OPS_MPI
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data + ((ops_reduction)args[7].data)->size * block->index);
  #else
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data);
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, (z_size-1)/OPS_block_size_z +1);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,OPS_block_size_z);

  int nblocks = ((x_size-1)/OPS_block_size_x+ 1)*((y_size-1)/OPS_block_size_y + 1)*((z_size-1)/OPS_block_size_z +1);
  int maxblocks = nblocks;
  int reduct_bytes = 0;
  int reduct_size = 0;

  reduct_bytes += ROUND_UP(maxblocks*28*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*28);

  reallocReductArrays(reduct_bytes);
  reduct_bytes = 0;

  arg7.data = OPS_reduct_h + reduct_bytes;
  arg7.data_d = OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<28; d++) ((double *)arg7.data)[d+b*28] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*28*sizeof(double));


  mvReductArraysToDevice(reduct_bytes);
  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int dat3 = (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  int dat4 = (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  int dat5 = (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  int dat6 = (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);

  char *p_a[8];

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

  int base2 = args[2].dat->base_offset + 
           dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    (start[2] * args[2].stencil->stride[2]);
  p_a[2] = (char *)args[2].data_d + base2;

  int base3 = args[3].dat->base_offset + 
           dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    (start[2] * args[3].stencil->stride[2]);
  p_a[3] = (char *)args[3].data_d + base3;

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

  int base5 = args[5].dat->base_offset + 
           dat5 * 1 * (start[0] * args[5].stencil->stride[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    (start[2] * args[5].stencil->stride[2]);
  p_a[5] = (char *)args[5].data_d + base5;

  int base6 = args[6].dat->base_offset + 
           dat6 * 1 * (start[0] * args[6].stencil->stride[0]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    (start[1] * args[6].stencil->stride[1]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    (start[2] * args[6].stencil->stride[2]);
  p_a[6] = (char *)args[6].data_d + base6;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 8);
  ops_halo_exchanges(args,8,range);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[100].mpi_time += t2-t1;
  }

  int nshared = 0;
  int nthread = OPS_block_size_x*OPS_block_size_y*OPS_block_size_z;

  nshared = MAX(nshared,sizeof(double)*28);

  nshared = MAX(nshared*nthread,reduct_size*nthread);

  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    ops_calc_dt_kernel_print<<<grid, tblock, nshared >>> (  (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2], (double *)p_a[3],
         (double *)p_a[4], (double *)p_a[5],
         (double *)p_a[6], (double *)arg7.data_d,x_size, y_size, z_size);

  cutilSafeCall(cudaGetLastError());

  mvReductArraysToHost(reduct_bytes);
  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<28; d++ ){
      arg7h[d] = arg7h[d] + ((double *)arg7.data)[d+b*28];
    }
  }
  arg7.data = (char *)arg7h;

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_kernels[100].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 8);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[100].mpi_time += t2-t1;
    OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[100].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_calc_dt_kernel_print(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 100;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 100;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 8;
  desc->args = (ops_arg*)malloc(8*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->args[6] = arg6;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg6.dat->index;
  desc->args[7] = arg7;
  desc->function = ops_par_loop_calc_dt_kernel_print_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(100,"calc_dt_kernel_print");
  }
  ops_enqueue_kernel(desc);
}
#endif
