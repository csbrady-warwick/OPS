//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_drhouupdx_kernel;
int xdim1_drhouupdx_kernel;
int xdim2_drhouupdx_kernel;
int xdim3_drhouupdx_kernel;

//user function
#pragma acc routine
inline 
void drhouupdx_kernel(const ptr_double rhou_new,
  const ptr_double rho_new,
  const ptr_double rhoE_new,
  ptr_double rhou_res) {

			double fni = OPS_ACC(rhou_new, 0) * OPS_ACC(rhou_new, 0) / OPS_ACC(rho_new, 0) ;
			double p = gam1 * (OPS_ACC(rhoE_new, 0) - 0.5 * fni);
			fni = fni + p;
			double fnim1 = OPS_ACC(rhou_new, -1) * OPS_ACC(rhou_new, -1) / OPS_ACC(rho_new, -1);
			p = gam1 * (OPS_ACC(rhoE_new, -1) - 0.5 * fnim1);
			fnim1 = fnim1 + p;
			double fnim2 = OPS_ACC(rhou_new, -2) * OPS_ACC(rhou_new, -2) / OPS_ACC(rho_new, -2);
			p = gam1 * (OPS_ACC(rhoE_new, -2) - 0.5 * fnim2);
			fnim2 = fnim2 + p;
			double fnip1 = OPS_ACC(rhou_new, 1) * OPS_ACC(rhou_new, 1) / OPS_ACC(rho_new, 1);
			p = gam1 * (OPS_ACC(rhoE_new, 1) - 0.5 * fnip1);
			fnip1 = fnip1 + p;
			double fnip2 = OPS_ACC(rhou_new, 2) * OPS_ACC(rhou_new, 2) / OPS_ACC(rho_new, 2);
			p = gam1 * (OPS_ACC(rhoE_new, 2) - 0.5 * fnip2);
			fnip2 = fnip2 + p;

			double deriv = (fnim2 - fnip2 + 8.0* (fnip1 - fnim1))/(12.00*dx);
			OPS_ACC(rhou_res, 0) = deriv;
}


void drhouupdx_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    const ptr_double ptr0 = {  p_a0 + n_x*1*1, };
    const ptr_double ptr1 = {  p_a1 + n_x*1*1, };
    const ptr_double ptr2 = {  p_a2 + n_x*1*1, };
    ptr_double ptr3 = {  p_a3 + n_x*1*1, };
    drhouupdx_kernel( ptr0,
          ptr1,ptr2,
          ptr3 );

  }
}
