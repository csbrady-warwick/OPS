//
// auto-generated by ops.py
//
__constant__ int dims_viscosity_kernel[12][2];
static int dims_viscosity_kernel_h[12][2] = {0};

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10
#undef OPS_ACC11

#define OPS_ACC0(x, y, z)                                                      \
  (x + dims_viscosity_kernel[0][0] * (y) +                                     \
   dims_viscosity_kernel[0][0] * dims_viscosity_kernel[0][1] * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (x + dims_viscosity_kernel[1][0] * (y) +                                     \
   dims_viscosity_kernel[1][0] * dims_viscosity_kernel[1][1] * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (x + dims_viscosity_kernel[2][0] * (y) +                                     \
   dims_viscosity_kernel[2][0] * dims_viscosity_kernel[2][1] * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (x + dims_viscosity_kernel[3][0] * (y) +                                     \
   dims_viscosity_kernel[3][0] * dims_viscosity_kernel[3][1] * (z))
#define OPS_ACC4(x, y, z)                                                      \
  (x + dims_viscosity_kernel[4][0] * (y) +                                     \
   dims_viscosity_kernel[4][0] * dims_viscosity_kernel[4][1] * (z))
#define OPS_ACC5(x, y, z)                                                      \
  (x + dims_viscosity_kernel[5][0] * (y) +                                     \
   dims_viscosity_kernel[5][0] * dims_viscosity_kernel[5][1] * (z))
#define OPS_ACC6(x, y, z)                                                      \
  (x + dims_viscosity_kernel[6][0] * (y) +                                     \
   dims_viscosity_kernel[6][0] * dims_viscosity_kernel[6][1] * (z))
#define OPS_ACC7(x, y, z)                                                      \
  (x + dims_viscosity_kernel[7][0] * (y) +                                     \
   dims_viscosity_kernel[7][0] * dims_viscosity_kernel[7][1] * (z))
#define OPS_ACC8(x, y, z)                                                      \
  (x + dims_viscosity_kernel[8][0] * (y) +                                     \
   dims_viscosity_kernel[8][0] * dims_viscosity_kernel[8][1] * (z))
#define OPS_ACC9(x, y, z)                                                      \
  (x + dims_viscosity_kernel[9][0] * (y) +                                     \
   dims_viscosity_kernel[9][0] * dims_viscosity_kernel[9][1] * (z))
#define OPS_ACC10(x, y, z)                                                     \
  (x + dims_viscosity_kernel[10][0] * (y) +                                    \
   dims_viscosity_kernel[10][0] * dims_viscosity_kernel[10][1] * (z))
#define OPS_ACC11(x, y, z)                                                     \
  (x + dims_viscosity_kernel[11][0] * (y) +                                    \
   dims_viscosity_kernel[11][0] * dims_viscosity_kernel[11][1] * (z))

// user function
__device__

    void
    viscosity_kernel_gpu(const double *xvel0, const double *yvel0,
                         const double *celldx, const double *celldy,
                         const double *pressure, const double *density0,
                         double *viscosity, const double *zvel0,
                         const double *celldz, const double *xarea,
                         const double *yarea, const double *zarea) {

  double grad2, pgradx, pgrady, pgradz, pgradx2, pgrady2, pgradz2, grad, ygrad,
      xgrad, zgrad, div, limiter, pgrad;

  double ugradx1 = xvel0[OPS_ACC0(0, 0, 0)] + xvel0[OPS_ACC0(0, 1, 0)] +
                   xvel0[OPS_ACC0(0, 0, 1)] + xvel0[OPS_ACC0(0, 1, 1)];
  double ugradx2 = xvel0[OPS_ACC0(1, 0, 0)] + xvel0[OPS_ACC0(1, 1, 0)] +
                   xvel0[OPS_ACC0(1, 0, 1)] + xvel0[OPS_ACC0(1, 1, 1)];
  double ugrady1 = xvel0[OPS_ACC0(0, 0, 0)] + xvel0[OPS_ACC0(1, 0, 0)] +
                   xvel0[OPS_ACC0(0, 0, 1)] + xvel0[OPS_ACC0(1, 0, 1)];
  double ugrady2 = xvel0[OPS_ACC0(0, 1, 0)] + xvel0[OPS_ACC0(1, 1, 0)] +
                   xvel0[OPS_ACC0(0, 1, 1)] + xvel0[OPS_ACC0(1, 1, 1)];
  double ugradz1 = xvel0[OPS_ACC0(0, 0, 0)] + xvel0[OPS_ACC0(1, 0, 0)] +
                   xvel0[OPS_ACC0(0, 1, 0)] + xvel0[OPS_ACC0(1, 1, 0)];
  double ugradz2 = xvel0[OPS_ACC0(0, 0, 1)] + xvel0[OPS_ACC0(1, 0, 1)] +
                   xvel0[OPS_ACC0(0, 1, 1)] + xvel0[OPS_ACC0(1, 1, 1)];

  double vgradx1 = yvel0[OPS_ACC1(0, 0, 0)] + yvel0[OPS_ACC1(0, 1, 0)] +
                   yvel0[OPS_ACC1(0, 0, 1)] + yvel0[OPS_ACC1(0, 1, 1)];
  double vgradx2 = yvel0[OPS_ACC1(1, 0, 0)] + yvel0[OPS_ACC1(1, 1, 0)] +
                   yvel0[OPS_ACC1(1, 0, 1)] + yvel0[OPS_ACC1(1, 1, 1)];
  double vgrady1 = yvel0[OPS_ACC1(0, 0, 0)] + yvel0[OPS_ACC1(1, 0, 0)] +
                   yvel0[OPS_ACC1(0, 0, 1)] + yvel0[OPS_ACC1(1, 0, 1)];
  double vgrady2 = yvel0[OPS_ACC1(0, 1, 0)] + yvel0[OPS_ACC1(1, 1, 0)] +
                   yvel0[OPS_ACC1(0, 1, 1)] + yvel0[OPS_ACC1(1, 1, 1)];
  double vgradz1 = yvel0[OPS_ACC1(0, 0, 0)] + yvel0[OPS_ACC1(1, 0, 0)] +
                   yvel0[OPS_ACC1(0, 1, 0)] + yvel0[OPS_ACC1(1, 1, 0)];
  double vgradz2 = yvel0[OPS_ACC1(0, 0, 1)] + yvel0[OPS_ACC1(1, 0, 1)] +
                   yvel0[OPS_ACC1(0, 1, 1)] + yvel0[OPS_ACC1(1, 1, 1)];

  double wgradx1 = zvel0[OPS_ACC7(0, 0, 0)] + zvel0[OPS_ACC7(0, 1, 0)] +
                   zvel0[OPS_ACC7(0, 0, 1)] + zvel0[OPS_ACC7(0, 1, 1)];
  double wgradx2 = zvel0[OPS_ACC7(1, 0, 0)] + zvel0[OPS_ACC7(1, 1, 0)] +
                   zvel0[OPS_ACC7(1, 0, 1)] + zvel0[OPS_ACC7(1, 1, 1)];
  double wgrady1 = zvel0[OPS_ACC7(0, 0, 0)] + zvel0[OPS_ACC7(1, 0, 0)] +
                   zvel0[OPS_ACC7(0, 0, 1)] + zvel0[OPS_ACC7(1, 0, 1)];
  double wgrady2 = zvel0[OPS_ACC7(0, 1, 0)] + zvel0[OPS_ACC7(1, 1, 0)] +
                   zvel0[OPS_ACC7(0, 1, 1)] + zvel0[OPS_ACC7(1, 1, 1)];
  double wgradz1 = zvel0[OPS_ACC7(0, 0, 0)] + zvel0[OPS_ACC7(1, 0, 0)] +
                   zvel0[OPS_ACC7(0, 1, 0)] + zvel0[OPS_ACC7(1, 1, 0)];
  double wgradz2 = zvel0[OPS_ACC7(0, 0, 1)] + zvel0[OPS_ACC7(1, 0, 1)] +
                   zvel0[OPS_ACC7(0, 1, 1)] + zvel0[OPS_ACC7(1, 1, 1)];

  div = xarea[OPS_ACC9(0, 0, 0)] * (ugradx2 - ugradx1) +
        yarea[OPS_ACC10(0, 0, 0)] * (vgrady2 - vgrady1) +
        zarea[OPS_ACC11(0, 0, 0)] * (wgradz2 - wgradz1);

  double xx = 0.25 * (ugradx2 - ugradx1) / (celldx[OPS_ACC2(0, 0, 0)]);
  double yy = 0.25 * (vgrady2 - vgrady1) / (celldy[OPS_ACC3(0, 0, 0)]);
  double zz = 0.25 * (wgradz2 - wgradz1) / (celldz[OPS_ACC8(0, 0, 0)]);
  double xy = 0.25 * (ugrady2 - ugrady1) / (celldy[OPS_ACC3(0, 0, 0)]) +
              0.25 * (vgradx2 - vgradx1) / (celldx[OPS_ACC2(0, 0, 0)]);
  double xz = 0.25 * (ugradz2 - ugradz1) / (celldz[OPS_ACC8(0, 0, 0)]) +
              0.25 * (wgradx2 - wgradx1) / (celldx[OPS_ACC2(0, 0, 0)]);
  double yz = 0.25 * (vgradz2 - vgradz1) / (celldz[OPS_ACC8(0, 0, 0)]) +
              0.25 * (wgrady2 - wgrady1) / (celldy[OPS_ACC3(0, 0, 0)]);

  pgradx = (pressure[OPS_ACC4(1, 0, 0)] - pressure[OPS_ACC4(-1, 0, 0)]) /
           (celldx[OPS_ACC2(0, 0, 0)] + celldx[OPS_ACC2(1, 0, 0)]);
  pgrady = (pressure[OPS_ACC4(0, 1, 0)] - pressure[OPS_ACC4(0, -1, 0)]) /
           (celldy[OPS_ACC3(0, 0, 0)] + celldy[OPS_ACC3(0, 1, 0)]);
  pgradz = (pressure[OPS_ACC4(0, 0, 1)] - pressure[OPS_ACC4(0, 0, -1)]) /
           (celldz[OPS_ACC8(0, 0, 0)] + celldz[OPS_ACC8(0, 0, 1)]);

  pgradx2 = pgradx * pgradx;
  pgrady2 = pgrady * pgrady;
  pgradz2 = pgradz * pgradz;
  limiter = (xx * pgradx2 + yy * pgrady2 + zz * pgradz2 + xy * pgradx * pgrady +
             xz * pgradx * pgradz + yz * pgrady * pgradz) /
            MAX(pgradx2 + pgrady2 + pgradz2, 1.0e-16);

  if ((limiter > 0.0) || (div >= 0.0)) {
    viscosity[OPS_ACC6(0, 0, 0)] = 0.0;
  } else {
    pgradx = SIGN(MAX(1.0e-16, fabs(pgradx)), pgradx);
    pgrady = SIGN(MAX(1.0e-16, fabs(pgrady)), pgrady);
    pgradz = SIGN(MAX(1.0e-16, fabs(pgradz)), pgradz);
    pgrad = sqrt(pgradx * pgradx + pgrady * pgrady + pgradz * pgradz);
    xgrad = fabs(celldx[OPS_ACC2(0, 0, 0)] * pgrad / pgradx);
    ygrad = fabs(celldy[OPS_ACC3(0, 0, 0)] * pgrad / pgrady);
    zgrad = fabs(celldz[OPS_ACC8(0, 0, 0)] * pgrad / pgradz);
    grad = MIN(xgrad, MIN(ygrad, zgrad));
    grad2 = grad * grad;

    viscosity[OPS_ACC6(0, 0, 0)] =
        2.0 * (density0[OPS_ACC5(0, 0, 0)]) * grad2 * limiter * limiter;
  }
}

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10
#undef OPS_ACC11

__global__ void ops_viscosity_kernel(
    const double *__restrict arg0, const double *__restrict arg1,
    const double *__restrict arg2, const double *__restrict arg3,
    const double *__restrict arg4, const double *__restrict arg5,
    double *__restrict arg6, const double *__restrict arg7,
    const double *__restrict arg8, const double *__restrict arg9,
    const double *__restrict arg10, const double *__restrict arg11, int size0,
    int size1, int size2) {

  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * dims_viscosity_kernel[0][0] +
      idx_z * 1 * 1 * dims_viscosity_kernel[0][0] * dims_viscosity_kernel[0][1];
  arg1 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * dims_viscosity_kernel[1][0] +
      idx_z * 1 * 1 * dims_viscosity_kernel[1][0] * dims_viscosity_kernel[1][1];
  arg2 +=
      idx_x * 1 * 1 + idx_y * 0 * 1 * dims_viscosity_kernel[2][0] +
      idx_z * 0 * 1 * dims_viscosity_kernel[2][0] * dims_viscosity_kernel[2][1];
  arg3 +=
      idx_x * 0 * 1 + idx_y * 1 * 1 * dims_viscosity_kernel[3][0] +
      idx_z * 0 * 1 * dims_viscosity_kernel[3][0] * dims_viscosity_kernel[3][1];
  arg4 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * dims_viscosity_kernel[4][0] +
      idx_z * 1 * 1 * dims_viscosity_kernel[4][0] * dims_viscosity_kernel[4][1];
  arg5 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * dims_viscosity_kernel[5][0] +
      idx_z * 1 * 1 * dims_viscosity_kernel[5][0] * dims_viscosity_kernel[5][1];
  arg6 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * dims_viscosity_kernel[6][0] +
      idx_z * 1 * 1 * dims_viscosity_kernel[6][0] * dims_viscosity_kernel[6][1];
  arg7 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * dims_viscosity_kernel[7][0] +
      idx_z * 1 * 1 * dims_viscosity_kernel[7][0] * dims_viscosity_kernel[7][1];
  arg8 +=
      idx_x * 0 * 1 + idx_y * 0 * 1 * dims_viscosity_kernel[8][0] +
      idx_z * 1 * 1 * dims_viscosity_kernel[8][0] * dims_viscosity_kernel[8][1];
  arg9 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * dims_viscosity_kernel[9][0] +
      idx_z * 1 * 1 * dims_viscosity_kernel[9][0] * dims_viscosity_kernel[9][1];
  arg10 += idx_x * 1 * 1 + idx_y * 1 * 1 * dims_viscosity_kernel[10][0] +
           idx_z * 1 * 1 * dims_viscosity_kernel[10][0] *
               dims_viscosity_kernel[10][1];
  arg11 += idx_x * 1 * 1 + idx_y * 1 * 1 * dims_viscosity_kernel[11][0] +
           idx_z * 1 * 1 * dims_viscosity_kernel[11][0] *
               dims_viscosity_kernel[11][1];

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    viscosity_kernel_gpu(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
                         arg9, arg10, arg11);
  }
}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_viscosity_kernel(char const *name, ops_block block, int dim,
                                   int *range, ops_arg arg0, ops_arg arg1,
                                   ops_arg arg2, ops_arg arg3, ops_arg arg4,
                                   ops_arg arg5, ops_arg arg6, ops_arg arg7,
                                   ops_arg arg8, ops_arg arg9, ops_arg arg10,
                                   ops_arg arg11) {
#else
void ops_par_loop_viscosity_kernel_execute(ops_kernel_descriptor *desc) {
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
  ops_arg arg5 = desc->args[5];
  ops_arg arg6 = desc->args[6];
  ops_arg arg7 = desc->args[7];
  ops_arg arg8 = desc->args[8];
  ops_arg arg9 = desc->args[9];
  ops_arg arg10 = desc->args[10];
  ops_arg arg11 = desc->args[11];
#endif

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[12] = {arg0, arg1, arg2, arg3, arg4,  arg5,
                      arg6, arg7, arg8, arg9, arg10, arg11};

#if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args, 12, range, 45))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(45, "viscosity_kernel");
    OPS_kernels[45].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute locally allocated range for the sub-block
  int start[3];
  int end[3];

#ifdef OPS_MPI
  int arg_idx[3];
#endif
#ifdef OPS_MPI
#ifdef OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  for (int n = 0; n < 3; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
    arg_idx[n] = sb->decomp_disp[n] + start[n];
  }
#else
  if (compute_ranges(args, 12, block, range, start, end, arg_idx) < 0)
    return;
#endif
#else
  for (int n = 0; n < 3; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#endif
  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];
  int xdim3 = args[3].dat->size[0];
  int ydim3 = args[3].dat->size[1];
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];
  int xdim5 = args[5].dat->size[0];
  int ydim5 = args[5].dat->size[1];
  int xdim6 = args[6].dat->size[0];
  int ydim6 = args[6].dat->size[1];
  int xdim7 = args[7].dat->size[0];
  int ydim7 = args[7].dat->size[1];
  int xdim8 = args[8].dat->size[0];
  int ydim8 = args[8].dat->size[1];
  int xdim9 = args[9].dat->size[0];
  int ydim9 = args[9].dat->size[1];
  int xdim10 = args[10].dat->size[0];
  int ydim10 = args[10].dat->size[1];
  int xdim11 = args[11].dat->size[0];
  int ydim11 = args[11].dat->size[1];

  if (xdim0 != dims_viscosity_kernel_h[0][0] ||
      ydim0 != dims_viscosity_kernel_h[0][1] ||
      xdim1 != dims_viscosity_kernel_h[1][0] ||
      ydim1 != dims_viscosity_kernel_h[1][1] ||
      xdim2 != dims_viscosity_kernel_h[2][0] ||
      ydim2 != dims_viscosity_kernel_h[2][1] ||
      xdim3 != dims_viscosity_kernel_h[3][0] ||
      ydim3 != dims_viscosity_kernel_h[3][1] ||
      xdim4 != dims_viscosity_kernel_h[4][0] ||
      ydim4 != dims_viscosity_kernel_h[4][1] ||
      xdim5 != dims_viscosity_kernel_h[5][0] ||
      ydim5 != dims_viscosity_kernel_h[5][1] ||
      xdim6 != dims_viscosity_kernel_h[6][0] ||
      ydim6 != dims_viscosity_kernel_h[6][1] ||
      xdim7 != dims_viscosity_kernel_h[7][0] ||
      ydim7 != dims_viscosity_kernel_h[7][1] ||
      xdim8 != dims_viscosity_kernel_h[8][0] ||
      ydim8 != dims_viscosity_kernel_h[8][1] ||
      xdim9 != dims_viscosity_kernel_h[9][0] ||
      ydim9 != dims_viscosity_kernel_h[9][1] ||
      xdim10 != dims_viscosity_kernel_h[10][0] ||
      ydim10 != dims_viscosity_kernel_h[10][1] ||
      xdim11 != dims_viscosity_kernel_h[11][0] ||
      ydim11 != dims_viscosity_kernel_h[11][1]) {
    dims_viscosity_kernel_h[0][0] = xdim0;
    dims_viscosity_kernel_h[0][1] = ydim0;
    dims_viscosity_kernel_h[1][0] = xdim1;
    dims_viscosity_kernel_h[1][1] = ydim1;
    dims_viscosity_kernel_h[2][0] = xdim2;
    dims_viscosity_kernel_h[2][1] = ydim2;
    dims_viscosity_kernel_h[3][0] = xdim3;
    dims_viscosity_kernel_h[3][1] = ydim3;
    dims_viscosity_kernel_h[4][0] = xdim4;
    dims_viscosity_kernel_h[4][1] = ydim4;
    dims_viscosity_kernel_h[5][0] = xdim5;
    dims_viscosity_kernel_h[5][1] = ydim5;
    dims_viscosity_kernel_h[6][0] = xdim6;
    dims_viscosity_kernel_h[6][1] = ydim6;
    dims_viscosity_kernel_h[7][0] = xdim7;
    dims_viscosity_kernel_h[7][1] = ydim7;
    dims_viscosity_kernel_h[8][0] = xdim8;
    dims_viscosity_kernel_h[8][1] = ydim8;
    dims_viscosity_kernel_h[9][0] = xdim9;
    dims_viscosity_kernel_h[9][1] = ydim9;
    dims_viscosity_kernel_h[10][0] = xdim10;
    dims_viscosity_kernel_h[10][1] = ydim10;
    dims_viscosity_kernel_h[11][0] = xdim11;
    dims_viscosity_kernel_h[11][1] = ydim11;
    cutilSafeCall(cudaMemcpyToSymbol(dims_viscosity_kernel,
                                     dims_viscosity_kernel_h,
                                     sizeof(dims_viscosity_kernel)));
  }

  int x_size = MAX(0, end[0] - start[0]);
  int y_size = MAX(0, end[1] - start[1]);
  int z_size = MAX(0, end[2] - start[2]);

  dim3 grid((x_size - 1) / OPS_block_size_x + 1,
            (y_size - 1) / OPS_block_size_y + 1,
            (z_size - 1) / OPS_block_size_z + 1);
  dim3 tblock(OPS_block_size_x, OPS_block_size_y, OPS_block_size_z);

  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int dat3 = (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  int dat4 = (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  int dat5 = (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  int dat6 = (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);
  int dat7 = (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size);
  int dat8 = (OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size);
  int dat9 = (OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size);
  int dat10 = (OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size);
  int dat11 = (OPS_soa ? args[11].dat->type_size : args[11].dat->elem_size);

  char *p_a[12];

  // set up initial pointers
  int base0 = args[0].dat->base_offset +
              dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0 +
          dat0 * args[0].dat->size[0] * (start[1] * args[0].stencil->stride[1]);
  base0 = base0 +
          dat0 * args[0].dat->size[0] * args[0].dat->size[1] *
              (start[2] * args[0].stencil->stride[2]);
  p_a[0] = (char *)args[0].data_d + base0;

  int base1 = args[1].dat->base_offset +
              dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  base1 = base1 +
          dat1 * args[1].dat->size[0] * (start[1] * args[1].stencil->stride[1]);
  base1 = base1 +
          dat1 * args[1].dat->size[0] * args[1].dat->size[1] *
              (start[2] * args[1].stencil->stride[2]);
  p_a[1] = (char *)args[1].data_d + base1;

  int base2 = args[2].dat->base_offset +
              dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  base2 = base2 +
          dat2 * args[2].dat->size[0] * (start[1] * args[2].stencil->stride[1]);
  base2 = base2 +
          dat2 * args[2].dat->size[0] * args[2].dat->size[1] *
              (start[2] * args[2].stencil->stride[2]);
  p_a[2] = (char *)args[2].data_d + base2;

  int base3 = args[3].dat->base_offset +
              dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  base3 = base3 +
          dat3 * args[3].dat->size[0] * (start[1] * args[3].stencil->stride[1]);
  base3 = base3 +
          dat3 * args[3].dat->size[0] * args[3].dat->size[1] *
              (start[2] * args[3].stencil->stride[2]);
  p_a[3] = (char *)args[3].data_d + base3;

  int base4 = args[4].dat->base_offset +
              dat4 * 1 * (start[0] * args[4].stencil->stride[0]);
  base4 = base4 +
          dat4 * args[4].dat->size[0] * (start[1] * args[4].stencil->stride[1]);
  base4 = base4 +
          dat4 * args[4].dat->size[0] * args[4].dat->size[1] *
              (start[2] * args[4].stencil->stride[2]);
  p_a[4] = (char *)args[4].data_d + base4;

  int base5 = args[5].dat->base_offset +
              dat5 * 1 * (start[0] * args[5].stencil->stride[0]);
  base5 = base5 +
          dat5 * args[5].dat->size[0] * (start[1] * args[5].stencil->stride[1]);
  base5 = base5 +
          dat5 * args[5].dat->size[0] * args[5].dat->size[1] *
              (start[2] * args[5].stencil->stride[2]);
  p_a[5] = (char *)args[5].data_d + base5;

  int base6 = args[6].dat->base_offset +
              dat6 * 1 * (start[0] * args[6].stencil->stride[0]);
  base6 = base6 +
          dat6 * args[6].dat->size[0] * (start[1] * args[6].stencil->stride[1]);
  base6 = base6 +
          dat6 * args[6].dat->size[0] * args[6].dat->size[1] *
              (start[2] * args[6].stencil->stride[2]);
  p_a[6] = (char *)args[6].data_d + base6;

  int base7 = args[7].dat->base_offset +
              dat7 * 1 * (start[0] * args[7].stencil->stride[0]);
  base7 = base7 +
          dat7 * args[7].dat->size[0] * (start[1] * args[7].stencil->stride[1]);
  base7 = base7 +
          dat7 * args[7].dat->size[0] * args[7].dat->size[1] *
              (start[2] * args[7].stencil->stride[2]);
  p_a[7] = (char *)args[7].data_d + base7;

  int base8 = args[8].dat->base_offset +
              dat8 * 1 * (start[0] * args[8].stencil->stride[0]);
  base8 = base8 +
          dat8 * args[8].dat->size[0] * (start[1] * args[8].stencil->stride[1]);
  base8 = base8 +
          dat8 * args[8].dat->size[0] * args[8].dat->size[1] *
              (start[2] * args[8].stencil->stride[2]);
  p_a[8] = (char *)args[8].data_d + base8;

  int base9 = args[9].dat->base_offset +
              dat9 * 1 * (start[0] * args[9].stencil->stride[0]);
  base9 = base9 +
          dat9 * args[9].dat->size[0] * (start[1] * args[9].stencil->stride[1]);
  base9 = base9 +
          dat9 * args[9].dat->size[0] * args[9].dat->size[1] *
              (start[2] * args[9].stencil->stride[2]);
  p_a[9] = (char *)args[9].data_d + base9;

  int base10 = args[10].dat->base_offset +
               dat10 * 1 * (start[0] * args[10].stencil->stride[0]);
  base10 =
      base10 +
      dat10 * args[10].dat->size[0] * (start[1] * args[10].stencil->stride[1]);
  base10 = base10 +
           dat10 * args[10].dat->size[0] * args[10].dat->size[1] *
               (start[2] * args[10].stencil->stride[2]);
  p_a[10] = (char *)args[10].data_d + base10;

  int base11 = args[11].dat->base_offset +
               dat11 * 1 * (start[0] * args[11].stencil->stride[0]);
  base11 =
      base11 +
      dat11 * args[11].dat->size[0] * (start[1] * args[11].stencil->stride[1]);
  base11 = base11 +
           dat11 * args[11].dat->size[0] * args[11].dat->size[1] *
               (start[2] * args[11].stencil->stride[2]);
  p_a[11] = (char *)args[11].data_d + base11;

#ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 12);
  ops_halo_exchanges(args, 12, range);
#endif

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[45].mpi_time += t2 - t1;
  }

  // call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0 && z_size > 0)
    ops_viscosity_kernel<<<grid, tblock>>>(
        (double *)p_a[0], (double *)p_a[1], (double *)p_a[2], (double *)p_a[3],
        (double *)p_a[4], (double *)p_a[5], (double *)p_a[6], (double *)p_a[7],
        (double *)p_a[8], (double *)p_a[9], (double *)p_a[10],
        (double *)p_a[11], x_size, y_size, z_size);

  cutilSafeCall(cudaGetLastError());

  if (OPS_diags > 1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1, &t1);
    OPS_kernels[45].time += t1 - t2;
  }

#ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 12);
  ops_set_halo_dirtybit3(&args[6], range);
#endif

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[45].mpi_time += t2 - t1;
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg7);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg8);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg9);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg10);
    OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg11);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_viscosity_kernel(char const *name, ops_block block, int dim,
                                   int *range, ops_arg arg0, ops_arg arg1,
                                   ops_arg arg2, ops_arg arg3, ops_arg arg4,
                                   ops_arg arg5, ops_arg arg6, ops_arg arg7,
                                   ops_arg arg8, ops_arg arg9, ops_arg arg10,
                                   ops_arg arg11) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 45;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 45;
  for (int i = 0; i < 6; i++) {
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 12;
  desc->args = (ops_arg *)malloc(12 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->args[6] = arg6;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg6.dat->index;
  desc->args[7] = arg7;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg7.dat->index;
  desc->args[8] = arg8;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg8.dat->index;
  desc->args[9] = arg9;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg9.dat->index;
  desc->args[10] = arg10;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg10.dat->index;
  desc->args[11] = arg11;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg11.dat->index;
  desc->function = ops_par_loop_viscosity_kernel_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(45, "viscosity_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
