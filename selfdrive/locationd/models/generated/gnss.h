#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_3234173390150289692);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6426308231832956965);
void gnss_H_mod_fun(double *state, double *out_4789783922296295613);
void gnss_f_fun(double *state, double dt, double *out_5003713091267657640);
void gnss_F_fun(double *state, double dt, double *out_4026846992583031053);
void gnss_h_6(double *state, double *sat_pos, double *out_1279017249473265072);
void gnss_H_6(double *state, double *sat_pos, double *out_897585579452227401);
void gnss_h_20(double *state, double *sat_pos, double *out_7009843262361186529);
void gnss_H_20(double *state, double *sat_pos, double *out_6911539669052263913);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_8150424199173631120);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_7779769974813977840);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_8150424199173631120);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_7779769974813977840);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}