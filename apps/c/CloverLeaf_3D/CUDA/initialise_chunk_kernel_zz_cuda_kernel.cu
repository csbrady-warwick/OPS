//
// auto-generated by ops.py
//
__constant__ int xdim0_initialise_chunk_kernel_zz;
int xdim0_initialise_chunk_kernel_zz_h = -1;
__constant__ int ydim0_initialise_chunk_kernel_zz;
int ydim0_initialise_chunk_kernel_zz_h = -1;

#undef OPS_ACC0


#define OPS_ACC0(x,y,z) (x+xdim0_initialise_chunk_kernel_zz*(y)+xdim0_initialise_chunk_kernel_zz*ydim0_initialise_chunk_kernel_zz*(z))

//user function
__device__

void initialise_chunk_kernel_zz_gpu(int *zz, int *idx) {
  zz[OPS_ACC0(0,0,0)] = idx[2]-2;
}



#undef OPS_ACC0


__global__ void ops_initialise_chunk_kernel_zz(
int* __restrict arg0,
int arg_idx0, int arg_idx1, int arg_idx2,
int size0,
int size1,
int size2 ){


  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  int arg_idx[3];
  arg_idx[0] = arg_idx0+idx_x;
  arg_idx[1] = arg_idx1+idx_y;
  arg_idx[2] = arg_idx2+idx_z;
  arg0 += idx_x * 0*1 + idx_y * 0*1 * xdim0_initialise_chunk_kernel_zz + idx_z * 1*1 * xdim0_initialise_chunk_kernel_zz * ydim0_initialise_chunk_kernel_zz;

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    initialise_chunk_kernel_zz_gpu(arg0, arg_idx);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_zz(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
#else
#ifdef OPS_HYBRID
void ops_par_loop_initialise_chunk_kernel_zz_execute_gpu(ops_kernel_descriptor *desc) {
#else
void ops_par_loop_initialise_chunk_kernel_zz_execute(ops_kernel_descriptor *desc) {
#endif
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[2] = { arg0, arg1};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,2,range,48)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(48,"initialise_chunk_kernel_zz");
    OPS_kernels[48].count++;
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

  int arg_idx[3];
  #ifdef OPS_MPI
  #ifdef OPS_LAZY
  ops_block block = desc->block;
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif
  arg_idx[0] = sb->decomp_disp[0]+start[0];
  arg_idx[1] = sb->decomp_disp[1]+start[1];
  arg_idx[2] = sb->decomp_disp[2]+start[2];
  #else
  arg_idx[0] = start[0];
  arg_idx[1] = start[1];
  arg_idx[2] = start[2];
  #endif
  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];

  if (xdim0 != xdim0_initialise_chunk_kernel_zz_h || ydim0 != ydim0_initialise_chunk_kernel_zz_h) {
    cudaMemcpyToSymbolAsync( xdim0_initialise_chunk_kernel_zz, &xdim0, sizeof(int),0 );
    xdim0_initialise_chunk_kernel_zz_h = xdim0;
    cudaMemcpyToSymbolAsync( ydim0_initialise_chunk_kernel_zz, &ydim0, sizeof(int),0 );
    ydim0_initialise_chunk_kernel_zz_h = ydim0;
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, z_size);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);

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

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[48].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  ops_initialise_chunk_kernel_zz<<<grid, tblock >>> (  (int *)p_a[0], arg_idx[0], arg_idx[1], arg_idx[2],x_size, y_size, z_size);

  if (OPS_diags>1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    OPS_kernels[48].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 2);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[48].mpi_time += t2-t1;
    OPS_kernels[48].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}

#ifdef OPS_HYBRID
void ops_par_loop_initialise_chunk_kernel_zz_execute_cpu(ops_kernel_descriptor *desc);
void ops_par_loop_initialise_chunk_kernel_zz_execute(ops_kernel_descriptor *desc) {
  if (desc->device == 1) {
    ops_par_loop_initialise_chunk_kernel_zz_execute_gpu(desc);
  }
  else {
    ops_par_loop_initialise_chunk_kernel_zz_execute_cpu(desc);
  }
}
#endif


#ifdef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_zz(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 48;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 48;
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
  desc->function = ops_par_loop_initialise_chunk_kernel_zz_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(48,"initialise_chunk_kernel_zz");
  }
  ops_enqueue_kernel(desc);
}
#endif
