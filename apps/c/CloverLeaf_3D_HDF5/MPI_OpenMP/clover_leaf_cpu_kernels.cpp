//
// auto-generated by ops.py//

//header
#define OPS_3D
#define OPS_API 2
#include "ops_lib_cpp.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
#include "user_types.h"

// global constants
extern double g_small;
extern double g_big;
extern double dtc_safe;
extern double dtu_safe;
extern double dtv_safe;
extern double dtw_safe;
extern double dtdiv_safe;
extern field_type field;
extern grid_type grid;
extern state_type *states;
extern int number_of_states;
extern int g_sphe;
extern int g_point;
extern int g_cube;
extern double dt;

void ops_init_backend() {}

//user kernel files
#include "initialise_chunk_kernel_xx_cpu_kernel.cpp"
#include "initialise_chunk_kernel_yy_cpu_kernel.cpp"
#include "initialise_chunk_kernel_zz_cpu_kernel.cpp"
#include "initialise_chunk_kernel_x_cpu_kernel.cpp"
#include "initialise_chunk_kernel_y_cpu_kernel.cpp"
#include "initialise_chunk_kernel_z_cpu_kernel.cpp"
#include "initialise_chunk_kernel_cellx_cpu_kernel.cpp"
#include "initialise_chunk_kernel_celly_cpu_kernel.cpp"
#include "initialise_chunk_kernel_cellz_cpu_kernel.cpp"
#include "initialise_chunk_kernel_volume_cpu_kernel.cpp"
#include "ideal_gas_kernel_cpu_kernel.cpp"
#include "update_halo_kernel1_b2_cpu_kernel.cpp"
#include "update_halo_kernel1_b1_cpu_kernel.cpp"
#include "update_halo_kernel1_t2_cpu_kernel.cpp"
#include "update_halo_kernel1_t1_cpu_kernel.cpp"
#include "update_halo_kernel1_l2_cpu_kernel.cpp"
#include "update_halo_kernel1_l1_cpu_kernel.cpp"
#include "update_halo_kernel1_r2_cpu_kernel.cpp"
#include "update_halo_kernel1_r1_cpu_kernel.cpp"
#include "update_halo_kernel1_ba2_cpu_kernel.cpp"
#include "update_halo_kernel1_ba1_cpu_kernel.cpp"
#include "update_halo_kernel1_fr2_cpu_kernel.cpp"
#include "update_halo_kernel1_fr1_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_4_bot_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_2_bot_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_4_top_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_2_top_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_minus_4_left_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_minus_2_left_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_minus_4_right_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_minus_2_right_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_4_back_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_2_back_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_4_front_cpu_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_2_front_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_minus_4_bot_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_minus_2_bot_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_minus_4_top_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_minus_2_top_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_4_left_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_2_left_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_4_right_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_2_right_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_4_back_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_2_back_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_4_front_cpu_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_2_front_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_4_bot_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_2_bot_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_4_top_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_2_top_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_4_left_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_2_left_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_4_right_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_2_right_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_minus_4_back_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_minus_2_back_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_minus_4_front_cpu_kernel.cpp"
#include "update_halo_kernel2_zvel_minus_2_front_cpu_kernel.cpp"
#include "update_halo_kernel3_plus_4_a_cpu_kernel.cpp"
#include "update_halo_kernel3_plus_2_a_cpu_kernel.cpp"
#include "update_halo_kernel3_plus_4_b_cpu_kernel.cpp"
#include "update_halo_kernel3_plus_2_b_cpu_kernel.cpp"
#include "update_halo_kernel3_minus_4_a_cpu_kernel.cpp"
#include "update_halo_kernel3_minus_2_a_cpu_kernel.cpp"
#include "update_halo_kernel3_minus_4_b_cpu_kernel.cpp"
#include "update_halo_kernel3_minus_2_b_cpu_kernel.cpp"
#include "update_halo_kernel3_plus_4_back_cpu_kernel.cpp"
#include "update_halo_kernel3_plus_2_back_cpu_kernel.cpp"
#include "update_halo_kernel3_plus_4_front_cpu_kernel.cpp"
#include "update_halo_kernel3_plus_2_front_cpu_kernel.cpp"
#include "update_halo_kernel4_minus_4_a_cpu_kernel.cpp"
#include "update_halo_kernel4_minus_2_a_cpu_kernel.cpp"
#include "update_halo_kernel4_minus_4_b_cpu_kernel.cpp"
#include "update_halo_kernel4_minus_2_b_cpu_kernel.cpp"
#include "update_halo_kernel4_plus_4_a_cpu_kernel.cpp"
#include "update_halo_kernel4_plus_2_a_cpu_kernel.cpp"
#include "update_halo_kernel4_plus_4_b_cpu_kernel.cpp"
#include "update_halo_kernel4_plus_2_b_cpu_kernel.cpp"
#include "update_halo_kernel4_plus_4_back_cpu_kernel.cpp"
#include "update_halo_kernel4_plus_2_back_cpu_kernel.cpp"
#include "update_halo_kernel4_plus_4_front_cpu_kernel.cpp"
#include "update_halo_kernel4_plus_2_front_cpu_kernel.cpp"
#include "update_halo_kernel5_plus_4_a_cpu_kernel.cpp"
#include "update_halo_kernel5_plus_2_a_cpu_kernel.cpp"
#include "update_halo_kernel5_plus_4_b_cpu_kernel.cpp"
#include "update_halo_kernel5_plus_2_b_cpu_kernel.cpp"
#include "update_halo_kernel5_plus_4_left_cpu_kernel.cpp"
#include "update_halo_kernel5_plus_2_left_cpu_kernel.cpp"
#include "update_halo_kernel5_plus_4_right_cpu_kernel.cpp"
#include "update_halo_kernel5_plus_2_right_cpu_kernel.cpp"
#include "update_halo_kernel5_minus_4_back_cpu_kernel.cpp"
#include "update_halo_kernel5_minus_2_back_cpu_kernel.cpp"
#include "update_halo_kernel5_minus_4_front_cpu_kernel.cpp"
#include "update_halo_kernel5_minus_2_front_cpu_kernel.cpp"
#include "field_summary_kernel_cpu_kernel.cpp"
#include "viscosity_kernel_cpu_kernel.cpp"
#include "calc_dt_kernel_cpu_kernel.cpp"
#include "calc_dt_kernel_min_cpu_kernel.cpp"
#include "calc_dt_kernel_get_cpu_kernel.cpp"
#include "calc_dt_kernel_print_cpu_kernel.cpp"
#include "PdV_kernel_predict_cpu_kernel.cpp"
#include "PdV_kernel_nopredict_cpu_kernel.cpp"
#include "revert_kernel_cpu_kernel.cpp"
#include "accelerate_kernel_cpu_kernel.cpp"
#include "flux_calc_kernelx_cpu_kernel.cpp"
#include "flux_calc_kernely_cpu_kernel.cpp"
#include "flux_calc_kernelz_cpu_kernel.cpp"
#include "advec_cell_kernel1_xdir_cpu_kernel.cpp"
#include "advec_cell_kernel2_xdir_cpu_kernel.cpp"
#include "advec_cell_kernel3_xdir_cpu_kernel.cpp"
#include "advec_cell_kernel4_xdir_cpu_kernel.cpp"
#include "advec_cell_kernel1_ydir_cpu_kernel.cpp"
#include "advec_cell_kernel2_ydir_cpu_kernel.cpp"
#include "advec_cell_kernel3_ydir_cpu_kernel.cpp"
#include "advec_cell_kernel4_ydir_cpu_kernel.cpp"
#include "advec_cell_kernel1_zdir_cpu_kernel.cpp"
#include "advec_cell_kernel2_zdir_cpu_kernel.cpp"
#include "advec_cell_kernel3_zdir_cpu_kernel.cpp"
#include "advec_cell_kernel4_zdir_cpu_kernel.cpp"
#include "advec_mom_kernel_x1_cpu_kernel.cpp"
#include "advec_mom_kernel_z1_cpu_kernel.cpp"
#include "advec_mom_kernel_x2_cpu_kernel.cpp"
#include "advec_mom_kernel_y2_cpu_kernel.cpp"
#include "advec_mom_kernel_x3_cpu_kernel.cpp"
#include "advec_mom_kernel_z3_cpu_kernel.cpp"
#include "advec_mom_kernel_mass_flux_x_cpu_kernel.cpp"
#include "advec_mom_kernel_post_pre_advec_x_cpu_kernel.cpp"
#include "advec_mom_kernel1_x_nonvector_cpu_kernel.cpp"
#include "advec_mom_kernel2_x_cpu_kernel.cpp"
#include "advec_mom_kernel_mass_flux_y_cpu_kernel.cpp"
#include "advec_mom_kernel_post_pre_advec_y_cpu_kernel.cpp"
#include "advec_mom_kernel1_y_nonvector_cpu_kernel.cpp"
#include "advec_mom_kernel2_y_cpu_kernel.cpp"
#include "advec_mom_kernel_mass_flux_z_cpu_kernel.cpp"
#include "advec_mom_kernel_post_pre_advec_z_cpu_kernel.cpp"
#include "advec_mom_kernel1_z_nonvector_cpu_kernel.cpp"
#include "advec_mom_kernel2_z_cpu_kernel.cpp"
#include "reset_field_kernel1_cpu_kernel.cpp"
#include "reset_field_kernel2_cpu_kernel.cpp"
