//
// auto-generated by ops.py
//

// user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_calupwindeff_kernel(char const *name, ops_block block,
                                      int dim, int *range, ops_arg arg0,
                                      ops_arg arg1, ops_arg arg2, ops_arg arg3,
                                      ops_arg arg4, ops_arg arg5,
                                      ops_arg arg6) {
#else
void ops_par_loop_calupwindeff_kernel_execute(ops_kernel_descriptor *desc) {
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
#endif

  // Timing
  double __t1, __t2, __c1, __c2;

  ops_arg args[7] = {arg0, arg1, arg2, arg3, arg4, arg5, arg6};

#if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args, 7, range, 11))
    return;
#endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(11, "calupwindeff_kernel");
    OPS_instance::getOPSInstance()->OPS_kernels[11].count++;
    ops_timers_core(&__c2, &__t2);
  }

#ifdef OPS_DEBUG
  ops_register_args(args, "calupwindeff_kernel");
#endif

  // compute locally allocated range for the sub-block
  int start[1];
  int end[1];
#ifdef OPS_MPI
  int arg_idx[1];
#endif
#if defined(OPS_LAZY) || !defined(OPS_MPI)
  for (int n = 0; n < 1; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#else
  if (compute_ranges(args, 7, block, range, start, end, arg_idx) < 0)
    return;
#endif

  // initialize global variable with the dimension of dats
  int xdim0_calupwindeff_kernel = args[0].dat->size[0];
  int xdim1_calupwindeff_kernel = args[1].dat->size[0];
  int xdim2_calupwindeff_kernel = args[2].dat->size[0];
  int xdim3_calupwindeff_kernel = args[3].dat->size[0];
  int xdim4_calupwindeff_kernel = args[4].dat->size[0];
  int xdim5_calupwindeff_kernel = args[5].dat->size[0];
  int xdim6_calupwindeff_kernel = args[6].dat->size[0];

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double *__restrict__ cmp_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double *__restrict__ gt_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double *__restrict__ cf_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double *__restrict__ al_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double *__restrict__ ep2_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double *__restrict__ r_p = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double *__restrict__ eff_p = (double *)(args[6].data + base6);

#ifndef OPS_LAZY
  // Halo Exchanges
  ops_H_D_exchanges_host(args, 7);
  ops_halo_exchanges(args, 7, range);
  ops_H_D_exchanges_host(args, 7);
#endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&__c1, &__t1);
    OPS_instance::getOPSInstance()->OPS_kernels[11].mpi_time += __t1 - __t2;
  }

#pragma omp parallel for
  for (int n_x = start[0]; n_x < end[0]; n_x++) {
#ifdef OPS_SOA
    const ACC<double> cmp(3, xdim0_calupwindeff_kernel, cmp_p + n_x * 1);
#else
    const ACC<double> cmp(3, xdim0_calupwindeff_kernel, cmp_p + 3 * (n_x * 1));
#endif
#ifdef OPS_SOA
    const ACC<double> gt(3, xdim1_calupwindeff_kernel, gt_p + n_x * 1);
#else
    const ACC<double> gt(3, xdim1_calupwindeff_kernel, gt_p + 3 * (n_x * 1));
#endif
#ifdef OPS_SOA
    const ACC<double> cf(3, xdim2_calupwindeff_kernel, cf_p + n_x * 1);
#else
    const ACC<double> cf(3, xdim2_calupwindeff_kernel, cf_p + 3 * (n_x * 1));
#endif
#ifdef OPS_SOA
    const ACC<double> al(3, xdim3_calupwindeff_kernel, al_p + n_x * 1);
#else
    const ACC<double> al(3, xdim3_calupwindeff_kernel, al_p + 3 * (n_x * 1));
#endif
#ifdef OPS_SOA
    const ACC<double> ep2(3, xdim4_calupwindeff_kernel, ep2_p + n_x * 1);
#else
    const ACC<double> ep2(3, xdim4_calupwindeff_kernel, ep2_p + 3 * (n_x * 1));
#endif
#ifdef OPS_SOA
    const ACC<double> r(9, xdim5_calupwindeff_kernel, r_p + n_x * 1);
#else
    const ACC<double> r(9, xdim5_calupwindeff_kernel, r_p + 9 * (n_x * 1));
#endif
#ifdef OPS_SOA
    ACC<double> eff(3, xdim6_calupwindeff_kernel, eff_p + n_x * 1);
#else
    ACC<double> eff(3, xdim6_calupwindeff_kernel, eff_p + 3 * (n_x * 1));
#endif

    double e1 =
        (cmp(0, 0) * (gt(0, 0) + gt(0, 1)) - cf(0, 0) * al(0, 0)) * ep2(0, 0);
    double e2 =
        (cmp(1, 0) * (gt(1, 0) + gt(1, 1)) - cf(1, 0) * al(1, 0)) * ep2(1, 0);
    double e3 =
        (cmp(2, 0) * (gt(2, 0) + gt(2, 1)) - cf(2, 0) * al(2, 0)) * ep2(2, 0);

    eff(0, 0) = e1 * r(0, 0) + e2 * r(1, 0) + e3 * r(2, 0);
    eff(1, 0) = e1 * r(3, 0) + e2 * r(4, 0) + e3 * r(5, 0);
    eff(2, 0) = e1 * r(6, 0) + e2 * r(7, 0) + e3 * r(8, 0);
  }
  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&__c2, &__t2);
    OPS_instance::getOPSInstance()->OPS_kernels[11].time += __t2 - __t1;
  }
#ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 7);
  ops_set_halo_dirtybit3(&args[6], range);
#endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&__c1, &__t1);
    OPS_instance::getOPSInstance()->OPS_kernels[11].mpi_time += __t1 - __t2;
    OPS_instance::getOPSInstance()->OPS_kernels[11].transfer +=
        ops_compute_transfer(dim, start, end, &arg0);
    OPS_instance::getOPSInstance()->OPS_kernels[11].transfer +=
        ops_compute_transfer(dim, start, end, &arg1);
    OPS_instance::getOPSInstance()->OPS_kernels[11].transfer +=
        ops_compute_transfer(dim, start, end, &arg2);
    OPS_instance::getOPSInstance()->OPS_kernels[11].transfer +=
        ops_compute_transfer(dim, start, end, &arg3);
    OPS_instance::getOPSInstance()->OPS_kernels[11].transfer +=
        ops_compute_transfer(dim, start, end, &arg4);
    OPS_instance::getOPSInstance()->OPS_kernels[11].transfer +=
        ops_compute_transfer(dim, start, end, &arg5);
    OPS_instance::getOPSInstance()->OPS_kernels[11].transfer +=
        ops_compute_transfer(dim, start, end, &arg6);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_calupwindeff_kernel(char const *name, ops_block block,
                                      int dim, int *range, ops_arg arg0,
                                      ops_arg arg1, ops_arg arg2, ops_arg arg3,
                                      ops_arg arg4, ops_arg arg5,
                                      ops_arg arg6) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 11;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 11;
  for (int i = 0; i < 2; i++) {
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 7;
  desc->args = (ops_arg *)malloc(7 * sizeof(ops_arg));
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
  desc->function = ops_par_loop_calupwindeff_kernel_execute;
  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(11, "calupwindeff_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
