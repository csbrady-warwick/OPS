//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_save_kernel;
int xdim1_save_kernel;
int xdim2_save_kernel;
int xdim3_save_kernel;
int xdim4_save_kernel;
int xdim5_save_kernel;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5

#define OPS_ACC0(x) (x)
#define OPS_ACC1(x) (x)
#define OPS_ACC2(x) (x)
#define OPS_ACC3(x) (x)
#define OPS_ACC4(x) (x)
#define OPS_ACC5(x) (x)

// user function
inline void save_kernel(double *rho_old, double *rhou_old, double *rhoE_old,
                        const double *rho_new, const double *rhou_new,
                        const double *rhoE_new) {
  rho_old[OPS_ACC0(0)] = rho_new[OPS_ACC3(0)];
  rhou_old[OPS_ACC1(0)] = rhou_new[OPS_ACC4(0)];
  rhoE_old[OPS_ACC2(0)] = rhoE_new[OPS_ACC5(0)];
}

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5

void save_kernel_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                           double *p_a3, double *p_a4, double *p_a5,
                           int x_size) {
#ifdef OPS_GPU
#pragma acc parallel deviceptr(p_a0, p_a1, p_a2, p_a3, p_a4, p_a5)
#pragma acc loop
#endif
  for (int n_x = 0; n_x < x_size; n_x++) {
    save_kernel(p_a0 + n_x * 1 * 1, p_a1 + n_x * 1 * 1, p_a2 + n_x * 1 * 1,
                p_a3 + n_x * 1 * 1, p_a4 + n_x * 1 * 1, p_a5 + n_x * 1 * 1);
  }
}
