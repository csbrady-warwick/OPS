//
// auto-generated by ops.py
//
__constant__ int xdim0_tea_leaf_ppcg_reduce_kernel;
int xdim0_tea_leaf_ppcg_reduce_kernel_h = -1;
__constant__ int xdim1_tea_leaf_ppcg_reduce_kernel;
int xdim1_tea_leaf_ppcg_reduce_kernel_h = -1;
__constant__ int xdim2_tea_leaf_ppcg_reduce_kernel;
int xdim2_tea_leaf_ppcg_reduce_kernel_h = -1;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2

#define OPS_ACC0(x, y) (x + xdim0_tea_leaf_ppcg_reduce_kernel * (y))
#define OPS_ACC1(x, y) (x + xdim1_tea_leaf_ppcg_reduce_kernel * (y))
#define OPS_ACC2(x, y) (x + xdim2_tea_leaf_ppcg_reduce_kernel * (y))

// user function
__device__

    void
    tea_leaf_ppcg_reduce_kernel_gpu(const double *rstore, const double *r,
                                    const double *z, double *rnn) {
  *rnn =
      *rnn + (r[OPS_ACC1(0, 0)] - rstore[OPS_ACC0(0, 0)]) * z[OPS_ACC2(0, 0)];
}

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2

__global__ void ops_tea_leaf_ppcg_reduce_kernel(const double *__restrict arg0,
                                                const double *__restrict arg1,
                                                const double *__restrict arg2,
                                                double *__restrict arg3,
                                                int size0, int size1) {

  double arg3_l[1];
  for (int d = 0; d < 1; d++)
    arg3_l[d] = ZERO_double;

  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim0_tea_leaf_ppcg_reduce_kernel;
  arg1 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim1_tea_leaf_ppcg_reduce_kernel;
  arg2 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim2_tea_leaf_ppcg_reduce_kernel;

  if (idx_x < size0 && idx_y < size1) {
    tea_leaf_ppcg_reduce_kernel_gpu(arg0, arg1, arg2, arg3_l);
  }
  for (int d = 0; d < 1; d++)
    ops_reduction_cuda<OPS_INC>(
        &arg3[d + (blockIdx.x + blockIdx.y * gridDim.x) * 1], arg3_l[d]);
}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_tea_leaf_ppcg_reduce_kernel(char const *name, ops_block block,
                                              int dim, int *range, ops_arg arg0,
                                              ops_arg arg1, ops_arg arg2,
                                              ops_arg arg3) {
#else
void ops_par_loop_tea_leaf_ppcg_reduce_kernel_execute(
    ops_kernel_descriptor *desc) {
  int dim = desc->dim;
#if OPS_MPI
  ops_block block = desc->block;
#endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
#endif

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[4] = {arg0, arg1, arg2, arg3};

#if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args, 4, range, 48))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(48, "tea_leaf_ppcg_reduce_kernel");
    OPS_kernels[48].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];
#if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
#endif // OPS_MPI

  int arg_idx[2];
  int arg_idx_base[2];
#ifdef OPS_MPI
  if (compute_ranges(args, 4, block, range, start, end, arg_idx) < 0)
    return;
#else // OPS_MPI
  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
    arg_idx[n] = start[n];
  }
#endif
  for (int n = 0; n < 2; n++) {
    arg_idx_base[n] = arg_idx[n];
  }
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];

  if (xdim0 != xdim0_tea_leaf_ppcg_reduce_kernel_h ||
      xdim1 != xdim1_tea_leaf_ppcg_reduce_kernel_h ||
      xdim2 != xdim2_tea_leaf_ppcg_reduce_kernel_h) {
    cudaMemcpyToSymbol(xdim0_tea_leaf_ppcg_reduce_kernel, &xdim0, sizeof(int));
    xdim0_tea_leaf_ppcg_reduce_kernel_h = xdim0;
    cudaMemcpyToSymbol(xdim1_tea_leaf_ppcg_reduce_kernel, &xdim1, sizeof(int));
    xdim1_tea_leaf_ppcg_reduce_kernel_h = xdim1;
    cudaMemcpyToSymbol(xdim2_tea_leaf_ppcg_reduce_kernel, &xdim2, sizeof(int));
    xdim2_tea_leaf_ppcg_reduce_kernel_h = xdim2;
  }

#if defined(OPS_LAZY) && !defined(OPS_MPI)
  ops_block block = desc->block;
#endif
#ifdef OPS_MPI
  double *arg3h =
      (double *)(((ops_reduction)args[3].data)->data +
                 ((ops_reduction)args[3].data)->size * block->index);
#else
  double *arg3h = (double *)(((ops_reduction)args[3].data)->data);
#endif

  int x_size = MAX(0, end[0] - start[0]);
  int y_size = MAX(0, end[1] - start[1]);

  dim3 grid((x_size - 1) / OPS_block_size_x + 1,
            (y_size - 1) / OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_block_size_x, OPS_block_size_y, OPS_block_size_z);

  int nblocks = ((x_size - 1) / OPS_block_size_x + 1) *
                ((y_size - 1) / OPS_block_size_y + 1);
  int maxblocks = nblocks;
  int reduct_bytes = 0;
  int reduct_size = 0;

  reduct_bytes += ROUND_UP(maxblocks * 1 * sizeof(double));
  reduct_size = MAX(reduct_size, sizeof(double) * 1);

  reallocReductArrays(reduct_bytes);
  reduct_bytes = 0;

  arg3.data = OPS_reduct_h + reduct_bytes;
  arg3.data_d = OPS_reduct_d + reduct_bytes;
  for (int b = 0; b < maxblocks; b++)
    for (int d = 0; d < 1; d++)
      ((double *)arg3.data)[d + b * 1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks * 1 * sizeof(double));

  mvReductArraysToDevice(reduct_bytes);
  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);

  char *p_a[4];

  // set up initial pointers
  int base0 = args[0].dat->base_offset +
              dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0 +
          dat0 * args[0].dat->size[0] * (start[1] * args[0].stencil->stride[1]);
  p_a[0] = (char *)args[0].data_d + base0;

  int base1 = args[1].dat->base_offset +
              dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  base1 = base1 +
          dat1 * args[1].dat->size[0] * (start[1] * args[1].stencil->stride[1]);
  p_a[1] = (char *)args[1].data_d + base1;

  int base2 = args[2].dat->base_offset +
              dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  base2 = base2 +
          dat2 * args[2].dat->size[0] * (start[1] * args[2].stencil->stride[1]);
  p_a[2] = (char *)args[2].data_d + base2;

#ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 4);
  ops_halo_exchanges(args, 4, range);
#endif

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[48].mpi_time += t2 - t1;
  }

  int nshared = 0;
  int nthread = OPS_block_size_x * OPS_block_size_y * OPS_block_size_z;

  nshared = MAX(nshared, sizeof(double) * 1);

  nshared = MAX(nshared * nthread, reduct_size * nthread);

  // call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    ops_tea_leaf_ppcg_reduce_kernel<<<grid, tblock, nshared>>>(
        (double *)p_a[0], (double *)p_a[1], (double *)p_a[2],
        (double *)arg3.data_d, x_size, y_size);

  cutilSafeCall(cudaGetLastError());

  mvReductArraysToHost(reduct_bytes);
  for (int b = 0; b < maxblocks; b++) {
    for (int d = 0; d < 1; d++) {
      arg3h[d] = arg3h[d] + ((double *)arg3.data)[d + b * 1];
    }
  }
  arg3.data = (char *)arg3h;

  if (OPS_diags > 1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1, &t1);
    OPS_kernels[48].time += t1 - t2;
  }

#ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 4);
#endif

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[48].mpi_time += t2 - t1;
    OPS_kernels[48].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[48].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[48].transfer += ops_compute_transfer(dim, start, end, &arg2);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_tea_leaf_ppcg_reduce_kernel(char const *name, ops_block block,
                                              int dim, int *range, ops_arg arg0,
                                              ops_arg arg1, ops_arg arg2,
                                              ops_arg arg3) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 48;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 48;
  for (int i = 0; i < 4; i++) {
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 4;
  desc->args = (ops_arg *)malloc(4 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->function = ops_par_loop_tea_leaf_ppcg_reduce_kernel_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(48, "tea_leaf_ppcg_reduce_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
