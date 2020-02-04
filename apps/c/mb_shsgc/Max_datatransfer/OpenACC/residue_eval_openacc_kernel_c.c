//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_residue_eval;
int xdim1_residue_eval;
int xdim2_residue_eval;
int xdim3_residue_eval;
int xdim4_residue_eval;
int xdim5_residue_eval;

//user function
inline void residue_eval(const ptr_double der1, const ptr_double der2,
                         const ptr_double der3, ptr_double rho_res,
                         ptr_double rhou_res, ptr_double rhoE_res) {
  OPS_ACC(rho_res, 0) = OPS_ACC(der1, 0);
  OPS_ACC(rhou_res, 0) = OPS_ACC(der2, 0);
  OPS_ACC(rhoE_res, 0) = OPS_ACC(der3, 0);
  }


void residue_eval_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    const ptr_double ptr0 = {p_a0 + n_x * 1 * 1};
    const ptr_double ptr1 = {p_a1 + n_x * 1 * 1};
    const ptr_double ptr2 = {p_a2 + n_x * 1 * 1};
    ptr_double ptr3 = {p_a3 + n_x * 1 * 1};
    ptr_double ptr4 = {p_a4 + n_x * 1 * 1};
    ptr_double ptr5 = {p_a5 + n_x * 1 * 1};
    residue_eval(ptr0, ptr1, ptr2, ptr3, ptr4, ptr5);
  }
}
