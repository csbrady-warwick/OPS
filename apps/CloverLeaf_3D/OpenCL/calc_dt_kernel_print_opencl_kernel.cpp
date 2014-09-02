//
// auto-generated by ops.py
//

#ifdef OCL_FMA_SWITCH_ON
#define OCL_FMA 1
#else
#define OCL_FMA 0
#endif


static bool isbuilt_calc_dt_kernel_print = false;

void buildOpenCLKernels_calc_dt_kernel_print(int xdim0, int ydim0,
 int xdim1, int ydim1,
 int xdim2, int ydim2,
 int xdim3, int ydim3,
 int xdim4, int ydim4,
 int xdim5, int ydim5,
 int xdim6, int ydim6) {

  //int ocl_fma = OCL_FMA;
  if(!isbuilt_calc_dt_kernel_print) {
    buildOpenCLKernels();
    //clSafeCall( clUnloadCompiler() );
    cl_int ret;
    char* source_filename[1] = {"./OpenCL/calc_dt_kernel_print.cl"};

    // Load the kernel source code into the array source_str
    FILE *fid;
    char *source_str[1];
    size_t source_size[1];

    for(int i=0; i<1; i++) {
      fid = fopen(source_filename[i], "r");
      if (!fid) {
        fprintf(stderr, "Can't open the kernel source file!\n");
        exit(1);
      }

      source_str[i] = (char*)malloc(4*0x1000000);
      source_size[i] = fread(source_str[i], 1, 4*0x1000000, fid);
      if(source_size[i] != 4*0x1000000) {
        if (ferror(fid)) {
          printf ("Error while reading kernel source file %s\n", source_filename[i]);
          exit(-1);
        }
        if (feof(fid))
          printf ("Kernel source file %s succesfuly read.\n", source_filename[i]);
          //printf("%s\n",source_str[i]);
      }
      fclose(fid);
    }

    printf("Compiling calc_dt_kernel_print %d source -- start \n",OCL_FMA);

      // Create a program from the source
      OPS_opencl_core.program = clCreateProgramWithSource(OPS_opencl_core.context, 1, (const char **) &source_str, (const size_t *) &source_size, &ret);
      clSafeCall( ret );

      // Build the program
      char buildOpts[255*8];
      char* pPath = NULL;
      pPath = getenv ("OPS_INSTALL_PATH");
      if (pPath!=NULL)
        if(OCL_FMA)
          sprintf(buildOpts,"-cl-mad-enable -DOCL_FMA -I%s/include -DOPS_WARPSIZE=%d  -Dxdim0_calc_dt_kernel_print=%d -Dydim0_calc_dt_kernel_print=%d -Dxdim1_calc_dt_kernel_print=%d -Dydim1_calc_dt_kernel_print=%d -Dxdim2_calc_dt_kernel_print=%d -Dydim2_calc_dt_kernel_print=%d -Dxdim3_calc_dt_kernel_print=%d -Dydim3_calc_dt_kernel_print=%d -Dxdim4_calc_dt_kernel_print=%d -Dydim4_calc_dt_kernel_print=%d -Dxdim5_calc_dt_kernel_print=%d -Dydim5_calc_dt_kernel_print=%d -Dxdim6_calc_dt_kernel_print=%d -Dydim6_calc_dt_kernel_print=%d", pPath, 32,xdim0, ydim0,xdim1, ydim1,xdim2, ydim2,xdim3, ydim3,xdim4, ydim4,xdim5, ydim5,xdim6, ydim6);
        else
          sprintf(buildOpts,"-cl-mad-enable -I%s/include -DOPS_WARPSIZE=%d  -Dxdim0_calc_dt_kernel_print=%d -Dydim0_calc_dt_kernel_print=%d -Dxdim1_calc_dt_kernel_print=%d -Dydim1_calc_dt_kernel_print=%d -Dxdim2_calc_dt_kernel_print=%d -Dydim2_calc_dt_kernel_print=%d -Dxdim3_calc_dt_kernel_print=%d -Dydim3_calc_dt_kernel_print=%d -Dxdim4_calc_dt_kernel_print=%d -Dydim4_calc_dt_kernel_print=%d -Dxdim5_calc_dt_kernel_print=%d -Dydim5_calc_dt_kernel_print=%d -Dxdim6_calc_dt_kernel_print=%d -Dydim6_calc_dt_kernel_print=%d", pPath, 32,xdim0, ydim0,xdim1, ydim1,xdim2, ydim2,xdim3, ydim3,xdim4, ydim4,xdim5, ydim5,xdim6, ydim6);
      else {
        sprintf("Incorrect OPS_INSTALL_PATH %s\n",pPath);
        exit(EXIT_FAILURE);
      }

      ret = clBuildProgram(OPS_opencl_core.program, 1, &OPS_opencl_core.device_id, buildOpts, NULL, NULL);

      if(ret != CL_SUCCESS) {
        char* build_log;
        size_t log_size;
        clSafeCall( clGetProgramBuildInfo(OPS_opencl_core.program, OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size) );
        build_log = (char*) malloc(log_size+1);
        clSafeCall( clGetProgramBuildInfo(OPS_opencl_core.program, OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, log_size, build_log, NULL) );
        build_log[log_size] = '\0';
        fprintf(stderr, "=============== OpenCL Program Build Info ================\n\n%s", build_log);
        fprintf(stderr, "\n========================================================= \n");
        free(build_log);
        exit(EXIT_FAILURE);
      }
      printf("compiling calc_dt_kernel_print -- done\n");

    // Create the OpenCL kernel
    OPS_opencl_core.kernel[40] = clCreateKernel(OPS_opencl_core.program, "ops_calc_dt_kernel_print", &ret);
    clSafeCall( ret );

    isbuilt_calc_dt_kernel_print = true;
  }

}


// host stub function
void ops_par_loop_calc_dt_kernel_print(char const *name, ops_block Block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};


  ops_timing_realloc(40,"calc_dt_kernel_print");
  OPS_kernels[40].count++;

  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<3; n++ ){
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
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif //OPS_MPI

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);


  int xdim0 = args[0].dat->size[0]*args[0].dat->dim;
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0]*args[1].dat->dim;
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0]*args[2].dat->dim;
  int ydim2 = args[2].dat->size[1];
  int xdim3 = args[3].dat->size[0]*args[3].dat->dim;
  int ydim3 = args[3].dat->size[1];
  int xdim4 = args[4].dat->size[0]*args[4].dat->dim;
  int ydim4 = args[4].dat->size[1];
  int xdim5 = args[5].dat->size[0]*args[5].dat->dim;
  int ydim5 = args[5].dat->size[1];
  int xdim6 = args[6].dat->size[0]*args[6].dat->dim;
  int ydim6 = args[6].dat->size[1];

  //build opencl kernel if not already built

  buildOpenCLKernels_calc_dt_kernel_print(
  xdim0, ydim0,
  xdim1, ydim1,
  xdim2, ydim2,
  xdim3, ydim3,
  xdim4, ydim4,
  xdim5, ydim5,
  xdim6, ydim6);

  //Timing
  double t1,t2,c1,c2;
  ops_timers_core(&c2,&t2);

  //set up OpenCL thread blocks
  size_t globalWorkSize[3] = {((x_size-1)/OPS_block_size_x+ 1)*OPS_block_size_x, ((y_size-1)/OPS_block_size_y + 1)*OPS_block_size_y, z_size};
  size_t localWorkSize[3] =  {OPS_block_size_x,OPS_block_size_y,1};


  #ifdef OPS_MPI
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data + ((ops_reduction)args[7].data)->size * block->index);
  #else //OPS_MPI
  double *arg7h = (double *)(((ops_reduction)args[7].data)->data);
  #endif //OPS_MPI

  int nblocks = ((x_size-1)/OPS_block_size_x+ 1)*((y_size-1)/OPS_block_size_y + 1)*z_size;
  int maxblocks = nblocks;
  int reduct_bytes = 0;

  reduct_bytes += ROUND_UP(maxblocks*28*sizeof(double));

  reallocReductArrays(reduct_bytes);
  reduct_bytes = 0;

  int r_bytes7 = reduct_bytes/sizeof(double);
  arg7.data = OPS_reduct_h + reduct_bytes;
  arg7.data_d = OPS_reduct_d;// + reduct_bytes;
  for (int b=0; b<maxblocks; b++)
  for (int d=0; d<28; d++) ((double *)arg7.data)[d+b*28] = ZERO_double;
  reduct_bytes += ROUND_UP(maxblocks*28*sizeof(double));


  mvReductArraysToDevice(reduct_bytes);
  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;
  int dat6 = args[6].dat->elem_size;

  //set up initial pointers
  int d_m[OPS_MAX_DIM];
  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d];
  #endif //OPS_MPI
  int base0 = 1 * 
  (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - d_m[0]);
  base0 = base0 + args[0].dat->size[0] *
  (start[1] * args[0].stencil->stride[1] - args[0].dat->base[1] - d_m[1]);
  base0 = base0 + args[0].dat->size[0] *  args[0].dat->size[1] *
  (start[2] * args[0].stencil->stride[2] - args[0].dat->base[2] - d_m[2]);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d];
  #endif //OPS_MPI
  int base1 = 1 * 
  (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - d_m[0]);
  base1 = base1 + args[1].dat->size[0] *
  (start[1] * args[1].stencil->stride[1] - args[1].dat->base[1] - d_m[1]);
  base1 = base1 + args[1].dat->size[0] *  args[1].dat->size[1] *
  (start[2] * args[1].stencil->stride[2] - args[1].dat->base[2] - d_m[2]);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d];
  #endif //OPS_MPI
  int base2 = 1 * 
  (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - d_m[0]);
  base2 = base2 + args[2].dat->size[0] *
  (start[1] * args[2].stencil->stride[1] - args[2].dat->base[1] - d_m[1]);
  base2 = base2 + args[2].dat->size[0] *  args[2].dat->size[1] *
  (start[2] * args[2].stencil->stride[2] - args[2].dat->base[2] - d_m[2]);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d] + OPS_sub_dat_list[args[3].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d];
  #endif //OPS_MPI
  int base3 = 1 * 
  (start[0] * args[3].stencil->stride[0] - args[3].dat->base[0] - d_m[0]);
  base3 = base3 + args[3].dat->size[0] *
  (start[1] * args[3].stencil->stride[1] - args[3].dat->base[1] - d_m[1]);
  base3 = base3 + args[3].dat->size[0] *  args[3].dat->size[1] *
  (start[2] * args[3].stencil->stride[2] - args[3].dat->base[2] - d_m[2]);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d] + OPS_sub_dat_list[args[4].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d];
  #endif //OPS_MPI
  int base4 = 1 * 
  (start[0] * args[4].stencil->stride[0] - args[4].dat->base[0] - d_m[0]);
  base4 = base4 + args[4].dat->size[0] *
  (start[1] * args[4].stencil->stride[1] - args[4].dat->base[1] - d_m[1]);
  base4 = base4 + args[4].dat->size[0] *  args[4].dat->size[1] *
  (start[2] * args[4].stencil->stride[2] - args[4].dat->base[2] - d_m[2]);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d] + OPS_sub_dat_list[args[5].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d];
  #endif //OPS_MPI
  int base5 = 1 * 
  (start[0] * args[5].stencil->stride[0] - args[5].dat->base[0] - d_m[0]);
  base5 = base5 + args[5].dat->size[0] *
  (start[1] * args[5].stencil->stride[1] - args[5].dat->base[1] - d_m[1]);
  base5 = base5 + args[5].dat->size[0] *  args[5].dat->size[1] *
  (start[2] * args[5].stencil->stride[2] - args[5].dat->base[2] - d_m[2]);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[6].dat->d_m[d] + OPS_sub_dat_list[args[6].dat->index]->d_im[d];
  #else //OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[6].dat->d_m[d];
  #endif //OPS_MPI
  int base6 = 1 * 
  (start[0] * args[6].stencil->stride[0] - args[6].dat->base[0] - d_m[0]);
  base6 = base6 + args[6].dat->size[0] *
  (start[1] * args[6].stencil->stride[1] - args[6].dat->base[1] - d_m[1]);
  base6 = base6 + args[6].dat->size[0] *  args[6].dat->size[1] *
  (start[2] * args[6].stencil->stride[2] - args[6].dat->base[2] - d_m[2]);


  ops_H_D_exchanges_device(args, 8);

  ops_timers_core(&c1,&t1);
  OPS_kernels[40].mpi_time += t1-t2;

  int nthread = OPS_block_size_x*OPS_block_size_y;


  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 0, sizeof(cl_mem), (void*) &arg0.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 1, sizeof(cl_mem), (void*) &arg1.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 2, sizeof(cl_mem), (void*) &arg2.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 3, sizeof(cl_mem), (void*) &arg3.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 4, sizeof(cl_mem), (void*) &arg4.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 5, sizeof(cl_mem), (void*) &arg5.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 6, sizeof(cl_mem), (void*) &arg6.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 7, sizeof(cl_mem), (void*) &arg7.data_d ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 8, nthread*sizeof(double), NULL));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 9, sizeof(cl_int), (void*) &r_bytes7 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 10, sizeof(cl_int), (void*) &base0 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 11, sizeof(cl_int), (void*) &base1 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 12, sizeof(cl_int), (void*) &base2 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 13, sizeof(cl_int), (void*) &base3 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 14, sizeof(cl_int), (void*) &base4 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 15, sizeof(cl_int), (void*) &base5 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 16, sizeof(cl_int), (void*) &base6 ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 17, sizeof(cl_int), (void*) &x_size ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 18, sizeof(cl_int), (void*) &y_size ));
  clSafeCall( clSetKernelArg(OPS_opencl_core.kernel[40], 19, sizeof(cl_int), (void*) &z_size ));

  //call/enque opencl kernel wrapper function
  clSafeCall( clEnqueueNDRangeKernel(OPS_opencl_core.command_queue, OPS_opencl_core.kernel[40], 3, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL) );
  if (OPS_diags>1) {
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }

  mvReductArraysToHost(reduct_bytes);
  for ( int b=0; b<maxblocks; b++ ){
    for ( int d=0; d<28; d++ ){
      arg7h[d] = arg7h[d] + ((double *)arg7.data)[d+b*28];
    }
  }
  arg7.data = (char *)arg7h;

  ops_set_dirtybit_device(args, 8);

  //Update kernel record
  ops_timers_core(&c2,&t2);
  OPS_kernels[40].time += t2-t1;
  OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg0);
  OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg1);
  OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg2);
  OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg3);
  OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg4);
  OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg5);
  OPS_kernels[40].transfer += ops_compute_transfer(dim, range, &arg6);
}
