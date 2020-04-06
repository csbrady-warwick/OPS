//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_PdV_kernel_nopredict;
int xdim1_PdV_kernel_nopredict;
int xdim2_PdV_kernel_nopredict;
int xdim3_PdV_kernel_nopredict;
int xdim4_PdV_kernel_nopredict;
int xdim5_PdV_kernel_nopredict;
int xdim6_PdV_kernel_nopredict;
int xdim7_PdV_kernel_nopredict;
int xdim8_PdV_kernel_nopredict;
int xdim9_PdV_kernel_nopredict;
int xdim10_PdV_kernel_nopredict;
int xdim11_PdV_kernel_nopredict;
int xdim12_PdV_kernel_nopredict;
int xdim13_PdV_kernel_nopredict;

//user function
#pragma acc routine
inline 
void PdV_kernel_nopredict(const ptr_double xarea,
  const ptr_double xvel0,
  const ptr_double xvel1,
  const ptr_double yarea,
  const ptr_double yvel0,
  const ptr_double yvel1,
  ptr_double volume_change,
  const ptr_double volume,
  const ptr_double pressure,
  const ptr_double density0,
  ptr_double density1,
  const ptr_double viscosity,
  const ptr_double energy0,
  ptr_double energy1) {


  double recip_volume, energy_change;
  double right_flux, left_flux, top_flux, bottom_flux, total_flux;

  left_flux = ( OPS_ACC(xarea, 0,0) * ( OPS_ACC(xvel0, 0,0) + OPS_ACC(xvel0, 0,1) +
                                OPS_ACC(xvel1, 0,0) + OPS_ACC(xvel1, 0,1) ) ) * 0.25 * dt;
  right_flux = ( OPS_ACC(xarea, 1,0) * ( OPS_ACC(xvel0, 1,0) + OPS_ACC(xvel0, 1,1) +
                                 OPS_ACC(xvel1, 1,0) + OPS_ACC(xvel1, 1,1) ) ) * 0.25 * dt;

  bottom_flux = ( OPS_ACC(yarea, 0,0) * ( OPS_ACC(yvel0, 0,0) + OPS_ACC(yvel0, 1,0) +
                                  OPS_ACC(yvel1, 0,0) + OPS_ACC(yvel1, 1,0) ) ) * 0.25* dt;
  top_flux = ( OPS_ACC(yarea, 0,1) * ( OPS_ACC(yvel0, 0,1) + OPS_ACC(yvel0, 1,1) +
                               OPS_ACC(yvel1, 0,1) + OPS_ACC(yvel1, 1,1) ) ) * 0.25 * dt;

  total_flux = right_flux - left_flux + top_flux - bottom_flux;

  OPS_ACC(volume_change, 0,0) = (OPS_ACC(volume, 0,0))/(OPS_ACC(volume, 0,0) + total_flux);




  recip_volume = 1.0/OPS_ACC(volume, 0,0);

  energy_change = ( OPS_ACC(pressure, 0,0)/OPS_ACC(density0, 0,0) +
                    OPS_ACC(viscosity, 0,0)/OPS_ACC(density0, 0,0) ) * total_flux * recip_volume;
  OPS_ACC(energy1, 0,0) = OPS_ACC(energy0, 0,0) - energy_change;
  OPS_ACC(density1, 0,0) = OPS_ACC(density0, 0,0) * OPS_ACC(volume_change, 0,0);

}


void PdV_kernel_nopredict_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  double *p_a11,
  double *p_a12,
  double *p_a13,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7,p_a8,p_a9,p_a10,p_a11,p_a12,p_a13)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_PdV_kernel_nopredict*1*1, xdim0_PdV_kernel_nopredict};
      const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_PdV_kernel_nopredict*1*1, xdim1_PdV_kernel_nopredict};
      const ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_PdV_kernel_nopredict*1*1, xdim2_PdV_kernel_nopredict};
      const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_PdV_kernel_nopredict*1*1, xdim3_PdV_kernel_nopredict};
      const ptr_double ptr4 = {  p_a4 + n_x*1*1 + n_y*xdim4_PdV_kernel_nopredict*1*1, xdim4_PdV_kernel_nopredict};
      const ptr_double ptr5 = {  p_a5 + n_x*1*1 + n_y*xdim5_PdV_kernel_nopredict*1*1, xdim5_PdV_kernel_nopredict};
      ptr_double ptr6 = {  p_a6 + n_x*1*1 + n_y*xdim6_PdV_kernel_nopredict*1*1, xdim6_PdV_kernel_nopredict};
      const ptr_double ptr7 = {  p_a7 + n_x*1*1 + n_y*xdim7_PdV_kernel_nopredict*1*1, xdim7_PdV_kernel_nopredict};
      const ptr_double ptr8 = {  p_a8 + n_x*1*1 + n_y*xdim8_PdV_kernel_nopredict*1*1, xdim8_PdV_kernel_nopredict};
      const ptr_double ptr9 = {  p_a9 + n_x*1*1 + n_y*xdim9_PdV_kernel_nopredict*1*1, xdim9_PdV_kernel_nopredict};
      ptr_double ptr10 = {  p_a10 + n_x*1*1 + n_y*xdim10_PdV_kernel_nopredict*1*1, xdim10_PdV_kernel_nopredict};
      const ptr_double ptr11 = {  p_a11 + n_x*1*1 + n_y*xdim11_PdV_kernel_nopredict*1*1, xdim11_PdV_kernel_nopredict};
      const ptr_double ptr12 = {  p_a12 + n_x*1*1 + n_y*xdim12_PdV_kernel_nopredict*1*1, xdim12_PdV_kernel_nopredict};
      ptr_double ptr13 = {  p_a13 + n_x*1*1 + n_y*xdim13_PdV_kernel_nopredict*1*1, xdim13_PdV_kernel_nopredict};
      PdV_kernel_nopredict( ptr0,
          ptr1,ptr2,
          ptr3,ptr4,
          ptr5,ptr6,
          ptr7,ptr8,
          ptr9,ptr10,
          ptr11,ptr12,
          ptr13 );

    }
  }
}
