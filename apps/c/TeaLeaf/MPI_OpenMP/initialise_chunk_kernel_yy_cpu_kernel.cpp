//
// auto-generated by ops.py
//
#define OPS_ACC0(x, y)                                                         \
  (n_x * 0 + x + (n_y * 1 + (y)) * xdim0_initialise_chunk_kernel_yy)

// user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_yy(char const *name, ops_block block,
                                             int dim, int *range, ops_arg arg0,
                                             ops_arg arg1) {
#else
void ops_par_loop_initialise_chunk_kernel_yy_execute(
    ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
#endif

  // Timing
  double __t1, __t2, __c1, __c2;

  ops_arg args[2] = {arg0, arg1};

#if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args, 2, range, 9))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(9, "initialise_chunk_kernel_yy");
    OPS_kernels[9].count++;
    ops_timers_core(&__c2, &__t2);
  }

#ifdef OPS_DEBUG
  ops_register_args(args, "initialise_chunk_kernel_yy");
#endif

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  int arg_idx[2];
#if defined(OPS_LAZY) || !defined(OPS_MPI)
  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#else
  if (compute_ranges(args, 2, block, range, start, end, arg_idx) < 0)
    return;
#endif

#ifdef OPS_MPI
  sub_dat_list sd = OPS_sub_dat_list[args[0].dat->index];
  arg_idx[0] = MAX(0, sd->decomp_disp[0]);
  arg_idx[1] = MAX(0, sd->decomp_disp[1]);
#else  // OPS_MPI
  arg_idx[0] = 0;
  arg_idx[1] = 0;
#endif // OPS_MPI

  // initialize global variable with the dimension of dats
  int xdim0_initialise_chunk_kernel_yy = args[0].dat->size[0];

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  int *__restrict__ yy = (int *)(args[0].data + base0);

#ifndef OPS_LAZY
  // Halo Exchanges
  ops_H_D_exchanges_host(args, 2);
  ops_halo_exchanges(args, 2, range);
  ops_H_D_exchanges_host(args, 2);
#endif

  if (OPS_diags > 1) {
    ops_timers_core(&__c1, &__t1);
    OPS_kernels[9].mpi_time += __t1 - __t2;
  }

#pragma omp parallel for
  for (int n_y = start[1]; n_y < end[1]; n_y++) {
#ifdef __INTEL_COMPILER
#pragma loop_count(10000)
#pragma omp simd aligned(yy)
#else
#pragma simd
#endif
    for (int n_x = start[0]; n_x < end[0]; n_x++) {
      int idx[] = {arg_idx[0] + n_x, arg_idx[1] + n_y};

      yy[OPS_ACC0(0, 0)] = idx[1] - 2;
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&__c2, &__t2);
    OPS_kernels[9].time += __t2 - __t1;
  }
#ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 2);
  ops_set_halo_dirtybit3(&args[0], range);
#endif

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&__c1, &__t1);
    OPS_kernels[9].mpi_time += __t1 - __t2;
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
#undef OPS_ACC0

#ifdef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_yy(char const *name, ops_block block,
                                             int dim, int *range, ops_arg arg0,
                                             ops_arg arg1) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 9;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 9;
  for (int i = 0; i < 4; i++) {
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 2;
  desc->args = (ops_arg *)malloc(2 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->function = ops_par_loop_initialise_chunk_kernel_yy_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(9, "initialise_chunk_kernel_yy");
  }
  ops_enqueue_kernel(desc);
}
#endif
