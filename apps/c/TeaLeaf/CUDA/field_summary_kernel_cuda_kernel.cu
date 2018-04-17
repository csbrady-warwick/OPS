//
// auto-generated by ops.py
//
__constant__ int xdim0_field_summary_kernel;
int xdim0_field_summary_kernel_h = -1;
__constant__ int xdim1_field_summary_kernel;
int xdim1_field_summary_kernel_h = -1;
__constant__ int xdim2_field_summary_kernel;
int xdim2_field_summary_kernel_h = -1;
__constant__ int xdim3_field_summary_kernel;
int xdim3_field_summary_kernel_h = -1;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

#define OPS_ACC0(x, y) (x + xdim0_field_summary_kernel * (y))
#define OPS_ACC1(x, y) (x + xdim1_field_summary_kernel * (y))
#define OPS_ACC2(x, y) (x + xdim2_field_summary_kernel * (y))
#define OPS_ACC3(x, y) (x + xdim3_field_summary_kernel * (y))

// user function
__device__

    void
    field_summary_kernel_gpu(const double *volume, const double *density,
                             const double *energy, const double *u, double *vol,
                             double *mass, double *ie, double *temp) {

  double cell_vol, cell_mass;

  cell_vol = volume[OPS_ACC0(0, 0)];
  cell_mass = cell_vol * density[OPS_ACC1(0, 0)];
  *vol = *vol + cell_vol;
  *mass = *mass + cell_mass;
  *ie = *ie + cell_mass * energy[OPS_ACC2(0, 0)];
  *temp = *temp + cell_mass * u[OPS_ACC3(0, 0)];
}

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

__global__ void ops_field_summary_kernel(
    const double *__restrict arg0, const double *__restrict arg1,
    const double *__restrict arg2, const double *__restrict arg3,
    double *__restrict arg4, double *__restrict arg5, double *__restrict arg6,
    double *__restrict arg7, int size0, int size1) {

  double arg4_l[1];
  double arg5_l[1];
  double arg6_l[1];
  double arg7_l[1];
  for (int d = 0; d < 1; d++)
    arg4_l[d] = ZERO_double;
  for (int d = 0; d < 1; d++)
    arg5_l[d] = ZERO_double;
  for (int d = 0; d < 1; d++)
    arg6_l[d] = ZERO_double;
  for (int d = 0; d < 1; d++)
    arg7_l[d] = ZERO_double;

  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim0_field_summary_kernel;
  arg1 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim1_field_summary_kernel;
  arg2 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim2_field_summary_kernel;
  arg3 += idx_x * 1 * 1 + idx_y * 1 * 1 * xdim3_field_summary_kernel;

  if (idx_x < size0 && idx_y < size1) {
    field_summary_kernel_gpu(arg0, arg1, arg2, arg3, arg4_l, arg5_l, arg6_l,
                             arg7_l);
  }
  for (int d = 0; d < 1; d++)
    ops_reduction_cuda<OPS_INC>(
        &arg4[d + (blockIdx.x + blockIdx.y * gridDim.x) * 1], arg4_l[d]);
  for (int d = 0; d < 1; d++)
    ops_reduction_cuda<OPS_INC>(
        &arg5[d + (blockIdx.x + blockIdx.y * gridDim.x) * 1], arg5_l[d]);
  for (int d = 0; d < 1; d++)
    ops_reduction_cuda<OPS_INC>(
        &arg6[d + (blockIdx.x + blockIdx.y * gridDim.x) * 1], arg6_l[d]);
  for (int d = 0; d < 1; d++)
    ops_reduction_cuda<OPS_INC>(
        &arg7[d + (blockIdx.x + blockIdx.y * gridDim.x) * 1], arg7_l[d]);
}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_field_summary_kernel(char const *name, ops_block block,
                                       int dim, int *range, ops_arg arg0,
                                       ops_arg arg1, ops_arg arg2, ops_arg arg3,
                                       ops_arg arg4, ops_arg arg5, ops_arg arg6,
                                       ops_arg arg7) {
#else
void ops_par_loop_field_summary_kernel_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
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

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[8] = {arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};

#if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args, 8, range, 0))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(0, "field_summary_kernel");
    OPS_kernels[0].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];
#if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 2; n++) {
    start[n] = sb->decomp_disp[n];
    end[n] = sb->decomp_disp[n] + sb->decomp_size[n];
    if (start[n] >= range[2 * n]) {
      start[n] = 0;
    } else {
      start[n] = range[2 * n] - start[n];
    }
    if (sb->id_m[n] == MPI_PROC_NULL && range[2 * n] < 0)
      start[n] = range[2 * n];
    if (end[n] >= range[2 * n + 1]) {
      end[n] = range[2 * n + 1] - sb->decomp_disp[n];
    } else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n] == MPI_PROC_NULL &&
        (range[2 * n + 1] > sb->decomp_disp[n] + sb->decomp_size[n]))
      end[n] += (range[2 * n + 1] - sb->decomp_disp[n] - sb->decomp_size[n]);
  }
#else
  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#endif

  int x_size = MAX(0, end[0] - start[0]);
  int y_size = MAX(0, end[1] - start[1]);

  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];

  if (xdim0 != xdim0_field_summary_kernel_h ||
      xdim1 != xdim1_field_summary_kernel_h ||
      xdim2 != xdim2_field_summary_kernel_h ||
      xdim3 != xdim3_field_summary_kernel_h) {
    cudaMemcpyToSymbol(xdim0_field_summary_kernel, &xdim0, sizeof(int));
    xdim0_field_summary_kernel_h = xdim0;
    cudaMemcpyToSymbol(xdim1_field_summary_kernel, &xdim1, sizeof(int));
    xdim1_field_summary_kernel_h = xdim1;
    cudaMemcpyToSymbol(xdim2_field_summary_kernel, &xdim2, sizeof(int));
    xdim2_field_summary_kernel_h = xdim2;
    cudaMemcpyToSymbol(xdim3_field_summary_kernel, &xdim3, sizeof(int));
    xdim3_field_summary_kernel_h = xdim3;
  }

#ifdef OPS_LAZY
  ops_block block = desc->block;
#endif
#ifdef OPS_MPI
  double *arg4h =
      (double *)(((ops_reduction)args[4].data)->data +
                 ((ops_reduction)args[4].data)->size * block->index);
#else
  double *arg4h = (double *)(((ops_reduction)args[4].data)->data);
#endif
#ifdef OPS_MPI
  double *arg5h =
      (double *)(((ops_reduction)args[5].data)->data +
                 ((ops_reduction)args[5].data)->size * block->index);
#else
  double *arg5h = (double *)(((ops_reduction)args[5].data)->data);
#endif
#ifdef OPS_MPI
  double *arg6h =
      (double *)(((ops_reduction)args[6].data)->data +
                 ((ops_reduction)args[6].data)->size * block->index);
#else
  double *arg6h = (double *)(((ops_reduction)args[6].data)->data);
#endif
#ifdef OPS_MPI
  double *arg7h =
      (double *)(((ops_reduction)args[7].data)->data +
                 ((ops_reduction)args[7].data)->size * block->index);
#else
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data);
#endif

  dim3 grid((x_size - 1) / OPS_block_size_x + 1,
            (y_size - 1) / OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_block_size_x, OPS_block_size_y, 1);

  int nblocks = ((x_size - 1) / OPS_block_size_x + 1) *
                ((y_size - 1) / OPS_block_size_y + 1);
  int maxblocks = nblocks;
  int reduct_bytes = 0;
  int reduct_size = 0;

  reduct_bytes += ROUND_UP(maxblocks * 1 * sizeof(double));
  reduct_size = MAX(reduct_size, sizeof(double) * 1);
  reduct_bytes += ROUND_UP(maxblocks * 1 * sizeof(double));
  reduct_size = MAX(reduct_size, sizeof(double) * 1);
  reduct_bytes += ROUND_UP(maxblocks * 1 * sizeof(double));
  reduct_size = MAX(reduct_size, sizeof(double) * 1);
  reduct_bytes += ROUND_UP(maxblocks * 1 * sizeof(double));
  reduct_size = MAX(reduct_size, sizeof(double) * 1);

  reallocReductArrays(reduct_bytes);
  reduct_bytes = 0;

  arg4.data = OPS_reduct_h + reduct_bytes;
  arg4.data_d = OPS_reduct_d + reduct_bytes;
  for (int b = 0; b < maxblocks; b++)
    for (int d = 0; d < 1; d++)
      ((double *)arg4.data)[d + b * 1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks * 1 * sizeof(double));

  arg5.data = OPS_reduct_h + reduct_bytes;
  arg5.data_d = OPS_reduct_d + reduct_bytes;
  for (int b = 0; b < maxblocks; b++)
    for (int d = 0; d < 1; d++)
      ((double *)arg5.data)[d + b * 1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks * 1 * sizeof(double));

  arg6.data = OPS_reduct_h + reduct_bytes;
  arg6.data_d = OPS_reduct_d + reduct_bytes;
  for (int b = 0; b < maxblocks; b++)
    for (int d = 0; d < 1; d++)
      ((double *)arg6.data)[d + b * 1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks * 1 * sizeof(double));

  arg7.data = OPS_reduct_h + reduct_bytes;
  arg7.data_d = OPS_reduct_d + reduct_bytes;
  for (int b = 0; b < maxblocks; b++)
    for (int d = 0; d < 1; d++)
      ((double *)arg7.data)[d + b * 1] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks * 1 * sizeof(double));

  mvReductArraysToDevice(reduct_bytes);
  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int dat3 = (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);

  char *p_a[8];

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

  int base3 = args[3].dat->base_offset +
              dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  base3 = base3 +
          dat3 * args[3].dat->size[0] * (start[1] * args[3].stencil->stride[1]);
  p_a[3] = (char *)args[3].data_d + base3;

#ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 8);
  ops_halo_exchanges(args, 8, range);
#endif

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[0].mpi_time += t2 - t1;
  }

  int nshared = 0;
  int nthread = OPS_block_size_x * OPS_block_size_y;

  nshared = MAX(nshared, sizeof(double) * 1);
  nshared = MAX(nshared, sizeof(double) * 1);
  nshared = MAX(nshared, sizeof(double) * 1);
  nshared = MAX(nshared, sizeof(double) * 1);

  nshared = MAX(nshared * nthread, reduct_size * nthread);

  // call kernel wrapper function, passing in pointers to data
  ops_field_summary_kernel<<<grid, tblock, nshared>>>(
      (double *)p_a[0], (double *)p_a[1], (double *)p_a[2], (double *)p_a[3],
      (double *)arg4.data_d, (double *)arg5.data_d, (double *)arg6.data_d,
      (double *)arg7.data_d, x_size, y_size);

  mvReductArraysToHost(reduct_bytes);
  for (int b = 0; b < maxblocks; b++) {
    for (int d = 0; d < 1; d++) {
      arg4h[d] = arg4h[d] + ((double *)arg4.data)[d + b * 1];
    }
  }
  arg4.data = (char *)arg4h;

  for (int b = 0; b < maxblocks; b++) {
    for (int d = 0; d < 1; d++) {
      arg5h[d] = arg5h[d] + ((double *)arg5.data)[d + b * 1];
    }
  }
  arg5.data = (char *)arg5h;

  for (int b = 0; b < maxblocks; b++) {
    for (int d = 0; d < 1; d++) {
      arg6h[d] = arg6h[d] + ((double *)arg6.data)[d + b * 1];
    }
  }
  arg6.data = (char *)arg6h;

  for (int b = 0; b < maxblocks; b++) {
    for (int d = 0; d < 1; d++) {
      arg7h[d] = arg7h[d] + ((double *)arg7.data)[d + b * 1];
    }
  }
  arg7.data = (char *)arg7h;

  if (OPS_diags > 1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1, &t1);
    OPS_kernels[0].time += t1 - t2;
  }

#ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 8);
#endif

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[0].mpi_time += t2 - t1;
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_field_summary_kernel(char const *name, ops_block block,
                                       int dim, int *range, ops_arg arg0,
                                       ops_arg arg1, ops_arg arg2, ops_arg arg3,
                                       ops_arg arg4, ops_arg arg5, ops_arg arg6,
                                       ops_arg arg7) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 0;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 0;
  for (int i = 0; i < 4; i++) {
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 8;
  desc->args = (ops_arg *)malloc(8 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->args[5] = arg5;
  desc->args[6] = arg6;
  desc->args[7] = arg7;
  desc->function = ops_par_loop_field_summary_kernel_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(0, "field_summary_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif