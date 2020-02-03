//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_gridgen_kernel;

//user function
#pragma acc routine
inline 
void gridgen_kernel(ptr_double x,
  const int *id) {

  OPS_ACC(x, 0) = xt +  id[0] *dx;

}


void gridgen_kernel_c_wrapper(
  double *p_a0,
  int *p_a1,
  int arg_idx0,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    int arg_idx[] = {arg_idx0+n_x};
    ptr_double ptr0 = {  p_a0 + n_x*1*1 };
    gridgen_kernel( ptr0,
          arg_idx );

  }
}
