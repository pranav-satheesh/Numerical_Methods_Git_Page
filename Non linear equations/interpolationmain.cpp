#include "matrixmethods.h"
#include "interpolation.h"

int main()
{

//Generate some data

double *x;
x = SetVector(x,3);
entervector(x,3);

double *y;
y = SetVector(x,3);

for(int i=0;i<3;i++)
{
y[i] = x[i]*x[i];
}

int npoints = 100;

int xmin = 0;
int xmax = 3;

double *newx;
newx = SetVector(newx,npoints);

for(int i=0;i<npoints;i++)
{

x[i] = xmin + i*(xmax-xmin)/(npoints-1);

}

double *newy;
newy = SetVector(newy,npoints);

interpolate(3,npoints,x,y,newx,newy);


for(int i=0;i<npoints;i++)
{
cout<<xnew[i]<<"\t"<<ynew[i]<<endl;
}

return 0;
}
