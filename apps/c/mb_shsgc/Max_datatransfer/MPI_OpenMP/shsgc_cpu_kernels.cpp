//
// auto-generated by ops.py//

//header
#define OPS_1D
#define OPS_API 2
#include "ops_lib_core.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif

// global constants
extern int nxp;
extern int nyp;
extern int xhalo;
extern double xmin;
extern double xmax;
extern double dx;
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
extern double Mach;
extern double xt;
extern int scale;

void ops_init_backend() {}

//user kernel files
#include "gridgen_kernel_cpu_kernel.cpp"
#include "init_kernel_cpu_kernel.cpp"
#include "save_kernel_cpu_kernel.cpp"
#include "calvar_kernel_cpu_kernel.cpp"
#include "xder1_kernel_cpu_kernel.cpp"
#include "residue_eval_cpu_kernel.cpp"
#include "updateRK3_kernel_cpu_kernel.cpp"
#include "Riemann_kernel_cpu_kernel.cpp"
#include "limiter_kernel_cpu_kernel.cpp"
#include "tvd_kernel_cpu_kernel.cpp"
#include "vars_kernel_cpu_kernel.cpp"
#include "calupwindeff_kernel_cpu_kernel.cpp"
#include "fact_kernel_cpu_kernel.cpp"
#include "update_kernel_cpu_kernel.cpp"
#include "checkop_kernel_cpu_kernel.cpp"
