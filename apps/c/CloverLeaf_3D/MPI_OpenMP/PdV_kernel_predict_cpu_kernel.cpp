//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_PdV_kernel_predict(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13) {
#else
void ops_par_loop_PdV_kernel_predict_execute(ops_kernel_descriptor *desc) {
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
  ops_arg arg11 = desc->args[11];
  ops_arg arg12 = desc->args[12];
  ops_arg arg13 = desc->args[13];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[14] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,14,range,102)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,102,"PdV_kernel_predict");
    block->instance->OPS_kernels[102].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "PdV_kernel_predict");
  #endif


  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #ifdef OPS_MPI
  int arg_idx[3];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 14,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_PdV_kernel_predict = args[0].dat->size[0];
  int ydim0_PdV_kernel_predict = args[0].dat->size[1];
  int xdim1_PdV_kernel_predict = args[1].dat->size[0];
  int ydim1_PdV_kernel_predict = args[1].dat->size[1];
  int xdim2_PdV_kernel_predict = args[2].dat->size[0];
  int ydim2_PdV_kernel_predict = args[2].dat->size[1];
  int xdim3_PdV_kernel_predict = args[3].dat->size[0];
  int ydim3_PdV_kernel_predict = args[3].dat->size[1];
  int xdim4_PdV_kernel_predict = args[4].dat->size[0];
  int ydim4_PdV_kernel_predict = args[4].dat->size[1];
  int xdim5_PdV_kernel_predict = args[5].dat->size[0];
  int ydim5_PdV_kernel_predict = args[5].dat->size[1];
  int xdim6_PdV_kernel_predict = args[6].dat->size[0];
  int ydim6_PdV_kernel_predict = args[6].dat->size[1];
  int xdim7_PdV_kernel_predict = args[7].dat->size[0];
  int ydim7_PdV_kernel_predict = args[7].dat->size[1];
  int xdim8_PdV_kernel_predict = args[8].dat->size[0];
  int ydim8_PdV_kernel_predict = args[8].dat->size[1];
  int xdim9_PdV_kernel_predict = args[9].dat->size[0];
  int ydim9_PdV_kernel_predict = args[9].dat->size[1];
  int xdim10_PdV_kernel_predict = args[10].dat->size[0];
  int ydim10_PdV_kernel_predict = args[10].dat->size[1];
  int xdim11_PdV_kernel_predict = args[11].dat->size[0];
  int ydim11_PdV_kernel_predict = args[11].dat->size[1];
  int xdim12_PdV_kernel_predict = args[12].dat->size[0];
  int ydim12_PdV_kernel_predict = args[12].dat->size[1];
  int xdim13_PdV_kernel_predict = args[13].dat->size[0];
  int ydim13_PdV_kernel_predict = args[13].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ xarea_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ xvel0_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ yarea_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ yvel0_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ volume_change_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ volume_p = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ pressure_p = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  double * __restrict__ density0_p = (double *)(args[7].data + base7);

  int base8 = args[8].dat->base_offset;
  double * __restrict__ density1_p = (double *)(args[8].data + base8);

  int base9 = args[9].dat->base_offset;
  double * __restrict__ viscosity_p = (double *)(args[9].data + base9);

  int base10 = args[10].dat->base_offset;
  double * __restrict__ energy0_p = (double *)(args[10].data + base10);

  int base11 = args[11].dat->base_offset;
  double * __restrict__ energy1_p = (double *)(args[11].data + base11);

  int base12 = args[12].dat->base_offset;
  double * __restrict__ zarea_p = (double *)(args[12].data + base12);

  int base13 = args[13].dat->base_offset;
  double * __restrict__ zvel0_p = (double *)(args[13].data + base13);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 14);
  ops_halo_exchanges(args,14,range);
  ops_H_D_exchanges_host(args, 14);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[102].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
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
        const ACC<double> xarea(xdim0_PdV_kernel_predict, ydim0_PdV_kernel_predict, xarea_p + n_x*1 + n_y * xdim0_PdV_kernel_predict*1 + n_z * xdim0_PdV_kernel_predict * ydim0_PdV_kernel_predict*1);
        const ACC<double> xvel0(xdim1_PdV_kernel_predict, ydim1_PdV_kernel_predict, xvel0_p + n_x*1 + n_y * xdim1_PdV_kernel_predict*1 + n_z * xdim1_PdV_kernel_predict * ydim1_PdV_kernel_predict*1);
        const ACC<double> yarea(xdim2_PdV_kernel_predict, ydim2_PdV_kernel_predict, yarea_p + n_x*1 + n_y * xdim2_PdV_kernel_predict*1 + n_z * xdim2_PdV_kernel_predict * ydim2_PdV_kernel_predict*1);
        const ACC<double> yvel0(xdim3_PdV_kernel_predict, ydim3_PdV_kernel_predict, yvel0_p + n_x*1 + n_y * xdim3_PdV_kernel_predict*1 + n_z * xdim3_PdV_kernel_predict * ydim3_PdV_kernel_predict*1);
        ACC<double> volume_change(xdim4_PdV_kernel_predict, ydim4_PdV_kernel_predict, volume_change_p + n_x*1 + n_y * xdim4_PdV_kernel_predict*1 + n_z * xdim4_PdV_kernel_predict * ydim4_PdV_kernel_predict*1);
        const ACC<double> volume(xdim5_PdV_kernel_predict, ydim5_PdV_kernel_predict, volume_p + n_x*1 + n_y * xdim5_PdV_kernel_predict*1 + n_z * xdim5_PdV_kernel_predict * ydim5_PdV_kernel_predict*1);
        const ACC<double> pressure(xdim6_PdV_kernel_predict, ydim6_PdV_kernel_predict, pressure_p + n_x*1 + n_y * xdim6_PdV_kernel_predict*1 + n_z * xdim6_PdV_kernel_predict * ydim6_PdV_kernel_predict*1);
        const ACC<double> density0(xdim7_PdV_kernel_predict, ydim7_PdV_kernel_predict, density0_p + n_x*1 + n_y * xdim7_PdV_kernel_predict*1 + n_z * xdim7_PdV_kernel_predict * ydim7_PdV_kernel_predict*1);
        ACC<double> density1(xdim8_PdV_kernel_predict, ydim8_PdV_kernel_predict, density1_p + n_x*1 + n_y * xdim8_PdV_kernel_predict*1 + n_z * xdim8_PdV_kernel_predict * ydim8_PdV_kernel_predict*1);
        const ACC<double> viscosity(xdim9_PdV_kernel_predict, ydim9_PdV_kernel_predict, viscosity_p + n_x*1 + n_y * xdim9_PdV_kernel_predict*1 + n_z * xdim9_PdV_kernel_predict * ydim9_PdV_kernel_predict*1);
        const ACC<double> energy0(xdim10_PdV_kernel_predict, ydim10_PdV_kernel_predict, energy0_p + n_x*1 + n_y * xdim10_PdV_kernel_predict*1 + n_z * xdim10_PdV_kernel_predict * ydim10_PdV_kernel_predict*1);
        ACC<double> energy1(xdim11_PdV_kernel_predict, ydim11_PdV_kernel_predict, energy1_p + n_x*1 + n_y * xdim11_PdV_kernel_predict*1 + n_z * xdim11_PdV_kernel_predict * ydim11_PdV_kernel_predict*1);
        const ACC<double> zarea(xdim12_PdV_kernel_predict, ydim12_PdV_kernel_predict, zarea_p + n_x*1 + n_y * xdim12_PdV_kernel_predict*1 + n_z * xdim12_PdV_kernel_predict * ydim12_PdV_kernel_predict*1);
        const ACC<double> zvel0(xdim13_PdV_kernel_predict, ydim13_PdV_kernel_predict, zvel0_p + n_x*1 + n_y * xdim13_PdV_kernel_predict*1 + n_z * xdim13_PdV_kernel_predict * ydim13_PdV_kernel_predict*1);
        

  double recip_volume, energy_change;
  double right_flux, left_flux, top_flux, bottom_flux, back_flux, front_flux, total_flux;

  left_flux = ( xarea(0,0,0) * ( xvel0(0,0,0) + xvel0(0,1,0) +
                                           xvel0(0,0,1) + xvel0(0,1,1) +
                                           xvel0(0,0,0) + xvel0(0,1,0) +
                                           xvel0(0,0,1) + xvel0(0,1,1) ) ) * 0.125 * dt * 0.5;
  right_flux = ( xarea(1,0,0) * ( xvel0(1,0,0) + xvel0(1,1,0) +
                                            xvel0(1,0,1) + xvel0(1,1,1) +
                                            xvel0(1,0,0) + xvel0(1,1,0) +
                                            xvel0(1,0,1) + xvel0(1,1,1) ) ) * 0.125 * dt * 0.5;

  bottom_flux = ( yarea(0,0,0) * ( yvel0(0,0,0) + yvel0(1,0,0) +
                                             yvel0(0,0,1) + yvel0(1,0,1) +
                                             yvel0(0,0,0) + yvel0(1,0,0) +
                                             yvel0(0,0,1) + yvel0(1,0,1) ) ) * 0.125* dt * 0.5;
  top_flux = ( yarea(0,1,0) * ( yvel0(0,1,0) + yvel0(1,1,0) +
                                          yvel0(0,1,1) + yvel0(1,1,1) +
                                          yvel0(0,1,0) + yvel0(1,1,0) +
                                          yvel0(0,1,1) + yvel0(1,1,1) ) ) * 0.125 * dt * 0.5;

  back_flux = ( zarea(0,0,0) * ( zvel0(0,0,0) + zvel0(1,0,0) +
                                            zvel0(0,1,0) + zvel0(1,1,0) +
                                            zvel0(0,0,0) + zvel0(1,0,0) +
                                            zvel0(0,1,0) + zvel0(1,1,0) ) ) * 0.125* dt * 0.5;
  front_flux = ( zarea(0,0,1) * ( zvel0(0,0,1) + zvel0(1,0,1) +
                                             zvel0(0,1,1) + zvel0(1,1,1) +
                                             zvel0(0,0,1) + zvel0(1,0,1) +
                                             zvel0(0,1,1) + zvel0(1,1,1) ) ) * 0.125 * dt * 0.5;

  total_flux = right_flux - left_flux + top_flux - bottom_flux + front_flux - back_flux;

  volume_change(0,0,0) = (volume(0,0,0))/(volume(0,0,0) + total_flux);
  recip_volume = 1.0/volume(0,0,0);
  energy_change = ( pressure(0,0,0)/density0(0,0,0) +
                    viscosity(0,0,0)/density0(0,0,0) ) * total_flux * recip_volume;
  energy1(0,0,0) = energy0(0,0,0) - energy_change;
  density1(0,0,0) = density0(0,0,0) * volume_change(0,0,0);


      }
    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[102].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 14);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[8],range);
  ops_set_halo_dirtybit3(&args[11],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[102].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg6);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg7);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg8);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg9);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg10);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg11);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg12);
    block->instance->OPS_kernels[102].transfer += ops_compute_transfer(dim, start, end, &arg13);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_PdV_kernel_predict(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 102;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 102;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 14;
  desc->args = (ops_arg*)malloc(14*sizeof(ops_arg));
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
  desc->args[11] = arg11;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg11.dat->index;
  desc->args[12] = arg12;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg12.dat->index;
  desc->args[13] = arg13;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg13.dat->index;
  desc->function = ops_par_loop_PdV_kernel_predict_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,102,"PdV_kernel_predict");
  }
  ops_enqueue_kernel(desc);
}
#endif
