#include "rkroutines.h"
#include "math.h"
using namespace std;

void rk4(double x[],int nx, double t, double tau,void (*derivsRK)(double x[],double t, double param[],double deriv[]),double param[]){
//Runge-Kutta integrator of 4th order

double *F1,*F2,*F3,*F4,*xtemp;

F1 = new double[nx];
F2 = new double[nx];
F3 = new double[nx];
F4 = new double[nx];

xtemp = new double[nx];

//*F1 = f(x,t)
derivsRK(x,t,param,F1);

//*F2 = f(x+ tau*F1/2,t+tau/2)

double t_half = t + 0.5*tau;
for(int i =0; i<nx; i++)
	xtemp[i] = x[i] + 0.5*tau*F1[i];

derivsRK(xtemp,t_half,param,F2);

//*F3 = f(x+ tau*F2/2,t+tau/2)

for(int i =0; i<nx; i++)
	xtemp[i] = x[i] + 0.5*tau*F2[i];

derivsRK(xtemp,t_half,param,F3);


//*F4 = f(x+ tau*F3,t+tau)
double t_full = t + tau;
for(int i =0; i<nx; i++)
	xtemp[i] = x[i] + tau*F3[i];

derivsRK(xtemp,t_full,param,F4);

for(int i=0;i<nx;i++)
	x[i] += (tau/6.)*(F1[i] + F4[i] + 2*(F2[i]+F3[i]));

delete [] F1,F2,F3,F4,xtemp;
}




void rka(double x[],int nx, double& t, double& tau,double err,void (*derivsRK)(double x[],double t, double param[],double deriv[]),double param[]){
//Adaptive Runge-Kutta routine


//* Set initial variables
double tsave = t; //save initial value
double safe1 = 0.9,safe2 = 4.0; //safety factors

//*Looping over maximum number of attemps to satisfy error bound
double *xsmall,*xbig;
xsmall = new double[nx];
xbig = new double[nx];

int maxTry = 100;

for(int itry=0;itry<maxTry;itry++)
{
	
	//Take the two small time steps
	double half_tau = 0.5*tau;
	for(int i=0;i<nx;i++)
		xsmall[i] = x[i];

	rk4(xsmall,nx,tsave,half_tau,derivsRK,param);

	t = tsave + half_tau;
	rk4(xsmall,nx,t,half_tau,derivsRK,param);

	//Take the single big time step
	t = tsave + tau;

	for(int i=0;i<nx;i++)
		xbig[i] = x[i];

	rk4(xbig,nx,tsave,tau,derivsRK,param);

	//*Compute the estimated truncation error
	double errorRatio = 0.0, eps = 1.0e-16;
	for(int i=0;i<nx;i++){

	double scale = err * (fabs(xsmall[i]) + fabs(xbig[i]))/2.0;
	double xdiff = xsmall[i] - xbig[i];
	double ratio = fabs(xdiff)/(scale + eps);
	errorRatio = (errorRatio > ratio)?errorRatio:ratio; }

	//*Estimate new tau value(including safety factors)
	double tau_old = tau;
	tau = safe1*tau_old*pow(errorRatio,-0.20);
	tau = (tau>tau_old/safe2) ? tau:tau_old/safe2;
	tau = (tau>safe2*tau_old) ? tau:safe2*tau_old;

	//*If error is acceptable, return computed values

	if(errorRatio < 1){

	for(int i=0; i<nx; i++)
		x[i] = xsmall[i];
	return;
	}
}

//*Issue error message if error bound never satisfied
cout<<"ERROR: Adaptive Runge-Kutta routine failed"<<endl;

}
