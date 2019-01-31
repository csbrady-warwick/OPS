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

// user function
#pragma acc routine
inline void save_kernel(ptr_double rho_old, ptr_double rhou_old,
                        ptr_double rhoE_old, const ptr_double rho_new,
                        const ptr_double rhou_new, const ptr_double rhoE_new) {
  OPS_ACC(rho_old, 0) = OPS_ACC(rho_new, 0);
  OPS_ACC(rhou_old, 0) = OPS_ACC(rhou_new, 0);
  OPS_ACC(rhoE_old, 0) = OPS_ACC(rhoE_new, 0);
}

void save_kernel_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                           double *p_a3, double *p_a4, double *p_a5,
                           int x_size) {
#ifdef OPS_GPU
#pragma acc parallel deviceptr(p_a0, p_a1, p_a2, p_a3, p_a4, p_a5)
#pragma acc loop
#endif
  for (int n_x = 0; n_x < x_size; n_x++) {
    ptr_double ptr0 = {p_a0 + n_x * 1 * 1};
    ptr_double ptr1 = {p_a1 + n_x * 1 * 1};
    ptr_double ptr2 = {p_a2 + n_x * 1 * 1};
    const ptr_double ptr3 = {p_a3 + n_x * 1 * 1};
    const ptr_double ptr4 = {p_a4 + n_x * 1 * 1};
    const ptr_double ptr5 = {p_a5 + n_x * 1 * 1};
    save_kernel(ptr0, ptr1, ptr2, ptr3, ptr4, ptr5);
  }
}
