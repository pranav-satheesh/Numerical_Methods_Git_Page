#include<iostream>
#include<math.h>
#include<fstream>
#include "Odefunctions.h"

double M = 1, L =1 , g = 1;
double beta = sqrt(g/L);

double deriv(double t,double theta,double omega,double* param)
{
   /*
   This function returns the analytical derivative of omega
   */
   double k = param[0];
   double A = param[1];
   double Om = param[2];

   return -beta * beta * theta - k * omega + A * cos(Om * t);
}


double doublderiv(double t,double theta,double omega,double* param)
{
   /*
   This function returns the analytical double derivative of omega
   */

   double k = param[0];
   double A = param[1];
   double Om = param[2];

   return -beta * beta * cos(theta) * omega -A * Om * sin(Om * t) - k * deriv(t,theta,omega,param);
}


int main()
{

double *parameter = new double[3];

cout<<"Enter the value of k:"<<endl;
cin>>parameter[0];
cout<<"Enter the value of A:"<<endl;
cin>>parameter[1];
cout<<"Enter the value of driving frequency:"<<endl;
cin>>parameter[2];

double dt;
int N;
cout<<"Enter the number of steps:"<<endl;
cin>>N;
cout<<"Enter the step size dt:"<<endl;
cin>>dt;

double *Omega = new double[N];
double *Theta = new double[N];
double *time = new double[N];
cout<<"Enter the inital values of theta and omega"<<endl;
cin>>Theta[0]>>Omega[0];

int choice;
string prefix;

cout<<"Select the Method : "<<endl;
cout<<"1. Euler Predictor"<<"\t"<<"2. Taylor series"<<"\t"<<"3. Rk2"<<"\t"<<"4. Rk4"<<endl;
cout<<"Enter the choices(1,2,3,4)"<<endl;
cin>>choice;

if(choice == 1)
{
Euler_predictor(Theta,Omega,N,dt,deriv,parameter);
prefix = "Euler";
}
else if(choice == 2)
{
   Taylor_series(Theta,Omega,N,dt,deriv,doublderiv,parameter);
   prefix = "Taylor";
}
else if(choice == 3)
{
   RK2(Theta,Omega,N,dt,deriv,parameter);
   prefix = "RK2";
}
else if(choice == 4)
{
   RK4(Theta,Omega,N,dt,deriv,parameter);
   prefix = "RK4";
}
else
{
   cout<<"Wrong choice! Try again.";
}

for(int i=0;i<=N;i++)
{
 time[i] = i*dt;
}

string filename;

ofstream My_file;

cout<<"Enter the file name";
cin>>filename;

filename = prefix + filename;

My_file.open(filename);

My_file<<"Parameters:"<<"\t"<<parameter[0]<<","<<parameter[1]<<","<<parameter[2]<<endl;
My_file<<"t"<<"\t"<<"theta"<<"\t"<<"Omega"<<"\t"<<endl;

for(int i=0;i<N;i++)
{
My_file<<time[i]<<"\t"<<Theta[i]<<"\t"<<Omega[i]<<endl;
}

My_file.close();

return 0;
}