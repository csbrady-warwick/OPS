//
// auto-generated by ops.py
//

int xdim0_calc_dt_kernel_print;
int ydim0_calc_dt_kernel_print;
int xdim1_calc_dt_kernel_print;
int ydim1_calc_dt_kernel_print;
int xdim2_calc_dt_kernel_print;
int ydim2_calc_dt_kernel_print;
int xdim3_calc_dt_kernel_print;
int ydim3_calc_dt_kernel_print;
int xdim4_calc_dt_kernel_print;
int ydim4_calc_dt_kernel_print;
int xdim5_calc_dt_kernel_print;
int ydim5_calc_dt_kernel_print;
int xdim6_calc_dt_kernel_print;
int ydim6_calc_dt_kernel_print;


//user function



void calc_dt_kernel_print_c_wrapper(
  double * restrict xvel0_p,
  double * restrict yvel0_p,
  double * restrict zvel0_p,
  double * restrict density0_p,
  double * restrict energy0_p,
  double * restrict pressure_p,
  double * restrict soundspeed_p,
  double * restrict output_g,
  int x_size, int y_size, int z_size) {
  double output_0 = output_g[0];
  double output_1 = output_g[1];
  double output_2 = output_g[2];
  double output_3 = output_g[3];
  double output_4 = output_g[4];
  double output_5 = output_g[5];
  double output_6 = output_g[6];
  double output_7 = output_g[7];
  double output_8 = output_g[8];
  double output_9 = output_g[9];
  double output_10 = output_g[10];
  double output_11 = output_g[11];
  double output_12 = output_g[12];
  double output_13 = output_g[13];
  double output_14 = output_g[14];
  double output_15 = output_g[15];
  double output_16 = output_g[16];
  double output_17 = output_g[17];
  double output_18 = output_g[18];
  double output_19 = output_g[19];
  double output_20 = output_g[20];
  double output_21 = output_g[21];
  double output_22 = output_g[22];
  double output_23 = output_g[23];
  double output_24 = output_g[24];
  double output_25 = output_g[25];
  double output_26 = output_g[26];
  double output_27 = output_g[27];
  #pragma omp parallel for reduction(+:output_0) reduction(+:output_1) reduction(+:output_2) reduction(+:output_3) reduction(+:output_4) reduction(+:output_5) reduction(+:output_6) reduction(+:output_7) reduction(+:output_8) reduction(+:output_9) reduction(+:output_10) reduction(+:output_11) reduction(+:output_12) reduction(+:output_13) reduction(+:output_14) reduction(+:output_15) reduction(+:output_16) reduction(+:output_17) reduction(+:output_18) reduction(+:output_19) reduction(+:output_20) reduction(+:output_21) reduction(+:output_22) reduction(+:output_23) reduction(+:output_24) reduction(+:output_25) reduction(+:output_26) reduction(+:output_27)
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        double output[28];
        output[0] = 0;
        output[1] = 0;
        output[2] = 0;
        output[3] = 0;
        output[4] = 0;
        output[5] = 0;
        output[6] = 0;
        output[7] = 0;
        output[8] = 0;
        output[9] = 0;
        output[10] = 0;
        output[11] = 0;
        output[12] = 0;
        output[13] = 0;
        output[14] = 0;
        output[15] = 0;
        output[16] = 0;
        output[17] = 0;
        output[18] = 0;
        output[19] = 0;
        output[20] = 0;
        output[21] = 0;
        output[22] = 0;
        output[23] = 0;
        output[24] = 0;
        output[25] = 0;
        output[26] = 0;
        output[27] = 0;
        const ptr_double xvel0 = { xvel0_p + n_x*1 + n_y * xdim0_calc_dt_kernel_print*1 + n_z * xdim0_calc_dt_kernel_print * ydim0_calc_dt_kernel_print*1, xdim0_calc_dt_kernel_print, ydim0_calc_dt_kernel_print};
        const ptr_double yvel0 = { yvel0_p + n_x*1 + n_y * xdim1_calc_dt_kernel_print*1 + n_z * xdim1_calc_dt_kernel_print * ydim1_calc_dt_kernel_print*1, xdim1_calc_dt_kernel_print, ydim1_calc_dt_kernel_print};
        const ptr_double zvel0 = { zvel0_p + n_x*1 + n_y * xdim2_calc_dt_kernel_print*1 + n_z * xdim2_calc_dt_kernel_print * ydim2_calc_dt_kernel_print*1, xdim2_calc_dt_kernel_print, ydim2_calc_dt_kernel_print};
        const ptr_double density0 = { density0_p + n_x*1 + n_y * xdim3_calc_dt_kernel_print*1 + n_z * xdim3_calc_dt_kernel_print * ydim3_calc_dt_kernel_print*1, xdim3_calc_dt_kernel_print, ydim3_calc_dt_kernel_print};
        const ptr_double energy0 = { energy0_p + n_x*1 + n_y * xdim4_calc_dt_kernel_print*1 + n_z * xdim4_calc_dt_kernel_print * ydim4_calc_dt_kernel_print*1, xdim4_calc_dt_kernel_print, ydim4_calc_dt_kernel_print};
        const ptr_double pressure = { pressure_p + n_x*1 + n_y * xdim5_calc_dt_kernel_print*1 + n_z * xdim5_calc_dt_kernel_print * ydim5_calc_dt_kernel_print*1, xdim5_calc_dt_kernel_print, ydim5_calc_dt_kernel_print};
        const ptr_double soundspeed = { soundspeed_p + n_x*1 + n_y * xdim6_calc_dt_kernel_print*1 + n_z * xdim6_calc_dt_kernel_print * ydim6_calc_dt_kernel_print*1, xdim6_calc_dt_kernel_print, ydim6_calc_dt_kernel_print};
        
  output[0] = OPS_ACC(xvel0, 0,0,0);
  output[1] = OPS_ACC(yvel0, 0,0,0);
  output[2] = OPS_ACC(zvel0, 0,0,0);
  output[3] = OPS_ACC(xvel0, 1,0,0);
  output[4] = OPS_ACC(yvel0, 1,0,0);
  output[5] = OPS_ACC(zvel0, 0,0,0);
  output[6] = OPS_ACC(xvel0, 1,1,0);
  output[7] = OPS_ACC(yvel0, 1,1,0);
  output[8] = OPS_ACC(zvel0, 0,0,0);
  output[9] = OPS_ACC(xvel0, 0,1,0);
  output[10] = OPS_ACC(yvel0, 0,1,0);
  output[11] = OPS_ACC(zvel0, 0,0,0);
  output[12] = OPS_ACC(xvel0, 0,0,1);
  output[13] = OPS_ACC(yvel0, 0,0,1);
  output[14] = OPS_ACC(zvel0, 0,0,1);
  output[15] = OPS_ACC(xvel0, 1,0,1);
  output[16] = OPS_ACC(yvel0, 1,0,1);
  output[17] = OPS_ACC(zvel0, 0,0,1);
  output[18] = OPS_ACC(xvel0, 1,1,1);
  output[19] = OPS_ACC(yvel0, 1,1,1);
  output[20] = OPS_ACC(zvel0, 0,0,1);
  output[21] = OPS_ACC(xvel0, 0,1,1);
  output[22] = OPS_ACC(yvel0, 0,1,1);
  output[23] = OPS_ACC(zvel0, 0,0,1);
  output[24] = OPS_ACC(density0, 0,0,0);
  output[25] = OPS_ACC(energy0, 0,0,0);
  output[26] = OPS_ACC(pressure, 0,0,0);
  output[27] = OPS_ACC(soundspeed, 0,0,0);


        output_0 +=output[0];
        output_1 +=output[1];
        output_2 +=output[2];
        output_3 +=output[3];
        output_4 +=output[4];
        output_5 +=output[5];
        output_6 +=output[6];
        output_7 +=output[7];
        output_8 +=output[8];
        output_9 +=output[9];
        output_10 +=output[10];
        output_11 +=output[11];
        output_12 +=output[12];
        output_13 +=output[13];
        output_14 +=output[14];
        output_15 +=output[15];
        output_16 +=output[16];
        output_17 +=output[17];
        output_18 +=output[18];
        output_19 +=output[19];
        output_20 +=output[20];
        output_21 +=output[21];
        output_22 +=output[22];
        output_23 +=output[23];
        output_24 +=output[24];
        output_25 +=output[25];
        output_26 +=output[26];
        output_27 +=output[27];
      }
    }
  }
  output_g[0] = output_0;
  output_g[1] = output_1;
  output_g[2] = output_2;
  output_g[3] = output_3;
  output_g[4] = output_4;
  output_g[5] = output_5;
  output_g[6] = output_6;
  output_g[7] = output_7;
  output_g[8] = output_8;
  output_g[9] = output_9;
  output_g[10] = output_10;
  output_g[11] = output_11;
  output_g[12] = output_12;
  output_g[13] = output_13;
  output_g[14] = output_14;
  output_g[15] = output_15;
  output_g[16] = output_16;
  output_g[17] = output_17;
  output_g[18] = output_18;
  output_g[19] = output_19;
  output_g[20] = output_20;
  output_g[21] = output_21;
  output_g[22] = output_22;
  output_g[23] = output_23;
  output_g[24] = output_24;
  output_g[25] = output_25;
  output_g[26] = output_26;
  output_g[27] = output_27;
}
