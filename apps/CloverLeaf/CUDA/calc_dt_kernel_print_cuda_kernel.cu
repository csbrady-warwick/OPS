//
// auto-generated by ops.py
//
__constant__ int xdim0_calc_dt_kernel_print;
__constant__ int xdim1_calc_dt_kernel_print;
__constant__ int xdim2_calc_dt_kernel_print;
__constant__ int xdim3_calc_dt_kernel_print;
__constant__ int xdim4_calc_dt_kernel_print;
__constant__ int xdim5_calc_dt_kernel_print;

#define OPS_ACC0(x,y) (x+xdim0_calc_dt_kernel_print*(y))
#define OPS_ACC1(x,y) (x+xdim1_calc_dt_kernel_print*(y))
#define OPS_ACC2(x,y) (x+xdim2_calc_dt_kernel_print*(y))
#define OPS_ACC3(x,y) (x+xdim3_calc_dt_kernel_print*(y))
#define OPS_ACC4(x,y) (x+xdim4_calc_dt_kernel_print*(y))
#define OPS_ACC5(x,y) (x+xdim5_calc_dt_kernel_print*(y))

//user function
__device__

void calc_dt_kernel_print(const double *xvel0, const double *yvel0,
                        const double *density0, const double *energy0,
                        const double *pressure, const double *soundspeed, double *output) {
  output[0] = xvel0[OPS_ACC0(1,0)];
  output[1] = yvel0[OPS_ACC1(1,0)];
  output[2] = xvel0[OPS_ACC0(-1,0)];
  output[3] = yvel0[OPS_ACC1(-1,0)];
  output[4] = xvel0[OPS_ACC0(0,1)];
  output[5] = yvel0[OPS_ACC1(0,1)];
  output[6] = xvel0[OPS_ACC0(0,-1)];
  output[7] = yvel0[OPS_ACC1(0,-1)];
  output[8] = density0[OPS_ACC2(0,0)];
  output[9] = energy0[OPS_ACC3(0,0)];
  output[10]= pressure[OPS_ACC4(0,0)];
  output[11]= soundspeed[OPS_ACC5(0,0)];

}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5


__global__ void ops_calc_dt_kernel_print(
const double* __restrict arg0,
const double* __restrict arg1,
const double* __restrict arg2,
const double* __restrict arg3,
const double* __restrict arg4,
const double* __restrict arg5,
double* __restrict arg6,
int size0,
int size1 ){

  double arg6_l[12];
  for (int d=0; d<12; d++) arg6_l[d] = ZERO_double;

  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 + idx_y * 1 * xdim0_calc_dt_kernel_print;
  arg1 += idx_x * 1 + idx_y * 1 * xdim1_calc_dt_kernel_print;
  arg2 += idx_x * 1 + idx_y * 1 * xdim2_calc_dt_kernel_print;
  arg3 += idx_x * 1 + idx_y * 1 * xdim3_calc_dt_kernel_print;
  arg4 += idx_x * 1 + idx_y * 1 * xdim4_calc_dt_kernel_print;
  arg5 += idx_x * 1 + idx_y * 1 * xdim5_calc_dt_kernel_print;

  if (idx_x < size0 && idx_y < size1) {
    calc_dt_kernel_print(arg0, arg1, arg2, arg3,
                   arg4, arg5, arg6_l);
  }
  for (int d=0; d<12; d++)
    ops_reduction_cuda<OPS_INC>(&arg6[d+blockIdx.x + blockIdx.y*gridDim.x],arg6_l[d]);

}

// host stub function
void ops_par_loop_calc_dt_kernel_print(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6) {

  ops_arg args[7] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6};


  ops_timing_realloc(30,"calc_dt_kernel_print");
  OPS_kernels[30].count++;

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<2; n++ ){
    start[n] = sb->decomp_disp[n];end[n] = sb->decomp_disp[n]+sb->decomp_size[n];
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (sb->id_m[n]==MPI_PROC_NULL && range[2*n] < 0) start[n] = range[2*n];
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->decomp_disp[n];
    }
    else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n]==MPI_PROC_NULL && (range[2*n+1] > sb->decomp_disp[n]+sb->decomp_size[n]))
      end[n] += (range[2*n+1]-sb->decomp_disp[n]-sb->decomp_size[n]);
  }
  #else //OPS_MPI
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif //OPS_MPI

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  int xdim0 = args[0].dat->size[0]*args[0].dat->dim;
  int xdim1 = args[1].dat->size[0]*args[1].dat->dim;
  int xdim2 = args[2].dat->size[0]*args[2].dat->dim;
  int xdim3 = args[3].dat->size[0]*args[3].dat->dim;
  int xdim4 = args[4].dat->size[0]*args[4].dat->dim;
  int xdim5 = args[5].dat->size[0]*args[5].dat->dim;


  //Timing
  double t1,t2,c1,c2;
  ops_timers_core(&c2,&t2);

  if (OPS_kernels[30].count == 0) {
    cudaMemcpyToSymbol( xdim0_calc_dt_kernel_print, &xdim0, sizeof(int) );
    cudaMemcpyToSymbol( xdim1_calc_dt_kernel_print, &xdim1, sizeof(int) );
    cudaMemcpyToSymbol( xdim2_calc_dt_kernel_print, &xdim2, sizeof(int) );
    cudaMemcpyToSymbol( xdim3_calc_dt_kernel_print, &xdim3, sizeof(int) );
    cudaMemcpyToSymbol( xdim4_calc_dt_kernel_print, &xdim4, sizeof(int) );
    cudaMemcpyToSymbol( xdim5_calc_dt_kernel_print, &xdim5, sizeof(int) );
  }


  #ifdef OPS_MPI
  double *arg6h = (double *)(((ops_reduction)args[6].data)->data + ((ops_reduction)args[6].data)->size * block->index);
  #else //OPS_MPI
  double *arg6h = (double *)(((ops_reduction)args[6].data)->data);
  #endif //OPS_MPI

  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,1);

  int nblocks = ((x_size-1)/OPS_block_size_x+ 1)*((y_size-1)/OPS_block_size_y + 1);
  int maxblocks = nblocks;
  int reduct_bytes = 0;
  int reduct_size = 0;

  reduct_bytes += ROUND_UP(maxblocks*12*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*12);

  reallocReductArrays(reduct_bytes);
  reduct_bytes = 0;

  arg6.data = OPS_reduct_h + reduct_bytes;
  arg6.data_d = OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<12; d++) ((double *)arg6.data)[d+b*12] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*12*sizeof(double));


  mvReductArraysToDevice(reduct_bytes);
  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;

  char *p_a[7];

  //set up initial pointers
  int d_m[OPS_MAX_DIM];
  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d];
  #endif //OPS_MPI
  int base0 = dat0 * 1 * 
  (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - d_m[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1] - args[0].dat->base[1] - d_m[1]);
  p_a[0] = (char *)args[0].data_d + base0;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d];
  #endif //OPS_MPI
  int base1 = dat1 * 1 * 
  (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - d_m[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1] - args[1].dat->base[1] - d_m[1]);
  p_a[1] = (char *)args[1].data_d + base1;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d];
  #endif //OPS_MPI
  int base2 = dat2 * 1 * 
  (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - d_m[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1] - args[2].dat->base[1] - d_m[1]);
  p_a[2] = (char *)args[2].data_d + base2;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d] + OPS_sub_dat_list[args[3].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d];
  #endif //OPS_MPI
  int base3 = dat3 * 1 * 
  (start[0] * args[3].stencil->stride[0] - args[3].dat->base[0] - d_m[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1] - args[3].dat->base[1] - d_m[1]);
  p_a[3] = (char *)args[3].data_d + base3;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d] + OPS_sub_dat_list[args[4].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d];
  #endif //OPS_MPI
  int base4 = dat4 * 1 * 
  (start[0] * args[4].stencil->stride[0] - args[4].dat->base[0] - d_m[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1] - args[4].dat->base[1] - d_m[1]);
  p_a[4] = (char *)args[4].data_d + base4;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d] + OPS_sub_dat_list[args[5].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d];
  #endif //OPS_MPI
  int base5 = dat5 * 1 * 
  (start[0] * args[5].stencil->stride[0] - args[5].dat->base[0] - d_m[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1] - args[5].dat->base[1] - d_m[1]);
  p_a[5] = (char *)args[5].data_d + base5;


  ops_H_D_exchanges_device(args, 7);
  ops_halo_exchanges(args,7,range);

  ops_timers_core(&c1,&t1);
  OPS_kernels[30].mpi_time += t1-t2;

  int nshared = 0;
  int nthread = OPS_block_size_x*OPS_block_size_y;

  nshared = MAX(nshared,sizeof(double)*12);

  nshared = MAX(nshared*nthread,reduct_size*nthread);

  //call kernel wrapper function, passing in pointers to data
  ops_calc_dt_kernel_print<<<grid, tblock, nshared >>> (  (double *)p_a[0], (double *)p_a[1],
           (double *)p_a[2], (double *)p_a[3],
           (double *)p_a[4], (double *)p_a[5],
           (double *)arg6.data_d,x_size, y_size);

  mvReductArraysToHost(reduct_bytes);
  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<12; d++ ){
      arg6h[d] = arg6h[d] + ((double *)arg6.data)[d+b*12];
    }
  }
  arg6.data = (char *)arg6h;

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
  }
  ops_timers_core(&c2,&t2);
  OPS_kernels[30].time += t2-t1;
  ops_set_dirtybit_device(args, 7);

  //Update kernel record
  OPS_kernels[30].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[30].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[30].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[30].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[30].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[30].transfer += ops_compute_transfer(dim, range, &arg5);
}
