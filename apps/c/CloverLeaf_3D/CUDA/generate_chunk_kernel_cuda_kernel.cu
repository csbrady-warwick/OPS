//
// auto-generated by ops.py
//
__constant__ int xdim0_generate_chunk_kernel;
int xdim0_generate_chunk_kernel_h = -1;
__constant__ int ydim0_generate_chunk_kernel;
int ydim0_generate_chunk_kernel_h = -1;
__constant__ int xdim1_generate_chunk_kernel;
int xdim1_generate_chunk_kernel_h = -1;
__constant__ int ydim1_generate_chunk_kernel;
int ydim1_generate_chunk_kernel_h = -1;
__constant__ int xdim2_generate_chunk_kernel;
int xdim2_generate_chunk_kernel_h = -1;
__constant__ int ydim2_generate_chunk_kernel;
int ydim2_generate_chunk_kernel_h = -1;
__constant__ int xdim3_generate_chunk_kernel;
int xdim3_generate_chunk_kernel_h = -1;
__constant__ int ydim3_generate_chunk_kernel;
int ydim3_generate_chunk_kernel_h = -1;
__constant__ int xdim4_generate_chunk_kernel;
int xdim4_generate_chunk_kernel_h = -1;
__constant__ int ydim4_generate_chunk_kernel;
int ydim4_generate_chunk_kernel_h = -1;
__constant__ int xdim5_generate_chunk_kernel;
int xdim5_generate_chunk_kernel_h = -1;
__constant__ int ydim5_generate_chunk_kernel;
int ydim5_generate_chunk_kernel_h = -1;
__constant__ int xdim6_generate_chunk_kernel;
int xdim6_generate_chunk_kernel_h = -1;
__constant__ int ydim6_generate_chunk_kernel;
int ydim6_generate_chunk_kernel_h = -1;
__constant__ int xdim7_generate_chunk_kernel;
int xdim7_generate_chunk_kernel_h = -1;
__constant__ int ydim7_generate_chunk_kernel;
int ydim7_generate_chunk_kernel_h = -1;
__constant__ int xdim8_generate_chunk_kernel;
int xdim8_generate_chunk_kernel_h = -1;
__constant__ int ydim8_generate_chunk_kernel;
int ydim8_generate_chunk_kernel_h = -1;
__constant__ int xdim9_generate_chunk_kernel;
int xdim9_generate_chunk_kernel_h = -1;
__constant__ int ydim9_generate_chunk_kernel;
int ydim9_generate_chunk_kernel_h = -1;
__constant__ int xdim10_generate_chunk_kernel;
int xdim10_generate_chunk_kernel_h = -1;
__constant__ int ydim10_generate_chunk_kernel;
int ydim10_generate_chunk_kernel_h = -1;

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

#define OPS_ACC0(x, y, z)                                                      \
  (x + xdim0_generate_chunk_kernel * (y) +                                     \
   xdim0_generate_chunk_kernel * ydim0_generate_chunk_kernel * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (x + xdim1_generate_chunk_kernel * (y) +                                     \
   xdim1_generate_chunk_kernel * ydim1_generate_chunk_kernel * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (x + xdim2_generate_chunk_kernel * (y) +                                     \
   xdim2_generate_chunk_kernel * ydim2_generate_chunk_kernel * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (x + xdim3_generate_chunk_kernel * (y) +                                     \
   xdim3_generate_chunk_kernel * ydim3_generate_chunk_kernel * (z))
#define OPS_ACC4(x, y, z)                                                      \
  (x + xdim4_generate_chunk_kernel * (y) +                                     \
   xdim4_generate_chunk_kernel * ydim4_generate_chunk_kernel * (z))
#define OPS_ACC5(x, y, z)                                                      \
  (x + xdim5_generate_chunk_kernel * (y) +                                     \
   xdim5_generate_chunk_kernel * ydim5_generate_chunk_kernel * (z))
#define OPS_ACC6(x, y, z)                                                      \
  (x + xdim6_generate_chunk_kernel * (y) +                                     \
   xdim6_generate_chunk_kernel * ydim6_generate_chunk_kernel * (z))
#define OPS_ACC7(x, y, z)                                                      \
  (x + xdim7_generate_chunk_kernel * (y) +                                     \
   xdim7_generate_chunk_kernel * ydim7_generate_chunk_kernel * (z))
#define OPS_ACC8(x, y, z)                                                      \
  (x + xdim8_generate_chunk_kernel * (y) +                                     \
   xdim8_generate_chunk_kernel * ydim8_generate_chunk_kernel * (z))
#define OPS_ACC9(x, y, z)                                                      \
  (x + xdim9_generate_chunk_kernel * (y) +                                     \
   xdim9_generate_chunk_kernel * ydim9_generate_chunk_kernel * (z))
#define OPS_ACC10(x, y, z)                                                     \
  (x + xdim10_generate_chunk_kernel * (y) +                                    \
   xdim10_generate_chunk_kernel * ydim10_generate_chunk_kernel * (z))

// user function
__device__

    void
    generate_chunk_kernel(const double *vertexx, const double *vertexy,
                          const double *vertexz, double *energy0,
                          double *density0, double *xvel0, double *yvel0,
                          double *zvel0, const double *cellx,
                          const double *celly, const double *cellz) {

  double radius, x_cent, y_cent, z_cent;
  int is_in = 0;

  energy0[OPS_ACC3(0, 0, 0)] = states[0].energy;
  density0[OPS_ACC4(0, 0, 0)] = states[0].density;
  xvel0[OPS_ACC5(0, 0, 0)] = states[0].xvel;
  yvel0[OPS_ACC6(0, 0, 0)] = states[0].yvel;
  zvel0[OPS_ACC7(0, 0, 0)] = states[0].zvel;

  for (int i = 1; i < number_of_states; i++) {

    x_cent = states[i].xmin;
    y_cent = states[i].ymin;
    z_cent = states[i].zmin;

    if (states[i].geometry == g_cube) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          for (int k1 = -1; k1 <= 0; k1++) {
            if (vertexx[OPS_ACC0(1 + i1, 0, 0)] >= states[i].xmin &&
                vertexx[OPS_ACC0(0 + i1, 0, 0)] < states[i].xmax) {
              if (vertexy[OPS_ACC1(0, 1 + j1, 0)] >= states[i].ymin &&
                  vertexy[OPS_ACC1(0, 0 + j1, 0)] < states[i].ymax) {
                if (vertexz[OPS_ACC2(0, 0, 1 + k1)] >= states[i].zmin &&
                    vertexz[OPS_ACC2(0, 0, 0 + k1)] < states[i].zmax) {
                  is_in = 1;
                }
              }
            }
          }
        }
      }

      if (vertexx[OPS_ACC0(1, 0, 0)] >= states[i].xmin &&
          vertexx[OPS_ACC0(0, 0, 0)] < states[i].xmax) {
        if (vertexy[OPS_ACC1(0, 1, 0)] >= states[i].ymin &&
            vertexy[OPS_ACC1(0, 0, 0)] < states[i].ymax) {
          if (vertexz[OPS_ACC2(0, 0, 1)] >= states[i].zmin &&
              vertexz[OPS_ACC2(0, 0, 0)] < states[i].zmax) {
            energy0[OPS_ACC3(0, 0, 0)] = states[i].energy;
            density0[OPS_ACC4(0, 0, 0)] = states[i].density;
          }
        }
      }

      if (is_in) {
        xvel0[OPS_ACC5(0, 0, 0)] = states[i].xvel;
        yvel0[OPS_ACC6(0, 0, 0)] = states[i].yvel;
        zvel0[OPS_ACC7(0, 0, 0)] = states[i].zvel;
      }
    } else if (states[i].geometry == g_sphe) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          for (int k1 = -1; k1 <= 0; k1++) {
            radius = sqrt((cellx[OPS_ACC8(0, 0, 0)] - x_cent) *
                              (cellx[OPS_ACC8(0, 0, 0)] - x_cent) +
                          (celly[OPS_ACC9(0, 0, 0)] - y_cent) *
                              (celly[OPS_ACC9(0, 0, 0)] - y_cent) +
                          (cellz[OPS_ACC10(0, 0, 0)] - z_cent) *
                              (cellz[OPS_ACC10(0, 0, 0)] - z_cent));
            if (radius <= states[i].radius)
              is_in = 1;
          }
        }
      }
      if (radius <= states[i].radius) {
        energy0[OPS_ACC3(0, 0, 0)] = states[i].energy;
        density0[OPS_ACC4(0, 0, 0)] = states[i].density;
      }
      if (is_in) {
        xvel0[OPS_ACC5(0, 0, 0)] = states[i].xvel;
        yvel0[OPS_ACC6(0, 0, 0)] = states[i].yvel;
        zvel0[OPS_ACC7(0, 0, 0)] = states[i].zvel;
      }
    } else if (states[i].geometry == g_point) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          for (int k1 = -1; k1 <= 0; k1++) {
            if (vertexx[OPS_ACC0(0 + i1, 0, 0)] == x_cent &&
                vertexy[OPS_ACC1(0, 0 + j1, 0)] == y_cent &&
                vertexz[OPS_ACC2(0, 0, 0 + k1)] == z_cent)
              is_in = 1;
          }
        }
      }

      if (vertexx[OPS_ACC0(0, 0, 0)] == x_cent &&
          vertexy[OPS_ACC1(0, 0, 0)] == y_cent &&
          vertexz[OPS_ACC2(0, 0, 0)] == z_cent) {
        energy0[OPS_ACC3(0, 0, 0)] = states[i].energy;
        density0[OPS_ACC4(0, 0, 0)] = states[i].density;
      }
      if (is_in) {
        xvel0[OPS_ACC5(0, 0, 0)] = states[i].xvel;
        yvel0[OPS_ACC6(0, 0, 0)] = states[i].yvel;
        zvel0[OPS_ACC7(0, 0, 0)] = states[i].zvel;
      }
    }
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

__global__ void ops_generate_chunk_kernel(
    const double *__restrict arg0, const double *__restrict arg1,
    const double *__restrict arg2, double *__restrict arg3,
    double *__restrict arg4, double *__restrict arg5, double *__restrict arg6,
    double *__restrict arg7, const double *__restrict arg8,
    const double *__restrict arg9, const double *__restrict arg10, int size0,
    int size1, int size2) {

  int idx_z = blockDim.z * blockIdx.z + threadIdx.z;
  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 +=
      idx_x * 1 * 1 + idx_y * 0 * 1 * xdim0_generate_chunk_kernel +
      idx_z * 0 * 1 * xdim0_generate_chunk_kernel * ydim0_generate_chunk_kernel;
  arg1 +=
      idx_x * 0 * 1 + idx_y * 1 * 1 * xdim1_generate_chunk_kernel +
      idx_z * 0 * 1 * xdim1_generate_chunk_kernel * ydim1_generate_chunk_kernel;
  arg2 +=
      idx_x * 0 * 1 + idx_y * 0 * 1 * xdim2_generate_chunk_kernel +
      idx_z * 1 * 1 * xdim2_generate_chunk_kernel * ydim2_generate_chunk_kernel;
  arg3 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * xdim3_generate_chunk_kernel +
      idx_z * 1 * 1 * xdim3_generate_chunk_kernel * ydim3_generate_chunk_kernel;
  arg4 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * xdim4_generate_chunk_kernel +
      idx_z * 1 * 1 * xdim4_generate_chunk_kernel * ydim4_generate_chunk_kernel;
  arg5 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * xdim5_generate_chunk_kernel +
      idx_z * 1 * 1 * xdim5_generate_chunk_kernel * ydim5_generate_chunk_kernel;
  arg6 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * xdim6_generate_chunk_kernel +
      idx_z * 1 * 1 * xdim6_generate_chunk_kernel * ydim6_generate_chunk_kernel;
  arg7 +=
      idx_x * 1 * 1 + idx_y * 1 * 1 * xdim7_generate_chunk_kernel +
      idx_z * 1 * 1 * xdim7_generate_chunk_kernel * ydim7_generate_chunk_kernel;
  arg8 +=
      idx_x * 1 * 1 + idx_y * 0 * 1 * xdim8_generate_chunk_kernel +
      idx_z * 0 * 1 * xdim8_generate_chunk_kernel * ydim8_generate_chunk_kernel;
  arg9 +=
      idx_x * 0 * 1 + idx_y * 1 * 1 * xdim9_generate_chunk_kernel +
      idx_z * 0 * 1 * xdim9_generate_chunk_kernel * ydim9_generate_chunk_kernel;
  arg10 += idx_x * 0 * 1 + idx_y * 0 * 1 * xdim10_generate_chunk_kernel +
           idx_z * 1 * 1 * xdim10_generate_chunk_kernel *
               ydim10_generate_chunk_kernel;

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    generate_chunk_kernel(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,
                          arg9, arg10);
  }
}

// host stub function
void ops_par_loop_generate_chunk_kernel(
    char const *name, ops_block block, int dim, int *range, ops_arg arg0,
    ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5,
    ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10) {

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[11] = {arg0, arg1, arg2, arg3, arg4, arg5,
                      arg6, arg7, arg8, arg9, arg10};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 11, range, 56))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(56, "generate_chunk_kernel");
    OPS_kernels[56].count++;
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

  if (xdim0 != xdim0_generate_chunk_kernel_h ||
      ydim0 != ydim0_generate_chunk_kernel_h ||
      xdim1 != xdim1_generate_chunk_kernel_h ||
      ydim1 != ydim1_generate_chunk_kernel_h ||
      xdim2 != xdim2_generate_chunk_kernel_h ||
      ydim2 != ydim2_generate_chunk_kernel_h ||
      xdim3 != xdim3_generate_chunk_kernel_h ||
      ydim3 != ydim3_generate_chunk_kernel_h ||
      xdim4 != xdim4_generate_chunk_kernel_h ||
      ydim4 != ydim4_generate_chunk_kernel_h ||
      xdim5 != xdim5_generate_chunk_kernel_h ||
      ydim5 != ydim5_generate_chunk_kernel_h ||
      xdim6 != xdim6_generate_chunk_kernel_h ||
      ydim6 != ydim6_generate_chunk_kernel_h ||
      xdim7 != xdim7_generate_chunk_kernel_h ||
      ydim7 != ydim7_generate_chunk_kernel_h ||
      xdim8 != xdim8_generate_chunk_kernel_h ||
      ydim8 != ydim8_generate_chunk_kernel_h ||
      xdim9 != xdim9_generate_chunk_kernel_h ||
      ydim9 != ydim9_generate_chunk_kernel_h ||
      xdim10 != xdim10_generate_chunk_kernel_h ||
      ydim10 != ydim10_generate_chunk_kernel_h) {
    cudaMemcpyToSymbol(xdim0_generate_chunk_kernel, &xdim0, sizeof(int));
    xdim0_generate_chunk_kernel_h = xdim0;
    cudaMemcpyToSymbol(ydim0_generate_chunk_kernel, &ydim0, sizeof(int));
    ydim0_generate_chunk_kernel_h = ydim0;
    cudaMemcpyToSymbol(xdim1_generate_chunk_kernel, &xdim1, sizeof(int));
    xdim1_generate_chunk_kernel_h = xdim1;
    cudaMemcpyToSymbol(ydim1_generate_chunk_kernel, &ydim1, sizeof(int));
    ydim1_generate_chunk_kernel_h = ydim1;
    cudaMemcpyToSymbol(xdim2_generate_chunk_kernel, &xdim2, sizeof(int));
    xdim2_generate_chunk_kernel_h = xdim2;
    cudaMemcpyToSymbol(ydim2_generate_chunk_kernel, &ydim2, sizeof(int));
    ydim2_generate_chunk_kernel_h = ydim2;
    cudaMemcpyToSymbol(xdim3_generate_chunk_kernel, &xdim3, sizeof(int));
    xdim3_generate_chunk_kernel_h = xdim3;
    cudaMemcpyToSymbol(ydim3_generate_chunk_kernel, &ydim3, sizeof(int));
    ydim3_generate_chunk_kernel_h = ydim3;
    cudaMemcpyToSymbol(xdim4_generate_chunk_kernel, &xdim4, sizeof(int));
    xdim4_generate_chunk_kernel_h = xdim4;
    cudaMemcpyToSymbol(ydim4_generate_chunk_kernel, &ydim4, sizeof(int));
    ydim4_generate_chunk_kernel_h = ydim4;
    cudaMemcpyToSymbol(xdim5_generate_chunk_kernel, &xdim5, sizeof(int));
    xdim5_generate_chunk_kernel_h = xdim5;
    cudaMemcpyToSymbol(ydim5_generate_chunk_kernel, &ydim5, sizeof(int));
    ydim5_generate_chunk_kernel_h = ydim5;
    cudaMemcpyToSymbol(xdim6_generate_chunk_kernel, &xdim6, sizeof(int));
    xdim6_generate_chunk_kernel_h = xdim6;
    cudaMemcpyToSymbol(ydim6_generate_chunk_kernel, &ydim6, sizeof(int));
    ydim6_generate_chunk_kernel_h = ydim6;
    cudaMemcpyToSymbol(xdim7_generate_chunk_kernel, &xdim7, sizeof(int));
    xdim7_generate_chunk_kernel_h = xdim7;
    cudaMemcpyToSymbol(ydim7_generate_chunk_kernel, &ydim7, sizeof(int));
    ydim7_generate_chunk_kernel_h = ydim7;
    cudaMemcpyToSymbol(xdim8_generate_chunk_kernel, &xdim8, sizeof(int));
    xdim8_generate_chunk_kernel_h = xdim8;
    cudaMemcpyToSymbol(ydim8_generate_chunk_kernel, &ydim8, sizeof(int));
    ydim8_generate_chunk_kernel_h = ydim8;
    cudaMemcpyToSymbol(xdim9_generate_chunk_kernel, &xdim9, sizeof(int));
    xdim9_generate_chunk_kernel_h = xdim9;
    cudaMemcpyToSymbol(ydim9_generate_chunk_kernel, &ydim9, sizeof(int));
    ydim9_generate_chunk_kernel_h = ydim9;
    cudaMemcpyToSymbol(xdim10_generate_chunk_kernel, &xdim10, sizeof(int));
    xdim10_generate_chunk_kernel_h = xdim10;
    cudaMemcpyToSymbol(ydim10_generate_chunk_kernel, &ydim10, sizeof(int));
    ydim10_generate_chunk_kernel_h = ydim10;
  }

  dim3 grid((x_size - 1) / OPS_block_size_x + 1,
            (y_size - 1) / OPS_block_size_y + 1, z_size);
  dim3 tblock(OPS_block_size_x, OPS_block_size_y, 1);

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;
  int dat6 = args[6].dat->elem_size;
  int dat7 = args[7].dat->elem_size;
  int dat8 = args[8].dat->elem_size;
  int dat9 = args[9].dat->elem_size;
  int dat10 = args[10].dat->elem_size;

  char *p_a[11];

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
  base3 = base3 +
          dat3 * args[3].dat->size[0] * (start[1] * args[3].stencil->stride[1] -
                                         args[3].dat->base[1] - d_m[1]);
  base3 = base3 +
          dat3 * args[3].dat->size[0] * args[3].dat->size[1] *
              (start[2] * args[3].stencil->stride[2] - args[3].dat->base[2] -
               d_m[2]);
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
  base4 = base4 +
          dat4 * args[4].dat->size[0] * (start[1] * args[4].stencil->stride[1] -
                                         args[4].dat->base[1] - d_m[1]);
  base4 = base4 +
          dat4 * args[4].dat->size[0] * args[4].dat->size[1] *
              (start[2] * args[4].stencil->stride[2] - args[4].dat->base[2] -
               d_m[2]);
  p_a[4] = (char *)args[4].data_d + base4;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[5].dat->d_m[d] + OPS_sub_dat_list[args[5].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[5].dat->d_m[d];
#endif
  int base5 = dat5 * 1 * (start[0] * args[5].stencil->stride[0] -
                          args[5].dat->base[0] - d_m[0]);
  base5 = base5 +
          dat5 * args[5].dat->size[0] * (start[1] * args[5].stencil->stride[1] -
                                         args[5].dat->base[1] - d_m[1]);
  base5 = base5 +
          dat5 * args[5].dat->size[0] * args[5].dat->size[1] *
              (start[2] * args[5].stencil->stride[2] - args[5].dat->base[2] -
               d_m[2]);
  p_a[5] = (char *)args[5].data_d + base5;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[6].dat->d_m[d] + OPS_sub_dat_list[args[6].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[6].dat->d_m[d];
#endif
  int base6 = dat6 * 1 * (start[0] * args[6].stencil->stride[0] -
                          args[6].dat->base[0] - d_m[0]);
  base6 = base6 +
          dat6 * args[6].dat->size[0] * (start[1] * args[6].stencil->stride[1] -
                                         args[6].dat->base[1] - d_m[1]);
  base6 = base6 +
          dat6 * args[6].dat->size[0] * args[6].dat->size[1] *
              (start[2] * args[6].stencil->stride[2] - args[6].dat->base[2] -
               d_m[2]);
  p_a[6] = (char *)args[6].data_d + base6;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[7].dat->d_m[d] + OPS_sub_dat_list[args[7].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[7].dat->d_m[d];
#endif
  int base7 = dat7 * 1 * (start[0] * args[7].stencil->stride[0] -
                          args[7].dat->base[0] - d_m[0]);
  base7 = base7 +
          dat7 * args[7].dat->size[0] * (start[1] * args[7].stencil->stride[1] -
                                         args[7].dat->base[1] - d_m[1]);
  base7 = base7 +
          dat7 * args[7].dat->size[0] * args[7].dat->size[1] *
              (start[2] * args[7].stencil->stride[2] - args[7].dat->base[2] -
               d_m[2]);
  p_a[7] = (char *)args[7].data_d + base7;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[8].dat->d_m[d] + OPS_sub_dat_list[args[8].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[8].dat->d_m[d];
#endif
  int base8 = dat8 * 1 * (start[0] * args[8].stencil->stride[0] -
                          args[8].dat->base[0] - d_m[0]);
  base8 = base8 +
          dat8 * args[8].dat->size[0] * (start[1] * args[8].stencil->stride[1] -
                                         args[8].dat->base[1] - d_m[1]);
  base8 = base8 +
          dat8 * args[8].dat->size[0] * args[8].dat->size[1] *
              (start[2] * args[8].stencil->stride[2] - args[8].dat->base[2] -
               d_m[2]);
  p_a[8] = (char *)args[8].data_d + base8;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[9].dat->d_m[d] + OPS_sub_dat_list[args[9].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[9].dat->d_m[d];
#endif
  int base9 = dat9 * 1 * (start[0] * args[9].stencil->stride[0] -
                          args[9].dat->base[0] - d_m[0]);
  base9 = base9 +
          dat9 * args[9].dat->size[0] * (start[1] * args[9].stencil->stride[1] -
                                         args[9].dat->base[1] - d_m[1]);
  base9 = base9 +
          dat9 * args[9].dat->size[0] * args[9].dat->size[1] *
              (start[2] * args[9].stencil->stride[2] - args[9].dat->base[2] -
               d_m[2]);
  p_a[9] = (char *)args[9].data_d + base9;

#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[10].dat->d_m[d] + OPS_sub_dat_list[args[10].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[10].dat->d_m[d];
#endif
  int base10 = dat10 * 1 * (start[0] * args[10].stencil->stride[0] -
                            args[10].dat->base[0] - d_m[0]);
  base10 =
      base10 +
      dat10 * args[10].dat->size[0] * (start[1] * args[10].stencil->stride[1] -
                                       args[10].dat->base[1] - d_m[1]);
  base10 = base10 +
           dat10 * args[10].dat->size[0] * args[10].dat->size[1] *
               (start[2] * args[10].stencil->stride[2] - args[10].dat->base[2] -
                d_m[2]);
  p_a[10] = (char *)args[10].data_d + base10;

  ops_H_D_exchanges_device(args, 11);
  ops_halo_exchanges(args, 11, range);

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[56].mpi_time += t2 - t1;
  }

  // call kernel wrapper function, passing in pointers to data
  ops_generate_chunk_kernel<<<grid, tblock>>>(
      (double *)p_a[0], (double *)p_a[1], (double *)p_a[2], (double *)p_a[3],
      (double *)p_a[4], (double *)p_a[5], (double *)p_a[6], (double *)p_a[7],
      (double *)p_a[8], (double *)p_a[9], (double *)p_a[10], x_size, y_size,
      z_size);

  if (OPS_diags > 1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1, &t1);
    OPS_kernels[56].time += t1 - t2;
  }

  ops_set_dirtybit_device(args, 11);
  ops_set_halo_dirtybit3(&args[3], range);
  ops_set_halo_dirtybit3(&args[4], range);
  ops_set_halo_dirtybit3(&args[5], range);
  ops_set_halo_dirtybit3(&args[6], range);
  ops_set_halo_dirtybit3(&args[7], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[56].mpi_time += t2 - t1;
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg7);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg8);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg9);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg10);
  }
}
