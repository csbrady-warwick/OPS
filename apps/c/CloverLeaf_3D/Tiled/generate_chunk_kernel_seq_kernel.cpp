//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y,z) (n_x*1+n_y*xdim0_generate_chunk_kernel*0+n_z*xdim0_generate_chunk_kernel*ydim0_generate_chunk_kernel*0+x+xdim0_generate_chunk_kernel*(y)+xdim0_generate_chunk_kernel*ydim0_generate_chunk_kernel*(z))
#define OPS_ACC1(x,y,z) (n_x*0+n_y*xdim1_generate_chunk_kernel*1+n_z*xdim1_generate_chunk_kernel*ydim1_generate_chunk_kernel*0+x+xdim1_generate_chunk_kernel*(y)+xdim1_generate_chunk_kernel*ydim1_generate_chunk_kernel*(z))
#define OPS_ACC2(x,y,z) (n_x*0+n_y*xdim2_generate_chunk_kernel*0+n_z*xdim2_generate_chunk_kernel*ydim2_generate_chunk_kernel*1+x+xdim2_generate_chunk_kernel*(y)+xdim2_generate_chunk_kernel*ydim2_generate_chunk_kernel*(z))
#define OPS_ACC3(x,y,z) (n_x*1+n_y*xdim3_generate_chunk_kernel*1+n_z*xdim3_generate_chunk_kernel*ydim3_generate_chunk_kernel*1+x+xdim3_generate_chunk_kernel*(y)+xdim3_generate_chunk_kernel*ydim3_generate_chunk_kernel*(z))
#define OPS_ACC4(x,y,z) (n_x*1+n_y*xdim4_generate_chunk_kernel*1+n_z*xdim4_generate_chunk_kernel*ydim4_generate_chunk_kernel*1+x+xdim4_generate_chunk_kernel*(y)+xdim4_generate_chunk_kernel*ydim4_generate_chunk_kernel*(z))
#define OPS_ACC5(x,y,z) (n_x*1+n_y*xdim5_generate_chunk_kernel*1+n_z*xdim5_generate_chunk_kernel*ydim5_generate_chunk_kernel*1+x+xdim5_generate_chunk_kernel*(y)+xdim5_generate_chunk_kernel*ydim5_generate_chunk_kernel*(z))
#define OPS_ACC6(x,y,z) (n_x*1+n_y*xdim6_generate_chunk_kernel*1+n_z*xdim6_generate_chunk_kernel*ydim6_generate_chunk_kernel*1+x+xdim6_generate_chunk_kernel*(y)+xdim6_generate_chunk_kernel*ydim6_generate_chunk_kernel*(z))
#define OPS_ACC7(x,y,z) (n_x*1+n_y*xdim7_generate_chunk_kernel*1+n_z*xdim7_generate_chunk_kernel*ydim7_generate_chunk_kernel*1+x+xdim7_generate_chunk_kernel*(y)+xdim7_generate_chunk_kernel*ydim7_generate_chunk_kernel*(z))
#define OPS_ACC8(x,y,z) (n_x*1+n_y*xdim8_generate_chunk_kernel*0+n_z*xdim8_generate_chunk_kernel*ydim8_generate_chunk_kernel*0+x+xdim8_generate_chunk_kernel*(y)+xdim8_generate_chunk_kernel*ydim8_generate_chunk_kernel*(z))
#define OPS_ACC9(x,y,z) (n_x*0+n_y*xdim9_generate_chunk_kernel*1+n_z*xdim9_generate_chunk_kernel*ydim9_generate_chunk_kernel*0+x+xdim9_generate_chunk_kernel*(y)+xdim9_generate_chunk_kernel*ydim9_generate_chunk_kernel*(z))
#define OPS_ACC10(x,y,z) (n_x*0+n_y*xdim10_generate_chunk_kernel*0+n_z*xdim10_generate_chunk_kernel*ydim10_generate_chunk_kernel*1+x+xdim10_generate_chunk_kernel*(y)+xdim10_generate_chunk_kernel*ydim10_generate_chunk_kernel*(z))


//user function

// host stub function
#ifdef OPS_HYBRID
void ops_par_loop_generate_chunk_kernel_execute_cpu(ops_kernel_descriptor *desc) {
#else
void ops_par_loop_generate_chunk_kernel_execute(ops_kernel_descriptor *desc) {
#endif
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  ops_arg arg6 = desc->args[6];
  ops_arg arg7 = desc->args[7];
  ops_arg arg8 = desc->args[8];
  ops_arg arg9 = desc->args[9];
  ops_arg arg10 = desc->args[10];

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[11] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,11,range,56)) return;
  #endif

  if (OPS_diags > 1) {
    OPS_kernels[56].count++;
    ops_timers_core(&c2,&t2);
  }

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];

  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "generate_chunk_kernel");
  #endif



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  const double * __restrict__ vertexx = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double * __restrict__ vertexy = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  const double * __restrict__ vertexz = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ energy0 = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ density0 = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ xvel0 = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ yvel0 = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  double * __restrict__ zvel0 = (double *)(args[7].data + base7);

  int base8 = args[8].dat->base_offset;
  const double * __restrict__ cellx = (double *)(args[8].data + base8);

  int base9 = args[9].dat->base_offset;
  const double * __restrict__ celly = (double *)(args[9].data + base9);

  int base10 = args[10].dat->base_offset;
  const double * __restrict__ cellz = (double *)(args[10].data + base10);


  //initialize global variable with the dimension of dats
  int xdim0_generate_chunk_kernel = args[0].dat->size[0];
  int ydim0_generate_chunk_kernel = args[0].dat->size[1];
  int xdim1_generate_chunk_kernel = args[1].dat->size[0];
  int ydim1_generate_chunk_kernel = args[1].dat->size[1];
  int xdim2_generate_chunk_kernel = args[2].dat->size[0];
  int ydim2_generate_chunk_kernel = args[2].dat->size[1];
  int xdim3_generate_chunk_kernel = args[3].dat->size[0];
  int ydim3_generate_chunk_kernel = args[3].dat->size[1];
  int xdim4_generate_chunk_kernel = args[4].dat->size[0];
  int ydim4_generate_chunk_kernel = args[4].dat->size[1];
  int xdim5_generate_chunk_kernel = args[5].dat->size[0];
  int ydim5_generate_chunk_kernel = args[5].dat->size[1];
  int xdim6_generate_chunk_kernel = args[6].dat->size[0];
  int ydim6_generate_chunk_kernel = args[6].dat->size[1];
  int xdim7_generate_chunk_kernel = args[7].dat->size[0];
  int ydim7_generate_chunk_kernel = args[7].dat->size[1];
  int xdim8_generate_chunk_kernel = args[8].dat->size[0];
  int ydim8_generate_chunk_kernel = args[8].dat->size[1];
  int xdim9_generate_chunk_kernel = args[9].dat->size[0];
  int ydim9_generate_chunk_kernel = args[9].dat->size[1];
  int xdim10_generate_chunk_kernel = args[10].dat->size[0];
  int ydim10_generate_chunk_kernel = args[10].dat->size[1];

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[56].mpi_time += t1-t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef intel
      #pragma loop_count(10000)
      #pragma omp simd aligned(vertexx,vertexy,vertexz,energy0,density0,xvel0,yvel0,zvel0,cellx,celly,cellz)
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        

  double radius, x_cent, y_cent, z_cent;
  int is_in = 0;


  energy0[OPS_ACC3(0,0,0)]= states[0].energy;
  density0[OPS_ACC4(0,0,0)]= states[0].density;
  xvel0[OPS_ACC5(0,0,0)]=states[0].xvel;
  yvel0[OPS_ACC6(0,0,0)]=states[0].yvel;
  zvel0[OPS_ACC7(0,0,0)]=states[0].zvel;

  for(int i = 1; i<number_of_states; i++) {

    x_cent=states[i].xmin;
    y_cent=states[i].ymin;
    z_cent=states[i].zmin;

    if (states[i].geometry == g_cube) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          for (int k1 = -1; k1 <= 0; k1++) {
            if(vertexx[OPS_ACC0(1+i1,0,0)] >= states[i].xmin  && vertexx[OPS_ACC0(0+i1,0,0)] < states[i].xmax) {
              if(vertexy[OPS_ACC1(0,1+j1,0)] >= states[i].ymin && vertexy[OPS_ACC1(0,0+j1,0)] < states[i].ymax) {
                if(vertexz[OPS_ACC2(0,0,1+k1)] >= states[i].zmin && vertexz[OPS_ACC2(0,0,0+k1)] < states[i].zmax) {
                  is_in=1;
                }
              }
            }
          }
        }
      }

      if(vertexx[OPS_ACC0(1,0,0)] >= states[i].xmin  && vertexx[OPS_ACC0(0,0,0)] < states[i].xmax) {
        if(vertexy[OPS_ACC1(0,1,0)] >= states[i].ymin && vertexy[OPS_ACC1(0,0,0)] < states[i].ymax) {
          if(vertexz[OPS_ACC2(0,0,1)] >= states[i].zmin && vertexz[OPS_ACC2(0,0,0)] < states[i].zmax) {
            energy0[OPS_ACC3(0,0,0)] = states[i].energy;
            density0[OPS_ACC4(0,0,0)] = states[i].density;
          }
        }
      }

      if (is_in) {
        xvel0[OPS_ACC5(0,0,0)] = states[i].xvel;
        yvel0[OPS_ACC6(0,0,0)] = states[i].yvel;
        zvel0[OPS_ACC7(0,0,0)] = states[i].zvel;
      }
    }
    else if(states[i].geometry == g_sphe) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          for (int k1 = -1; k1 <= 0; k1++) {
            radius = sqrt ((cellx[OPS_ACC8(0,0,0)] - x_cent) * (cellx[OPS_ACC8(0,0,0)] - x_cent) +
                     (celly[OPS_ACC9(0,0,0)] - y_cent) * (celly[OPS_ACC9(0,0,0)] - y_cent) +
                     (cellz[OPS_ACC10(0,0,0)] - z_cent) * (cellz[OPS_ACC10(0,0,0)] - z_cent));
            if(radius <= states[i].radius) is_in = 1;
          }
        }
      }
      if(radius <= states[i].radius) {
        energy0[OPS_ACC3(0,0,0)] = states[i].energy;
        density0[OPS_ACC4(0,0,0)] = states[i].density;
      }
      if (is_in) {
        xvel0[OPS_ACC5(0,0,0)] = states[i].xvel;
        yvel0[OPS_ACC6(0,0,0)] = states[i].yvel;
        zvel0[OPS_ACC7(0,0,0)] = states[i].zvel;

      }
    }
    else if(states[i].geometry == g_point) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          for (int k1 = -1; k1 <= 0; k1++) {
            if(vertexx[OPS_ACC0(0+i1,0,0)] == x_cent && vertexy[OPS_ACC1(0,0+j1,0)] == y_cent && vertexz[OPS_ACC2(0,0,0+k1)] == z_cent)
              is_in = 1;
          }
        }
      }

      if(vertexx[OPS_ACC0(0,0,0)] == x_cent && vertexy[OPS_ACC1(0,0,0)] == y_cent && vertexz[OPS_ACC2(0,0,0)] == z_cent) {
        energy0[OPS_ACC3(0,0,0)] = states[i].energy;
        density0[OPS_ACC4(0,0,0)] = states[i].density;
      }
      if (is_in) {
        xvel0[OPS_ACC5(0,0,0)] = states[i].xvel;
        yvel0[OPS_ACC6(0,0,0)] = states[i].yvel;
        zvel0[OPS_ACC7(0,0,0)] = states[i].zvel;
      }
    }
  }

      }
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[56].time += t2-t1;
  }

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c1,&t1);
    OPS_kernels[56].mpi_time += t1-t2;
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg7);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg8);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg9);
    OPS_kernels[56].transfer += ops_compute_transfer(dim, start, end, &arg10);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10


#ifndef OPS_HYBRID
void ops_par_loop_generate_chunk_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 56;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 56;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 11;
  desc->args = (ops_arg*)malloc(11*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->args[6] = arg6;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg6.dat->index;
  desc->args[7] = arg7;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg7.dat->index;
  desc->args[8] = arg8;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg8.dat->index;
  desc->args[9] = arg9;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg9.dat->index;
  desc->args[10] = arg10;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg10.dat->index;
  desc->function = ops_par_loop_generate_chunk_kernel_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(56,"generate_chunk_kernel");
  }
  ops_enqueue_kernel(desc);
  }
  #endif
