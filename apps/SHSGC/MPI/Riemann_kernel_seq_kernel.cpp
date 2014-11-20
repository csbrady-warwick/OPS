//
// auto-generated by ops.py
//
#define OPS_ACC_MD3(d,x) ((x)*3+(d))
#define OPS_ACC_MD4(d,x) ((x)*9+(d))
#define OPS_ACC_MD5(d,x) ((x)*3+(d))

//user function

void Riemann_kernel(double* rho_new, double *rhou_new,  double* rhoE_new,
                    double* alam, double* r, double* al) {

  double rl, rr, rho, leftu, rightu, u, hl, hr, h, Vsq, csq, c, g;
  double dw1, dw2, dw3, delpc2, rdeluc;
  double ri[3][3];

  rl = sqrt(rho_new[OPS_ACC0(0)]);
  rr = sqrt(rho_new[OPS_ACC0(1)]);
  rho = rl + rr;
  u = ((rhou_new[OPS_ACC1(0)] / rl) + (rhou_new[OPS_ACC1(1)] / rr)) / rho ;
  double fni = rhou_new[OPS_ACC1(0)] * rhou_new[OPS_ACC1(0)] / rho_new[OPS_ACC0(0)] ;
  double p = gam1 * (rhoE_new[OPS_ACC2(0)] - 0.5 * fni);
  hl = (rhoE_new[OPS_ACC2(0)] + p)  / rl ;
  fni = rhou_new[OPS_ACC1(1)] * rhou_new[OPS_ACC1(1)] / rho_new[OPS_ACC0(1)] ;
  p = gam1 * (rhoE_new[OPS_ACC2(1)] - 0.5 * fni);
  hr = (rhoE_new[OPS_ACC2(1)] + p)  / rr ;
  h = (hl + hr)/rho;
  Vsq = u*u;
  csq = gam1 * (h - 0.5 * Vsq);
  g = gam1 / csq;
  c = sqrt(csq);

  alam[OPS_ACC_MD3(0,0)] = u - c;
  alam[OPS_ACC_MD3(1,0)] = u;
  alam[OPS_ACC_MD3(2,0)] = u + c;

  r[OPS_ACC_MD4(0,0)] = 1.0;
  r[OPS_ACC_MD4(1,0)] = 1.0;
  r[OPS_ACC_MD4(2,0)] = 1.0;

  r[OPS_ACC_MD4(3,0)] = u - c;
  r[OPS_ACC_MD4(4,0)] = u;
  r[OPS_ACC_MD4(5,0)] = u + c;

  r[OPS_ACC_MD4(6,0)] = h - u * c;
  r[OPS_ACC_MD4(7,0)] = 0.5 * Vsq;
  r[OPS_ACC_MD4(8,0)] = h + u * c;

  for (int m=0; m<9; m++)
    r[OPS_ACC_MD4(m,0)] = r[OPS_ACC_MD4(m,0)] / csq;

  dw1 = rho_new[OPS_ACC0(1)] - rho_new[OPS_ACC0(0)];
  dw2 = rhou_new[OPS_ACC1(1)] - rhou_new[OPS_ACC1(0)];
  dw3 = rhoE_new[OPS_ACC2(1)] - rhoE_new[OPS_ACC2(0)];

  delpc2 = gam1 * ( dw3 + 0.50 * Vsq * dw1  - u * dw2) / csq;
  rdeluc = ( dw2 - u * dw1) / c ;

  al[OPS_ACC_MD5(0,0)] = 0.5 * (delpc2 - rdeluc);
  al[OPS_ACC_MD5(1,0)] = dw1 - delpc2 ;
  al[OPS_ACC_MD5(2,0)] = 0.5 * ( delpc2 + rdeluc );

  for (int m=0; m<3; m++)
    al[OPS_ACC_MD5(m,0)] = al[OPS_ACC_MD5(m,0)] * csq;
}



#undef OPS_ACC_MD3
#undef OPS_ACC_MD4
#undef OPS_ACC_MD5


// host stub function
void ops_par_loop_Riemann_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {

  char *p_a[6];
  int  offs[6][1];
  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,6,range,7)) return;
  #endif

  ops_timing_realloc(7,"Riemann_kernel");
  OPS_kernels[7].count++;

  //compute locally allocated range for the sub-block
  int start[1];
  int end[1];

  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<1; n++ ){
    start[n] = sb->decomp_disp[n];end[n] = sb->decomp_disp[n]+sb->decomp_size[n];
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (sb->id_m[n]==MPI_PROC_NULL && range[2*n] < 0) start[n] = range[2*n];
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->decomp_disp[n];
    }
    else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n]==MPI_PROC_NULL && (range[2*n+1] > sb->decomp_disp[n]+sb->decomp_size[n]))
      end[n] += (range[2*n+1]-sb->decomp_disp[n]-sb->decomp_size[n]);
  }
  #else //OPS_MPI
  for ( int n=0; n<1; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif //OPS_MPI
  #ifdef OPS_DEBUG
  ops_register_args(args, "Riemann_kernel");
  #endif

  offs[0][0] = args[0].stencil->stride[0]*1;  //unit step in x dimension

  offs[1][0] = args[1].stencil->stride[0]*1;  //unit step in x dimension

  offs[2][0] = args[2].stencil->stride[0]*1;  //unit step in x dimension

  offs[3][0] = args[3].stencil->stride[0]*1;  //unit step in x dimension

  offs[4][0] = args[4].stencil->stride[0]*1;  //unit step in x dimension

  offs[5][0] = args[5].stencil->stride[0]*1;  //unit step in x dimension



  //Timing
  double t1,t2,c1,c2;
  ops_timers_core(&c2,&t2);

  int off0_0 = offs[0][0];
  int dat0 = args[0].dat->elem_size;
  int off1_0 = offs[1][0];
  int dat1 = args[1].dat->elem_size;
  int off2_0 = offs[2][0];
  int dat2 = args[2].dat->elem_size;
  int off3_0 = offs[3][0];
  int dat3 = args[3].dat->elem_size;
  int off4_0 = offs[4][0];
  int dat4 = args[4].dat->elem_size;
  int off5_0 = offs[5][0];
  int dat5 = args[5].dat->elem_size;

  //set up initial pointers and exchange halos if necessary
  int d_m[OPS_MAX_DIM];
  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d];
  #endif //OPS_MPI
  int base0 = dat0 * 1 * 
    (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - d_m[0]);
  p_a[0] = (char *)args[0].data + base0;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d];
  #endif //OPS_MPI
  int base1 = dat1 * 1 * 
    (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - d_m[0]);
  p_a[1] = (char *)args[1].data + base1;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d];
  #endif //OPS_MPI
  int base2 = dat2 * 1 * 
    (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - d_m[0]);
  p_a[2] = (char *)args[2].data + base2;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d] + OPS_sub_dat_list[args[3].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d];
  #endif //OPS_MPI
  int base3 = dat3 * 1 * 
    (start[0] * args[3].stencil->stride[0] - args[3].dat->base[0] - d_m[0]);
  p_a[3] = (char *)args[3].data + base3;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d] + OPS_sub_dat_list[args[4].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d];
  #endif //OPS_MPI
  int base4 = dat4 * 1 * 
    (start[0] * args[4].stencil->stride[0] - args[4].dat->base[0] - d_m[0]);
  p_a[4] = (char *)args[4].data + base4;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d] + OPS_sub_dat_list[args[5].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d];
  #endif //OPS_MPI
  int base5 = dat5 * 1 * 
    (start[0] * args[5].stencil->stride[0] - args[5].dat->base[0] - d_m[0]);
  p_a[5] = (char *)args[5].data + base5;


  ops_H_D_exchanges_host(args, 6);
  ops_halo_exchanges(args,6,range);
  ops_H_D_exchanges_host(args, 6);

  ops_timers_core(&c1,&t1);
  OPS_kernels[7].mpi_time += t1-t2;

  //initialize global variable with the dimension of dats

  int n_x;
  #pragma novector
  for( n_x=start[0]; n_x<start[0]+((end[0]-start[0])/SIMD_VEC)*SIMD_VEC; n_x+=SIMD_VEC ) {
    //call kernel function, passing in pointers to data -vectorised
    #pragma simd
    for ( int i=0; i<SIMD_VEC; i++ ){
      Riemann_kernel(  (double *)p_a[0]+ i*1*1, (double *)p_a[1]+ i*1*1, (double *)p_a[2]+ i*1*1,
           (double *)p_a[3]+ i*1*3, (double *)p_a[4]+ i*1*9, (double *)p_a[5]+ i*1*3 );

    }

    //shift pointers to data x direction
    p_a[0]= p_a[0] + (dat0 * off0_0)*SIMD_VEC;
    p_a[1]= p_a[1] + (dat1 * off1_0)*SIMD_VEC;
    p_a[2]= p_a[2] + (dat2 * off2_0)*SIMD_VEC;
    p_a[3]= p_a[3] + (dat3 * off3_0)*SIMD_VEC;
    p_a[4]= p_a[4] + (dat4 * off4_0)*SIMD_VEC;
    p_a[5]= p_a[5] + (dat5 * off5_0)*SIMD_VEC;
  }

  for ( int n_x=start[0]+((end[0]-start[0])/SIMD_VEC)*SIMD_VEC; n_x<end[0]; n_x++ ){
    //call kernel function, passing in pointers to data - remainder
    Riemann_kernel(  (double *)p_a[0], (double *)p_a[1], (double *)p_a[2],
           (double *)p_a[3], (double *)p_a[4], (double *)p_a[5] );


    //shift pointers to data x direction
    p_a[0]= p_a[0] + (dat0 * off0_0);
    p_a[1]= p_a[1] + (dat1 * off1_0);
    p_a[2]= p_a[2] + (dat2 * off2_0);
    p_a[3]= p_a[3] + (dat3 * off3_0);
    p_a[4]= p_a[4] + (dat4 * off4_0);
    p_a[5]= p_a[5] + (dat5 * off5_0);
  }

  ops_timers_core(&c2,&t2);
  OPS_kernels[7].time += t2-t1;
  ops_set_dirtybit_host(args, 6);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[5],range);

  //Update kernel record
  OPS_kernels[7].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[7].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[7].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[7].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[7].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[7].transfer += ops_compute_transfer(dim, range, &arg5);
}
