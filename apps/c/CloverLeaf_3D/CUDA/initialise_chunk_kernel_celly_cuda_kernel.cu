//
// auto-generated by ops.py
//
__constant__ int xdim0_initialise_chunk_kernel_celly;
int xdim0_initialise_chunk_kernel_celly_h = -1;
__constant__ int ydim0_initialise_chunk_kernel_celly;
int ydim0_initialise_chunk_kernel_celly_h = -1;
__constant__ int xdim1_initialise_chunk_kernel_celly;
int xdim1_initialise_chunk_kernel_celly_h = -1;
__constant__ int ydim1_initialise_chunk_kernel_celly;
int ydim1_initialise_chunk_kernel_celly_h = -1;
__constant__ int xdim2_initialise_chunk_kernel_celly;
int xdim2_initialise_chunk_kernel_celly_h = -1;
__constant__ int ydim2_initialise_chunk_kernel_celly;
int ydim2_initialise_chunk_kernel_celly_h = -1;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2

#define OPS_ACC0(x, y, z)                                                      \
  (x + xdim0_initialise_chunk_kernel_celly * (y) +                             \
   xdim0_initialise_chunk_kernel_celly * ydim0_initialise_chunk_kernel_celly * \
       (z))
#define OPS_ACC1(x, y, z)                                                      \
  (x + xdim1_initialise_chunk_kernel_celly * (y) +                             \
   xdim1_initialise_chunk_kernel_celly * ydim1_initialise_chunk_kernel_celly * \
       (z))
#define OPS_ACC2(x, y, z)                                                      \
  (x + xdim2_initialise_chunk_kernel_celly * (y) +                             \
   xdim2_initialise_chunk_kernel_celly * ydim2_initialise_chunk_kernel_celly * \
       (z))

// user function
__device__

    void
    initialise_chunk_kernel_celly(const double *vertexy, double *celly,
                                  double *celldy) {
  double d_y = (grid.ymax - grid.ymin) / (double)grid.y_cells;
  celly[OPS_ACC1(0, 0, 0)] =
      0.5 * (vertexy[OPS_ACC0(0, 0, 0)] + vertexy[OPS_ACC0(0, 1, 0)]);
  celldy[OPS_ACC2(0, 0, 0)] = d_y;
  if (celldy[OPS_ACC2(0, 0, 0)] < 0) {
  }
}

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2

__global__ void ops_initialise_chunk_kernel_celly(const double *__restrict arg0,
                                                  double *__restrict arg1,
                                                  double *__restrict arg2,
                                                  int size0, int size1,
                                                  int size2) {

  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 0 * 1 + idx_y * 1 * 1 * xdim0_initialise_chunk_kernel_celly +
          idx_z * 0 * 1 * xdim0_initialise_chunk_kernel_celly *
              ydim0_initialise_chunk_kernel_celly;
  arg1 += idx_x * 0 * 1 + idx_y * 1 * 1 * xdim1_initialise_chunk_kernel_celly +
          idx_z * 0 * 1 * xdim1_initialise_chunk_kernel_celly *
              ydim1_initialise_chunk_kernel_celly;
  arg2 += idx_x * 0 * 1 + idx_y * 1 * 1 * xdim2_initialise_chunk_kernel_celly +
          idx_z * 0 * 1 * xdim2_initialise_chunk_kernel_celly *
              ydim2_initialise_chunk_kernel_celly;

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    initialise_chunk_kernel_celly(arg0, arg1, arg2);
  }
}

// host stub function
void ops_par_loop_initialise_chunk_kernel_celly(char const *name,
                                                ops_block block, int dim,
                                                int *range, ops_arg arg0,
                                                ops_arg arg1, ops_arg arg2) {

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[3] = {arg0, arg1, arg2};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 3, range, 53))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(53, "initialise_chunk_kernel_celly");
    OPS_kernels[53].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute locally allocated range for the sub-block
  int start[3];
  int end[3];
#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 3; n++) {
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
  for (int n = 0; n < 3; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#endif

  int x_size = MAX(0, end[0] - start[0]);
  int y_size = MAX(0, end[1] - start[1]);
  int z_size = MAX(0, end[2] - start[2]);

  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];

  if (xdim0 != xdim0_initialise_chunk_kernel_celly_h ||
      ydim0 != ydim0_initialise_chunk_kernel_celly_h ||
      xdim1 != xdim1_initialise_chunk_kernel_celly_h ||
      ydim1 != ydim1_initialise_chunk_kernel_celly_h ||
      xdim2 != xdim2_initialise_chunk_kernel_celly_h ||
      ydim2 != ydim2_initialise_chunk_kernel_celly_h) {
    cudaMemcpyToSymbol(xdim0_initialise_chunk_kernel_celly, &xdim0,
                       sizeof(int));
    xdim0_initialise_chunk_kernel_celly_h = xdim0;
    cudaMemcpyToSymbol(ydim0_initialise_chunk_kernel_celly, &ydim0,
                       sizeof(int));
    ydim0_initialise_chunk_kernel_celly_h = ydim0;
    cudaMemcpyToSymbol(xdim1_initialise_chunk_kernel_celly, &xdim1,
                       sizeof(int));
    xdim1_initialise_chunk_kernel_celly_h = xdim1;
    cudaMemcpyToSymbol(ydim1_initialise_chunk_kernel_celly, &ydim1,
                       sizeof(int));
    ydim1_initialise_chunk_kernel_celly_h = ydim1;
    cudaMemcpyToSymbol(xdim2_initialise_chunk_kernel_celly, &xdim2,
                       sizeof(int));
    xdim2_initialise_chunk_kernel_celly_h = xdim2;
    cudaMemcpyToSymbol(ydim2_initialise_chunk_kernel_celly, &ydim2,
                       sizeof(int));
    ydim2_initialise_chunk_kernel_celly_h = ydim2;
  }

  dim3 grid((x_size - 1) / OPS_block_size_x + 1,
            (y_size - 1) / OPS_block_size_y + 1, z_size);
  dim3 tblock(OPS_block_size_x, OPS_block_size_y, 1);

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;

  char *p_a[3];

  // set up initial pointers
  int d_m[OPS_MAX_DIM];
#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[0].dat->d_m[d];
#endif
  int base0 = dat0 * 1 * (start[0] * args[0].stencil->stride[0] -
                          args[0].dat->base[0] - d_m[0]);
  base0 = base0 +
          dat0 * args[0].dat->size[0] * (start[1] * args[0].stencil->stride[1] -
                                         args[0].dat->base[1] - d_m[1]);
  base0 = base0 +
          dat0 * args[0].dat->size[0] * args[0].dat->size[1] *
              (start[2] * args[0].stencil->stride[2] - args[0].dat->base[2] -
               d_m[2]);
  p_a[0] = (char *)args[0].data_d + base0;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[1].dat->d_m[d];
#endif
  int base1 = dat1 * 1 * (start[0] * args[1].stencil->stride[0] -
                          args[1].dat->base[0] - d_m[0]);
  base1 = base1 +
          dat1 * args[1].dat->size[0] * (start[1] * args[1].stencil->stride[1] -
                                         args[1].dat->base[1] - d_m[1]);
  base1 = base1 +
          dat1 * args[1].dat->size[0] * args[1].dat->size[1] *
              (start[2] * args[1].stencil->stride[2] - args[1].dat->base[2] -
               d_m[2]);
  p_a[1] = (char *)args[1].data_d + base1;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[2].dat->d_m[d];
#endif
  int base2 = dat2 * 1 * (start[0] * args[2].stencil->stride[0] -
                          args[2].dat->base[0] - d_m[0]);
  base2 = base2 +
          dat2 * args[2].dat->size[0] * (start[1] * args[2].stencil->stride[1] -
                                         args[2].dat->base[1] - d_m[1]);
  base2 = base2 +
          dat2 * args[2].dat->size[0] * args[2].dat->size[1] *
              (start[2] * args[2].stencil->stride[2] - args[2].dat->base[2] -
               d_m[2]);
  p_a[2] = (char *)args[2].data_d + base2;

  ops_H_D_exchanges_device(args, 3);
  ops_halo_exchanges(args, 3, range);

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[53].mpi_time += t2 - t1;
  }

  // call kernel wrapper function, passing in pointers to data
  ops_initialise_chunk_kernel_celly<<<grid, tblock>>>(
      (double *)p_a[0], (double *)p_a[1], (double *)p_a[2], x_size, y_size,
      z_size);

  if (OPS_diags > 1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1, &t1);
    OPS_kernels[53].time += t1 - t2;
  }

  ops_set_dirtybit_device(args, 3);
  ops_set_halo_dirtybit3(&args[1], range);
  ops_set_halo_dirtybit3(&args[2], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[53].mpi_time += t2 - t1;
    OPS_kernels[53].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[53].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[53].transfer += ops_compute_transfer(dim, start, end, &arg2);
  }
}
