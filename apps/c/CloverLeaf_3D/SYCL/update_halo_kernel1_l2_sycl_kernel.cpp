//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_update_halo_kernel1_l2(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
#else
void ops_par_loop_update_halo_kernel1_l2_execute(ops_kernel_descriptor *desc) {
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

  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4,
 arg5, arg6, arg7};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,8,range,16)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,16,"update_halo_kernel1_l2");
    block->instance->OPS_kernels[16].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "update_halo_kernel1_l2");
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
  if (compute_ranges(args, 8,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_update_halo_kernel1_l2 = args[0].dat->size[0];
  int ydim0_update_halo_kernel1_l2 = args[0].dat->size[1];
  int xdim1_update_halo_kernel1_l2 = args[1].dat->size[0];
  int ydim1_update_halo_kernel1_l2 = args[1].dat->size[1];
  int xdim2_update_halo_kernel1_l2 = args[2].dat->size[0];
  int ydim2_update_halo_kernel1_l2 = args[2].dat->size[1];
  int xdim3_update_halo_kernel1_l2 = args[3].dat->size[0];
  int ydim3_update_halo_kernel1_l2 = args[3].dat->size[1];
  int xdim4_update_halo_kernel1_l2 = args[4].dat->size[0];
  int ydim4_update_halo_kernel1_l2 = args[4].dat->size[1];
  int xdim5_update_halo_kernel1_l2 = args[5].dat->size[0];
  int ydim5_update_halo_kernel1_l2 = args[5].dat->size[1];
  int xdim6_update_halo_kernel1_l2 = args[6].dat->size[0];
  int ydim6_update_halo_kernel1_l2 = args[6].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> density0_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[0].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[0].dat->mem/sizeof(double)));

  int base1 = args[1].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> density1_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[1].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[1].dat->mem/sizeof(double)));

  int base2 = args[2].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> energy0_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[2].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[2].dat->mem/sizeof(double)));

  int base3 = args[3].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> energy1_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[3].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[3].dat->mem/sizeof(double)));

  int base4 = args[4].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> pressure_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[4].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[4].dat->mem/sizeof(double)));

  int base5 = args[5].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> viscosity_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[5].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[5].dat->mem/sizeof(double)));

  int base6 = args[6].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> soundspeed_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[6].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[6].dat->mem/sizeof(double)));

  int *arg7h = (int *)args[7].data;


  int consts_bytes = 0;

  consts_bytes += ROUND_UP(NUM_FIELDS*sizeof(int));

  reallocConstArrays(block->instance,consts_bytes);
  consts_bytes = 0;
  arg7.data = block->instance->OPS_consts_h + consts_bytes;
  int arg7_offset = consts_bytes;
  for (int d=0; d<NUM_FIELDS; d++) ((int *)arg7.data)[d] = arg7h[d];
  consts_bytes += ROUND_UP(NUM_FIELDS*sizeof(int));
  mvConstArraysToDevice(block->instance,consts_bytes);
  cl::sycl::buffer<char,1> *consts = static_cast<cl::sycl::buffer<char,1> *>((void*)block->instance->OPS_consts_d);

  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_device(args, 8);
  ops_halo_exchanges(args,8,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[16].mpi_time += __t1-__t2;
  }

  int start_0 = start[0];
  int end_0 = end[0];
  int start_1 = start[1];
  int end_1 = end[1];
  int start_2 = start[2];
  int end_2 = end[2];
  block->instance->sycl_instance->queue->submit([&](cl::sycl::handler &cgh) {
    //accessors
    auto Accessor_density0 = density0_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_density1 = density1_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_energy0 = energy0_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_energy1 = energy1_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_pressure = pressure_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_viscosity = viscosity_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_soundspeed = soundspeed_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_consts_char = consts->get_access<cl::sycl::access::mode::read_write>(cgh);


    cgh.parallel_for<class update_halo_kernel1_l2_kernel>(cl::sycl::nd_range<3>(cl::sycl::range<3>(
          ((end[0]-start[0]-1)/block->instance->OPS_block_size_x+1)*block->instance->OPS_block_size_x
         ,((end[1]-start[1]-1)/block->instance->OPS_block_size_y+1)*block->instance->OPS_block_size_y
         ,((end[2]-start[2]-1)/block->instance->OPS_block_size_z+1)*block->instance->OPS_block_size_z
           ),cl::sycl::range<3>(block->instance->OPS_block_size_x
           , block->instance->OPS_block_size_y
           , block->instance->OPS_block_size_z
           )), [=](cl::sycl::nd_item<3> item) {
      cl::sycl::cl_int n_z = item.get_global_id()[2]+start_2;
      cl::sycl::cl_int n_y = item.get_global_id()[1]+start_1;
      cl::sycl::cl_int n_x = item.get_global_id()[0]+start_0;
      ACC<double> density0(xdim0_update_halo_kernel1_l2, ydim0_update_halo_kernel1_l2, &Accessor_density0[0] + base0 + n_x*1 + n_y * xdim0_update_halo_kernel1_l2*1 + n_z * xdim0_update_halo_kernel1_l2 * ydim0_update_halo_kernel1_l2*1);
      ACC<double> density1(xdim1_update_halo_kernel1_l2, ydim1_update_halo_kernel1_l2, &Accessor_density1[0] + base1 + n_x*1 + n_y * xdim1_update_halo_kernel1_l2*1 + n_z * xdim1_update_halo_kernel1_l2 * ydim1_update_halo_kernel1_l2*1);
      ACC<double> energy0(xdim2_update_halo_kernel1_l2, ydim2_update_halo_kernel1_l2, &Accessor_energy0[0] + base2 + n_x*1 + n_y * xdim2_update_halo_kernel1_l2*1 + n_z * xdim2_update_halo_kernel1_l2 * ydim2_update_halo_kernel1_l2*1);
      ACC<double> energy1(xdim3_update_halo_kernel1_l2, ydim3_update_halo_kernel1_l2, &Accessor_energy1[0] + base3 + n_x*1 + n_y * xdim3_update_halo_kernel1_l2*1 + n_z * xdim3_update_halo_kernel1_l2 * ydim3_update_halo_kernel1_l2*1);
      ACC<double> pressure(xdim4_update_halo_kernel1_l2, ydim4_update_halo_kernel1_l2, &Accessor_pressure[0] + base4 + n_x*1 + n_y * xdim4_update_halo_kernel1_l2*1 + n_z * xdim4_update_halo_kernel1_l2 * ydim4_update_halo_kernel1_l2*1);
      ACC<double> viscosity(xdim5_update_halo_kernel1_l2, ydim5_update_halo_kernel1_l2, &Accessor_viscosity[0] + base5 + n_x*1 + n_y * xdim5_update_halo_kernel1_l2*1 + n_z * xdim5_update_halo_kernel1_l2 * ydim5_update_halo_kernel1_l2*1);
      ACC<double> soundspeed(xdim6_update_halo_kernel1_l2, ydim6_update_halo_kernel1_l2, &Accessor_soundspeed[0] + base6 + n_x*1 + n_y * xdim6_update_halo_kernel1_l2*1 + n_z * xdim6_update_halo_kernel1_l2 * ydim6_update_halo_kernel1_l2*1);
      const int *fields = (int*)&Accessor_consts_char[arg7_offset];
      //USER CODE
      if (n_x < end_0 && n_y < end_1 && n_z < end_2) {
        
  if(fields[FIELD_DENSITY0] == 1) density0(0,0,0) = density0(3,0,0);
  if(fields[FIELD_DENSITY1] == 1) density1(0,0,0) = density1(3,0,0);
  if(fields[FIELD_ENERGY0] == 1) energy0(0,0,0) = energy0(3,0,0);
  if(fields[FIELD_ENERGY1] == 1) energy1(0,0,0) = energy1(3,0,0);
  if(fields[FIELD_PRESSURE] == 1) pressure(0,0,0) = pressure(3,0,0);
  if(fields[FIELD_VISCOSITY] == 1) viscosity(0,0,0) = viscosity(3,0,0);
  if(fields[FIELD_SOUNDSPEED] == 1) soundspeed(0,0,0) = soundspeed(3,0,0);


      }
    });
  });
  if (block->instance->OPS_diags > 1) {
    block->instance->sycl_instance->queue->wait();
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[16].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 8);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[2],range);
  ops_set_halo_dirtybit3(&args[3],range);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[5],range);
  ops_set_halo_dirtybit3(&args[6],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[16].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[16].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[16].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[16].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[16].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[16].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[16].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[16].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_update_halo_kernel1_l2(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 16;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 16;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 8;
  desc->args = (ops_arg*)ops_malloc(8*sizeof(ops_arg));
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
  char *tmp = (char*)ops_malloc(NUM_FIELDS*sizeof(int));
  memcpy(tmp, arg7.data,NUM_FIELDS*sizeof(int));
  desc->args[7].data = tmp;
  desc->function = ops_par_loop_update_halo_kernel1_l2_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,16,"update_halo_kernel1_l2");
  }
  ops_enqueue_kernel(desc);
}
#endif
