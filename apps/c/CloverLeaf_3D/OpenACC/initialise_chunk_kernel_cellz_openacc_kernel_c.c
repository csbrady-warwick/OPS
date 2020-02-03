//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_initialise_chunk_kernel_cellz;
int ydim0_initialise_chunk_kernel_cellz;
int xdim1_initialise_chunk_kernel_cellz;
int ydim1_initialise_chunk_kernel_cellz;
int xdim2_initialise_chunk_kernel_cellz;
int ydim2_initialise_chunk_kernel_cellz;

//user function
#pragma acc routine
inline 
void initialise_chunk_kernel_cellz(const ptr_double vertexz,
  ptr_double  cellz,
  ptr_double celldz) {
  double d_z = (grid.zmax - grid.zmin)/(double)grid.z_cells;
  OPS_ACC(cellz, 0,0,0)  = 0.5*( OPS_ACC(vertexz, 0,0,0) + OPS_ACC(vertexz, 0,0,1) );
  OPS_ACC(celldz, 0,0,0)  = d_z;




}


void initialise_chunk_kernel_cellz_c_wrapper(
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
        const ptr_double ptr0 = {  p_a0 + n_x*0*1 + n_y*xdim0_initialise_chunk_kernel_cellz*0*1 + n_z*xdim0_initialise_chunk_kernel_cellz*ydim0_initialise_chunk_kernel_cellz*1*1, xdim0_initialise_chunk_kernel_cellz, ydim0_initialise_chunk_kernel_cellz};
        ptr_double ptr1 = {  p_a1 + n_x*0*1 + n_y*xdim1_initialise_chunk_kernel_cellz*0*1 + n_z*xdim1_initialise_chunk_kernel_cellz*ydim1_initialise_chunk_kernel_cellz*1*1, xdim1_initialise_chunk_kernel_cellz, ydim1_initialise_chunk_kernel_cellz};
        ptr_double ptr2 = {  p_a2 + n_x*0*1 + n_y*xdim2_initialise_chunk_kernel_cellz*0*1 + n_z*xdim2_initialise_chunk_kernel_cellz*ydim2_initialise_chunk_kernel_cellz*1*1, xdim2_initialise_chunk_kernel_cellz, ydim2_initialise_chunk_kernel_cellz};
        initialise_chunk_kernel_cellz( ptr0,
          ptr1,
          ptr2 );

      }
    }
  }
}
