//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_gridgen_kernel;

#undef OPS_ACC0

#define OPS_ACC0(x) (x)

// user function
inline void gridgen_kernel(double *x, const int *id) {

  x[OPS_ACC0(0)] = xt + id[0] * dx;
}

#undef OPS_ACC0

void gridgen_kernel_c_wrapper(double *p_a0, int *p_a1, int arg_idx0,
                              int x_size) {
#ifdef OPS_GPU
#pragma acc parallel deviceptr(p_a0)
#pragma acc loop
#endif
  for (int n_x = 0; n_x < x_size; n_x++) {
    int arg_idx[] = {arg_idx0 + n_x};
    gridgen_kernel(p_a0 + n_x * 1 * 1, arg_idx);
  }
}
