/************************************************************************************

FILENAME: ebtel-2fl_functions.h

AUTHOR Will Barnes

DATE: created: 7 March 2014

DESCRIPTION: This file gives the function prototypes for functions in defined in ebtel_functions.c. Global variables are also declared here. See ebtel_functions.c and ebtel_main.c for more information on EBTEL and its original implementation in the IDL programming language (see Klimchuk et al., 2008). 

************************************************************************************/

#ifndef EBTEL2fl_FUNCTIONS_H
#define EBTEL2fl_FUNCTIONS_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <sys/stat.h>
#include <sys/types.h>

//Declare global variables
double K_B;
double KAPPA_0_E;
double KAPPA_0_I;
double M_P;
double M_EL;
double Q_E;
double Z_AVG;
double MU;
double PI;
double TWO_SEVENTHS;
double SEVEN_HALVES;
double TWO_THIRDS;
double ROOT_C2;
double C3;
double C4;

//Declare structures
struct Option {
	int dynamic;
	int dem_old;
	int rtv;
	int usage;
	int solver;
	int mode;
	int heating_shape;
	int index_dem;
	double energy_nt;
	double T0;
	double n0;
	double h_nano;
	double t_pulse_half;
	double t_start;
	double tau;
	double error;
};
struct ebtel_params_st {
		int i_max;
		double *heat;
		double *time;
		double *tau;
		double *temp_e;
		double *temp_i;
		double *ndens;
		double *press_e;
		double *press_i;
		double *vel;
		double *tapex_e;
		double *tapex_i;
		double *napex;
		double *papex_e;
		double *papex_i;
		double *coeff_1;
		double *logtdem;
		double *f_ratio;
		double *rad_ratio;
		double *cond_e;
		double *cond_i;
		double *rad_cor;
		double *rad;
		double *dem_tr_log10mean;
		double *dem_cor_log10mean; 
		double *dem_tot_log10mean;
		//DEBUG--add dpe,dpi
		double *dpe,*dpe1,*dpe2,*dpe3,*dpe4,*dpe5;
		double *dpi,*dpi1,*dpi2,*dpi3;
};
struct rk_params {
		double L;
		double *kpar;
		double r12;
		double r2;
		double r3;
		double r4;
		double q1;
		double q2;
		//double flux_nt;
		double f_e;
		double f_i;
		double f_eq;
		//double v;
		double Pae;
};
struct ebtel_rka_st {
		double tau;
		double *state;
};

//Declare prototype for ebtel_loop_solver of type struct *
struct ebtel_params_st *ebtel_loop_solver( int, double, double, struct Option);

//Declare prototype for ebtel_kpar_set of type void
double * ebtel_kpar_set( int);

//Declare prototype for ebtel_rad_loss of type double
double ebtel_rad_loss( double, double[], int);

//Declare prototype for ebtel_calc_c1 of type double
double ebtel_calc_c1(double, double, double, double);

//Declare prototype for ebtel_calc_c2 of type double
double ebtel_calc_c2(void);

//Declare prototype for ebtel_calc_c2e of type double
double ebtel_calc_c2e(void);

//Declare prototype for ebtel_calc_c2i of type double
double ebtel_calc_c2i(void);

//Declare prototype for ebtel_calc_c3 of type double
double ebtel_calc_c3(void);

//Declare prototype for ebtel_calc_c3e of type double
double ebtel_calc_c3e(void);

//Declare prototype for ebtel_calc_c3i of type double
double ebtel_calc_c3i(void);

//Declare prototype for ebtel_calc_lambda of type double
double ebtel_calc_lambda(double);

//Declare prototype for ebtel_linspace of type void
double * ebtel_linspace( int, int, int);

//Declare prototype for ebtel_calc_tr_dem of type double
double ebtel_calc_tr_dem( double, double, double, double, double, double, double, double[], int );

//Declare prototype for ebtel_avg_val of type double
double ebtel_avg_val(double[], int );

//Declare protoype for ebtel_max_val of type double
double ebtel_max_val(double, double);

//Declare prototype for ebtel_mem_free of type void
void ebtel_free_mem(struct ebtel_params_st *);

//Declare prototype for ebtel_rk of type double
double * ebtel_rk(double[], int, double, double, struct rk_params, struct Option);

//Declare prototype for ebtel_rk_derivs of type double
double * ebtel_rk_derivs(double[], double, int, struct rk_params, struct Option);

//Declare prototype for ebtel_heating of type double
double ebtel_heating(double, struct Option);

//Declare prototype for ebtel_print_header of type void
void ebtel_print_header(int, int, int, int, struct Option);

//Declare prototype for ebtel_euler of type double
double * ebtel_euler(double[], double, struct rk_params, struct Option);

//Declare prototype for ebtel_data_writer of type void
void ebtel_file_writer(int, struct Option, struct ebtel_params_st *);

//Declare prototype for ebtel_rk_adapt of type struct ebtel_rka_st
struct ebtel_rka_st *ebtel_rk_adapt(double[], int, double, double, double, struct rk_params, struct Option);

//Declare prototype for ebtel_min_val of type double
double ebtel_min_val(double, double);

//Declare prototype for ebtel_calc_abundance of type void
void ebtel_calc_abundance(void);

//Declare prototype for ebtel_static_eq of type double
double * ebtel_calc_ic(double[], double, double, struct Option);

//Declare prototype for ebtel_colon_operator of type double *
double * ebtel_colon_operator(double, double, double);

//Declare prototype for ebtel_weighted_avg_val of type double
double ebtel_weighted_avg_val(double[], int, double[]);

//Declare prototype for ebtel_conduction of type double
double * ebtel_calc_conduction(double, double, double, double, double, double, int);

//Declare prototype for ebtel_collision_freq of type double
double ebtel_collision_freq(double,double,double);

//Declare prototype for ebtel_calc_vel of type double
double ebtel_calc_vel(double, double, double, struct rk_params);

#endif