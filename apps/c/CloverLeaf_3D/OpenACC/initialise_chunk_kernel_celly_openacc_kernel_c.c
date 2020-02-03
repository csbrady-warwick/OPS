//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_initialise_chunk_kernel_celly;
int ydim0_initialise_chunk_kernel_celly;
int xdim1_initialise_chunk_kernel_celly;
int ydim1_initialise_chunk_kernel_celly;
int xdim2_initialise_chunk_kernel_celly;
int ydim2_initialise_chunk_kernel_celly;

//user function
#pragma acc routine
inline 
void initialise_chunk_kernel_celly(const ptr_double vertexy,
  ptr_double  celly,
  ptr_double celldy) {
  double d_y = (grid.ymax - grid.ymin)/(double)grid.y_cells;
  OPS_ACC(celly, 0,0,0)  = 0.5*( OPS_ACC(vertexy, 0,0,0) + OPS_ACC(vertexy, 0,1,0) );
  OPS_ACC(celldy, 0,0,0)  = d_y;
  if(OPS_ACC(celldy, 0,0,0) < 0) {


  }
}


void initialise_chunk_kernel_celly_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2)
  #pragma acc loop
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double ptr0 = {  p_a0 + n_x*0*1 + n_y*xdim0_initialise_chunk_kernel_celly*1*1 + n_z*xdim0_initialise_chunk_kernel_celly*ydim0_initialise_chunk_kernel_celly*0*1, xdim0_initialise_chunk_kernel_celly, ydim0_initialise_chunk_kernel_celly};
        ptr_double ptr1 = {  p_a1 + n_x*0*1 + n_y*xdim1_initialise_chunk_kernel_celly*1*1 + n_z*xdim1_initialise_chunk_kernel_celly*ydim1_initialise_chunk_kernel_celly*0*1, xdim1_initialise_chunk_kernel_celly, ydim1_initialise_chunk_kernel_celly};
        ptr_double ptr2 = {  p_a2 + n_x*0*1 + n_y*xdim2_initialise_chunk_kernel_celly*1*1 + n_z*xdim2_initialise_chunk_kernel_celly*ydim2_initialise_chunk_kernel_celly*0*1, xdim2_initialise_chunk_kernel_celly, ydim2_initialise_chunk_kernel_celly};
        initialise_chunk_kernel_celly( ptr0,
          ptr1,
          ptr2 );

      }
    }
  }
}
