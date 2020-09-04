#include<iostream>
#include<math.h>
using namespace std;

void rk4(double x[],int nx, double t, double tau,void (*derivsRK)(double x[],double t, double param[],double deriv[]),double param[]);


void rka(double x[], int nx, double &t, double &tau, double err,void (*derivsRK)(double x[],double t, double param[],double deriv[]),double param[]);

