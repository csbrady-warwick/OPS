//
// auto-generated by ops.py
//

int xdim0_update_halo_kernel1_b2;
int xdim1_update_halo_kernel1_b2;
int xdim2_update_halo_kernel1_b2;
int xdim3_update_halo_kernel1_b2;
int xdim4_update_halo_kernel1_b2;
int xdim5_update_halo_kernel1_b2;
int xdim6_update_halo_kernel1_b2;


//user function



void update_halo_kernel1_b2_c_wrapper(
  double * restrict density0_p,
  double * restrict density1_p,
  double * restrict energy0_p,
  double * restrict energy1_p,
  double * restrict pressure_p,
  double * restrict viscosity_p,
  double * restrict soundspeed_p,
  const int * restrict fields,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double density0 = { density0_p + n_x*1 + n_y * xdim0_update_halo_kernel1_b2*1, xdim0_update_halo_kernel1_b2};
      ptr_double density1 = { density1_p + n_x*1 + n_y * xdim1_update_halo_kernel1_b2*1, xdim1_update_halo_kernel1_b2};
      ptr_double energy0 = { energy0_p + n_x*1 + n_y * xdim2_update_halo_kernel1_b2*1, xdim2_update_halo_kernel1_b2};
      ptr_double energy1 = { energy1_p + n_x*1 + n_y * xdim3_update_halo_kernel1_b2*1, xdim3_update_halo_kernel1_b2};
      ptr_double pressure = { pressure_p + n_x*1 + n_y * xdim4_update_halo_kernel1_b2*1, xdim4_update_halo_kernel1_b2};
      ptr_double viscosity = { viscosity_p + n_x*1 + n_y * xdim5_update_halo_kernel1_b2*1, xdim5_update_halo_kernel1_b2};
      ptr_double soundspeed = { soundspeed_p + n_x*1 + n_y * xdim6_update_halo_kernel1_b2*1, xdim6_update_halo_kernel1_b2};

      if (fields[FIELD_DENSITY0] == 1)
        OPS_ACC(density0, 0, 0) = OPS_ACC(density0, 0, 3);
      if (fields[FIELD_DENSITY1] == 1)
        OPS_ACC(density1, 0, 0) = OPS_ACC(density1, 0, 3);
      if (fields[FIELD_ENERGY0] == 1)
        OPS_ACC(energy0, 0, 0) = OPS_ACC(energy0, 0, 3);
      if (fields[FIELD_ENERGY1] == 1)
        OPS_ACC(energy1, 0, 0) = OPS_ACC(energy1, 0, 3);
      if (fields[FIELD_PRESSURE] == 1)
        OPS_ACC(pressure, 0, 0) = OPS_ACC(pressure, 0, 3);
      if (fields[FIELD_VISCOSITY] == 1)
        OPS_ACC(viscosity, 0, 0) = OPS_ACC(viscosity, 0, 3);
      if (fields[FIELD_SOUNDSPEED] == 1)
        OPS_ACC(soundspeed, 0, 0) = OPS_ACC(soundspeed, 0, 3);
    }
  }
}
