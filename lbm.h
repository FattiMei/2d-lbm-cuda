#ifndef __LBM_H__
#define __LBM_H__


#include <stdio.h>
#include <stdbool.h>


int width,
    height,
    max_it;


float reynolds,
      u_in;


float nu,
      tau,
      sigma,
      double_square_sigma,
      lambda_trt,
      tau_minus,
      omega_plus,
      omega_minus,
      sub_param,
      sum_param;


int *boundary;
bool *obstacles;
float *ux,
      *uy,
      *f,
      *new_f,
      *rho,
      *u_out;


void lbm_setup(FILE *in);


void lbm_init(
	  float f[]
	, float rho[]
	, float ux[]
	, float uy[]
	, const int width
	, const int height
	, const bool obstacles[]
);


void lbm_calc_boundary(
	  int boundary[]
	, const bool obstacles[]
	, const int width
	, const int height
);


void lbm_step1(
	  const int width
	, const int height
	, const int it
	, const float u_in_now
	, const float om_p
        , const float sum_param
	, const float sub_param
	, float f[]
	, float new_f[]
	, float rho[]
	, float ux[]
        , float uy[]
	, float u_out[]
	, const int boundary[]
	, const bool obstacles[]
);


void lbm_step2(
	  const int width
	, const int height
	, float f[]
	, const float new_f[]
	, const bool obstacles[]
);


#endif
