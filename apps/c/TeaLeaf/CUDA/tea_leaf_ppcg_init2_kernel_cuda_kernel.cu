//
// auto-generated by ops.py
//
__constant__ int dims_tea_leaf_ppcg_init2_kernel [5][1];
static int dims_tea_leaf_ppcg_init2_kernel_h [5][1] = {0};

//user function
__device__

void tea_leaf_ppcg_init2_kernel_gpu(ACC<double> &sd,
  ACC<double> &rtemp,
  ACC<double> &utemp,
  const ACC<double> &r,
  const double *theta_r) {
	sd(0,0) = r(0,0)*(*theta_r);
	rtemp(0,0) = r(0,0);
	utemp(0,0) = sd(0,0);
}



__global__ void ops_tea_leaf_ppcg_init2_kernel(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
const double arg4,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * dims_tea_leaf_ppcg_init2_kernel[0][0];
  arg1 += idx_x * 1*1 + idx_y * 1*1 * dims_tea_leaf_ppcg_init2_kernel[1][0];
  arg2 += idx_x * 1*1 + idx_y * 1*1 * dims_tea_leaf_ppcg_init2_kernel[2][0];
  arg3 += idx_x * 1*1 + idx_y * 1*1 * dims_tea_leaf_ppcg_init2_kernel[3][0];

  if (idx_x < size0 && idx_y < size1) {
    ACC<double> argp0(dims_tea_leaf_ppcg_init2_kernel[0][0], arg0);
    ACC<double> argp1(dims_tea_leaf_ppcg_init2_kernel[1][0], arg1);
    ACC<double> argp2(dims_tea_leaf_ppcg_init2_kernel[2][0], arg2);
    const ACC<double> argp3(dims_tea_leaf_ppcg_init2_kernel[3][0], arg3);
    tea_leaf_ppcg_init2_kernel_gpu(argp0,
                   argp1,
                   argp2,
                   argp3,
                   &arg4);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_tea_leaf_ppcg_init2_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
#else
void ops_par_loop_tea_leaf_ppcg_init2_kernel_execute(ops_kernel_descriptor *desc) {
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
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,5,range,44)) return;
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(44,"tea_leaf_ppcg_init2_kernel");
    OPS_instance::getOPSInstance()->OPS_kernels[44].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  #ifdef OPS_MPI
  int arg_idx[2];
  #endif
  #ifdef OPS_MPI
  #ifdef OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = sb->decomp_disp[n]+start[n];
  }
  #else
  if (compute_ranges(args, 5,block, range, start, end, arg_idx) < 0) return;
  #endif
  #else
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];

  if (xdim0 != dims_tea_leaf_ppcg_init2_kernel_h[0][0] || xdim1 != dims_tea_leaf_ppcg_init2_kernel_h[1][0] || xdim2 != dims_tea_leaf_ppcg_init2_kernel_h[2][0] || xdim3 != dims_tea_leaf_ppcg_init2_kernel_h[3][0]) {
    dims_tea_leaf_ppcg_init2_kernel_h[0][0] = xdim0;
    dims_tea_leaf_ppcg_init2_kernel_h[1][0] = xdim1;
    dims_tea_leaf_ppcg_init2_kernel_h[2][0] = xdim2;
    dims_tea_leaf_ppcg_init2_kernel_h[3][0] = xdim3;
    cutilSafeCall(cudaMemcpyToSymbol( dims_tea_leaf_ppcg_init2_kernel, dims_tea_leaf_ppcg_init2_kernel_h, sizeof(dims_tea_leaf_ppcg_init2_kernel)));
  }



  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  dim3 grid( (x_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_x+ 1, (y_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_instance::getOPSInstance()->OPS_block_size_x,OPS_instance::getOPSInstance()->OPS_block_size_y,OPS_instance::getOPSInstance()->OPS_block_size_z);



  int dat0 = (OPS_instance::getOPSInstance()->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_instance::getOPSInstance()->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (OPS_instance::getOPSInstance()->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int dat3 = (OPS_instance::getOPSInstance()->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);

  char *p_a[5];

  //set up initial pointers
  int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1]);
  p_a[0] = (char *)args[0].data_d + base0;

  int base1 = args[1].dat->base_offset + 
           dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1]);
  p_a[1] = (char *)args[1].data_d + base1;

  int base2 = args[2].dat->base_offset + 
           dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1]);
  p_a[2] = (char *)args[2].data_d + base2;

  int base3 = args[3].dat->base_offset + 
           dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1]);
  p_a[3] = (char *)args[3].data_d + base3;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 5);
  ops_halo_exchanges(args,5,range);
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_instance::getOPSInstance()->OPS_kernels[44].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    ops_tea_leaf_ppcg_init2_kernel<<<grid, tblock >>> (  (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2], (double *)p_a[3],
         *(double *)arg4.data,x_size, y_size);

  cutilSafeCall(cudaGetLastError());

  if (OPS_instance::getOPSInstance()->OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_instance::getOPSInstance()->OPS_kernels[44].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 5);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[2],range);
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_instance::getOPSInstance()->OPS_kernels[44].mpi_time += t2-t1;
    OPS_instance::getOPSInstance()->OPS_kernels[44].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_instance::getOPSInstance()->OPS_kernels[44].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_instance::getOPSInstance()->OPS_kernels[44].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_instance::getOPSInstance()->OPS_kernels[44].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_tea_leaf_ppcg_init2_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 44;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 44;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 5;
  desc->args = (ops_arg*)malloc(5*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  char *tmp = (char*)malloc(1*sizeof(double));
  memcpy(tmp, arg4.data,1*sizeof(double));
  desc->args[4].data = tmp;
  desc->function = ops_par_loop_tea_leaf_ppcg_init2_kernel_execute;
  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(44,"tea_leaf_ppcg_init2_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
