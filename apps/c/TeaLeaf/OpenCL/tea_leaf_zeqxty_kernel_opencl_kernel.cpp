//
// auto-generated by ops.py
//

#ifdef OCL_FMA_SWITCH_ON
#define OCL_FMA 1
#else
#define OCL_FMA 0
#endif


static bool isbuilt_tea_leaf_zeqxty_kernel = false;

void buildOpenCLKernels_tea_leaf_zeqxty_kernel(int xdim0, int xdim1, int xdim2) {

  //int ocl_fma = OCL_FMA;
  if(!isbuilt_tea_leaf_zeqxty_kernel) {
    buildOpenCLKernels();
    //clSafeCall( clUnloadCompiler() );
    cl_int ret;
    char* source_filename[1] = {(char*)"./OpenCL/tea_leaf_zeqxty_kernel.cl"};

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

    printf("Compiling tea_leaf_zeqxty_kernel %d source -- start \n",OCL_FMA);

      // Create a program from the source
      OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.program = clCreateProgramWithSource(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.context, 1, (const char **) &source_str, (const size_t *) &source_size, &ret);
      clSafeCall( ret );

      // Build the program
      char buildOpts[255*3];
      char* pPath = NULL;
      pPath = getenv ("OPS_INSTALL_PATH");
      if (pPath!=NULL)
        if(OCL_FMA)
          sprintf(buildOpts,"-cl-mad-enable -DOCL_FMA -I%s/c/include -DOPS_WARPSIZE=%d  -Dxdim0_tea_leaf_zeqxty_kernel=%d  -Dxdim1_tea_leaf_zeqxty_kernel=%d  -Dxdim2_tea_leaf_zeqxty_kernel=%d ", pPath, 32,xdim0,xdim1,xdim2);
        else
          sprintf(buildOpts,"-cl-mad-enable -I%s/c/include -DOPS_WARPSIZE=%d  -Dxdim0_tea_leaf_zeqxty_kernel=%d  -Dxdim1_tea_leaf_zeqxty_kernel=%d  -Dxdim2_tea_leaf_zeqxty_kernel=%d ", pPath, 32,xdim0,xdim1,xdim2);
      else {
        sprintf((char*)"Incorrect OPS_INSTALL_PATH %s\n",pPath);
        exit(EXIT_FAILURE);
      }

      ret = clBuildProgram(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.program, 1, &OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.device_id, buildOpts, NULL, NULL);

      if(ret != CL_SUCCESS) {
        char* build_log;
        size_t log_size;
        clSafeCall( clGetProgramBuildInfo(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.program, OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size) );
        build_log = (char*) malloc(log_size+1);
        clSafeCall( clGetProgramBuildInfo(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.program, OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, log_size, build_log, NULL) );
        build_log[log_size] = '\0';
        fprintf(stderr, "=============== OpenCL Program Build Info ================\n\n%s", build_log);
        fprintf(stderr, "\n========================================================= \n");
        free(build_log);
        exit(EXIT_FAILURE);
      }
      printf("compiling tea_leaf_zeqxty_kernel -- done\n");

    // Create the OpenCL kernel
    OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.kernel[41] = clCreateKernel(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.program, "ops_tea_leaf_zeqxty_kernel", &ret);
    clSafeCall( ret );

    isbuilt_tea_leaf_zeqxty_kernel = true;
  }

}


// host stub function
void ops_par_loop_tea_leaf_zeqxty_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[3] = { arg0, arg1, arg2};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,3,range,41)) return;
  #endif

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timing_realloc(41,"tea_leaf_zeqxty_kernel");
    OPS_instance::getOPSInstance()->OPS_kernels[41].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<2; n++ ){
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
  #else
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);


  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];

  //build opencl kernel if not already built

  buildOpenCLKernels_tea_leaf_zeqxty_kernel(
  xdim0,xdim1,xdim2);

  //set up OpenCL thread blocks
  size_t globalWorkSize[3] = {((x_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_x+ 1)*OPS_instance::getOPSInstance()->OPS_block_size_x, ((y_size-1)/OPS_instance::getOPSInstance()->OPS_block_size_y + 1)*OPS_instance::getOPSInstance()->OPS_block_size_y, 1};
  size_t localWorkSize[3] =  {OPS_instance::getOPSInstance()->OPS_block_size_x,OPS_instance::getOPSInstance()->OPS_block_size_y,OPS_instance::getOPSInstance()->OPS_block_size_z};






  //set up initial pointers
  int d_m[OPS_MAX_DIM];
  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d];
  #endif
  int base0 = 1 *1*
  (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - d_m[0]);
  base0 = base0 + args[0].dat->size[0] *1*
  (start[1] * args[0].stencil->stride[1] - args[0].dat->base[1] - d_m[1]);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d];
  #endif
  int base1 = 1 *1*
  (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - d_m[0]);
  base1 = base1 + args[1].dat->size[0] *1*
  (start[1] * args[1].stencil->stride[1] - args[1].dat->base[1] - d_m[1]);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d];
  #endif
  int base2 = 1 *1*
  (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - d_m[0]);
  base2 = base2 + args[2].dat->size[0] *1*
  (start[1] * args[2].stencil->stride[1] - args[2].dat->base[1] - d_m[1]);


  ops_H_D_exchanges_device(args, 3);
  ops_halo_exchanges(args,3,range);
  ops_H_D_exchanges_device(args, 3);

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_instance::getOPSInstance()->OPS_kernels[41].mpi_time += t2-t1;
  }

  if (globalWorkSize[0]>0 && globalWorkSize[1]>0 && globalWorkSize[2]>0) {

    clSafeCall( clSetKernelArg(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.kernel[41], 0, sizeof(cl_mem), (void*) &arg0.data_d ));
    clSafeCall( clSetKernelArg(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.kernel[41], 1, sizeof(cl_mem), (void*) &arg1.data_d ));
    clSafeCall( clSetKernelArg(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.kernel[41], 2, sizeof(cl_mem), (void*) &arg2.data_d ));
    clSafeCall( clSetKernelArg(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.kernel[41], 3, sizeof(cl_int), (void*) &base0 ));
    clSafeCall( clSetKernelArg(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.kernel[41], 4, sizeof(cl_int), (void*) &base1 ));
    clSafeCall( clSetKernelArg(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.kernel[41], 5, sizeof(cl_int), (void*) &base2 ));
    clSafeCall( clSetKernelArg(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.kernel[41], 6, sizeof(cl_int), (void*) &x_size ));
    clSafeCall( clSetKernelArg(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.kernel[41], 7, sizeof(cl_int), (void*) &y_size ));

    //call/enque opencl kernel wrapper function
    clSafeCall( clEnqueueNDRangeKernel(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.command_queue, OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.kernel[41], 3, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL) );
  }
  if (OPS_instance::getOPSInstance()->OPS_diags>1) {
    clSafeCall( clFinish(OPS_instance::getOPSInstance()->opencl_instance->OPS_opencl_core.command_queue) );
  }

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_instance::getOPSInstance()->OPS_kernels[41].time += t1-t2;
  }

  ops_set_dirtybit_device(args, 3);
  ops_set_halo_dirtybit3(&args[0],range);

  if (OPS_instance::getOPSInstance()->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_instance::getOPSInstance()->OPS_kernels[41].mpi_time += t2-t1;
    OPS_instance::getOPSInstance()->OPS_kernels[41].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_instance::getOPSInstance()->OPS_kernels[41].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_instance::getOPSInstance()->OPS_kernels[41].transfer += ops_compute_transfer(dim, start, end, &arg2);
  }
}
