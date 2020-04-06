//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_generate_chunk_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
#else
void ops_par_loop_generate_chunk_kernel_execute(ops_kernel_descriptor *desc) {
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
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,8,range,7)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,7,"generate_chunk_kernel");
    block->instance->OPS_kernels[7].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "generate_chunk_kernel");
  #endif


  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #if defined(OPS_MPI) && !defined(OPS_LAZY)
  int arg_idx[2];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 8,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_generate_chunk_kernel = args[0].dat->size[0];
  int xdim1_generate_chunk_kernel = args[1].dat->size[0];
  int xdim2_generate_chunk_kernel = args[2].dat->size[0];
  int xdim3_generate_chunk_kernel = args[3].dat->size[0];
  int xdim4_generate_chunk_kernel = args[4].dat->size[0];
  int xdim5_generate_chunk_kernel = args[5].dat->size[0];
  int xdim6_generate_chunk_kernel = args[6].dat->size[0];
  int xdim7_generate_chunk_kernel = args[7].dat->size[0];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ vertexx_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ vertexy_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ energy0_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ density0_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ xvel0_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ yvel0_p = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ cellx_p = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  double * __restrict__ celly_p = (double *)(args[7].data + base7);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 8);
  ops_halo_exchanges(args,8,range);
  ops_H_D_exchanges_host(args, 8);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[7].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #ifdef __INTEL_COMPILER
    #pragma loop_count(10000)
    #pragma omp simd
    #elif defined(__clang__)
    #pragma clang loop vectorize(assume_safety)
    #elif defined(__GNUC__)
    #pragma GCC ivdep
    #else
    #pragma simd
    #endif
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      const ACC<double> vertexx(xdim0_generate_chunk_kernel, vertexx_p + n_x*1 + n_y * xdim0_generate_chunk_kernel*0);
      const ACC<double> vertexy(xdim1_generate_chunk_kernel, vertexy_p + n_x*0 + n_y * xdim1_generate_chunk_kernel*1);
      ACC<double> energy0(xdim2_generate_chunk_kernel, energy0_p + n_x*1 + n_y * xdim2_generate_chunk_kernel*1);
      ACC<double> density0(xdim3_generate_chunk_kernel, density0_p + n_x*1 + n_y * xdim3_generate_chunk_kernel*1);
      ACC<double> xvel0(xdim4_generate_chunk_kernel, xvel0_p + n_x*1 + n_y * xdim4_generate_chunk_kernel*1);
      ACC<double> yvel0(xdim5_generate_chunk_kernel, yvel0_p + n_x*1 + n_y * xdim5_generate_chunk_kernel*1);
      const ACC<double> cellx(xdim6_generate_chunk_kernel, cellx_p + n_x*1 + n_y * xdim6_generate_chunk_kernel*0);
      const ACC<double> celly(xdim7_generate_chunk_kernel, celly_p + n_x*0 + n_y * xdim7_generate_chunk_kernel*1);
      

  double radius, x_cent, y_cent;
  int is_in = 0;
  int is_in2 = 0;


  energy0(0,0)= states[0].energy;
  density0(0,0)= states[0].density;
  xvel0(0,0)=states[0].xvel;
  yvel0(0,0)=states[0].yvel;

  for(int i = 1; i<number_of_states; i++) {

    x_cent=states[i].xmin;
    y_cent=states[i].ymin;
    is_in = 0;
    is_in2 = 0;

    if (states[i].geometry == g_rect) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          if(vertexx(1+i1,0) >= states[i].xmin  && vertexx(0+i1,0) < states[i].xmax) {
            if(vertexy(0,1+j1) >= states[i].ymin && vertexy(0,0+j1) < states[i].ymax) {
              is_in = 1;
            }
          }
        }
      }
      if(vertexx(1,0) >= states[i].xmin  && vertexx(0,0) < states[i].xmax) {
        if(vertexy(0,1) >= states[i].ymin && vertexy(0,0) < states[i].ymax) {
          is_in2 = 1;
        }
      }
      if (is_in2) {
        energy0(0,0) = states[i].energy;
        density0(0,0) = states[i].density;
      }
      if (is_in) {
        xvel0(0,0) = states[i].xvel;
        yvel0(0,0) = states[i].yvel;
      }
    }
    else if(states[i].geometry == g_circ) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          radius = sqrt ((cellx(i1,0) - x_cent) * (cellx(i1,0) - x_cent) +
                     (celly(0,j1) - y_cent) * (celly(0,j1) - y_cent));
          if (radius <= states[i].radius) {
            is_in = 1;
          }
        }
      }
      if (radius <= states[i].radius) is_in2 = 1;

      if (is_in2) {
        energy0(0,0) = states[i].energy;
        density0(0,0) = states[i].density;
      }

      if (is_in) {
        xvel0(0,0) = states[i].xvel;
        yvel0(0,0) = states[i].yvel;
      }
    }
    else if(states[i].geometry == g_point) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          if(vertexx(i1,0) == x_cent && vertexy(0,j1) == y_cent) {
            is_in = 1;
          }
        }
      }
      if(vertexx(0,0) == x_cent && vertexy(0,0) == y_cent)
        is_in2 = 1;

      if (is_in2) {
        energy0(0,0) = states[i].energy;
        density0(0,0) = states[i].density;
      }

      if (is_in) {
        xvel0(0,0) = states[i].xvel;
        yvel0(0,0) = states[i].yvel;
      }
    }
  }

    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[7].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 8);
  ops_set_halo_dirtybit3(&args[2],range);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[5],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[7].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg6);
    block->instance->OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg7);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_generate_chunk_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 7;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 7;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 8;
  desc->args = (ops_arg*)malloc(8*sizeof(ops_arg));
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
  desc->function = ops_par_loop_generate_chunk_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,7,"generate_chunk_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
