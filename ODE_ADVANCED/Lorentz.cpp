#include<iostream>
#include<math.h>
#include<fstream>
#include "rkroutines.h"
using namespace std;
void loreq(double X[],double t, double param[],double deriv[])
{

double x = X[0];
double y = X[1];
double z = X[2];

double r = param[0];
double sigma = param[1];
double b = param[2];

deriv[0] = sigma*(y-x);
deriv[1] = r*x - y - x*z;
deriv[2] = x*y-b*z;

return;
}

int main(){

cout<<"Enter initial values(x,y,z)"<<endl;
double x; cout<<"x=";cin>>x;
double y; cout<<"y=";cin>>y;
double z; cout<<"z=";cin>>z;


const int nstate = 3;
double state[nstate];

state[0] = x;state[1] = y;state[2] = z;

cout<<"Enter the parameter r: ";
double r; cin>>r;

double sigma = 10;
double b =8.0/3.0;

double param[3];

param[0]=r;param[1]=sigma;param[2]=b;

double tau = 0.1;

double time =0;

int nsteps;
cout<< "Enter number of steps:";
cin>>nsteps;


double *tplot,*xplot,*yplot,*zplot;

tplot = new double [nsteps];
xplot = new double [nsteps];
yplot = new double [nsteps];
zplot = new double [nsteps];

for(int i = 0; i<nsteps; i++)
{

x = state[0];
y = state[1];
z = state[2];

tplot[i] = time;

xplot[i] = x;
yplot[i] = y;
zplot[i] = z;

if((i%50)<1)
	cout<<"Finished"<<i+1<<"steps out of "<<nsteps<<endl;

//* Find new state using adaptive Runge-Kutta

rk4(state,nstate,time,tau,loreq,param);

time = time + tau;
}


//Find the locaation of the three steady states
double x_ss[3],y_ss[3],z_ss[3];

x_ss[0] = 0; y_ss[0]=0; z_ss[0]=0;
x_ss[1] = sqrt(b*(r-1)); y_ss[1] = x_ss[1]; z_ss[1]=r-1;
x_ss[2] = -sqrt(b*(r-1)); y_ss[2] = x_ss[2]; z_ss[2]=r-1;


ofstream lorenz;
lorenz.open("Lorenzdata.txt");

lorenz<<"tplot"<<"\t"<<"xplot"<<"\t"<<"yplot"<<"\t"<<"zplot"<<endl;

for(int i=0;i<nsteps;i++)
{
lorenz<<tplot[i]<<"\t"<<xplot[i]<<"\t"<<yplot[i]<<"\t"<<zplot[i]<<endl;
}

lorenz.close();

ofstream steady;
steady.open("stationary.txt");

for(int i=0;i<3;i++)
{

steady<<x_ss[i]<<"\t"<<y_ss[i]<<"\t"<<z_ss[i]<<endl;
	
}

delete [] tplot,xplot,yplot,zplot;

}
