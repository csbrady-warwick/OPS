//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_tea_leaf_ppcg_reduce_kernel;
int xdim1_tea_leaf_ppcg_reduce_kernel;
int xdim2_tea_leaf_ppcg_reduce_kernel;

//user function
inline 
void tea_leaf_ppcg_reduce_kernel(const ptr_double rstore,
  const ptr_double r,
  const ptr_double z,
  double *rnn) {
  *rnn = *rnn + (OPS_ACC(r, 0,0) - OPS_ACC(rstore, 0,0)) * OPS_ACC(z, 0,0);
}


void tea_leaf_ppcg_reduce_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size, int y_size) {
  double p_a3_0 = p_a3[0];
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2) reduction(+:p_a3_0)
  #pragma acc loop reduction(+:p_a3_0)
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop reduction(+:p_a3_0)
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_tea_leaf_ppcg_reduce_kernel*1*1, xdim0_tea_leaf_ppcg_reduce_kernel};
      const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_tea_leaf_ppcg_reduce_kernel*1*1, xdim1_tea_leaf_ppcg_reduce_kernel};
      const ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_tea_leaf_ppcg_reduce_kernel*1*1, xdim2_tea_leaf_ppcg_reduce_kernel};
      tea_leaf_ppcg_reduce_kernel( ptr0,
          ptr1,ptr2,
           &p_a3_0 );

    }
  }
  p_a3[0] = p_a3_0;
}
