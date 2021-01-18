//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_calc_dt_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13) {
#else
void ops_par_loop_calc_dt_kernel_execute(ops_kernel_descriptor *desc) {
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
  if (!ops_checkpointing_before(args,14,range,98)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,98,"calc_dt_kernel");
    block->instance->OPS_kernels[98].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "calc_dt_kernel");
  #endif


  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if defined(OPS_MPI) && !defined(OPS_LAZY)
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
  int xdim0_calc_dt_kernel = args[0].dat->size[0];
  int ydim0_calc_dt_kernel = args[0].dat->size[1];
  int xdim1_calc_dt_kernel = args[1].dat->size[0];
  int ydim1_calc_dt_kernel = args[1].dat->size[1];
  int xdim2_calc_dt_kernel = args[2].dat->size[0];
  int ydim2_calc_dt_kernel = args[2].dat->size[1];
  int xdim3_calc_dt_kernel = args[3].dat->size[0];
  int ydim3_calc_dt_kernel = args[3].dat->size[1];
  int xdim4_calc_dt_kernel = args[4].dat->size[0];
  int ydim4_calc_dt_kernel = args[4].dat->size[1];
  int xdim5_calc_dt_kernel = args[5].dat->size[0];
  int ydim5_calc_dt_kernel = args[5].dat->size[1];
  int xdim6_calc_dt_kernel = args[6].dat->size[0];
  int ydim6_calc_dt_kernel = args[6].dat->size[1];
  int xdim7_calc_dt_kernel = args[7].dat->size[0];
  int ydim7_calc_dt_kernel = args[7].dat->size[1];
  int xdim8_calc_dt_kernel = args[8].dat->size[0];
  int ydim8_calc_dt_kernel = args[8].dat->size[1];
  int xdim9_calc_dt_kernel = args[9].dat->size[0];
  int ydim9_calc_dt_kernel = args[9].dat->size[1];
  int xdim10_calc_dt_kernel = args[10].dat->size[0];
  int ydim10_calc_dt_kernel = args[10].dat->size[1];
  int xdim11_calc_dt_kernel = args[11].dat->size[0];
  int ydim11_calc_dt_kernel = args[11].dat->size[1];
  int xdim12_calc_dt_kernel = args[12].dat->size[0];
  int ydim12_calc_dt_kernel = args[12].dat->size[1];
  int xdim13_calc_dt_kernel = args[13].dat->size[0];
  int ydim13_calc_dt_kernel = args[13].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ celldx_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ celldy_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ soundspeed_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ viscosity_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ density0_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ xvel0_p = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ xarea_p = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  double * __restrict__ volume_p = (double *)(args[7].data + base7);

  int base8 = args[8].dat->base_offset;
  double * __restrict__ yvel0_p = (double *)(args[8].data + base8);

  int base9 = args[9].dat->base_offset;
  double * __restrict__ yarea_p = (double *)(args[9].data + base9);

  int base10 = args[10].dat->base_offset;
  double * __restrict__ dt_min_p = (double *)(args[10].data + base10);

  int base11 = args[11].dat->base_offset;
  double * __restrict__ celldz_p = (double *)(args[11].data + base11);

  int base12 = args[12].dat->base_offset;
  double * __restrict__ zvel0_p = (double *)(args[12].data + base12);

  int base13 = args[13].dat->base_offset;
  double * __restrict__ zarea_p = (double *)(args[13].data + base13);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 14);
  ops_halo_exchanges(args,14,range);
  ops_H_D_exchanges_host(args, 14);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[98].mpi_time += __t1-__t2;
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
        const ACC<double> celldx(xdim0_calc_dt_kernel, ydim0_calc_dt_kernel, celldx_p + n_x*1 + n_y * xdim0_calc_dt_kernel*0 + n_z * xdim0_calc_dt_kernel * ydim0_calc_dt_kernel*0);
        const ACC<double> celldy(xdim1_calc_dt_kernel, ydim1_calc_dt_kernel, celldy_p + n_x*0 + n_y * xdim1_calc_dt_kernel*1 + n_z * xdim1_calc_dt_kernel * ydim1_calc_dt_kernel*0);
        const ACC<double> soundspeed(xdim2_calc_dt_kernel, ydim2_calc_dt_kernel, soundspeed_p + n_x*1 + n_y * xdim2_calc_dt_kernel*1 + n_z * xdim2_calc_dt_kernel * ydim2_calc_dt_kernel*1);
        const ACC<double> viscosity(xdim3_calc_dt_kernel, ydim3_calc_dt_kernel, viscosity_p + n_x*1 + n_y * xdim3_calc_dt_kernel*1 + n_z * xdim3_calc_dt_kernel * ydim3_calc_dt_kernel*1);
        const ACC<double> density0(xdim4_calc_dt_kernel, ydim4_calc_dt_kernel, density0_p + n_x*1 + n_y * xdim4_calc_dt_kernel*1 + n_z * xdim4_calc_dt_kernel * ydim4_calc_dt_kernel*1);
        const ACC<double> xvel0(xdim5_calc_dt_kernel, ydim5_calc_dt_kernel, xvel0_p + n_x*1 + n_y * xdim5_calc_dt_kernel*1 + n_z * xdim5_calc_dt_kernel * ydim5_calc_dt_kernel*1);
        const ACC<double> xarea(xdim6_calc_dt_kernel, ydim6_calc_dt_kernel, xarea_p + n_x*1 + n_y * xdim6_calc_dt_kernel*1 + n_z * xdim6_calc_dt_kernel * ydim6_calc_dt_kernel*1);
        const ACC<double> volume(xdim7_calc_dt_kernel, ydim7_calc_dt_kernel, volume_p + n_x*1 + n_y * xdim7_calc_dt_kernel*1 + n_z * xdim7_calc_dt_kernel * ydim7_calc_dt_kernel*1);
        const ACC<double> yvel0(xdim8_calc_dt_kernel, ydim8_calc_dt_kernel, yvel0_p + n_x*1 + n_y * xdim8_calc_dt_kernel*1 + n_z * xdim8_calc_dt_kernel * ydim8_calc_dt_kernel*1);
        const ACC<double> yarea(xdim9_calc_dt_kernel, ydim9_calc_dt_kernel, yarea_p + n_x*1 + n_y * xdim9_calc_dt_kernel*1 + n_z * xdim9_calc_dt_kernel * ydim9_calc_dt_kernel*1);
        ACC<double> dt_min(xdim10_calc_dt_kernel, ydim10_calc_dt_kernel, dt_min_p + n_x*1 + n_y * xdim10_calc_dt_kernel*1 + n_z * xdim10_calc_dt_kernel * ydim10_calc_dt_kernel*1);
        const ACC<double> celldz(xdim11_calc_dt_kernel, ydim11_calc_dt_kernel, celldz_p + n_x*0 + n_y * xdim11_calc_dt_kernel*0 + n_z * xdim11_calc_dt_kernel * ydim11_calc_dt_kernel*1);
        const ACC<double> zvel0(xdim12_calc_dt_kernel, ydim12_calc_dt_kernel, zvel0_p + n_x*1 + n_y * xdim12_calc_dt_kernel*1 + n_z * xdim12_calc_dt_kernel * ydim12_calc_dt_kernel*1);
        const ACC<double> zarea(xdim13_calc_dt_kernel, ydim13_calc_dt_kernel, zarea_p + n_x*1 + n_y * xdim13_calc_dt_kernel*1 + n_z * xdim13_calc_dt_kernel * ydim13_calc_dt_kernel*1);
        

  double div, ds, dtut, dtvt, dtct, dtwt, dtdivt, cc, dv1, dv2, du1, du2, dw1, dw2;

  ds = MIN(MIN(celldx(0,0,0), celldy(0,0,0)), celldz(0,0,0));
  ds = 1.0/(ds*ds);

  cc = soundspeed(0,0,0) * soundspeed(0,0,0);
  cc = cc + 2.0 * viscosity(0,0,0)/density0(0,0,0);

  dtct=ds*cc;
  dtct = dtc_safe*1.0/MAX(sqrt(dtct),g_small);

  du1=(xvel0(0,0,0)+xvel0(0,1,0)+xvel0(0,0,1)+xvel0(0,1,1))*xarea(0,0,0);
  du2=(xvel0(1,0,0)+xvel0(1,1,0)+xvel0(1,0,1)+xvel0(1,1,1))*xarea(0,0,0);

  dtut = dtu_safe * 4.0 * volume(0,0,0)/MAX(MAX(fabs(du1), fabs(du2)), 1.0e-5 * volume(0,0,0));

  dv1=(yvel0(0,0,0)+yvel0(1,0,0)+yvel0(0,0,1)+yvel0(1,0,1))*yarea(0,0,0);
  dv2=(yvel0(0,1,0)+yvel0(1,1,0)+yvel0(0,1,1)+yvel0(1,1,1))*yarea(0,0,0);

  dtvt = dtv_safe * 4.0 * volume(0,0,0)/MAX(MAX(fabs(dv1),fabs(dv2)), 1.0e-5 * volume(0,0,0));

  dw1=(zvel0(0,0,0)+zvel0(0,1,0)+zvel0(1,0,0)+zvel0(1,1,0))*zarea(0,0,0);
  dw2=(zvel0(0,0,1)+zvel0(0,1,1)+zvel0(1,0,1)+zvel0(1,1,1))*zarea(0,0,0);

  dtwt = dtw_safe * 4.0 * volume(0,0,0)/MAX(MAX(fabs(dw1),fabs(dw2)), 1.0e-5 * volume(0,0,0));

  div = du2-du1+dv2-dv1+dw2-dw1;
  dtdivt=dtdiv_safe*4.0*(volume(0,0,0))/MAX(volume(0,0,0)*1.0e-05,fabs(div));

  dt_min(0,0,0) = MIN(MIN(MIN(dtct, dtut), MIN(dtvt, dtdivt)),dtwt);

      }
    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[98].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 14);
  ops_set_halo_dirtybit3(&args[10],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[98].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg6);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg7);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg8);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg9);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg10);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg11);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg12);
    block->instance->OPS_kernels[98].transfer += ops_compute_transfer(dim, start, end, &arg13);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_calc_dt_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 98;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 98;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 14;
  desc->args = (ops_arg *)ops_malloc(14 * sizeof(ops_arg));
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
  desc->function = ops_par_loop_calc_dt_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,98,"calc_dt_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
