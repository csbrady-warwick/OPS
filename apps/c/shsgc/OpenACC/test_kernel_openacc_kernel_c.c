//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_test_kernel;

//user function
#pragma acc routine
inline 
void test_kernel(const ptr_double rho_new,
  double *rms) {

  rms[0] = rms[0] + pow (OPS_ACC(rho_new, 0), 2.0);
}


void test_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  int x_size) {
  double p_a1_0 = p_a1[0];
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0) reduction(+:p_a1_0)
  #pragma acc loop reduction(+:p_a1_0)
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    const ptr_double ptr0 = {  p_a0 + n_x*1*1, };
    test_kernel( ptr0,
           &p_a1_0 );

  }
  p_a1[0] = p_a1_0;
}
