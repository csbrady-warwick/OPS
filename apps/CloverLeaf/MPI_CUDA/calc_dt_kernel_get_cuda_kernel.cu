//
// auto-generated by ops.py on 2014-03-07 11:24
//

__constant__ int xdim0_calc_dt_kernel_get;
__constant__ int xdim1_calc_dt_kernel_get;

#define OPS_ACC0(x,y) (x+xdim0_calc_dt_kernel_get*(y))
#define OPS_ACC1(x,y) (x+xdim1_calc_dt_kernel_get*(y))

//user function
__device__

void calc_dt_kernel_get(const double* cellx, const double* celly, double* xl_pos, double* yl_pos) {
  *xl_pos = cellx[OPS_ACC0(0,0)];
  *yl_pos = celly[OPS_ACC1(0,0)];
}



#undef OPS_ACC0
#undef OPS_ACC1


__global__ void ops_calc_dt_kernel_get(
const double* __restrict arg0,
const double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
int size0,
int size1 ){

  double arg2_l[1];
  double arg3_l[1];

  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 + idx_y * 0 * xdim0_calc_dt_kernel_get;
  arg1 += idx_x * 0 + idx_y * 1 * xdim1_calc_dt_kernel_get;

  if (idx_x < size0 && idx_y < size1) {
    calc_dt_kernel_get(arg0, arg1, arg2_l, arg3_l);
  }

}

// host stub function
void ops_par_loop_calc_dt_kernel_get(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {

  ops_arg args[4] = { arg0, arg1, arg2, arg3};

  sub_block_list sb = OPS_sub_block_list[Block->index];
  //compute localy allocated range for the sub-block
  int ndim = sb->ndim;
  int start_add[ndim*4];

  int s[ndim];
  int e[ndim];

  for ( int n=0; n<ndim; n++ ){
    s[n] = sb->istart[n];e[n] = sb->iend[n]+1;
    if (s[n] >= range[2*n]) {
      s[n] = 0;
    }
    else {
      s[n] = range[2*n] - s[n];
    }
    if (e[n] >= range[2*n+1]) {
      e[n] = range[2*n+1] - sb->istart[n];
    }
    else {
      e[n] = sb->sizes[n];
    }
  }

  for ( int i=0; i<4; i++ ){
    for ( int n=0; n<ndim; n++ ){
      start_add[i*ndim+n] = s[n];
    }
  }


  int x_size = e[0]-s[0];
  int y_size = e[1]-s[1];

  int xdim0 = args[0].dat->block_size[0];
  int xdim1 = args[1].dat->block_size[0];


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(30,"calc_dt_kernel_get");
  ops_timers_core(&c1,&t1);

  if (OPS_kernels[30].count == 0) {
    cudaMemcpyToSymbol( xdim0_calc_dt_kernel_get, &xdim0, sizeof(int) );
    cudaMemcpyToSymbol( xdim1_calc_dt_kernel_get, &xdim1, sizeof(int) );
  }


  double *arg2h = (double *)arg2.data;
  double *arg3h = (double *)arg3.data;

  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 block(OPS_block_size_x,OPS_block_size_y,1);

  int nblocks = ((x_size-1)/OPS_block_size_x+ 1)*((y_size-1)/OPS_block_size_y + 1);
  int maxblocks = nblocks;
  int reduct_bytes = 0;
  int reduct_size = 0;

  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));
  reduct_size = MAX(reduct_size,sizeof(double)*1);

  arg2.data = OPS_reduct_h + reduct_bytes;
  arg2.data_d = OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));

  arg3.data = OPS_reduct_h + reduct_bytes;
  arg3.data_d = OPS_reduct_d + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  reduct_bytes += ROUND_UP(maxblocks*1*sizeof(double));


  int dat0 = args[0].dat->size;
  int dat1 = args[1].dat->size;

  char *p_a[4];

  //set up initial pointers
  int base0 = dat0 * 1 * 
  (start_add[ndim+0] * args[0].stencil->stride[0] - args[0].dat->offset[0]);
  base0 = base0  + dat0 * args[0].dat->block_size[0] * 
  (start_add[ndim+1] * args[0].stencil->stride[1] - args[0].dat->offset[1]);
  p_a[0] = (char *)args[0].data_d + base0;

  //set up initial pointers
  int base1 = dat1 * 1 * 
  (start_add[ndim+0] * args[1].stencil->stride[0] - args[1].dat->offset[0]);
  base1 = base1  + dat1 * args[1].dat->block_size[0] * 
  (start_add[ndim+1] * args[1].stencil->stride[1] - args[1].dat->offset[1]);
  p_a[1] = (char *)args[1].data_d + base1;


  ops_H_D_exchanges_cuda(args, 4);

  int nshared = 0;
  int nthread = OPS_block_size_x*OPS_block_size_y;

  nshared = MAX(nshared,sizeof(double)*1);
  nshared = MAX(nshared,sizeof(double)*1);

  nshared = MAX(nshared*nthread,reduct_size*nthread);

  //call kernel wrapper function, passing in pointers to data
  ops_calc_dt_kernel_get<<<grid, block >>> (  (double *)p_a[0], (double *)p_a[1],
           (double *)arg2.data_d, (double *)arg3.data_d,x_size, y_size);

  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
    }
  }
  arg2.data = (char *)arg2h;

  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<1; d++ ){
    }
  }
  arg3.data = (char *)arg3h;

  if (OPS_diags>1) cudaDeviceSynchronize();
  ops_set_dirtybit_cuda(args, 4);

  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[30].count++;
  OPS_kernels[30].time += t2-t1;
  OPS_kernels[30].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[30].transfer += ops_compute_transfer(dim, range, &arg1);
}
