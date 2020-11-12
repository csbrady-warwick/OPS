
# Open source copyright declaration based on BSD open source template:
# http://www.opensource.org/licenses/bsd-license.php
#
# This file is part of the OPS distribution.
#
# Copyright (c) 2013, Mike Giles and others. Please see the AUTHORS file in
# the main source directory for a full list of copyright holders.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
# Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution.
# The name of Mike Giles may not be used to endorse or promote products
# derived from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED BY Mike Giles ''AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL Mike Giles BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

## @file
## @brief OPS SYCL code generator
#
#  This routine is called by ops.py which parses the input files
#
#  It produces a file xxx_sycl_kernel.cpp for each kernel,
#  plus a master kernel file
#

"""
OPS MPI_seq code generator

This routine is called by ops.py which parses the input files

It produces a file xxx_sycl_kernel.cpp for each kernel,
plus a master kernel file

"""

import re
import datetime
import os
import glob

import util
import config

para_parse = util.para_parse
comment_remover = util.comment_remover
remove_trailing_w_space = util.remove_trailing_w_space
parse_signature = util.parse_signature
check_accs = util.check_accs
mult = util.mult
convert_ACC_body = util.convert_ACC_body

comm = util.comm
code = util.code
FOR = util.FOR
FOR2 = util.FOR2
WHILE = util.WHILE
ENDWHILE = util.ENDWHILE
ENDFOR = util.ENDFOR
IF = util.IF
ELSEIF = util.ELSEIF
ELSE = util.ELSE
ENDIF = util.ENDIF


def clean_type(arg):
    for qual in ['__restrict__', 'RESTRICT', '__volatile__']:
        arg = arg.replace(qual, '')
    return arg

def group_n_per_line(vals, n_per_line = 4, sep = ','):
  return (sep + '\n').join([','.join([vals[i] for i in range(s, min(len(vals), s + n_per_line))]) for s in range(0, len(vals), n_per_line)])


def ops_gen_sycl(master, date, consts, kernels, soa_set):

  global dims, stens
  global g_m, file_text, depth

  OPS_ID   = 1;  OPS_GBL   = 2;  OPS_MAP = 3;

  OPS_READ = 1;  OPS_WRITE = 2;  OPS_RW  = 3;
  OPS_INC  = 4;  OPS_MAX   = 5;  OPS_MIN = 6;

  accsstring = ['OPS_READ','OPS_WRITE','OPS_RW','OPS_INC','OPS_MAX','OPS_MIN' ]

  NDIM = 2 #the dimension of the application is hardcoded here .. need to get this dynamically

  src_dir = os.path.dirname(master) or '.'
  master_basename = os.path.splitext(os.path.basename(master))


##########################################################################
#  create new kernel file
##########################################################################

  for nk in range (0,len(kernels)):
    arg_typ  = kernels[nk]['arg_type']
    name  = kernels[nk]['name']
    nargs = kernels[nk]['nargs']
    dim   = kernels[nk]['dim']
    dims  = kernels[nk]['dims']
    stens = kernels[nk]['stens']
    var   = kernels[nk]['var']
    accs  = kernels[nk]['accs']
    typs  = kernels[nk]['typs']
    NDIM = int(dim)
    #parse stencil to locate strided access
    stride = ['1'] * (nargs+4) * NDIM
    restrict = [1] * nargs
    prolong = [1] * nargs

    if NDIM == 2:
      for n in range (0, nargs):
        if str(stens[n]).find('STRID2D_X') > 0:
          stride[NDIM*n+1] = '0'
        elif str(stens[n]).find('STRID2D_Y') > 0:
          stride[NDIM*n] = '0'

    if NDIM == 3:
      for n in range (0, nargs):
        if str(stens[n]).find('STRID3D_XY') > 0:
          stride[NDIM*n+2] = '0'
        elif str(stens[n]).find('STRID3D_YZ') > 0:
          stride[NDIM*n] = '0'
        elif str(stens[n]).find('STRID3D_XZ') > 0:
          stride[NDIM*n+1] = '0'
        elif str(stens[n]).find('STRID3D_X') > 0:
          stride[NDIM*n+1] = '0'
          stride[NDIM*n+2] = '0'
        elif str(stens[n]).find('STRID3D_Y') > 0:
          stride[NDIM*n] = '0'
          stride[NDIM*n+2] = '0'
        elif str(stens[n]).find('STRID3D_Z') > 0:
          stride[NDIM*n] = '0'
          stride[NDIM*n+1] = '0'

    ### Determine if this is a MULTI_GRID LOOP with
    ### either restrict or prolong
    MULTI_GRID = 0
    for n in range (0, nargs):
      restrict[n] = 0
      prolong[n] = 0
      if str(stens[n]).find('RESTRICT') > 0:
        restrict[n] = 1
        MULTI_GRID = 1
      if str(stens[n]).find('PROLONG') > 0 :
        prolong[n] = 1
        MULTI_GRID = 1

    reduction = 0
    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_gbl' and accs[n] != OPS_READ:
        reduction = 1

    arg_idx = -1
    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_idx':
        arg_idx = n

    config.file_text = ''
    config.depth = 0
    n_per_line = 4

    i = name.find('kernel')
    name2 = name[0:i-1]

##########################################################################
#  start with seq kernel function
##########################################################################

    code('')
    comm('user function')

    found = 0
    for files in glob.glob( os.path.join(src_dir,"*.h") ):
      f = open( files, 'r' )
      for line in f:
        if name in line:
          file_name = f.name
          found = 1;
          break
      if found == 1:
        break;

    if found == 0:
      print(("COUND NOT FIND KERNEL", name))

    fid = open(file_name, 'r')
    text = fid.read()

    fid.close()
    text = comment_remover(text)
    text = remove_trailing_w_space(text)

    p = re.compile('void\\s+\\b'+name+'\\b')

    i = p.search(text).start()

    if(i < 0):
      print("\n********")
      print(("Error: cannot locate user kernel function: "+name+" - Aborting code generation"))
      exit(2)

    i2 = text[i:].find(name)
    i2 = i+i2
    j = text[i:].find('{')
    k = para_parse(text, i+j, '{', '}')
    kernel_text = text[i+j+1:k]
    kernel_text = convert_ACC_body(kernel_text)
    m = text.find(name)
    arg_list = parse_signature(text[i2+len(name):i+j])

    global_consts = []
    for nc in range (0,len(consts)):
      const = consts[nc]['name'].replace('"','')
      if re.search(r'\b'+const+r'\b',kernel_text):
        global_consts = global_consts + ['auto '+const+'_sycl = (*'+const+'_p).template get_access<cl::sycl::access::mode::read>(cgh);']
        if consts[nc]['dim'].isdigit() and int(consts[nc]['dim'])==1:
            kernel_text = re.sub(r'\b'+const+r'\b',const+'_sycl[0]',kernel_text)
        else:
            kernel_text = re.sub(r'\b'+const+r'\b',const+'_sycl',kernel_text)

    kernel_text = re.sub(r'\bsqrt\b','cl::sycl::sqrt',kernel_text)
    kernel_text = re.sub(r'\bcbrt\b','cl::sycl::cbrt',kernel_text)
    kernel_text = re.sub(r'\bfabs\b','cl::sycl::fabs',kernel_text)
    kernel_text = re.sub(r'\bfmin\b','cl::sycl::fmin',kernel_text)
    kernel_text = re.sub(r'\bfmax\b','cl::sycl::fmax',kernel_text)
    kernel_text = re.sub(r'\bisnan\b','cl::sycl::isnan',kernel_text)
    kernel_text = re.sub(r'\bisinf\b','cl::sycl::isinf',kernel_text)

    comm('')
    comm(' host stub function')
    code('#ifndef OPS_LAZY')
    code('void ops_par_loop_'+name+'(char const *name, ops_block block, int dim, int* range,')
    code(group_n_per_line([' ops_arg arg{}'.format(n) for n in range(nargs)], n_per_line) + ') {')
    code('#else')
    code('void ops_par_loop_'+name+'_execute(ops_kernel_descriptor *desc) {')
    config.depth = 2
    #code('char const *name = "'+name+'";')
    code('ops_block block = desc->block;')
    code('int dim = desc->dim;')
    code('int *range = desc->range;')
    
    for n in range (0, nargs):
      code('ops_arg arg'+str(n)+' = desc->args['+str(n)+'];')

    code('#endif')

    code('');
    comm('Timing')
    code('double __t1,__t2,__c1,__c2;')
    code('');

    #code('ops_printf("In loop \%s\\n","'+name+'");')

    
    code('ops_arg args['+str(nargs)+'] = {' +
        group_n_per_line([' arg{}'.format(n) for n in range(nargs)], 5) + '};\n\n')
    code('')
    code('#if defined(CHECKPOINTING) && !defined(OPS_LAZY)')
    code('if (!ops_checkpointing_before(args,'+str(nargs)+',range,'+str(nk)+')) return;')
    code('#endif')
    code('')

    IF('block->instance->OPS_diags > 1')
    code('ops_timing_realloc(block->instance,'+str(nk)+',"'+name+'");')
    code('block->instance->OPS_kernels['+str(nk)+'].count++;')
    code('ops_timers_core(&__c2,&__t2);')
    ENDIF()
    code('')

    code('#ifdef OPS_DEBUG')
    code('ops_register_args(block->instance, args, "'+name+'");')
    code('#endif')
    code('')

    code('')

    comm('compute locally allocated range for the sub-block')
    code('int start['+str(NDIM)+'];')
    code('int end['+str(NDIM)+'];')
    if not (arg_idx!=-1) and not MULTI_GRID:
      code('#if defined(OPS_MPI) && !defined(OPS_LAZY)')
#    if MULTI_GRID:
#      code('#ifdef OPS_MPI')
    code('int arg_idx['+str(NDIM)+'];')
#    if not (arg_idx!=-1 and not MULTI_GRID):
    if not (arg_idx!=-1) and not MULTI_GRID:
      code('#endif')

    code('#if defined(OPS_LAZY) || !defined(OPS_MPI)')
    FOR('n','0',str(NDIM))
    code('start[n] = range[2*n];end[n] = range[2*n+1];')
    ENDFOR()
    code('#else')
    code('if (compute_ranges(args, '+str(nargs)+',block, range, start, end, arg_idx) < 0) return;')
    code('#endif')

    code('')
    if arg_idx!=-1 or MULTI_GRID:
      code('#if defined(OPS_MPI)')
      code('#if defined(OPS_LAZY)')
      code('sub_block_list sb = OPS_sub_block_list[block->index];')
      for n in range (0,NDIM):
        code('arg_idx['+str(n)+'] = sb->decomp_disp['+str(n)+'];')
      code('#else')
      for n in range (0,NDIM):
        code('arg_idx['+str(n)+'] -= start['+str(n)+'];')
      code('#endif')
      code('#else //OPS_MPI')
      for n in range (0,NDIM):
        code('arg_idx['+str(n)+'] = 0;')
      code('#endif //OPS_MPI')


    code('')
    comm("initialize global variable with the dimension of dats")
    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_dat':
        if NDIM>1 or (NDIM==1 and (not dims[n].isdigit() or int(dims[n])>1)):
          code('int xdim'+str(n)+'_'+name+' = args['+str(n)+'].dat->size[0];')#*args['+str(n)+'].dat->dim;')
        if NDIM>2 or (NDIM==2 and (not dims[n].isdigit() or int(dims[n])>1)):
          code('int ydim'+str(n)+'_'+name+' = args['+str(n)+'].dat->size[1];')
        if NDIM>3 or (NDIM==3 and (not dims[n].isdigit() or int(dims[n])>1)):
          code('int zdim'+str(n)+'_'+name+' = args['+str(n)+'].dat->size[2];')


    code('')
    comm('set up initial pointers and exchange halos if necessary')
    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_dat':
          code('int base'+str(n)+' = args['+str(n)+'].dat->base_offset/sizeof('+typs[n]+');')
          code('cl::sycl::buffer<'+typs[n]+',1> '+clean_type(arg_list[n])+'_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args['+str(n)+'].data_d)->reinterpret<'+typs[n]+',1>(cl::sycl::range<1>(args['+str(n)+'].dat->mem/sizeof('+typs[n]+')));')
          #code(typs[n]+' * __restrict__ '+clean_type(arg_list[n])+'_p = ('+typs[n]+' *)(args['+str(n)+'].data + base'+str(n)+');')
          if restrict[n] == 1 or prolong[n] == 1:
            code('#ifdef OPS_MPI')
            code('sub_dat_list sd'+str(n)+' = OPS_sub_dat_list[args['+str(n)+'].dat->index];')
          if restrict[n] == 1:
            code(clean_type(arg_list[n])+'_p += arg_idx[0]*args['+str(n)+'].stencil->mgrid_stride[0] - sd'+str(n)+'->decomp_disp[0] + args['+str(n)+'].dat->d_m[0];')
            if NDIM>1:
              code(clean_type(arg_list[n])+'_p += (arg_idx[1]*args['+str(n)+'].stencil->mgrid_stride[1] - sd'+str(n)+'->decomp_disp[1] + args['+str(n)+'].dat->d_m[1])*xdim'+str(n)+'_'+name+';')
            if NDIM>2:
              code(clean_type(arg_list[n])+'_p += (arg_idx[2]*args['+str(n)+'].stencil->mgrid_stride[2] - sd'+str(n)+'->decomp_disp[2] + args['+str(n)+'].dat->d_m[2])*xdim'+str(n)+'_'+name+' * ydim'+str(n)+'_'+name+';')
          if prolong[n] == 1:
            code(clean_type(arg_list[n])+'_p += arg_idx[0]/args['+str(n)+'].stencil->mgrid_stride[0] - sd'+str(n)+'->decomp_disp[0] + args['+str(n)+'].dat->d_m[0];')
            if NDIM>1:
              code(clean_type(arg_list[n])+'_p += (arg_idx[1]/args['+str(n)+'].stencil->mgrid_stride[1] - sd'+str(n)+'->decomp_disp[1] + args['+str(n)+'].dat->d_m[1])*xdim'+str(n)+'_'+name+';')
            if NDIM>2:
              code(clean_type(arg_list[n])+'_p += (arg_idx[2]/args['+str(n)+'].stencil->mgrid_stride[2] - sd'+str(n)+'->decomp_disp[2] + args['+str(n)+'].dat->d_m[2])*xdim'+str(n)+'_'+name+' * ydim'+str(n)+'_'+name+';')

          if restrict[n] == 1 or prolong[n] == 1:
            code('#endif')
      elif arg_typ[n] == 'ops_arg_gbl':
        if accs[n] == OPS_READ:
          if dims[n].isdigit() and int(dims[n])==1:
            code(typs[n]+' '+clean_type(arg_list[n])+'_val = *('+typs[n]+' *)args['+str(n)+'].data;')
          else:
            code(typs[n]+' *arg'+str(n)+'h = ('+typs[n]+' *)args['+str(n)+'].data;')
        else:
          code('#ifdef OPS_MPI')
          code(typs[n]+' * __restrict__ p_a'+str(n)+' = ('+typs[n]+' *)(((ops_reduction)args['+str(n)+'].data)->data + ((ops_reduction)args['+str(n)+'].data)->size * block->index);')
          code('#else //OPS_MPI')
          code(typs[n]+' * __restrict__ p_a'+str(n)+' = ('+typs[n]+' *)((ops_reduction)args['+str(n)+'].data)->data;')
          code('#endif //OPS_MPI')
        code('')
      code('')

    GBL_READ = False
    GBL_READ_MDIM = False
    GBL_INC = False
    GBL_MAX = False
    GBL_MIN = False
    GBL_WRITE = False

    #set up reduction variables
    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_gbl':
        if accs[n] == OPS_READ:
          GBL_READ = True
          if not dims[n].isdigit() or int(dims[n])>1:
            GBL_READ_MDIM = True
        if accs[n] == OPS_INC:
          GBL_INC = True
        if accs[n] == OPS_MAX:
          GBL_MAX = True
        if accs[n] == OPS_MIN:
          GBL_MIN = True
        if accs[n] == OPS_WRITE:
          GBL_WRITE = True

    if GBL_INC == True or GBL_MIN == True or GBL_MAX == True or GBL_WRITE == True:
      code('int maxblocks = (end[0]-start[0]-1)/block->instance->OPS_block_size_x+1;')
      if NDIM>1:
        code('maxblocks *= (end[1]-start[1]-1)/block->instance->OPS_block_size_y+1;')
      if NDIM>2:
        code('maxblocks *= (end[2]-start[2]-1)/block->instance->OPS_block_size_z+1;')
      code('int reduct_bytes = 0;')
      code('size_t reduct_size = 0;')
      code('')
    if GBL_READ == True and GBL_READ_MDIM == True:
      code('int consts_bytes = 0;')
      code('')

    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_gbl':
        if accs[n] == OPS_READ and (not dims[n].isdigit() or int(dims[n])>1):
          code('consts_bytes += ROUND_UP('+str(dims[n])+'*sizeof('+typs[n]+'));')
        elif accs[n] != OPS_READ:
          code('reduct_bytes += ROUND_UP(maxblocks*'+str(dims[n])+'*sizeof('+typs[n]+'));')
          code('reduct_size = MAX(reduct_size,sizeof('+typs[n]+'));')
    code('')

    if GBL_READ == True and GBL_READ_MDIM == True:
      code('reallocConstArrays(block->instance,consts_bytes);')
    if GBL_INC == True or GBL_MIN == True or GBL_MAX == True or GBL_WRITE == True:
      code('reallocReductArrays(block->instance,reduct_bytes);')
      code('reduct_bytes = 0;')
      code('')

    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_gbl' and accs[n] <> OPS_READ:
        code('arg'+str(n)+'.data = block->instance->OPS_reduct_h + reduct_bytes;')
        code('int arg'+str(n)+'_offset = reduct_bytes;')
        code('for (int b=0; b<maxblocks; b++)')
        if accs[n] == OPS_INC:
          code('for (int d=0; d<'+str(dims[n])+'; d++) (('+typs[n]+' *)arg'+str(n)+'.data)[d+b*'+str(dims[n])+'] = ZERO_'+typs[n]+';')
        if accs[n] == OPS_MAX:
          code('for (int d=0; d<'+str(dims[n])+'; d++) (('+typs[n]+' *)arg'+str(n)+'.data)[d+b*'+str(dims[n])+'] = -INFINITY_'+typs[n]+';')
        if accs[n] == OPS_MIN:
          code('for (int d=0; d<'+str(dims[n])+'; d++) (('+typs[n]+' *)arg'+str(n)+'.data)[d+b*'+str(dims[n])+'] = INFINITY_'+typs[n]+';')
        code('reduct_bytes += ROUND_UP(maxblocks*'+str(dims[n])+'*sizeof('+typs[n]+'));')
        code('')

    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_gbl':
        if accs[n] == OPS_READ and (not dims[n].isdigit() or int(dims[n])>1):
          code('consts_bytes = 0;')
          code('arg'+str(n)+'.data = block->instance->OPS_consts_h + consts_bytes;')
          code('int arg'+str(n)+'_offset = consts_bytes;')
          code('for (int d=0; d<'+str(dims[n])+'; d++) (('+typs[n]+' *)arg'+str(n)+'.data)[d] = arg'+str(n)+'h[d];')
          code('consts_bytes += ROUND_UP('+str(dims[n])+'*sizeof(int));')
    if GBL_READ == True and GBL_READ_MDIM == True:
      code('mvConstArraysToDevice(block->instance,consts_bytes);')
      code('cl::sycl::buffer<char,1> *consts = static_cast<cl::sycl::buffer<char,1> *>((void*)block->instance->OPS_consts_d);')

    if GBL_INC == True or GBL_MIN == True or GBL_MAX == True or GBL_WRITE == True:
      code('mvReductArraysToDevice(block->instance,reduct_bytes);')
      code('cl::sycl::buffer<char,1> *reduct = static_cast<cl::sycl::buffer<char,1> *>((void*)block->instance->OPS_reduct_d);')

    code('')

    code('#ifndef OPS_LAZY')
    comm('Halo Exchanges')
    code('ops_H_D_exchanges_device(args, '+str(nargs)+');')
    code('ops_halo_exchanges(args,'+str(nargs)+',range);')
    code('#endif')
    code('')
    IF('block->instance->OPS_diags > 1')
    code('ops_timers_core(&__c1,&__t1);')
    code('block->instance->OPS_kernels['+str(nk)+'].mpi_time += __t1-__t2;')
    ENDIF()
    code('')

    for d in range(0, NDIM):
      code('int start_'+str(d)+' = start['+str(d)+'];')
      code('int end_'+str(d)+' = end['+str(d)+'];')
      if arg_idx != -1:
        code('int arg_idx_'+str(d)+' = arg_idx['+str(d)+'];')

    code('block->instance->sycl_instance->queue->submit([&](cl::sycl::handler &cgh) {')
    config.depth += 2
    comm('accessors')
    for n in range(0,nargs):
      if arg_typ[n] == 'ops_arg_dat':
        code('auto Accessor_'+clean_type(arg_list[n])+' = '+clean_type(arg_list[n])+'_p.get_access<cl::sycl::access::mode::read_write>(cgh);')
    if GBL_READ == True and GBL_READ_MDIM == True:
      code('auto Accessor_consts_char = consts->get_access<cl::sycl::access::mode::read_write>(cgh);')
    if GBL_INC == True or GBL_MIN == True or GBL_MAX == True or GBL_WRITE == True:
      code('auto Accessor_reduct_char = reduct->get_access<cl::sycl::access::mode::read_write>(cgh);')
      code('cl::sycl::accessor<char, 1, cl::sycl::access::mode::read_write, cl::sycl::access::target::local> local_mem(reduct_size*cl::sycl::range<1>(block->instance->OPS_block_size_x*block->instance->OPS_block_size_y),cgh);')
    code('')
    for c in global_consts:
      code(c)
    code('')

    code('cgh.parallel_for<class '+name+'_kernel>(cl::sycl::nd_range<'+str(NDIM)+'>(cl::sycl::range<'+str(NDIM)+'>(')
    code('      ((end[0]-start[0]-1)/block->instance->OPS_block_size_x+1)*block->instance->OPS_block_size_x')
    if NDIM>1:
      code('     ,((end[1]-start[1]-1)/block->instance->OPS_block_size_y+1)*block->instance->OPS_block_size_y')
    if NDIM>2:
      code('     ,((end[2]-start[2]-1)/block->instance->OPS_block_size_z+1)*block->instance->OPS_block_size_z')
    code('       ),cl::sycl::range<'+str(NDIM)+'>(block->instance->OPS_block_size_x')
    if NDIM>1:
      code('       , block->instance->OPS_block_size_y')
    if NDIM>2:
      code('       , block->instance->OPS_block_size_z')
    code('       )), [=](cl::sycl::nd_item<'+str(NDIM)+'> item) {')
    config.depth += 2
    line3 = ''
    for n in range (0,nargs):
      if arg_typ[n] == 'ops_arg_dat':
        line3 = line3 +arg_list[n]+','
    #FOR('n_x','start[0]','end[0]')
    if NDIM>2:
      code('cl::sycl::cl_int n_z = item.get_global_id()[2]+start_2;')
    if NDIM>1:
      code('cl::sycl::cl_int n_y = item.get_global_id()[1]+start_1;')
    code('cl::sycl::cl_int n_x = item.get_global_id()[0]+start_0;')
    if arg_idx != -1:
      if NDIM==1:
        code('int '+clean_type(arg_list[arg_idx])+'[] = {arg_idx_0+n_x};')
      elif NDIM==2:
        code('int '+clean_type(arg_list[arg_idx])+'[] = {arg_idx_0+n_x, arg_idx_1+n_y};')
      elif NDIM==3:
        code('int '+clean_type(arg_list[arg_idx])+'[] = {arg_idx_0+n_x, arg_idx_1+n_y, arg_idx_2+n_z};')

    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_dat':
        pre = ''
        if accs[n] == OPS_READ:
          pre = 'const '
        offset = ''
        dim = ''
        sizelist = ''
        extradim = 0
        if dims[n].isdigit() and int(dims[n])>1:
            dim = dims[n]+', '
            extradim = 1
        elif not dims[n].isdigit():
            dim = 'arg'+str(n)+'.dim, '
            extradim = 1
        if restrict[n] == 1:
          n_x = 'n_x*args['+str(n)+'].stencil->mgrid_stride[0]'
          n_y = 'n_y*args['+str(n)+'].stencil->mgrid_stride[1]'
          n_z = 'n_z*args['+str(n)+'].stencil->mgrid_stride[2]'
        elif prolong[n] == 1:
          n_x = '(n_x+arg_idx[0]%args['+str(n)+'].stencil->mgrid_stride[0])/args['+str(n)+'].stencil->mgrid_stride[0]'
          n_y = '(n_y+arg_idx[1]%args['+str(n)+'].stencil->mgrid_stride[1])/args['+str(n)+'].stencil->mgrid_stride[1]'
          n_z = '(n_z+arg_idx[2]%args['+str(n)+'].stencil->mgrid_stride[2])/args['+str(n)+'].stencil->mgrid_stride[2]'
        else:
          n_x = 'n_x'
          n_y = 'n_y'
          n_z = 'n_z'

        if NDIM > 0:
          offset = offset + n_x+'*'+stride[NDIM*n]
        if NDIM > 1:
          offset = offset + ' + '+n_y+' * xdim'+str(n)+'_'+name+'*'+stride[NDIM*n+1]
        if NDIM > 2:
          offset = offset + ' + '+n_z+' * xdim'+str(n)+'_'+name+' * ydim'+str(n)+'_'+name+'*'+stride[NDIM*n+2]
        dimlabels = 'xyzuv'
        for i in range(1,NDIM+extradim):
          sizelist = sizelist + dimlabels[i-1]+'dim'+str(n)+'_'+name+', '

        if not dims[n].isdigit() or int(dims[n])>1:
          code('#ifdef OPS_SOA')
        code(pre + 'ACC<'+typs[n]+'> '+arg_list[n]+'('+dim+sizelist+'&Accessor_'+arg_list[n]+'[0] + base'+str(n)+' + '+offset+');')
        if not dims[n].isdigit() or int(dims[n])>1:
          code('#else')
          code(pre + 'ACC<'+typs[n]+'> '+arg_list[n]+'('+dim+sizelist+'&Accessor_'+arg_list[n]+'[0] + '+dim[:-2]+'*('+offset+'));')
          code('#endif')
    for n in range (0,nargs):
      if arg_typ[n] == 'ops_arg_gbl':
        if accs[n] == OPS_MIN:
          code(typs[n]+' '+arg_list[n]+'['+str(dims[n])+'];')
          for d in range(0,int(dims[n])):
            code(arg_list[n]+'['+str(d)+'] = +INFINITY_'+typs[n]+';') #need +INFINITY_ change to
        if accs[n] == OPS_MAX:
          code(typs[n]+' '+arg_list[n]+'['+str(dims[n])+'];')
          for d in range(0,int(dims[n])):
            code(arg_list[n]+'['+str(d)+'] = -INFINITY_'+typs[n]+';') #need -INFINITY_ change to
        if accs[n] == OPS_INC:
          code(typs[n]+' '+arg_list[n]+'['+str(dims[n])+'];')
          for d in range(0,int(dims[n])):
            code(arg_list[n]+'['+str(d)+'] = ZERO_'+typs[n]+';')
        if accs[n] == OPS_WRITE: #this may not be correct
          code(typs[n]+' '+arg_list[n]+'['+str(dims[n])+'];')
          for d in range(0,int(dims[n])):
            code(arg_list[n]+'['+str(d)+'] = ZERO_'+typs[n]+';')
        if accs[n] == OPS_READ:
          if dims[n].isdigit() and int(dims[n])==1:
            code('const '+typs[n]+' *'+clean_type(arg_list[n])+' = &'+clean_type(arg_list[n])+'_val;')
          else:
            code('const '+typs[n]+' *'+clean_type(arg_list[n])+' = ('+typs[n]+'*)&Accessor_consts_char[arg'+str(n)+'_offset];')

    #insert user kernel
    comm('USER CODE')
    cond = 'n_x < end_0'
    if NDIM>1:
      cond = cond + ' && n_y < end_1'
    if NDIM>2:
      cond = cond + ' && n_z < end_2'
    IF(cond)
    code(kernel_text);
    ENDIF()

    if GBL_INC == True or GBL_MIN == True or GBL_MAX == True or GBL_WRITE == True:
      code('int group_size = item.get_local_range(0);')
      if NDIM>1:
        code('group_size *= item.get_local_range(1);')
      if NDIM>2:
        code('group_size *= item.get_local_range(2);')
    for n in range (0,nargs):
      if arg_typ[n] == 'ops_arg_gbl' and accs[n] != OPS_READ:
        FOR('d', '0', dims[n])
        if accs[n] == OPS_MIN:
          code('ops_reduction_sycl<OPS_MIN>((('+typs[n]+'*)&Accessor_reduct_char[arg'+str(n)+'_offset]) + d+item.get_group_linear_id()*'+str(dims[n])+', '+arg_list[n]+'['+str(d)+'], ('+typs[n]+'*)&local_mem[0], item, group_size);')
        if accs[n] == OPS_MAX:
          #code('ops_reduction_sycl<OPS_MAX>(Accessor_'+arg_list[n]+', item.get_group_linear_id(), '+arg_list[n]+'['+str(d)+'], ('+typs[n]+'*)&local_mem[0], item);')
          code('ops_reduction_sycl<OPS_MAX>((('+typs[n]+'*)&Accessor_reduct_char[arg'+str(n)+'_offset]) + d+item.get_group_linear_id()*'+str(dims[n])+', '+arg_list[n]+'['+str(d)+'], ('+typs[n]+'*)&local_mem[0], item, group_size);')
        if accs[n] == OPS_INC:
          code('ops_reduction_sycl<OPS_INC>((('+typs[n]+'*)&Accessor_reduct_char[arg'+str(n)+'_offset]) + d+item.get_group_linear_id()*'+str(dims[n])+', '+arg_list[n]+'['+str(d)+'], ('+typs[n]+'*)&local_mem[0], item, group_size);')
        if accs[n] == OPS_WRITE: #this may not be correct
          #code('p_a'+str(n)+'_'+str(d)+' +='+arg_list[n]+'['+str(d)+'];')
          code('ops_reduction_sycl<OPS_MIN>((('+typs[n]+'*)&Accessor_reduct_char[arg'+str(n)+'_offset]) + d+item.get_group_linear_id()*'+str(dims[n])+', '+arg_list[n]+'['+str(d)+'], ('+typs[n]+'*)&local_mem[0], item, group_size);')
        ENDFOR()
    
    config.depth -= 2
    code('});')
    config.depth -= 2
    code('});')
    #ENDFOR()
    #if NDIM>1:
      #ENDFOR()
    #if NDIM>2:
      #ENDFOR()

    #
    # Complete Reduction Operation by moving data onto host
    # and reducing over blocks
    #
    if GBL_INC == True or GBL_MIN == True or GBL_MAX == True or GBL_WRITE == True:
      code('mvReductArraysToHost(block->instance,reduct_bytes);')

    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_gbl' and accs[n] != OPS_READ:
        FOR('b','0','maxblocks')
        FOR('d','0',str(dims[n]))
        if accs[n] == OPS_INC:
          code('p_a'+str(n)+'[d] = p_a'+str(n)+'[d] + (('+typs[n]+' *)arg'+str(n)+'.data)[d+b*'+str(dims[n])+'];')
        elif accs[n] == OPS_MAX:
          code('p_a'+str(n)+'[d] = MAX(p_a'+str(n)+'[d],(('+typs[n]+' *)arg'+str(n)+'.data)[d+b*'+str(dims[n])+']);')
        elif accs[n] == OPS_MIN:
          code('p_a'+str(n)+'[d] = MIN(p_a'+str(n)+'[d],(('+typs[n]+' *)arg'+str(n)+'.data)[d+b*'+str(dims[n])+']);')
        ENDFOR()
        ENDFOR()
 
    IF('block->instance->OPS_diags > 1')
    code('block->instance->sycl_instance->queue->wait();')
    code('ops_timers_core(&__c2,&__t2);')
    code('block->instance->OPS_kernels['+str(nk)+'].time += __t2-__t1;')
    ENDIF()

    code('#ifndef OPS_LAZY')
    code('ops_set_dirtybit_device(args, '+str(nargs)+');')
    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_dat' and (accs[n] == OPS_WRITE or accs[n] == OPS_RW or accs[n] == OPS_INC):
        code('ops_set_halo_dirtybit3(&args['+str(n)+'],range);')
    code('#endif')

    code('')
    IF('block->instance->OPS_diags > 1')
    comm('Update kernel record')
    code('ops_timers_core(&__c1,&__t1);')
    code('block->instance->OPS_kernels['+str(nk)+'].mpi_time += __t1-__t2;')
    for n in range (0, nargs):
      if arg_typ[n] == 'ops_arg_dat':
        code('block->instance->OPS_kernels['+str(nk)+'].transfer += ops_compute_transfer(dim, start, end, &arg'+str(n)+');')
    ENDIF()
    config.depth = config.depth - 2
    code('}')
    code('')

    ## TODO should be fine after this point
    code('')
    code('#ifdef OPS_LAZY')
    code('void ops_par_loop_'+name+'(char const *name, ops_block block, int dim, int* range,')
    text = ''
    for n in range (0, nargs):

      text = text +' ops_arg arg'+str(n)
      if nargs != 1 and n != nargs-1:
        text = text +','
      else:
        text = text +') {'
      if n%n_per_line == 3 and n != nargs-1:
         text = text +'\n'
    code(text);
    config.depth = 2
    code('ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));')
    #code('desc->name = (char *)malloc(strlen(name)+1);')
    #code('strcpy(desc->name, name);')
    code('desc->name = name;')
    code('desc->block = block;')
    code('desc->dim = dim;')
    code('desc->device = 1;')
    code('desc->index = '+str(nk)+';')
    code('desc->hash = 5381;')
    code('desc->hash = ((desc->hash << 5) + desc->hash) + '+str(nk)+';')
    FOR('i','0',str(2*NDIM))
    code('desc->range[i] = range[i];')
    code('desc->orig_range[i] = range[i];')
    code('desc->hash = ((desc->hash << 5) + desc->hash) + range[i];')
    ENDFOR()

    code('desc->nargs = '+str(nargs)+';')
    code('desc->args = (ops_arg*)ops_malloc('+str(nargs)+'*sizeof(ops_arg));')
    declared = 0
    for n in range (0, nargs):
      code('desc->args['+str(n)+'] = arg'+str(n)+';')
      if arg_typ[n] == 'ops_arg_dat':
        code('desc->hash = ((desc->hash << 5) + desc->hash) + arg'+str(n)+'.dat->index;')
      if arg_typ[n] == 'ops_arg_gbl' and accs[n] == OPS_READ:
        if declared == 0:
          code('char *tmp = (char*)ops_malloc('+dims[n]+'*sizeof('+typs[n]+'));')
          declared = 1
        else:
          code('tmp = (char*)ops_malloc('+dims[n]+'*sizeof('+typs[n]+'));')
        code('memcpy(tmp, arg'+str(n)+'.data,'+dims[n]+'*sizeof('+typs[n]+'));')
        code('desc->args['+str(n)+'].data = tmp;')
    code('desc->function = ops_par_loop_'+name+'_execute;')
    IF('block->instance->OPS_diags > 1')
    code('ops_timing_realloc(block->instance,'+str(nk)+',"'+name+'");')
    ENDIF()
    code('ops_enqueue_kernel(desc);')
    config.depth = 0
    code('}')
    code('#endif')

##########################################################################
#  output individual kernel file
##########################################################################
    try:
      os.makedirs('./SYCL') 
    except OSError as e:
      if e.errno != os.errno.EEXIST:
        raise
    fid = open('./SYCL/'+name+'_sycl_kernel.cpp','w')
    date = datetime.datetime.now()
    fid.write('//\n// auto-generated by ops.py\n//\n')
    fid.write(config.file_text)
    fid.close()

# end of main kernel call loop

##########################################################################
#  output one master kernel file
##########################################################################
  config.depth = 0
  config.file_text =''
  comm('header')
  if NDIM==1:
    code('#define OPS_1D')
  if NDIM==2:
    code('#define OPS_2D')
  if NDIM==3:
    code('#define OPS_3D')
  if soa_set:
    code('#define OPS_SOA')
  code('#define OPS_API 2')
  code('#include "ops_lib_core.h"')
  code('#ifdef OPS_MPI')
  code('#include "ops_mpi_core.h"')
  code('#endif')
  if os.path.exists(os.path.join(src_dir, 'user_types.h')):
    code('#include "user_types.h"')
  code('')

  code('#include "ops_sycl_rt_support.h"')
  code('#include "ops_sycl_reduction.h"')

  comm(' global constants')
  for nc in range (0,len(consts)):
    code('cl::sycl::buffer<'+consts[nc]['type']+',1> *'+consts[nc]['name'].replace('"','')+'_p=nullptr;')
    if (not consts[nc]['dim'].isdigit()) or int(consts[nc]['dim'])>1:
      code('extern '+consts[nc]['type']+' *'+consts[nc]['name'].replace('"','')+';')
    else:
      code('extern '+consts[nc]['type']+' '+consts[nc]['name'].replace('"','')+';')
  code('')

  code('void ops_init_backend() {}')
  code('')

  code('void ops_decl_const_char(int dim, char const * type, int size, char * dat, char const * name ) {')
  config.depth =config.depth + 2
  for nc in range(0,len(consts)):
    IF('!strcmp(name,"'+(consts[nc]['name'].replace('"','')).strip()+'")')
    code('if ('+consts[nc]['name'].replace('"','')+'_p == nullptr) '+consts[nc]['name'].replace('"','')+'_p = new cl::sycl::buffer<'+consts[nc]['type']+',1>(cl::sycl::range<1>(dim));')
    code('auto accessor = (*'+consts[nc]['name'].replace('"','')+'_p).get_access<cl::sycl::access::mode::write>();')
    FOR('d','0','dim')
    code('accessor[d] = (('+consts[nc]['type']+'*)dat)[d];')
    ENDFOR()
    ENDIF()
    code('else')
  code('{')
  config.depth = config.depth + 2
  code('throw OPSException(OPS_RUNTIME_ERROR, "error: unknown const name");')
  ENDIF()
  config.depth = config.depth - 2
  code('}')
  code('')
  comm('user kernel files')

  kernel_name_list = []

  for nk in range(0,len(kernels)):
    if kernels[nk]['name'] not in kernel_name_list :
      code('#include "'+kernels[nk]['name']+'_sycl_kernel.cpp"')
      kernel_name_list.append(kernels[nk]['name'])

  fid = open('./SYCL/'+master_basename[0]+'_sycl_kernels.cpp','w')
  fid.write('//\n// auto-generated by ops.py//\n\n')
  fid.write(config.file_text)
  fid.close()
