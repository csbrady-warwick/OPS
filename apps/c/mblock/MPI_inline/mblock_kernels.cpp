//
// auto-generated by ops.py
//

#include "./MPI_inline/mblock_common.h"


void ops_init_backend() {}

void ops_decl_const_char2(int dim, char const *type,
int size, char *dat, char const *name){
  {
    printf("error: unknown const name\n"); exit(1);
  }
}

//user kernel files
#include "mblock_populate_kernel_mpiinline_kernel.cpp"