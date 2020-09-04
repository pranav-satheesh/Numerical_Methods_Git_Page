#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;

void Euler_predictor(double* theta,double* omega,int n,double deltat,double(*fun)(double t,double theta,double omega,double* param),double* parameters);
void Taylor_series(double* theta,double* omega,int n,double deltat,double (*fun)(double t,double theta,double omega,double* param),double (*funderiv)(double t,double theta,double omega,double* param),double* parameters);
void RK2(double* theta,double* omega,int n,double deltat,double (*fun)(double t,double theta,double omega,double* param),double* parameters);
void RK4(double* theta,double* omega,int n,double deltat,double (*fun)(double t,double theta,double omega,double* param),double* parameters);

