#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8898850186491034744) {
   out_8898850186491034744[0] = delta_x[0] + nom_x[0];
   out_8898850186491034744[1] = delta_x[1] + nom_x[1];
   out_8898850186491034744[2] = delta_x[2] + nom_x[2];
   out_8898850186491034744[3] = delta_x[3] + nom_x[3];
   out_8898850186491034744[4] = delta_x[4] + nom_x[4];
   out_8898850186491034744[5] = delta_x[5] + nom_x[5];
   out_8898850186491034744[6] = delta_x[6] + nom_x[6];
   out_8898850186491034744[7] = delta_x[7] + nom_x[7];
   out_8898850186491034744[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4123389795425744501) {
   out_4123389795425744501[0] = -nom_x[0] + true_x[0];
   out_4123389795425744501[1] = -nom_x[1] + true_x[1];
   out_4123389795425744501[2] = -nom_x[2] + true_x[2];
   out_4123389795425744501[3] = -nom_x[3] + true_x[3];
   out_4123389795425744501[4] = -nom_x[4] + true_x[4];
   out_4123389795425744501[5] = -nom_x[5] + true_x[5];
   out_4123389795425744501[6] = -nom_x[6] + true_x[6];
   out_4123389795425744501[7] = -nom_x[7] + true_x[7];
   out_4123389795425744501[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3040560945639458805) {
   out_3040560945639458805[0] = 1.0;
   out_3040560945639458805[1] = 0;
   out_3040560945639458805[2] = 0;
   out_3040560945639458805[3] = 0;
   out_3040560945639458805[4] = 0;
   out_3040560945639458805[5] = 0;
   out_3040560945639458805[6] = 0;
   out_3040560945639458805[7] = 0;
   out_3040560945639458805[8] = 0;
   out_3040560945639458805[9] = 0;
   out_3040560945639458805[10] = 1.0;
   out_3040560945639458805[11] = 0;
   out_3040560945639458805[12] = 0;
   out_3040560945639458805[13] = 0;
   out_3040560945639458805[14] = 0;
   out_3040560945639458805[15] = 0;
   out_3040560945639458805[16] = 0;
   out_3040560945639458805[17] = 0;
   out_3040560945639458805[18] = 0;
   out_3040560945639458805[19] = 0;
   out_3040560945639458805[20] = 1.0;
   out_3040560945639458805[21] = 0;
   out_3040560945639458805[22] = 0;
   out_3040560945639458805[23] = 0;
   out_3040560945639458805[24] = 0;
   out_3040560945639458805[25] = 0;
   out_3040560945639458805[26] = 0;
   out_3040560945639458805[27] = 0;
   out_3040560945639458805[28] = 0;
   out_3040560945639458805[29] = 0;
   out_3040560945639458805[30] = 1.0;
   out_3040560945639458805[31] = 0;
   out_3040560945639458805[32] = 0;
   out_3040560945639458805[33] = 0;
   out_3040560945639458805[34] = 0;
   out_3040560945639458805[35] = 0;
   out_3040560945639458805[36] = 0;
   out_3040560945639458805[37] = 0;
   out_3040560945639458805[38] = 0;
   out_3040560945639458805[39] = 0;
   out_3040560945639458805[40] = 1.0;
   out_3040560945639458805[41] = 0;
   out_3040560945639458805[42] = 0;
   out_3040560945639458805[43] = 0;
   out_3040560945639458805[44] = 0;
   out_3040560945639458805[45] = 0;
   out_3040560945639458805[46] = 0;
   out_3040560945639458805[47] = 0;
   out_3040560945639458805[48] = 0;
   out_3040560945639458805[49] = 0;
   out_3040560945639458805[50] = 1.0;
   out_3040560945639458805[51] = 0;
   out_3040560945639458805[52] = 0;
   out_3040560945639458805[53] = 0;
   out_3040560945639458805[54] = 0;
   out_3040560945639458805[55] = 0;
   out_3040560945639458805[56] = 0;
   out_3040560945639458805[57] = 0;
   out_3040560945639458805[58] = 0;
   out_3040560945639458805[59] = 0;
   out_3040560945639458805[60] = 1.0;
   out_3040560945639458805[61] = 0;
   out_3040560945639458805[62] = 0;
   out_3040560945639458805[63] = 0;
   out_3040560945639458805[64] = 0;
   out_3040560945639458805[65] = 0;
   out_3040560945639458805[66] = 0;
   out_3040560945639458805[67] = 0;
   out_3040560945639458805[68] = 0;
   out_3040560945639458805[69] = 0;
   out_3040560945639458805[70] = 1.0;
   out_3040560945639458805[71] = 0;
   out_3040560945639458805[72] = 0;
   out_3040560945639458805[73] = 0;
   out_3040560945639458805[74] = 0;
   out_3040560945639458805[75] = 0;
   out_3040560945639458805[76] = 0;
   out_3040560945639458805[77] = 0;
   out_3040560945639458805[78] = 0;
   out_3040560945639458805[79] = 0;
   out_3040560945639458805[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4352631400091210883) {
   out_4352631400091210883[0] = state[0];
   out_4352631400091210883[1] = state[1];
   out_4352631400091210883[2] = state[2];
   out_4352631400091210883[3] = state[3];
   out_4352631400091210883[4] = state[4];
   out_4352631400091210883[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4352631400091210883[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4352631400091210883[7] = state[7];
   out_4352631400091210883[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4780386535614995733) {
   out_4780386535614995733[0] = 1;
   out_4780386535614995733[1] = 0;
   out_4780386535614995733[2] = 0;
   out_4780386535614995733[3] = 0;
   out_4780386535614995733[4] = 0;
   out_4780386535614995733[5] = 0;
   out_4780386535614995733[6] = 0;
   out_4780386535614995733[7] = 0;
   out_4780386535614995733[8] = 0;
   out_4780386535614995733[9] = 0;
   out_4780386535614995733[10] = 1;
   out_4780386535614995733[11] = 0;
   out_4780386535614995733[12] = 0;
   out_4780386535614995733[13] = 0;
   out_4780386535614995733[14] = 0;
   out_4780386535614995733[15] = 0;
   out_4780386535614995733[16] = 0;
   out_4780386535614995733[17] = 0;
   out_4780386535614995733[18] = 0;
   out_4780386535614995733[19] = 0;
   out_4780386535614995733[20] = 1;
   out_4780386535614995733[21] = 0;
   out_4780386535614995733[22] = 0;
   out_4780386535614995733[23] = 0;
   out_4780386535614995733[24] = 0;
   out_4780386535614995733[25] = 0;
   out_4780386535614995733[26] = 0;
   out_4780386535614995733[27] = 0;
   out_4780386535614995733[28] = 0;
   out_4780386535614995733[29] = 0;
   out_4780386535614995733[30] = 1;
   out_4780386535614995733[31] = 0;
   out_4780386535614995733[32] = 0;
   out_4780386535614995733[33] = 0;
   out_4780386535614995733[34] = 0;
   out_4780386535614995733[35] = 0;
   out_4780386535614995733[36] = 0;
   out_4780386535614995733[37] = 0;
   out_4780386535614995733[38] = 0;
   out_4780386535614995733[39] = 0;
   out_4780386535614995733[40] = 1;
   out_4780386535614995733[41] = 0;
   out_4780386535614995733[42] = 0;
   out_4780386535614995733[43] = 0;
   out_4780386535614995733[44] = 0;
   out_4780386535614995733[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4780386535614995733[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4780386535614995733[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4780386535614995733[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4780386535614995733[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4780386535614995733[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4780386535614995733[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4780386535614995733[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4780386535614995733[53] = -9.8000000000000007*dt;
   out_4780386535614995733[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4780386535614995733[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4780386535614995733[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4780386535614995733[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4780386535614995733[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4780386535614995733[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4780386535614995733[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4780386535614995733[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4780386535614995733[62] = 0;
   out_4780386535614995733[63] = 0;
   out_4780386535614995733[64] = 0;
   out_4780386535614995733[65] = 0;
   out_4780386535614995733[66] = 0;
   out_4780386535614995733[67] = 0;
   out_4780386535614995733[68] = 0;
   out_4780386535614995733[69] = 0;
   out_4780386535614995733[70] = 1;
   out_4780386535614995733[71] = 0;
   out_4780386535614995733[72] = 0;
   out_4780386535614995733[73] = 0;
   out_4780386535614995733[74] = 0;
   out_4780386535614995733[75] = 0;
   out_4780386535614995733[76] = 0;
   out_4780386535614995733[77] = 0;
   out_4780386535614995733[78] = 0;
   out_4780386535614995733[79] = 0;
   out_4780386535614995733[80] = 1;
}
void h_25(double *state, double *unused, double *out_6281372376385490076) {
   out_6281372376385490076[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4726918648082750388) {
   out_4726918648082750388[0] = 0;
   out_4726918648082750388[1] = 0;
   out_4726918648082750388[2] = 0;
   out_4726918648082750388[3] = 0;
   out_4726918648082750388[4] = 0;
   out_4726918648082750388[5] = 0;
   out_4726918648082750388[6] = 1;
   out_4726918648082750388[7] = 0;
   out_4726918648082750388[8] = 0;
}
void h_24(double *state, double *unused, double *out_6915004078644704554) {
   out_6915004078644704554[0] = state[4];
   out_6915004078644704554[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8284844246885073524) {
   out_8284844246885073524[0] = 0;
   out_8284844246885073524[1] = 0;
   out_8284844246885073524[2] = 0;
   out_8284844246885073524[3] = 0;
   out_8284844246885073524[4] = 1;
   out_8284844246885073524[5] = 0;
   out_8284844246885073524[6] = 0;
   out_8284844246885073524[7] = 0;
   out_8284844246885073524[8] = 0;
   out_8284844246885073524[9] = 0;
   out_8284844246885073524[10] = 0;
   out_8284844246885073524[11] = 0;
   out_8284844246885073524[12] = 0;
   out_8284844246885073524[13] = 0;
   out_8284844246885073524[14] = 1;
   out_8284844246885073524[15] = 0;
   out_8284844246885073524[16] = 0;
   out_8284844246885073524[17] = 0;
}
void h_30(double *state, double *unused, double *out_2040201661752251093) {
   out_2040201661752251093[0] = state[4];
}
void H_30(double *state, double *unused, double *out_6803135084135184473) {
   out_6803135084135184473[0] = 0;
   out_6803135084135184473[1] = 0;
   out_6803135084135184473[2] = 0;
   out_6803135084135184473[3] = 0;
   out_6803135084135184473[4] = 1;
   out_6803135084135184473[5] = 0;
   out_6803135084135184473[6] = 0;
   out_6803135084135184473[7] = 0;
   out_6803135084135184473[8] = 0;
}
void h_26(double *state, double *unused, double *out_2697944387754562837) {
   out_2697944387754562837[0] = state[7];
}
void H_26(double *state, double *unused, double *out_985415329208694164) {
   out_985415329208694164[0] = 0;
   out_985415329208694164[1] = 0;
   out_985415329208694164[2] = 0;
   out_985415329208694164[3] = 0;
   out_985415329208694164[4] = 0;
   out_985415329208694164[5] = 0;
   out_985415329208694164[6] = 0;
   out_985415329208694164[7] = 1;
   out_985415329208694164[8] = 0;
}
void h_27(double *state, double *unused, double *out_9128585645879728855) {
   out_9128585645879728855[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8977898395935609384) {
   out_8977898395935609384[0] = 0;
   out_8977898395935609384[1] = 0;
   out_8977898395935609384[2] = 0;
   out_8977898395935609384[3] = 1;
   out_8977898395935609384[4] = 0;
   out_8977898395935609384[5] = 0;
   out_8977898395935609384[6] = 0;
   out_8977898395935609384[7] = 0;
   out_8977898395935609384[8] = 0;
}
void h_29(double *state, double *unused, double *out_2357750419529377919) {
   out_2357750419529377919[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7755482950904391199) {
   out_7755482950904391199[0] = 0;
   out_7755482950904391199[1] = 1;
   out_7755482950904391199[2] = 0;
   out_7755482950904391199[3] = 0;
   out_7755482950904391199[4] = 0;
   out_7755482950904391199[5] = 0;
   out_7755482950904391199[6] = 0;
   out_7755482950904391199[7] = 0;
   out_7755482950904391199[8] = 0;
}
void h_28(double *state, double *unused, double *out_4092251211994497814) {
   out_4092251211994497814[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2673083933834860625) {
   out_2673083933834860625[0] = 1;
   out_2673083933834860625[1] = 0;
   out_2673083933834860625[2] = 0;
   out_2673083933834860625[3] = 0;
   out_2673083933834860625[4] = 0;
   out_2673083933834860625[5] = 0;
   out_2673083933834860625[6] = 0;
   out_2673083933834860625[7] = 0;
   out_2673083933834860625[8] = 0;
}
void h_31(double *state, double *unused, double *out_6556566438669995965) {
   out_6556566438669995965[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4757564609959710816) {
   out_4757564609959710816[0] = 0;
   out_4757564609959710816[1] = 0;
   out_4757564609959710816[2] = 0;
   out_4757564609959710816[3] = 0;
   out_4757564609959710816[4] = 0;
   out_4757564609959710816[5] = 0;
   out_4757564609959710816[6] = 0;
   out_4757564609959710816[7] = 0;
   out_4757564609959710816[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_8898850186491034744) {
  err_fun(nom_x, delta_x, out_8898850186491034744);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4123389795425744501) {
  inv_err_fun(nom_x, true_x, out_4123389795425744501);
}
void car_H_mod_fun(double *state, double *out_3040560945639458805) {
  H_mod_fun(state, out_3040560945639458805);
}
void car_f_fun(double *state, double dt, double *out_4352631400091210883) {
  f_fun(state,  dt, out_4352631400091210883);
}
void car_F_fun(double *state, double dt, double *out_4780386535614995733) {
  F_fun(state,  dt, out_4780386535614995733);
}
void car_h_25(double *state, double *unused, double *out_6281372376385490076) {
  h_25(state, unused, out_6281372376385490076);
}
void car_H_25(double *state, double *unused, double *out_4726918648082750388) {
  H_25(state, unused, out_4726918648082750388);
}
void car_h_24(double *state, double *unused, double *out_6915004078644704554) {
  h_24(state, unused, out_6915004078644704554);
}
void car_H_24(double *state, double *unused, double *out_8284844246885073524) {
  H_24(state, unused, out_8284844246885073524);
}
void car_h_30(double *state, double *unused, double *out_2040201661752251093) {
  h_30(state, unused, out_2040201661752251093);
}
void car_H_30(double *state, double *unused, double *out_6803135084135184473) {
  H_30(state, unused, out_6803135084135184473);
}
void car_h_26(double *state, double *unused, double *out_2697944387754562837) {
  h_26(state, unused, out_2697944387754562837);
}
void car_H_26(double *state, double *unused, double *out_985415329208694164) {
  H_26(state, unused, out_985415329208694164);
}
void car_h_27(double *state, double *unused, double *out_9128585645879728855) {
  h_27(state, unused, out_9128585645879728855);
}
void car_H_27(double *state, double *unused, double *out_8977898395935609384) {
  H_27(state, unused, out_8977898395935609384);
}
void car_h_29(double *state, double *unused, double *out_2357750419529377919) {
  h_29(state, unused, out_2357750419529377919);
}
void car_H_29(double *state, double *unused, double *out_7755482950904391199) {
  H_29(state, unused, out_7755482950904391199);
}
void car_h_28(double *state, double *unused, double *out_4092251211994497814) {
  h_28(state, unused, out_4092251211994497814);
}
void car_H_28(double *state, double *unused, double *out_2673083933834860625) {
  H_28(state, unused, out_2673083933834860625);
}
void car_h_31(double *state, double *unused, double *out_6556566438669995965) {
  h_31(state, unused, out_6556566438669995965);
}
void car_H_31(double *state, double *unused, double *out_4757564609959710816) {
  H_31(state, unused, out_4757564609959710816);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
