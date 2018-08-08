//
// auto-generated by ops.py
//
__constant__ int xdim0_update_halo_kernel5_minus_4_front;
int xdim0_update_halo_kernel5_minus_4_front_h = -1;
__constant__ int ydim0_update_halo_kernel5_minus_4_front;
int ydim0_update_halo_kernel5_minus_4_front_h = -1;
__constant__ int xdim1_update_halo_kernel5_minus_4_front;
int xdim1_update_halo_kernel5_minus_4_front_h = -1;
__constant__ int ydim1_update_halo_kernel5_minus_4_front;
int ydim1_update_halo_kernel5_minus_4_front_h = -1;

#undef OPS_ACC0
#undef OPS_ACC1


#define OPS_ACC0(x,y,z) (x+xdim0_update_halo_kernel5_minus_4_front*(y)+xdim0_update_halo_kernel5_minus_4_front*ydim0_update_halo_kernel5_minus_4_front*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_update_halo_kernel5_minus_4_front*(y)+xdim1_update_halo_kernel5_minus_4_front*ydim1_update_halo_kernel5_minus_4_front*(z))

//user function
__device__

inline void update_halo_kernel5_minus_4_front_gpu(double *vol_flux_z, double *mass_flux_z, const int* fields) {
  if((*fields) & FIELD_VOL_FLUX_Z)  vol_flux_z[OPS_ACC0(0,0,0)]  = -vol_flux_z[OPS_ACC0(0,0,-4)];
  if((*fields) & FIELD_MASS_FLUX_Z) mass_flux_z[OPS_ACC1(0,0,0)] = -mass_flux_z[OPS_ACC1(0,0,-4)];
}



#undef OPS_ACC0
#undef OPS_ACC1


__global__ void ops_update_halo_kernel5_minus_4_front(
double* __restrict arg0,
double* __restrict arg1,
const int arg2,
int size0,
int size1,
int size2 ){


  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * xdim0_update_halo_kernel5_minus_4_front + idx_z * 1*1 * xdim0_update_halo_kernel5_minus_4_front * ydim0_update_halo_kernel5_minus_4_front;
  arg1 += idx_x * 1*1 + idx_y * 1*1 * xdim1_update_halo_kernel5_minus_4_front + idx_z * 1*1 * xdim1_update_halo_kernel5_minus_4_front * ydim1_update_halo_kernel5_minus_4_front;

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    update_halo_kernel5_minus_4_front_gpu(arg0, arg1, &arg2);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_update_halo_kernel5_minus_4_front(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
#else
#ifdef OPS_HYBRID
void ops_par_loop_update_halo_kernel5_minus_4_front_execute_gpu(ops_kernel_descriptor *desc) {
#else
void ops_par_loop_update_halo_kernel5_minus_4_front_execute(ops_kernel_descriptor *desc) {
#endif
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[3] = { arg0, arg1, arg2};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,3,range,139)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(139,"update_halo_kernel5_minus_4_front");
    OPS_kernels[139].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<3; n++ ){
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
  #else
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];

  if (xdim0 != xdim0_update_halo_kernel5_minus_4_front_h || ydim0 != ydim0_update_halo_kernel5_minus_4_front_h || xdim1 != xdim1_update_halo_kernel5_minus_4_front_h || ydim1 != ydim1_update_halo_kernel5_minus_4_front_h) {
    cudaMemcpyToSymbolAsync( xdim0_update_halo_kernel5_minus_4_front, &xdim0, sizeof(int),0 );
    xdim0_update_halo_kernel5_minus_4_front_h = xdim0;
    cudaMemcpyToSymbolAsync( ydim0_update_halo_kernel5_minus_4_front, &ydim0, sizeof(int),0 );
    ydim0_update_halo_kernel5_minus_4_front_h = ydim0;
    cudaMemcpyToSymbolAsync( xdim1_update_halo_kernel5_minus_4_front, &xdim1, sizeof(int),0 );
    xdim1_update_halo_kernel5_minus_4_front_h = xdim1;
    cudaMemcpyToSymbolAsync( ydim1_update_halo_kernel5_minus_4_front, &ydim1, sizeof(int),0 );
    ydim1_update_halo_kernel5_minus_4_front_h = ydim1;
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, z_size);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);

  char *p_a[3];

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


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 3);
  ops_halo_exchanges(args,3,range);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[139].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  ops_update_halo_kernel5_minus_4_front<<<grid, tblock >>> (  (double *)p_a[0], (double *)p_a[1],
           *(int *)arg2.data,x_size, y_size, z_size);

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_kernels[139].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 3);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[139].mpi_time += t2-t1;
    OPS_kernels[139].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[139].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}

#ifdef OPS_HYBRID
void ops_par_loop_update_halo_kernel5_minus_4_front_execute_cpu(ops_kernel_descriptor *desc);
void ops_par_loop_update_halo_kernel5_minus_4_front_execute(ops_kernel_descriptor *desc) {
  if (desc->device == 1) {
    ops_par_loop_update_halo_kernel5_minus_4_front_execute_gpu(desc);
  }
  else {
    ops_par_loop_update_halo_kernel5_minus_4_front_execute_cpu(desc);
  }
}
#endif


#ifdef OPS_LAZY
void ops_par_loop_update_halo_kernel5_minus_4_front(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 139;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 139;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 3;
  desc->args = (ops_arg*)malloc(3*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  char *tmp = (char*)malloc(1*sizeof(int));
  memcpy(tmp, arg2.data,1*sizeof(int));
  desc->args[2].data = tmp;
  desc->function = ops_par_loop_update_halo_kernel5_minus_4_front_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(139,"update_halo_kernel5_minus_4_front");
  }
  ops_enqueue_kernel(desc);
}
#endif
