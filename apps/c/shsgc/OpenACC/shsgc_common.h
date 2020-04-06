//
// auto-generated by ops.py
//
//header
#define OPS_API 2
#define OPS_1D
#include <math.h>
#include "ops_macros.h"
#ifdef __cplusplus
#include "ops_lib_core.h"
#include "ops_cuda_rt_support.h"
#endif
#if defined(OPS_MPI) && defined(__cplusplus)
#include "ops_mpi_core.h"
#endif
// global constants
extern int nxp;
extern int nyp;
extern int xhalo;
extern int yhalo;
extern double xmin;
extern double ymin;
extern double xmax;
extern double ymax;
extern double dx;
extern double dy;
extern double pl;
extern double pr;
extern double rhol;
extern double rhor;
extern double ul2;
extern double ur;
extern double gam;
extern double gam1;
extern double eps;
extern double lambda;
extern double dt;
extern double del2;
extern double akap2;
extern double tvdsmu;
extern double con;
