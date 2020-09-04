#include "NuMeth.h"
double intrpf(double xi,double x[],double y[]);
void main(){
//* Initialize the data points to be fit by quadratic

double x[4],y[4];
cout<<"Enter data points:"<<endl;

for(int i=1; i<=3; i++){
cout<<"x["<<i<<"]=";
cin>>x[i];
cout<<"y["<<i<<"]=";
cin>>y[i];
}

Establish the range of interpolation(from x_min to x_max)
double x_min,x_max;
cout<<"Enter minimum value of x:";
cin>>x_min;
cout<<"Enter maximum value of x:";
cin>>x_max;

//* Find yi for thr desired interpolation values xi using 
// the function intrpf

int nplot = 100; //Number of points for interpolation curve
double *xi,*yi;
xi = new double[nplot+1];
yi = new double[nplot+1];

for(i=1; i<=nplot; i++){

xi[i] = x_min + (x_max-x_min)*(i-1)/(nplot-1);
yi[i] = intrpf(xi[i],x,y);
}

//*Print out the plotting variables: x,y,xi,yo

ofstream xout("x.txt"),yout("y.txt"),xiout("xi.txt"),yiout("yi.txt");

for(i=1;i<=3;i++)
{

xout<<x[i]<<endl;
yout<<y[i]<<endl;

}

for(i=1;i<=nplot;i++)
{

xout<<xi[i]<<endl;
yout<<yi[i]<<endl;

}

delete [] xi,yi;

double intrpf(double xi,double x[],double y[])
{


double yi = (xi-x[2])*(xi-x[3])*y[1]/((x[1]-x[2])*(x[1]-x[3])) + (xi-x[1])*(xi-x[3])*y[2]/((x[2]-x[1])*(x[2]-x[3])) +(xi-x[1])*(xi-x[2])*y[3]/((x[3]-x[1])*(x[3]-x[2])) ;


return(yi);

}

