//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_update_halo_kernel4_plus_4_b;
extern int xdim1_update_halo_kernel4_plus_4_b;

#undef OPS_ACC0
#undef OPS_ACC1

#define OPS_ACC0(x, y) (x + xdim0_update_halo_kernel4_plus_4_b * (y))
#define OPS_ACC1(x, y) (x + xdim1_update_halo_kernel4_plus_4_b * (y))

// user function

void update_halo_kernel4_plus_4_b_c_wrapper(double *p_a0, int base0, int tot0,
                                            double *p_a1, int base1, int tot1,
                                            int *p_a2, int tot2, int x_size,
                                            int y_size) {
  int num_blocks = OPS_threads;
#pragma omp target enter data map(                                             \
    to : p_a0[0 : tot0], p_a1[0 : tot1], p_a2[0 : tot2],                       \
                                              states[0 : number_of_states])
#ifdef OPS_GPU

#pragma omp target teams num_teams(num_blocks)                                 \
    thread_limit(OPS_threads_for_block)
#pragma omp distribute parallel for simd schedule(static, 1)
#endif
  for (int i = 0; i < y_size * x_size; i++) {
#ifdef OPS_GPU
#endif
    int n_x = i % x_size;
    int n_y = i / x_size;
    double *vol_flux_y = p_a0 + base0 + n_x * 1 * 1 +
                         n_y * xdim0_update_halo_kernel4_plus_4_b * 1 * 1;

    double *mass_flux_y = p_a1 + base1 + n_x * 1 * 1 +
                          n_y * xdim1_update_halo_kernel4_plus_4_b * 1 * 1;
    const int *fields = p_a2;

    if (fields[FIELD_VOL_FLUX_Y] == 1)
      vol_flux_y[OPS_ACC0(0, 0)] = vol_flux_y[OPS_ACC0(-4, 0)];
    if (fields[FIELD_MASS_FLUX_Y] == 1)
      mass_flux_y[OPS_ACC1(0, 0)] = mass_flux_y[OPS_ACC1(-4, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
