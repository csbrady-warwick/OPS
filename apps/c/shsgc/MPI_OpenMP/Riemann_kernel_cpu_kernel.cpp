//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_Riemann_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
#else
void ops_par_loop_Riemann_kernel_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,6,range,7)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,7,"Riemann_kernel");
    block->instance->OPS_kernels[7].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "Riemann_kernel");
  #endif


  //compute locally allocated range for the sub-block
  int start[1];
  int end[1];
  #if defined(OPS_MPI) && !defined(OPS_LAZY)
  int arg_idx[1];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<1; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim3_Riemann_kernel = args[3].dat->size[0];
  int xdim4_Riemann_kernel = args[4].dat->size[0];
  int xdim5_Riemann_kernel = args[5].dat->size[0];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ rho_new_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ rhou_new_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ rhoE_new_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ alam_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ r_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ al_p = (double *)(args[5].data + base5);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 6);
  ops_halo_exchanges(args,6,range);
  ops_H_D_exchanges_host(args, 6);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[7].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for
  for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
    const ACC<double> rho_new(rho_new_p + n_x*1);
    const ACC<double> rhou_new(rhou_new_p + n_x*1);
    const ACC<double> rhoE_new(rhoE_new_p + n_x*1);
    #ifdef OPS_SOA
    ACC<double> alam(3, xdim3_Riemann_kernel, alam_p + n_x*1);
    #else
    ACC<double> alam(3, xdim3_Riemann_kernel, alam_p + 3*(n_x*1));
    #endif
    #ifdef OPS_SOA
    ACC<double> r(9, xdim4_Riemann_kernel, r_p + n_x*1);
    #else
    ACC<double> r(9, xdim4_Riemann_kernel, r_p + 9*(n_x*1));
    #endif
    #ifdef OPS_SOA
    ACC<double> al(3, xdim5_Riemann_kernel, al_p + n_x*1);
    #else
    ACC<double> al(3, xdim5_Riemann_kernel, al_p + 3*(n_x*1));
    #endif
    

  double rl, rr, rho, u, hl, hr, h, Vsq, csq, c;
  double dw1, dw2, dw3, delpc2, rdeluc;

  rl = sqrt(rho_new(0));
  rr = sqrt(rho_new(1));
  rho = rl + rr;
  u = ((rhou_new(0) / rl) + (rhou_new(1) / rr)) / rho ;
  double fni = rhou_new(0) * rhou_new(0) / rho_new(0) ;
  double p = gam1 * (rhoE_new(0) - 0.5 * fni);
  hl = (rhoE_new(0) + p)  / rl ;
  fni = rhou_new(1) * rhou_new(1) / rho_new(1) ;
  p = gam1 * (rhoE_new(1) - 0.5 * fni);
  hr = (rhoE_new(1) + p)  / rr ;
  h = (hl + hr)/rho;
  Vsq = u*u;
  csq = gam1 * (h - 0.5 * Vsq);
  c = sqrt(csq);

  alam(0,0) = u - c;
  alam(1,0) = u;
  alam(2,0) = u + c;

  r(0,0) = 1.0;
  r(1,0) = 1.0;
  r(2,0) = 1.0;

  r(3,0) = u - c;
  r(4,0) = u;
  r(5,0) = u + c;

  r(6,0) = h - u * c;
  r(7,0) = 0.5 * Vsq;
  r(8,0) = h + u * c;

  for (int m=0; m<9; m++)
    r(m,0) = r(m,0) / csq;

  dw1 = rho_new(1) - rho_new(0);
  dw2 = rhou_new(1) - rhou_new(0);
  dw3 = rhoE_new(1) - rhoE_new(0);

  delpc2 = gam1 * ( dw3 + 0.50 * Vsq * dw1  - u * dw2) / csq;
  rdeluc = ( dw2 - u * dw1) / c ;

  al(0,0) = 0.5 * (delpc2 - rdeluc);
  al(1,0) = dw1 - delpc2 ;
  al(2,0) = 0.5 * ( delpc2 + rdeluc );

  for (int m=0; m<3; m++)
    al(m,0) = al(m,0) * csq;

  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[7].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 6);
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
  }
}


#ifdef OPS_LAZY
void ops_par_loop_Riemann_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 7;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 7;
  for ( int i=0; i<2; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 6;
  desc->args = (ops_arg*)malloc(6*sizeof(ops_arg));
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
  desc->function = ops_par_loop_Riemann_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,7,"Riemann_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
