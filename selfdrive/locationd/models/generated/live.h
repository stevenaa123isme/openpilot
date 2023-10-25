#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_2143820057594458175);
void live_err_fun(double *nom_x, double *delta_x, double *out_7485915491974212468);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_7598107627610175110);
void live_H_mod_fun(double *state, double *out_2937987622268780709);
void live_f_fun(double *state, double dt, double *out_4615445404091588944);
void live_F_fun(double *state, double dt, double *out_1120091521351388821);
void live_h_4(double *state, double *unused, double *out_2921641620890039986);
void live_H_4(double *state, double *unused, double *out_6386686942332723458);
void live_h_9(double *state, double *unused, double *out_3756012193049619054);
void live_H_9(double *state, double *unused, double *out_900531992931724012);
void live_h_10(double *state, double *unused, double *out_1854846109295052328);
void live_H_10(double *state, double *unused, double *out_7074881526148492092);
void live_h_12(double *state, double *unused, double *out_3945832473763671516);
void live_H_12(double *state, double *unused, double *out_1367230534300761663);
void live_h_35(double *state, double *unused, double *out_6054195810410085163);
void live_H_35(double *state, double *unused, double *out_1378332498024252046);
void live_h_32(double *state, double *unused, double *out_6543260540981204956);
void live_H_32(double *state, double *unused, double *out_5093826771868110853);
void live_h_13(double *state, double *unused, double *out_1035498849764318858);
void live_H_13(double *state, double *unused, double *out_7394664322068384603);
void live_h_14(double *state, double *unused, double *out_3756012193049619054);
void live_H_14(double *state, double *unused, double *out_900531992931724012);
void live_h_33(double *state, double *unused, double *out_8369402130700828615);
void live_H_33(double *state, double *unused, double *out_4528889502663109650);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}