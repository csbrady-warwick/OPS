//
// auto-generated by ops.py
//

int xdim0_copy;
int xdim1_copy;


//user function



void copy_c_wrapper(
  double * restrict A_p,
  double * restrict Anew_p,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double A = { A_p + n_x*1 + n_y * xdim0_copy*1, xdim0_copy};
      const ptr_double Anew = { Anew_p + n_x*1 + n_y * xdim1_copy*1, xdim1_copy};
      
  OPS_ACC(A, 0,0) = OPS_ACC(Anew, 0,0);

    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1

