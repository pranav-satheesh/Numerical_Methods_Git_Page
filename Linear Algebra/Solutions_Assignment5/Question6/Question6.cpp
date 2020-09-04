/*============================================================================
Program     : LU Decomposition using gsl libraries
Description : This program calculates solution of simultaneous equations using
              method of LU decompostion. It makes use of GNU scientific libraries.
              
              To intall gsl libraries in your linux OS: Run following command in your terminal.
				  sudo su && cd $HOME && wget ftp://ftp.gnu.org/gnu/gsl/gsl-latest.tar.gz && tar -xf gsl-latest.tar.gz && cd gsl-2* && ./configure && make && make install
				  
Course      : PH5720              
Author      : Pritam Kalbhor
Email       : physics.pritam@gmail.com
Date        : March 10, 2020

How to Run  : g++ -std=c++17 -o a.out Question6.cpp -lgsl -lgslcblas -lm && ./a.out
====================================================================================*/						

#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_linalg.h>		//Don't forget to include Header files

#include<time.h>
#include<iostream>
#include<string>
#include <cstring>
using namespace std;

//-----------------Function prototypes----------------------------------------
 double f(double x){double p=(3*x)+(x*x); return ( p*exp(x) );}
 double gsl_lib(double *A, double *B, int N, double h, gsl_vector *xp);
 double u(double x){return (x*(1-x)*exp(x) );}
 
int main(){
	int i, j;		//iteration arguments for various loops
	double h;		// step size
	double x_num;	// numerical solution
	double x_true;	// exact solution
	double rel_err; // relative error
	int Ns[]={10, 100, 1000};			// matrix dimension
	
	for(int k=0; k<sizeof(Ns)/sizeof(Ns[0]); k++){
		int N=Ns[k]; cout<<"Size of Matrix is: "<<N<<endl; //Get Matrix Size
		
		//next 3 lines are for choosing dynamic file names
		string name("fileFor_");   string name2=to_string(N); name.append(name2); 
		name.append(".dat"); char *cname=new char[name.length()+1]; strcpy(cname,name.c_str());
		FILE *f_ptr=fopen(cname, "w");		// this is used for printing relative error
		
		h=1./(N+1.);		// step size
			
		//	Put 1d array.
		double *B=new double[N];
		double *A=new double[N*N]; // 2D array... Matrix
		 
		 clock_t start, stop;								//declaring clock_t variables

		// set matrix element
		 for(i=0; i<N; i++)for(j=0; j<N; j++){ 		
				 if(i==j)A[i*N+j] = 2.;
				 else	if(abs(i-j)==1)A[i*N+j] = -1.;
				 else A[i*N+j]=0.;
				}
	  	 for(i=0; i<N; i++)B[i] = h*h*f(0.+(i+1)*h);		// sets values of B matrix (AX=B)
		
		//Print matrix using following line
		//for(i=0; i<N; i++){for(j=0; j<N; j++)cout<<A[i*N+j]<<"\t"; cout<<endl;}
		
		start = clock();	//starts clock
		gsl_vector *xp = gsl_vector_alloc (N); //Declare and allocate size of gsl vector	
		gsl_lib(A, B, N, h, xp);

		//Writing to file
			for(i=0; i<N; i++){
					x_num = gsl_vector_get (xp,i); //Get solution Xi ith value
					double x = (i+1)*h;
					x_true = u(x);
					rel_err = fabs( (x_num - x_true) / x_true); //Relative error
					fprintf(f_ptr,"%lf \t %g \n", x, rel_err  );//Write to file
				}  
		gsl_vector_free (xp);
		
		// *CLOCKS_PER_SEC is number of ticks in a second and the clock() function measures in time in units of ticks.	
		stop = clock();	double time = (double)(stop-start)/(CLOCKS_PER_SEC);
		cout<<"Time Taken: "<<time<<endl<<endl;
		free(A);
		free(B);
		fclose(f_ptr);
	}
  return 0;
}//End of Main

//-----------------------------------------------------------------
	
double gsl_lib(double *A, double *B, int N, double h, gsl_vector *xp){
	  gsl_matrix_view m = gsl_matrix_view_array (A, N, N);	//GSL Matrix
	  gsl_vector_view b = gsl_vector_view_array (B, N);		//GSL Vector
	  
	  int s;
	  gsl_permutation *p = gsl_permutation_alloc (N); //Declare Permutation Matrix
	  gsl_linalg_LU_decomp (&m.matrix, p, &s);				//Decomposition
	  gsl_linalg_LU_solve (&m.matrix, p, &b.vector, xp);  //Solution

	  printf ("x = ");
	  //Printing GSL vector xp is the solution
	 //gsl_vector_fprintf (stdout, xp, "\t%g");

	  gsl_permutation_free (p);
  }
