#include "interpolation.h"

//Code for N points interpolation

void interpolate(int N,int npoints,double *xvalues,double *yvalues,double *newx, double *newy)
{

for(int i=0;i<npoints;i++)
{

double x = newx[i];
double result = 0;

for(int j=0;j<N;j++)
{

double term = yvalues[j];

	for(int k=0;k<N;k++)
	{
	 if(k!=j)
		term = term * (x-xvalues[k])/(xvalues[j]-xvalues[k]);
	}
result += term;
}

newy[i] = result;

}

}
 
