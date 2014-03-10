//
// auto-generated by ops.py on 2014-03-10 12:53
//

__constant__ int xdim0_advec_mom_kernel_mass_flux_y;
__constant__ int xdim1_advec_mom_kernel_mass_flux_y;

#define OPS_ACC0(x,y) (x+xdim0_advec_mom_kernel_mass_flux_y*(y))
#define OPS_ACC1(x,y) (x+xdim1_advec_mom_kernel_mass_flux_y*(y))

//user function
__device__

inline void advec_mom_kernel_mass_flux_y( double *node_flux, const double *mass_flux_y) {


  node_flux[OPS_ACC0(0,0)] = 0.25 * ( mass_flux_y[OPS_ACC1(-1,0)] + mass_flux_y[OPS_ACC1(0,0)] +
      mass_flux_y[OPS_ACC1(-1,1)] + mass_flux_y[OPS_ACC1(0,1)] );
}



#undef OPS_ACC0
#undef OPS_ACC1


__global__ void ops_advec_mom_kernel_mass_flux_y(
double* __restrict arg0,
const double* __restrict arg1,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 + idx_y * 1 * xdim0_advec_mom_kernel_mass_flux_y;
  arg1 += idx_x * 1 + idx_y * 1 * xdim1_advec_mom_kernel_mass_flux_y;

  if (idx_x < size0 && idx_y < size1) {
    advec_mom_kernel_mass_flux_y(arg0, arg1);
  }

}

// host stub function
void ops_par_loop_advec_mom_kernel_mass_flux_y(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {

  ops_arg args[2] = { arg0, arg1};

  sub_block_list sb = OPS_sub_block_list[Block->index];
  //compute localy allocated range for the sub-block
  int ndim = sb->ndim;
  int start_add[ndim*2];

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

  for ( int i=0; i<2; i++ ){
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
  ops_timing_realloc(24,"advec_mom_kernel_mass_flux_y");
  ops_timers_core(&c1,&t1);

  if (OPS_kernels[24].count == 0) {
    cudaMemcpyToSymbol( xdim0_advec_mom_kernel_mass_flux_y, &xdim0, sizeof(int) );
    cudaMemcpyToSymbol( xdim1_advec_mom_kernel_mass_flux_y, &xdim1, sizeof(int) );
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 block(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = args[0].dat->size;
  int dat1 = args[1].dat->size;

  char *p_a[2];

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


  ops_H_D_exchanges_cuda(args, 2);


  //call kernel wrapper function, passing in pointers to data
  ops_advec_mom_kernel_mass_flux_y<<<grid, block >>> (  (double *)p_a[0], (double *)p_a[1],x_size, y_size);

  if (OPS_diags>1) cutilSafeCall(cudaDeviceSynchronize());
  ops_set_dirtybit_cuda(args, 2);

  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[24].count++;
  OPS_kernels[24].time += t2-t1;
  OPS_kernels[24].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[24].transfer += ops_compute_transfer(dim, range, &arg1);
}
