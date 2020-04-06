//
// auto-generated by ops.py//

#include "./OpenACC/clover_leaf_common.h"
#include <math.h>
#include "ops_macros.h"
#include <openacc.h>

//user kernel files
#include "initialise_chunk_kernel_xx_openacc_kernel_c.c"
#include "initialise_chunk_kernel_yy_openacc_kernel_c.c"
#include "initialise_chunk_kernel_zz_openacc_kernel_c.c"
#include "initialise_chunk_kernel_x_openacc_kernel_c.c"
#include "initialise_chunk_kernel_y_openacc_kernel_c.c"
#include "initialise_chunk_kernel_z_openacc_kernel_c.c"
#include "initialise_chunk_kernel_cellx_openacc_kernel_c.c"
#include "initialise_chunk_kernel_celly_openacc_kernel_c.c"
#include "initialise_chunk_kernel_cellz_openacc_kernel_c.c"
#include "initialise_chunk_kernel_volume_openacc_kernel_c.c"
#include "ideal_gas_kernel_openacc_kernel_c.c"
#include "update_halo_kernel1_b2_openacc_kernel_c.c"
#include "update_halo_kernel1_b1_openacc_kernel_c.c"
#include "update_halo_kernel1_t2_openacc_kernel_c.c"
#include "update_halo_kernel1_t1_openacc_kernel_c.c"
#include "update_halo_kernel1_l2_openacc_kernel_c.c"
#include "update_halo_kernel1_l1_openacc_kernel_c.c"
#include "update_halo_kernel1_r2_openacc_kernel_c.c"
#include "update_halo_kernel1_r1_openacc_kernel_c.c"
#include "update_halo_kernel1_ba2_openacc_kernel_c.c"
#include "update_halo_kernel1_ba1_openacc_kernel_c.c"
#include "update_halo_kernel1_fr2_openacc_kernel_c.c"
#include "update_halo_kernel1_fr1_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_4_bot_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_2_bot_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_4_top_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_2_top_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_minus_4_left_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_minus_2_left_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_minus_4_right_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_minus_2_right_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_4_back_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_2_back_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_4_front_openacc_kernel_c.c"
#include "update_halo_kernel2_xvel_plus_2_front_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_minus_4_bot_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_minus_2_bot_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_minus_4_top_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_minus_2_top_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_4_left_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_2_left_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_4_right_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_2_right_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_4_back_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_2_back_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_4_front_openacc_kernel_c.c"
#include "update_halo_kernel2_yvel_plus_2_front_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_plus_4_bot_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_plus_2_bot_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_plus_4_top_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_plus_2_top_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_plus_4_left_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_plus_2_left_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_plus_4_right_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_plus_2_right_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_minus_4_back_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_minus_2_back_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_minus_4_front_openacc_kernel_c.c"
#include "update_halo_kernel2_zvel_minus_2_front_openacc_kernel_c.c"
#include "update_halo_kernel3_plus_4_a_openacc_kernel_c.c"
#include "update_halo_kernel3_plus_2_a_openacc_kernel_c.c"
#include "update_halo_kernel3_plus_4_b_openacc_kernel_c.c"
#include "update_halo_kernel3_plus_2_b_openacc_kernel_c.c"
#include "update_halo_kernel3_minus_4_a_openacc_kernel_c.c"
#include "update_halo_kernel3_minus_2_a_openacc_kernel_c.c"
#include "update_halo_kernel3_minus_4_b_openacc_kernel_c.c"
#include "update_halo_kernel3_minus_2_b_openacc_kernel_c.c"
#include "update_halo_kernel3_plus_4_back_openacc_kernel_c.c"
#include "update_halo_kernel3_plus_2_back_openacc_kernel_c.c"
#include "update_halo_kernel3_plus_4_front_openacc_kernel_c.c"
#include "update_halo_kernel3_plus_2_front_openacc_kernel_c.c"
#include "update_halo_kernel4_minus_4_a_openacc_kernel_c.c"
#include "update_halo_kernel4_minus_2_a_openacc_kernel_c.c"
#include "update_halo_kernel4_minus_4_b_openacc_kernel_c.c"
#include "update_halo_kernel4_minus_2_b_openacc_kernel_c.c"
#include "update_halo_kernel4_plus_4_a_openacc_kernel_c.c"
#include "update_halo_kernel4_plus_2_a_openacc_kernel_c.c"
#include "update_halo_kernel4_plus_4_b_openacc_kernel_c.c"
#include "update_halo_kernel4_plus_2_b_openacc_kernel_c.c"
#include "update_halo_kernel4_plus_4_back_openacc_kernel_c.c"
#include "update_halo_kernel4_plus_2_back_openacc_kernel_c.c"
#include "update_halo_kernel4_plus_4_front_openacc_kernel_c.c"
#include "update_halo_kernel4_plus_2_front_openacc_kernel_c.c"
#include "update_halo_kernel5_plus_4_a_openacc_kernel_c.c"
#include "update_halo_kernel5_plus_2_a_openacc_kernel_c.c"
#include "update_halo_kernel5_plus_4_b_openacc_kernel_c.c"
#include "update_halo_kernel5_plus_2_b_openacc_kernel_c.c"
#include "update_halo_kernel5_plus_4_left_openacc_kernel_c.c"
#include "update_halo_kernel5_plus_2_left_openacc_kernel_c.c"
#include "update_halo_kernel5_plus_4_right_openacc_kernel_c.c"
#include "update_halo_kernel5_plus_2_right_openacc_kernel_c.c"
#include "update_halo_kernel5_minus_4_back_openacc_kernel_c.c"
#include "update_halo_kernel5_minus_2_back_openacc_kernel_c.c"
#include "update_halo_kernel5_minus_4_front_openacc_kernel_c.c"
#include "update_halo_kernel5_minus_2_front_openacc_kernel_c.c"
#include "field_summary_kernel_openacc_kernel_c.c"
#include "viscosity_kernel_openacc_kernel_c.c"
#include "calc_dt_kernel_openacc_kernel_c.c"
#include "calc_dt_kernel_min_openacc_kernel_c.c"
#include "calc_dt_kernel_get_openacc_kernel_c.c"
#include "calc_dt_kernel_print_openacc_kernel_c.c"
#include "PdV_kernel_predict_openacc_kernel_c.c"
#include "PdV_kernel_nopredict_openacc_kernel_c.c"
#include "revert_kernel_openacc_kernel_c.c"
#include "accelerate_kernel_openacc_kernel_c.c"
#include "flux_calc_kernelx_openacc_kernel_c.c"
#include "flux_calc_kernely_openacc_kernel_c.c"
#include "flux_calc_kernelz_openacc_kernel_c.c"
#include "advec_cell_kernel1_xdir_openacc_kernel_c.c"
#include "advec_cell_kernel2_xdir_openacc_kernel_c.c"
#include "advec_cell_kernel3_xdir_openacc_kernel_c.c"
#include "advec_cell_kernel4_xdir_openacc_kernel_c.c"
#include "advec_cell_kernel1_ydir_openacc_kernel_c.c"
#include "advec_cell_kernel2_ydir_openacc_kernel_c.c"
#include "advec_cell_kernel3_ydir_openacc_kernel_c.c"
#include "advec_cell_kernel4_ydir_openacc_kernel_c.c"
#include "advec_cell_kernel1_zdir_openacc_kernel_c.c"
#include "advec_cell_kernel2_zdir_openacc_kernel_c.c"
#include "advec_cell_kernel3_zdir_openacc_kernel_c.c"
#include "advec_cell_kernel4_zdir_openacc_kernel_c.c"
#include "advec_mom_kernel_x1_openacc_kernel_c.c"
#include "advec_mom_kernel_z1_openacc_kernel_c.c"
#include "advec_mom_kernel_x2_openacc_kernel_c.c"
#include "advec_mom_kernel_y2_openacc_kernel_c.c"
#include "advec_mom_kernel_x3_openacc_kernel_c.c"
#include "advec_mom_kernel_z3_openacc_kernel_c.c"
#include "advec_mom_kernel_mass_flux_x_openacc_kernel_c.c"
#include "advec_mom_kernel_post_pre_advec_x_openacc_kernel_c.c"
#include "advec_mom_kernel1_x_nonvector_openacc_kernel_c.c"
#include "advec_mom_kernel2_x_openacc_kernel_c.c"
#include "advec_mom_kernel_mass_flux_y_openacc_kernel_c.c"
#include "advec_mom_kernel_post_pre_advec_y_openacc_kernel_c.c"
#include "advec_mom_kernel1_y_nonvector_openacc_kernel_c.c"
#include "advec_mom_kernel2_y_openacc_kernel_c.c"
#include "advec_mom_kernel_mass_flux_z_openacc_kernel_c.c"
#include "advec_mom_kernel_post_pre_advec_z_openacc_kernel_c.c"
#include "advec_mom_kernel1_z_nonvector_openacc_kernel_c.c"
#include "advec_mom_kernel2_z_openacc_kernel_c.c"
#include "reset_field_kernel1_openacc_kernel_c.c"
#include "reset_field_kernel2_openacc_kernel_c.c"
