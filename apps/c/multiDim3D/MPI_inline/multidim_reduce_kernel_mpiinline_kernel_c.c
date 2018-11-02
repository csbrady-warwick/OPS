//
// auto-generated by ops.py
//

int xdim0_multidim_reduce_kernel;
int ydim0_multidim_reduce_kernel;
int zdim0_multidim_reduce_kernel;


#define OPS_ACC_MD0(d,x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim0_multidim_reduce_kernel + (n_z*1+(z))*xdim0_multidim_reduce_kernel*ydim0_multidim_reduce_kernel+(d)*xdim0_multidim_reduce_kernel*ydim0_multidim_reduce_kernel*zdim0_multidim_reduce_kernel)
//user function



void multidim_reduce_kernel_c_wrapper(
  const double * restrict val,
  double * restrict redu_dat1_g,
  int x_size, int y_size, int z_size) {
  double redu_dat1_0 = redu_dat1_g[0];
  double redu_dat1_1 = redu_dat1_g[1];
  double redu_dat1_2 = redu_dat1_g[2];
  #pragma omp parallel for reduction(+:redu_dat1_0) reduction(+:redu_dat1_1) reduction(+:redu_dat1_2)
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        double redu_dat1[3];
        redu_dat1[0] = ZERO_double;
        redu_dat1[1] = ZERO_double;
        redu_dat1[2] = ZERO_double;
        

  redu_dat1[0] = redu_dat1[0] + val(0,0,0,0);
  redu_dat1[1] = redu_dat1[1] + val(1,0,0,0);
  redu_dat1[2] = redu_dat1[2] + val(2,0,0,0);

        redu_dat1_0 +=redu_dat1[0];
        redu_dat1_1 +=redu_dat1[1];
        redu_dat1_2 +=redu_dat1[2];
      }
    }
  }
  redu_dat1_g[0] = redu_dat1_0;
  redu_dat1_g[1] = redu_dat1_1;
  redu_dat1_g[2] = redu_dat1_2;
}

#undef OPS_ACC_MD0
