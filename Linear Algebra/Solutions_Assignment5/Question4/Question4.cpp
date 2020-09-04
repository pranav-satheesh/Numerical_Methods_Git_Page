/*============================================================================
Program     : Method for Solving Tridiagonal Matrix Equations 
Description : This program calculates solution of simultaneous equations which
              forms Tridiagonal Matrix if converted to AX=B form.
              
              We are taking Matrix A from previous question i.e. from Poisson Equations. 
              We will declare 3 set of 1D array. One set for diagonal elements and
              other two sets for off-diagonal elemets 

Course      : PH5720              
Author      : Pritam Kalbhor
Email       : physics.pritam@gmail.com
Date        : March 10, 2020
=============================================================================*/
#include <iostream>
#include <fstream>
#include<iomanip>
#include<cmath>
#include<time.h>
#include<cstring>
using namespace std;

double h;
double f(double x){ return (3.*x+(x*x))*exp(x);}
double u(double x){ return x*(1.-x)*exp(x);}  

int main(){
   clock_t start, stop;
   int N[]={10, 100, 1000, 100000};
   
   for(int k=0; k<sizeof(N)/sizeof(N[0]);k++){
      start=clock();
      int n=N[k];
      //Next 3 lines help us to write 3 different file names for each value of n
      string name("fileFor_"); string name2=to_string(n); name.append(name2); 
      name.append(".dat"); char *cname=new char[name.length()+1]; strcpy(cname,name.c_str());
	   FILE *f_ptr=fopen(cname, "w");		// this is used for printing relative error
      
      cout<<"Size of Matrix is: "<<n<<endl;
      h=1./(1.+n);
      double *X,*B,*L,*D,*U;
      
      X=new double[n+1];   //Solution vector           :    from 1 to n
      B=new double[n+1];   //B verctor of AX=B equation:    from 1 to n
      D=new double[n+1];   //Diagonal elemets stored   :    from 1 to n-1
      L=new double[n+1];   //Lower diagonal elements   :    from 2 to n
      U=new double[n+1];   //Upper diagonal elements   :    from 1 to n-1
      
      for(int i=1; i<=n; i++)    D[i]=2.;
      for(int i=1; i<=n-1; i++)  U[i]=-1.;
      for(int i=2; i<=n; i++)    L[i]=-1.;
      for(int i=1; i<=n; i++)    B[i]=f(i*h)*h*h;

      int p=0; //Float point Ops Counter
      //Forward Elimination
      for(int i=2;i<=n;i++){
	      double w=L[i]/D[i-1]; p +=1;
	      D[i]-=w*U[i-1]; p +=2;
	      B[i]-=w*B[i-1]; p +=2;
	      L[i]=0.;
      }
      
      //Backward Substitution
      X[n]=B[n]/D[n];
      for(int i=n-1;i>=1;i--){X[i]=(B[i]-U[i]*(X[i+1]))/D[i]; p+=3;}

      if(n!=100000)for(int i=1; i<=n; i++){fprintf(f_ptr, "%lf \t %lf \t %lf \t %lf\n", i*h, X[i], u(i*h), log10( abs(X[i]-u(i*h))*100./u(i*h)) ); }
      
      cout<<"Number of Floating point operations: "<<p<<endl;
      stop=clock();
      cout<<"Time taken: "<<(double)(stop-start)/(CLOCKS_PER_SEC)<<" seconds\n"<<endl;
   }
}
