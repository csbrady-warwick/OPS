//
// auto-generated by ops.py on 2014-03-07 11:24
//

__constant__ int xdim0_advec_mom_kernel_x2;
__constant__ int xdim1_advec_mom_kernel_x2;
__constant__ int xdim2_advec_mom_kernel_x2;
__constant__ int xdim3_advec_mom_kernel_x2;

#define OPS_ACC0(x,y) (x+xdim0_advec_mom_kernel_x2*(y))
#define OPS_ACC1(x,y) (x+xdim1_advec_mom_kernel_x2*(y))
#define OPS_ACC2(x,y) (x+xdim2_advec_mom_kernel_x2*(y))
#define OPS_ACC3(x,y) (x+xdim3_advec_mom_kernel_x2*(y))

//user function
__device__

inline void advec_mom_kernel_x2( double *pre_vol, double *post_vol,
                          const double *volume,
                          const double *vol_flux_y) {

  post_vol[OPS_ACC1(0,0)]  = volume[OPS_ACC2(0,0)] ;
  pre_vol[OPS_ACC0(0,0)]   = post_vol[OPS_ACC1(0,0)]  + vol_flux_y[OPS_ACC3(0,1)] - vol_flux_y[OPS_ACC3(0,0)];

}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3


__global__ void ops_advec_mom_kernel_x2(
double* __restrict arg0,
double* __restrict arg1,
const double* __restrict arg2,
const double* __restrict arg3,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 + idx_y * 1 * xdim0_advec_mom_kernel_x2;
  arg1 += idx_x * 1 + idx_y * 1 * xdim1_advec_mom_kernel_x2;
  arg2 += idx_x * 1 + idx_y * 1 * xdim2_advec_mom_kernel_x2;
  arg3 += idx_x * 1 + idx_y * 1 * xdim3_advec_mom_kernel_x2;

  if (idx_x < size0 && idx_y < size1) {
    advec_mom_kernel_x2(arg0, arg1, arg2, arg3);
  }

}

// host stub function
void ops_par_loop_advec_mom_kernel_x2(char const *name, ops_block Block, int dim, int* range,
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
  int xdim2 = args[2].dat->block_size[0];
  int xdim3 = args[3].dat->block_size[0];


  //Timing
  double t1,t2,c1,c2;
  ops_timing_realloc(18,"advec_mom_kernel_x2");
  ops_timers_core(&c1,&t1);

  if (OPS_kernels[18].count == 0) {
    cudaMemcpyToSymbol( xdim0_advec_mom_kernel_x2, &xdim0, sizeof(int) );
    cudaMemcpyToSymbol( xdim1_advec_mom_kernel_x2, &xdim1, sizeof(int) );
    cudaMemcpyToSymbol( xdim2_advec_mom_kernel_x2, &xdim2, sizeof(int) );
    cudaMemcpyToSymbol( xdim3_advec_mom_kernel_x2, &xdim3, sizeof(int) );
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 block(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = args[0].dat->size;
  int dat1 = args[1].dat->size;
  int dat2 = args[2].dat->size;
  int dat3 = args[3].dat->size;

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

  //set up initial pointers
  int base2 = dat2 * 1 * 
  (start_add[ndim+0] * args[2].stencil->stride[0] - args[2].dat->offset[0]);
  base2 = base2  + dat2 * args[2].dat->block_size[0] * 
  (start_add[ndim+1] * args[2].stencil->stride[1] - args[2].dat->offset[1]);
  p_a[2] = (char *)args[2].data_d + base2;

  //set up initial pointers
  int base3 = dat3 * 1 * 
  (start_add[ndim+0] * args[3].stencil->stride[0] - args[3].dat->offset[0]);
  base3 = base3  + dat3 * args[3].dat->block_size[0] * 
  (start_add[ndim+1] * args[3].stencil->stride[1] - args[3].dat->offset[1]);
  p_a[3] = (char *)args[3].data_d + base3;


  ops_H_D_exchanges_cuda(args, 4);


  //call kernel wrapper function, passing in pointers to data
  ops_advec_mom_kernel_x2<<<grid, block >>> (  (double *)p_a[0], (double *)p_a[1],
           (double *)p_a[2], (double *)p_a[3],x_size, y_size);

  if (OPS_diags>1) cudaDeviceSynchronize();
  ops_set_dirtybit_cuda(args, 4);

  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[18].count++;
  OPS_kernels[18].time += t2-t1;
  OPS_kernels[18].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[18].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[18].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[18].transfer += ops_compute_transfer(dim, range, &arg3);
}
