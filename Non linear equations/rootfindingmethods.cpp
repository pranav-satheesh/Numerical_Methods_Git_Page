#include "rootfindingmethods.h"

double bisection(double (*func)(double),double x1,double x2,double xdelta,int max_iter = 1000)
{

double xmid,fmid;


f1 = (*func)(x1);
f2 = (*func)(x2);

if(f1*f2 >= 0.0){
cout<<"Error in the method. Enter the proper range."<<endl;
}

else{

for(int i=0;i<= max_iter;i++)
{

xmid = (x1+x2)/2;
fmid = (*func)(xmid);

if(f1*fmid <0):
x2 = xmid;

else if(f1*fmid>0):
x1 = xmid;

if(fabs(x2-x1)<xdelta || fmid == 0.0)
return xmid;
}

cout<<"Too many iterations!Try changing the maximum iteration number"<<endl;

}

}


double newtonraphson(void (*funcd)(double,double *,double *),double x1,double x2,double xacc)
{
//*The funcd function is a user defined function that gives the function value at point x and its derivative.[x1,x2] defines the interval we are searching the root at. xacc determines the accuracy of our equation.*//

double f,df,dx,xnext;

int max_iterations = 1000;
//initial gues

xnext = 0.5 * (x1+x2);

for(int j=0; j<max_iterations; j++)
{

(*funcd)(xnext,&f,&df);
dx = f/df;
xnext -= dx;

if((x1-xnext)*(xnet-x2) < 0.0){
cout<<"Error in function newtonraphson:"<<endl;}

if(fabs(dx)<xacc)
return xnext;
}
}

double secantmethod(double (*func)(double),double x1,double x2,double xdelta,int max_iter = 1000)
{

double xnew;

double xn = x2;
double xnminus1 = x1;

for(int i=0;i<max_iter;i++)
{

xnew = ((*func)(xn)*xminus1 -(*func)(xminus1)*xn)/((*func)(xn) - (*func)(xminus1));

xminus1 = xn;
xn = xnew;

if(fabs(xn-xminus1)<xacc || (*func)(xn) == 0.0)
return xn;
}

}
