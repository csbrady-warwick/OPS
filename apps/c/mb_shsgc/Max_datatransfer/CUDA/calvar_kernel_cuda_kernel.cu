//
// auto-generated by ops.py
//
__constant__ int xdim0_calvar_kernel;
int xdim0_calvar_kernel_h = -1;
int ydim0_calvar_kernel_h = -1;
__constant__ int xdim1_calvar_kernel;
int xdim1_calvar_kernel_h = -1;
int ydim1_calvar_kernel_h = -1;
__constant__ int xdim2_calvar_kernel;
int xdim2_calvar_kernel_h = -1;
int ydim2_calvar_kernel_h = -1;
__constant__ int xdim3_calvar_kernel;
int xdim3_calvar_kernel_h = -1;
int ydim3_calvar_kernel_h = -1;
__constant__ int xdim4_calvar_kernel;
int xdim4_calvar_kernel_h = -1;
int ydim4_calvar_kernel_h = -1;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4

#define OPS_ACC0(x) (x)
#define OPS_ACC1(x) (x)
#define OPS_ACC2(x) (x)
#define OPS_ACC3(x) (x)
#define OPS_ACC4(x) (x)

// user function
__device__

    void
    calvar_kernel(const double *rho_new, const double *rhou_new,
                  const double *rhoE_new, double *workarray2,
                  double *workarray3) {
  double p, rhoi, u;
  rhoi = 1 / rho_new[OPS_ACC0(0)];
  u = rhou_new[OPS_ACC1(0)] * rhoi;
  p = gam1 * (rhoE_new[OPS_ACC2(0)] - 0.5 * rho_new[OPS_ACC0(0)] * u * u);

  workarray2[OPS_ACC3(0)] = p + rhou_new[OPS_ACC1(0)] * u;
  workarray3[OPS_ACC4(0)] = (p + rhoE_new[OPS_ACC2(0)]) * u;
}

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4

__global__ void ops_calvar_kernel(const double *__restrict arg0,
                                  const double *__restrict arg1,
                                  const double *__restrict arg2,
                                  double *__restrict arg3,
                                  double *__restrict arg4, int size0) {

  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 * 1;
  arg1 += idx_x * 1 * 1;
  arg2 += idx_x * 1 * 1;
  arg3 += idx_x * 1 * 1;
  arg4 += idx_x * 1 * 1;

  if (idx_x < size0) {
    calvar_kernel(arg0, arg1, arg2, arg3, arg4);
  }
}

// host stub function
void ops_par_loop_calvar_kernel(char const *name, ops_block block, int dim,
                                int *range, ops_arg arg0, ops_arg arg1,
                                ops_arg arg2, ops_arg arg3, ops_arg arg4) {

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[5] = {arg0, arg1, arg2, arg3, arg4};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 5, range, 3))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(3, "calvar_kernel");
    OPS_kernels[3].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute locally allocated range for the sub-block
  int start[1];
  int end[1];
#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 1; n++) {
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
  for (int n = 0; n < 1; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#endif

  int x_size = MAX(0, end[0] - start[0]);

  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];

  if (xdim0 != xdim0_calvar_kernel_h || xdim1 != xdim1_calvar_kernel_h ||
      xdim2 != xdim2_calvar_kernel_h || xdim3 != xdim3_calvar_kernel_h ||
      xdim4 != xdim4_calvar_kernel_h) {
    cudaMemcpyToSymbol(xdim0_calvar_kernel, &xdim0, sizeof(int));
    xdim0_calvar_kernel_h = xdim0;
    cudaMemcpyToSymbol(xdim1_calvar_kernel, &xdim1, sizeof(int));
    xdim1_calvar_kernel_h = xdim1;
    cudaMemcpyToSymbol(xdim2_calvar_kernel, &xdim2, sizeof(int));
    xdim2_calvar_kernel_h = xdim2;
    cudaMemcpyToSymbol(xdim3_calvar_kernel, &xdim3, sizeof(int));
    xdim3_calvar_kernel_h = xdim3;
    cudaMemcpyToSymbol(xdim4_calvar_kernel, &xdim4, sizeof(int));
    xdim4_calvar_kernel_h = xdim4;
  }

  dim3 grid((x_size - 1) / OPS_block_size_x + 1, 1, 1);
  dim3 tblock(OPS_block_size_x, 1, 1);

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;

  char *p_a[5];

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
  p_a[2] = (char *)args[2].data_d + base2;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[3].dat->d_m[d] + OPS_sub_dat_list[args[3].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[3].dat->d_m[d];
#endif
  int base3 = dat3 * 1 * (start[0] * args[3].stencil->stride[0] -
                          args[3].dat->base[0] - d_m[0]);
  p_a[3] = (char *)args[3].data_d + base3;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[4].dat->d_m[d] + OPS_sub_dat_list[args[4].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[4].dat->d_m[d];
#endif
  int base4 = dat4 * 1 * (start[0] * args[4].stencil->stride[0] -
                          args[4].dat->base[0] - d_m[0]);
  p_a[4] = (char *)args[4].data_d + base4;

  ops_H_D_exchanges_device(args, 5);
  ops_halo_exchanges(args, 5, range);

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[3].mpi_time += t2 - t1;
  }

  // call kernel wrapper function, passing in pointers to data
  ops_calvar_kernel<<<grid, tblock>>>((double *)p_a[0], (double *)p_a[1],
                                      (double *)p_a[2], (double *)p_a[3],
                                      (double *)p_a[4], x_size);

  if (OPS_diags > 1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1, &t1);
    OPS_kernels[3].time += t1 - t2;
  }

  ops_set_dirtybit_device(args, 5);
  ops_set_halo_dirtybit3(&args[3], range);
  ops_set_halo_dirtybit3(&args[4], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[3].mpi_time += t2 - t1;
    OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}
