#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3234173390150289692) {
   out_3234173390150289692[0] = delta_x[0] + nom_x[0];
   out_3234173390150289692[1] = delta_x[1] + nom_x[1];
   out_3234173390150289692[2] = delta_x[2] + nom_x[2];
   out_3234173390150289692[3] = delta_x[3] + nom_x[3];
   out_3234173390150289692[4] = delta_x[4] + nom_x[4];
   out_3234173390150289692[5] = delta_x[5] + nom_x[5];
   out_3234173390150289692[6] = delta_x[6] + nom_x[6];
   out_3234173390150289692[7] = delta_x[7] + nom_x[7];
   out_3234173390150289692[8] = delta_x[8] + nom_x[8];
   out_3234173390150289692[9] = delta_x[9] + nom_x[9];
   out_3234173390150289692[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6426308231832956965) {
   out_6426308231832956965[0] = -nom_x[0] + true_x[0];
   out_6426308231832956965[1] = -nom_x[1] + true_x[1];
   out_6426308231832956965[2] = -nom_x[2] + true_x[2];
   out_6426308231832956965[3] = -nom_x[3] + true_x[3];
   out_6426308231832956965[4] = -nom_x[4] + true_x[4];
   out_6426308231832956965[5] = -nom_x[5] + true_x[5];
   out_6426308231832956965[6] = -nom_x[6] + true_x[6];
   out_6426308231832956965[7] = -nom_x[7] + true_x[7];
   out_6426308231832956965[8] = -nom_x[8] + true_x[8];
   out_6426308231832956965[9] = -nom_x[9] + true_x[9];
   out_6426308231832956965[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_4789783922296295613) {
   out_4789783922296295613[0] = 1.0;
   out_4789783922296295613[1] = 0;
   out_4789783922296295613[2] = 0;
   out_4789783922296295613[3] = 0;
   out_4789783922296295613[4] = 0;
   out_4789783922296295613[5] = 0;
   out_4789783922296295613[6] = 0;
   out_4789783922296295613[7] = 0;
   out_4789783922296295613[8] = 0;
   out_4789783922296295613[9] = 0;
   out_4789783922296295613[10] = 0;
   out_4789783922296295613[11] = 0;
   out_4789783922296295613[12] = 1.0;
   out_4789783922296295613[13] = 0;
   out_4789783922296295613[14] = 0;
   out_4789783922296295613[15] = 0;
   out_4789783922296295613[16] = 0;
   out_4789783922296295613[17] = 0;
   out_4789783922296295613[18] = 0;
   out_4789783922296295613[19] = 0;
   out_4789783922296295613[20] = 0;
   out_4789783922296295613[21] = 0;
   out_4789783922296295613[22] = 0;
   out_4789783922296295613[23] = 0;
   out_4789783922296295613[24] = 1.0;
   out_4789783922296295613[25] = 0;
   out_4789783922296295613[26] = 0;
   out_4789783922296295613[27] = 0;
   out_4789783922296295613[28] = 0;
   out_4789783922296295613[29] = 0;
   out_4789783922296295613[30] = 0;
   out_4789783922296295613[31] = 0;
   out_4789783922296295613[32] = 0;
   out_4789783922296295613[33] = 0;
   out_4789783922296295613[34] = 0;
   out_4789783922296295613[35] = 0;
   out_4789783922296295613[36] = 1.0;
   out_4789783922296295613[37] = 0;
   out_4789783922296295613[38] = 0;
   out_4789783922296295613[39] = 0;
   out_4789783922296295613[40] = 0;
   out_4789783922296295613[41] = 0;
   out_4789783922296295613[42] = 0;
   out_4789783922296295613[43] = 0;
   out_4789783922296295613[44] = 0;
   out_4789783922296295613[45] = 0;
   out_4789783922296295613[46] = 0;
   out_4789783922296295613[47] = 0;
   out_4789783922296295613[48] = 1.0;
   out_4789783922296295613[49] = 0;
   out_4789783922296295613[50] = 0;
   out_4789783922296295613[51] = 0;
   out_4789783922296295613[52] = 0;
   out_4789783922296295613[53] = 0;
   out_4789783922296295613[54] = 0;
   out_4789783922296295613[55] = 0;
   out_4789783922296295613[56] = 0;
   out_4789783922296295613[57] = 0;
   out_4789783922296295613[58] = 0;
   out_4789783922296295613[59] = 0;
   out_4789783922296295613[60] = 1.0;
   out_4789783922296295613[61] = 0;
   out_4789783922296295613[62] = 0;
   out_4789783922296295613[63] = 0;
   out_4789783922296295613[64] = 0;
   out_4789783922296295613[65] = 0;
   out_4789783922296295613[66] = 0;
   out_4789783922296295613[67] = 0;
   out_4789783922296295613[68] = 0;
   out_4789783922296295613[69] = 0;
   out_4789783922296295613[70] = 0;
   out_4789783922296295613[71] = 0;
   out_4789783922296295613[72] = 1.0;
   out_4789783922296295613[73] = 0;
   out_4789783922296295613[74] = 0;
   out_4789783922296295613[75] = 0;
   out_4789783922296295613[76] = 0;
   out_4789783922296295613[77] = 0;
   out_4789783922296295613[78] = 0;
   out_4789783922296295613[79] = 0;
   out_4789783922296295613[80] = 0;
   out_4789783922296295613[81] = 0;
   out_4789783922296295613[82] = 0;
   out_4789783922296295613[83] = 0;
   out_4789783922296295613[84] = 1.0;
   out_4789783922296295613[85] = 0;
   out_4789783922296295613[86] = 0;
   out_4789783922296295613[87] = 0;
   out_4789783922296295613[88] = 0;
   out_4789783922296295613[89] = 0;
   out_4789783922296295613[90] = 0;
   out_4789783922296295613[91] = 0;
   out_4789783922296295613[92] = 0;
   out_4789783922296295613[93] = 0;
   out_4789783922296295613[94] = 0;
   out_4789783922296295613[95] = 0;
   out_4789783922296295613[96] = 1.0;
   out_4789783922296295613[97] = 0;
   out_4789783922296295613[98] = 0;
   out_4789783922296295613[99] = 0;
   out_4789783922296295613[100] = 0;
   out_4789783922296295613[101] = 0;
   out_4789783922296295613[102] = 0;
   out_4789783922296295613[103] = 0;
   out_4789783922296295613[104] = 0;
   out_4789783922296295613[105] = 0;
   out_4789783922296295613[106] = 0;
   out_4789783922296295613[107] = 0;
   out_4789783922296295613[108] = 1.0;
   out_4789783922296295613[109] = 0;
   out_4789783922296295613[110] = 0;
   out_4789783922296295613[111] = 0;
   out_4789783922296295613[112] = 0;
   out_4789783922296295613[113] = 0;
   out_4789783922296295613[114] = 0;
   out_4789783922296295613[115] = 0;
   out_4789783922296295613[116] = 0;
   out_4789783922296295613[117] = 0;
   out_4789783922296295613[118] = 0;
   out_4789783922296295613[119] = 0;
   out_4789783922296295613[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_5003713091267657640) {
   out_5003713091267657640[0] = dt*state[3] + state[0];
   out_5003713091267657640[1] = dt*state[4] + state[1];
   out_5003713091267657640[2] = dt*state[5] + state[2];
   out_5003713091267657640[3] = state[3];
   out_5003713091267657640[4] = state[4];
   out_5003713091267657640[5] = state[5];
   out_5003713091267657640[6] = dt*state[7] + state[6];
   out_5003713091267657640[7] = dt*state[8] + state[7];
   out_5003713091267657640[8] = state[8];
   out_5003713091267657640[9] = state[9];
   out_5003713091267657640[10] = state[10];
}
void F_fun(double *state, double dt, double *out_4026846992583031053) {
   out_4026846992583031053[0] = 1;
   out_4026846992583031053[1] = 0;
   out_4026846992583031053[2] = 0;
   out_4026846992583031053[3] = dt;
   out_4026846992583031053[4] = 0;
   out_4026846992583031053[5] = 0;
   out_4026846992583031053[6] = 0;
   out_4026846992583031053[7] = 0;
   out_4026846992583031053[8] = 0;
   out_4026846992583031053[9] = 0;
   out_4026846992583031053[10] = 0;
   out_4026846992583031053[11] = 0;
   out_4026846992583031053[12] = 1;
   out_4026846992583031053[13] = 0;
   out_4026846992583031053[14] = 0;
   out_4026846992583031053[15] = dt;
   out_4026846992583031053[16] = 0;
   out_4026846992583031053[17] = 0;
   out_4026846992583031053[18] = 0;
   out_4026846992583031053[19] = 0;
   out_4026846992583031053[20] = 0;
   out_4026846992583031053[21] = 0;
   out_4026846992583031053[22] = 0;
   out_4026846992583031053[23] = 0;
   out_4026846992583031053[24] = 1;
   out_4026846992583031053[25] = 0;
   out_4026846992583031053[26] = 0;
   out_4026846992583031053[27] = dt;
   out_4026846992583031053[28] = 0;
   out_4026846992583031053[29] = 0;
   out_4026846992583031053[30] = 0;
   out_4026846992583031053[31] = 0;
   out_4026846992583031053[32] = 0;
   out_4026846992583031053[33] = 0;
   out_4026846992583031053[34] = 0;
   out_4026846992583031053[35] = 0;
   out_4026846992583031053[36] = 1;
   out_4026846992583031053[37] = 0;
   out_4026846992583031053[38] = 0;
   out_4026846992583031053[39] = 0;
   out_4026846992583031053[40] = 0;
   out_4026846992583031053[41] = 0;
   out_4026846992583031053[42] = 0;
   out_4026846992583031053[43] = 0;
   out_4026846992583031053[44] = 0;
   out_4026846992583031053[45] = 0;
   out_4026846992583031053[46] = 0;
   out_4026846992583031053[47] = 0;
   out_4026846992583031053[48] = 1;
   out_4026846992583031053[49] = 0;
   out_4026846992583031053[50] = 0;
   out_4026846992583031053[51] = 0;
   out_4026846992583031053[52] = 0;
   out_4026846992583031053[53] = 0;
   out_4026846992583031053[54] = 0;
   out_4026846992583031053[55] = 0;
   out_4026846992583031053[56] = 0;
   out_4026846992583031053[57] = 0;
   out_4026846992583031053[58] = 0;
   out_4026846992583031053[59] = 0;
   out_4026846992583031053[60] = 1;
   out_4026846992583031053[61] = 0;
   out_4026846992583031053[62] = 0;
   out_4026846992583031053[63] = 0;
   out_4026846992583031053[64] = 0;
   out_4026846992583031053[65] = 0;
   out_4026846992583031053[66] = 0;
   out_4026846992583031053[67] = 0;
   out_4026846992583031053[68] = 0;
   out_4026846992583031053[69] = 0;
   out_4026846992583031053[70] = 0;
   out_4026846992583031053[71] = 0;
   out_4026846992583031053[72] = 1;
   out_4026846992583031053[73] = dt;
   out_4026846992583031053[74] = 0;
   out_4026846992583031053[75] = 0;
   out_4026846992583031053[76] = 0;
   out_4026846992583031053[77] = 0;
   out_4026846992583031053[78] = 0;
   out_4026846992583031053[79] = 0;
   out_4026846992583031053[80] = 0;
   out_4026846992583031053[81] = 0;
   out_4026846992583031053[82] = 0;
   out_4026846992583031053[83] = 0;
   out_4026846992583031053[84] = 1;
   out_4026846992583031053[85] = dt;
   out_4026846992583031053[86] = 0;
   out_4026846992583031053[87] = 0;
   out_4026846992583031053[88] = 0;
   out_4026846992583031053[89] = 0;
   out_4026846992583031053[90] = 0;
   out_4026846992583031053[91] = 0;
   out_4026846992583031053[92] = 0;
   out_4026846992583031053[93] = 0;
   out_4026846992583031053[94] = 0;
   out_4026846992583031053[95] = 0;
   out_4026846992583031053[96] = 1;
   out_4026846992583031053[97] = 0;
   out_4026846992583031053[98] = 0;
   out_4026846992583031053[99] = 0;
   out_4026846992583031053[100] = 0;
   out_4026846992583031053[101] = 0;
   out_4026846992583031053[102] = 0;
   out_4026846992583031053[103] = 0;
   out_4026846992583031053[104] = 0;
   out_4026846992583031053[105] = 0;
   out_4026846992583031053[106] = 0;
   out_4026846992583031053[107] = 0;
   out_4026846992583031053[108] = 1;
   out_4026846992583031053[109] = 0;
   out_4026846992583031053[110] = 0;
   out_4026846992583031053[111] = 0;
   out_4026846992583031053[112] = 0;
   out_4026846992583031053[113] = 0;
   out_4026846992583031053[114] = 0;
   out_4026846992583031053[115] = 0;
   out_4026846992583031053[116] = 0;
   out_4026846992583031053[117] = 0;
   out_4026846992583031053[118] = 0;
   out_4026846992583031053[119] = 0;
   out_4026846992583031053[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_1279017249473265072) {
   out_1279017249473265072[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_897585579452227401) {
   out_897585579452227401[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_897585579452227401[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_897585579452227401[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_897585579452227401[3] = 0;
   out_897585579452227401[4] = 0;
   out_897585579452227401[5] = 0;
   out_897585579452227401[6] = 1;
   out_897585579452227401[7] = 0;
   out_897585579452227401[8] = 0;
   out_897585579452227401[9] = 0;
   out_897585579452227401[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_7009843262361186529) {
   out_7009843262361186529[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_6911539669052263913) {
   out_6911539669052263913[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6911539669052263913[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6911539669052263913[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_6911539669052263913[3] = 0;
   out_6911539669052263913[4] = 0;
   out_6911539669052263913[5] = 0;
   out_6911539669052263913[6] = 1;
   out_6911539669052263913[7] = 0;
   out_6911539669052263913[8] = 0;
   out_6911539669052263913[9] = 1;
   out_6911539669052263913[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_8150424199173631120) {
   out_8150424199173631120[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_7779769974813977840) {
   out_7779769974813977840[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[6] = 0;
   out_7779769974813977840[7] = 1;
   out_7779769974813977840[8] = 0;
   out_7779769974813977840[9] = 0;
   out_7779769974813977840[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_8150424199173631120) {
   out_8150424199173631120[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_7779769974813977840) {
   out_7779769974813977840[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_7779769974813977840[6] = 0;
   out_7779769974813977840[7] = 1;
   out_7779769974813977840[8] = 0;
   out_7779769974813977840[9] = 0;
   out_7779769974813977840[10] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_3234173390150289692) {
  err_fun(nom_x, delta_x, out_3234173390150289692);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6426308231832956965) {
  inv_err_fun(nom_x, true_x, out_6426308231832956965);
}
void gnss_H_mod_fun(double *state, double *out_4789783922296295613) {
  H_mod_fun(state, out_4789783922296295613);
}
void gnss_f_fun(double *state, double dt, double *out_5003713091267657640) {
  f_fun(state,  dt, out_5003713091267657640);
}
void gnss_F_fun(double *state, double dt, double *out_4026846992583031053) {
  F_fun(state,  dt, out_4026846992583031053);
}
void gnss_h_6(double *state, double *sat_pos, double *out_1279017249473265072) {
  h_6(state, sat_pos, out_1279017249473265072);
}
void gnss_H_6(double *state, double *sat_pos, double *out_897585579452227401) {
  H_6(state, sat_pos, out_897585579452227401);
}
void gnss_h_20(double *state, double *sat_pos, double *out_7009843262361186529) {
  h_20(state, sat_pos, out_7009843262361186529);
}
void gnss_H_20(double *state, double *sat_pos, double *out_6911539669052263913) {
  H_20(state, sat_pos, out_6911539669052263913);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_8150424199173631120) {
  h_7(state, sat_pos_vel, out_8150424199173631120);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7779769974813977840) {
  H_7(state, sat_pos_vel, out_7779769974813977840);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_8150424199173631120) {
  h_21(state, sat_pos_vel, out_8150424199173631120);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7779769974813977840) {
  H_21(state, sat_pos_vel, out_7779769974813977840);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
