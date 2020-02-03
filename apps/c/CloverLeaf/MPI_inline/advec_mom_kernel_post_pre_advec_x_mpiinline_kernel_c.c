//
// auto-generated by ops.py
//

int xdim0_advec_mom_kernel_post_pre_advec_x;
int xdim1_advec_mom_kernel_post_pre_advec_x;
int xdim2_advec_mom_kernel_post_pre_advec_x;
int xdim3_advec_mom_kernel_post_pre_advec_x;
int xdim4_advec_mom_kernel_post_pre_advec_x;


//user function



void advec_mom_kernel_post_pre_advec_x_c_wrapper(
  double * restrict node_mass_post_p,
  double * restrict post_vol_p,
  double * restrict density1_p,
  double * restrict node_mass_pre_p,
  double * restrict node_flux_p,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double node_mass_post = { node_mass_post_p + n_x*1 + n_y * xdim0_advec_mom_kernel_post_pre_advec_x*1, xdim0_advec_mom_kernel_post_pre_advec_x};
      const ptr_double post_vol = { post_vol_p + n_x*1 + n_y * xdim1_advec_mom_kernel_post_pre_advec_x*1, xdim1_advec_mom_kernel_post_pre_advec_x};
      const ptr_double density1 = { density1_p + n_x*1 + n_y * xdim2_advec_mom_kernel_post_pre_advec_x*1, xdim2_advec_mom_kernel_post_pre_advec_x};
      ptr_double node_mass_pre = { node_mass_pre_p + n_x*1 + n_y * xdim3_advec_mom_kernel_post_pre_advec_x*1, xdim3_advec_mom_kernel_post_pre_advec_x};
      const ptr_double node_flux = { node_flux_p + n_x*1 + n_y * xdim4_advec_mom_kernel_post_pre_advec_x*1, xdim4_advec_mom_kernel_post_pre_advec_x};
      



  OPS_ACC(node_mass_post, 0,0) = 0.25 * ( OPS_ACC(density1, 0,-1) * OPS_ACC(post_vol, 0,-1) +
                              OPS_ACC(density1, 0,0)   * OPS_ACC(post_vol, 0,0)   +
                              OPS_ACC(density1, -1,-1) * OPS_ACC(post_vol, -1,-1) +
                              OPS_ACC(density1, -1,0)  * OPS_ACC(post_vol, -1,0)  );

  OPS_ACC(node_mass_pre, 0,0) = OPS_ACC(node_mass_post, 0,0) - OPS_ACC(node_flux, -1,0) + OPS_ACC(node_flux, 0,0);


    }
  }
}
