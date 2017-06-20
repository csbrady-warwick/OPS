//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_revert_kernel;
extern int xdim1_revert_kernel;
extern int xdim2_revert_kernel;
extern int xdim3_revert_kernel;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

#define OPS_ACC0(x, y) (x + xdim0_revert_kernel * (y))
#define OPS_ACC1(x, y) (x + xdim1_revert_kernel * (y))
#define OPS_ACC2(x, y) (x + xdim2_revert_kernel * (y))
#define OPS_ACC3(x, y) (x + xdim3_revert_kernel * (y))

// user function

void revert_kernel_c_wrapper(double *p_a0, int base0, int tot0, double *p_a1,
                             int base1, int tot1, double *p_a2, int base2,
                             int tot2, double *p_a3, int base3, int tot3,
                             int x_size, int y_size) {
  int num_blocks = OPS_threads;
#pragma omp target enter data map(                                             \
    to : p_a0[0 : tot0], p_a1[0 : tot1],                                       \
                              p_a2[0 : tot2],                                  \
                                   p_a3[0 : tot3],                             \
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
    const double *density0 =
        p_a0 + base0 + n_x * 1 * 1 + n_y * xdim0_revert_kernel * 1 * 1;

    double *density1 =
        p_a1 + base1 + n_x * 1 * 1 + n_y * xdim1_revert_kernel * 1 * 1;
    const double *energy0 =
        p_a2 + base2 + n_x * 1 * 1 + n_y * xdim2_revert_kernel * 1 * 1;

    double *energy1 =
        p_a3 + base3 + n_x * 1 * 1 + n_y * xdim3_revert_kernel * 1 * 1;

    density1[OPS_ACC1(0, 0)] = density0[OPS_ACC0(0, 0)];
    energy1[OPS_ACC3(0, 0)] = energy0[OPS_ACC2(0, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
