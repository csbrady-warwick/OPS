//
// auto-generated by ops.py
//

int xdim0_tea_leaf_jacobi_kernel;
int xdim1_tea_leaf_jacobi_kernel;
int xdim2_tea_leaf_jacobi_kernel;
int xdim3_tea_leaf_jacobi_kernel;
int xdim4_tea_leaf_jacobi_kernel;


//user function



void tea_leaf_jacobi_kernel_c_wrapper(
  double * restrict u1_p,
  double * restrict Kx_p,
  double * restrict Ky_p,
  double * restrict un_p,
  double * restrict u0_p,
  const double * restrict rx,
  const double * restrict ry,
  double * restrict error_g,
  int x_size, int y_size) {
  double error_0 = error_g[0];
  #pragma omp parallel for reduction(+:error_0)
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      double error[1];
      error[0] = 0;
      ptr_double u1 = { u1_p + n_x*1 + n_y * xdim0_tea_leaf_jacobi_kernel*1, xdim0_tea_leaf_jacobi_kernel};
      const ptr_double Kx = { Kx_p + n_x*1 + n_y * xdim1_tea_leaf_jacobi_kernel*1, xdim1_tea_leaf_jacobi_kernel};
      const ptr_double Ky = { Ky_p + n_x*1 + n_y * xdim2_tea_leaf_jacobi_kernel*1, xdim2_tea_leaf_jacobi_kernel};
      const ptr_double un = { un_p + n_x*1 + n_y * xdim3_tea_leaf_jacobi_kernel*1, xdim3_tea_leaf_jacobi_kernel};
      const ptr_double u0 = { u0_p + n_x*1 + n_y * xdim4_tea_leaf_jacobi_kernel*1, xdim4_tea_leaf_jacobi_kernel};
      
	OPS_ACC(u1, 0,0) = (OPS_ACC(u0, 0,0)
		+ (*rx)*(OPS_ACC(Kx, 1, 0) *OPS_ACC(un, 1, 0) + OPS_ACC(Kx, 0,0)*OPS_ACC(un, -1, 0))
		+ (*ry)*(OPS_ACC(Ky, 0, 1) *OPS_ACC(un, 0, 1) + OPS_ACC(Ky, 0,0)*OPS_ACC(un, 0, -1)))
			/(1.0
				+ (*rx)*(OPS_ACC(Kx, 1, 0) + OPS_ACC(Kx, 0,0))
				+ (*ry)*(OPS_ACC(Ky, 0, 1) + OPS_ACC(Ky, 0,0)));

    *error = *error + fabs(OPS_ACC(u1, 0,0) - OPS_ACC(un, 0,0));

      error_0 +=error[0];
    }
  }
  error_g[0] = error_0;
}
