//
// auto-generated by ops.py
//

#ifdef OCL_FMA_SWITCH_ON
#define OCL_FMA 1
#else
#define OCL_FMA 0
#endif


static bool isbuilt_advec_mom_kernel1_x_nonvector = false;

void buildOpenCLKernels_advec_mom_kernel1_x_nonvector(OPS_instance *instance, int xdim0, int xdim1, int xdim2, int xdim3, int xdim4) {

  //int ocl_fma = OCL_FMA;
  if(!isbuilt_advec_mom_kernel1_x_nonvector) {
    buildOpenCLKernels(instance);
    //clSafeCall( clUnloadCompiler() );
    cl_int ret;
    char* source_filename[1] = {(char*)"./OpenCL/advec_mom_kernel1_x_nonvector.cl"};

    // Load the kernel source code into the array source_str
    FILE *fid;
    char *source_str[1];
    size_t source_size[1];

    for(int i=0; i<1; i++) {
      fid = fopen(source_filename[i], "r");
      if (!fid) {
        OPSException e(OPS_RUNTIME_ERROR, "Can't open the kernel source file: ");
        e << source_filename[i] << "\n";
        throw e;
      }

      source_str[i] = (char*)malloc(4*0x1000000);
      source_size[i] = fread(source_str[i], 1, 4*0x1000000, fid);
      if(source_size[i] != 4*0x1000000) {
        if (ferror(fid)) {
          OPSException e(OPS_RUNTIME_ERROR, "Error while reading kernel source file ");
          e << source_filename[i] << "\n";
          throw e;
        }
        if (feof(fid))
          instance->ostream() << "Kernel source file "<< source_filename[i] <<" succesfuly read.\n";
      }
      fclose(fid);
    }

    instance->ostream() <<"Compiling advec_mom_kernel1_x_nonvector "<<OCL_FMA<<" source -- start \n";

      // Create a program from the source
      instance->opencl_instance->OPS_opencl_core.program = clCreateProgramWithSource(instance->opencl_instance->OPS_opencl_core.context, 1, (const char **) &source_str, (const size_t *) &source_size, &ret);
      clSafeCall( ret );

      // Build the program
      char buildOpts[255*5];
      char* pPath = NULL;
      pPath = getenv ("OPS_INSTALL_PATH");
      if (pPath!=NULL)
        if(OCL_FMA)
          sprintf(buildOpts,"-cl-mad-enable -DOCL_FMA -I%s/c/include -DOPS_WARPSIZE=%d  -Dxdim0_advec_mom_kernel1_x_nonvector=%d  -Dxdim1_advec_mom_kernel1_x_nonvector=%d  -Dxdim2_advec_mom_kernel1_x_nonvector=%d  -Dxdim3_advec_mom_kernel1_x_nonvector=%d  -Dxdim4_advec_mom_kernel1_x_nonvector=%d ", pPath, 32,xdim0,xdim1,xdim2,xdim3,xdim4);
        else
          sprintf(buildOpts,"-cl-mad-enable -I%s/c/include -DOPS_WARPSIZE=%d  -Dxdim0_advec_mom_kernel1_x_nonvector=%d  -Dxdim1_advec_mom_kernel1_x_nonvector=%d  -Dxdim2_advec_mom_kernel1_x_nonvector=%d  -Dxdim3_advec_mom_kernel1_x_nonvector=%d  -Dxdim4_advec_mom_kernel1_x_nonvector=%d ", pPath, 32,xdim0,xdim1,xdim2,xdim3,xdim4);
      else {
        sprintf((char*)"Incorrect OPS_INSTALL_PATH %s\n",pPath);
        exit(EXIT_FAILURE);
      }

      #ifdef OPS_SOA
      sprintf(buildOpts, "%s -DOPS_SOA", buildOpts);
      #endif
      ret = clBuildProgram(instance->opencl_instance->OPS_opencl_core.program, 1, &instance->opencl_instance->OPS_opencl_core.device_id, buildOpts, NULL, NULL);

      if(ret != CL_SUCCESS) {
        char* build_log;
        size_t log_size;
        clSafeCall( clGetProgramBuildInfo(instance->opencl_instance->OPS_opencl_core.program, instance->opencl_instance->OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size) );
        build_log = (char*) malloc(log_size+1);
        clSafeCall( clGetProgramBuildInfo(instance->opencl_instance->OPS_opencl_core.program, instance->opencl_instance->OPS_opencl_core.device_id, CL_PROGRAM_BUILD_LOG, log_size, build_log, NULL) );
        build_log[log_size] = '\0';
        instance->ostream() << "=============== OpenCL Program Build Info ================\n\n" << build_log;
        instance->ostream() << "\n========================================================= \n";
        free(build_log);
        exit(EXIT_FAILURE);
      }
      instance->ostream() << "compiling advec_mom_kernel1_x_nonvector -- done\n";

    // Create the OpenCL kernel
    instance->opencl_instance->OPS_opencl_core.kernel[75] = clCreateKernel(instance->opencl_instance->OPS_opencl_core.program, "ops_advec_mom_kernel1_x_nonvector", &ret);
    clSafeCall( ret );

    isbuilt_advec_mom_kernel1_x_nonvector = true;
  }

}


// host stub function
void ops_par_loop_advec_mom_kernel1_x_nonvector(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,5,range,75)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,75,"advec_mom_kernel1_x_nonvector");
    block->instance->OPS_kernels[75].count++;
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
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];

  //build opencl kernel if not already built

  buildOpenCLKernels_advec_mom_kernel1_x_nonvector(block->instance,
  xdim0,xdim1,xdim2,xdim3,xdim4);

  //set up OpenCL thread blocks
  size_t globalWorkSize[3] = {((x_size-1)/block->instance->OPS_block_size_x+ 1)*block->instance->OPS_block_size_x, ((y_size-1)/block->instance->OPS_block_size_y + 1)*block->instance->OPS_block_size_y, 1};
  size_t localWorkSize[3] =  {block->instance->OPS_block_size_x,block->instance->OPS_block_size_y,block->instance->OPS_block_size_z};






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

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d] + OPS_sub_dat_list[args[3].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d];
  #endif
  int base3 = 1 *1*
  (start[0] * args[3].stencil->stride[0] - args[3].dat->base[0] - d_m[0]);
  base3 = base3 + args[3].dat->size[0] *1*
  (start[1] * args[3].stencil->stride[1] - args[3].dat->base[1] - d_m[1]);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d] + OPS_sub_dat_list[args[4].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d];
  #endif
  int base4 = 1 *1*
  (start[0] * args[4].stencil->stride[0] - args[4].dat->base[0] - d_m[0]);
  base4 = base4 + args[4].dat->size[0] *1*
  (start[1] * args[4].stencil->stride[1] - args[4].dat->base[1] - d_m[1]);


  ops_H_D_exchanges_device(args, 5);
  ops_halo_exchanges(args,5,range);
  ops_H_D_exchanges_device(args, 5);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[75].mpi_time += t2-t1;
  }

  if (globalWorkSize[0]>0 && globalWorkSize[1]>0 && globalWorkSize[2]>0) {

    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 0, sizeof(cl_mem), (void*) &arg0.data_d ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 1, sizeof(cl_mem), (void*) &arg1.data_d ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 2, sizeof(cl_mem), (void*) &arg2.data_d ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 3, sizeof(cl_mem), (void*) &arg3.data_d ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 4, sizeof(cl_mem), (void*) &arg4.data_d ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 5, sizeof(cl_int), (void*) &base0 ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 6, sizeof(cl_int), (void*) &base1 ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 7, sizeof(cl_int), (void*) &base2 ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 8, sizeof(cl_int), (void*) &base3 ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 9, sizeof(cl_int), (void*) &base4 ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 10, sizeof(cl_int), (void*) &x_size ));
    clSafeCall( clSetKernelArg(block->instance->opencl_instance->OPS_opencl_core.kernel[75], 11, sizeof(cl_int), (void*) &y_size ));

    //call/enque opencl kernel wrapper function
    clSafeCall( clEnqueueNDRangeKernel(block->instance->opencl_instance->OPS_opencl_core.command_queue, block->instance->opencl_instance->OPS_opencl_core.kernel[75], 3, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL) );
  }
  if (block->instance->OPS_diags>1) {
    clSafeCall( clFinish(block->instance->opencl_instance->OPS_opencl_core.command_queue) );
  }

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[75].time += t1-t2;
  }

  ops_set_dirtybit_device(args, 5);
  ops_set_halo_dirtybit3(&args[2],range);

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[75].mpi_time += t2-t1;
    block->instance->OPS_kernels[75].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[75].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[75].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[75].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[75].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}
