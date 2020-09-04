#include "matrixmethods.h"
#include "interpolation.h"
#include<fstream>
int main()
{

//Generate some data

double *x;
x = SetVector(x,3);
entervector(x,3);

double *y;
y = SetVector(y,3);

for(int i=0;i<3;i++)
{
y[i] = x[i]*x[i];

cout<<x[i]<<"\t"<<y[i]<<endl;
}

int npoints = 100;

double xmin = 0;
double xmax = 3;

double *newx;
newx = SetVector(newx,npoints);

for(int i=0;i<npoints;i++)
{

newx[i] = xmin + i*(xmax-xmin)/(npoints-1);

}

double *newy;
newy = SetVector(newy,npoints);

interpolate(3,npoints,x,y,newx,newy);


for(int i=0;i<npoints;i++)
{
cout<<newx[i]<<"\t"<<newy[i]<<endl;
}


//Store in File

ofstream file;

file.open("outputdatapoints.txt");

file<<"x_value"<<"\t"<<"y_value"<<endl;

for(int i=0;i<npoints;i++)
{
file<<newx[i]<<"\t"<<newy[i]<<endl;
}

file.close();

return 0;
}



