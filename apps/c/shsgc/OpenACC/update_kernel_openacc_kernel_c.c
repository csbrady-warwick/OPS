//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_update_kernel;
int xdim1_update_kernel;
int xdim2_update_kernel;
int xdim3_update_kernel;

//user function
#pragma acc routine
inline 
void update_kernel(ptr_double rho_new,
  ptr_double rhou_new,
  ptr_double rhoE_new,
  const ptrm_double s) {
		OPS_ACC(rho_new, 0)  = OPS_ACC(rho_new, 0)  + OPS_ACC(s, 0,0);
		OPS_ACC(rhou_new, 0) = OPS_ACC(rhou_new, 0) + OPS_ACC(s, 1,0);
		OPS_ACC(rhoE_new, 0) = OPS_ACC(rhoE_new, 0) + OPS_ACC(s, 2,0);
}


void update_kernel_c_wrapper(
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
    ptr_double ptr0 = {  p_a0 + n_x*1*1, };
    ptr_double ptr1 = {  p_a1 + n_x*1*1, };
    ptr_double ptr2 = {  p_a2 + n_x*1*1, };
    #ifdef OPS_SOA
    const ptrm_double ptr3 = {  p_a3 + n_x*1*3, xdim3_update_kernel};
    #else
    const ptrm_double ptr3 = {  p_a3 + n_x*1*3, 3};
    #endif
    update_kernel( ptr0,
          ptr1,ptr2,
          ptr3 );

  }
}
