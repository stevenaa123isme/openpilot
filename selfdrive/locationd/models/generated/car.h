#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8898850186491034744);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4123389795425744501);
void car_H_mod_fun(double *state, double *out_3040560945639458805);
void car_f_fun(double *state, double dt, double *out_4352631400091210883);
void car_F_fun(double *state, double dt, double *out_4780386535614995733);
void car_h_25(double *state, double *unused, double *out_6281372376385490076);
void car_H_25(double *state, double *unused, double *out_4726918648082750388);
void car_h_24(double *state, double *unused, double *out_6915004078644704554);
void car_H_24(double *state, double *unused, double *out_8284844246885073524);
void car_h_30(double *state, double *unused, double *out_2040201661752251093);
void car_H_30(double *state, double *unused, double *out_6803135084135184473);
void car_h_26(double *state, double *unused, double *out_2697944387754562837);
void car_H_26(double *state, double *unused, double *out_985415329208694164);
void car_h_27(double *state, double *unused, double *out_9128585645879728855);
void car_H_27(double *state, double *unused, double *out_8977898395935609384);
void car_h_29(double *state, double *unused, double *out_2357750419529377919);
void car_H_29(double *state, double *unused, double *out_7755482950904391199);
void car_h_28(double *state, double *unused, double *out_4092251211994497814);
void car_H_28(double *state, double *unused, double *out_2673083933834860625);
void car_h_31(double *state, double *unused, double *out_6556566438669995965);
void car_H_31(double *state, double *unused, double *out_4757564609959710816);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}