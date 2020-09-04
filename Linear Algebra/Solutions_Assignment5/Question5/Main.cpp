#include <iostream>
using namespace std;
#include "LUDecomposition.h"
#include <typeinfo>
#include <fstream>
#include <time.h>
#include <cmath>

int N=10;    // Size of the Matrix

float *BackSubstitution(float **U, float *X, float *Y, int n){
   // Solves UX=Y
   for(int i=n-1;i>=0;i--){            
      X[i]=Y[i];
      for(int j=i+1;j<n;j++){
         if(i!=j){
            X[i]=X[i]-(U[i][j]*X[j]);
         }          
      }
      X[i]=X[i]/U[i][i];  
   }
   return X;
}

float *ForwardSubstitution(float **L, float *Y, float *B, int n){
   //Solve LY=B
   for(int i=0;i<n;i++){            
      Y[i]=B[i];
      for(int j=0;j<=i-1;j++){
         if(i!=j){
            Y[i]=Y[i]-L[i][j]*Y[j];
         }          
      }
      Y[i]=Y[i]/L[i][i];  
   }
   return Y;
}

int main(){
   clock_t start, stop;
    float **A;  // 2D square Matrix
    float **L;  // Lower Triangular Matrix
    float **U;  // Upper Triangular Matrix

   //Set Dimensions of Matrices
   int Ns[]={4, 10, 50, 100, 200,300,400,500,600,700,800,900, 1000, 1200, 1400, 1600, 1800, 2000, 2200};
	ofstream tfile("timedata.dat");
	
   for( int t = 0; t < sizeof(Ns)/sizeof(Ns[0]); t++ ){ //Loop over size of matrices
		 N=Ns[t];
		 cout<<"Size of Matrix is: "<<N<<endl;
		 A=SetSize(A, N);
		 L=SetSize(L, N);
		 U=SetSize(U, N);
		 A=SetValues(A, N);              // Create a Matrix and put values in 
    	 
    	 start=clock(); // Clock Start
		 LUDecomposition(A, L, U, N);    // This will return L and U
		 
		float h; h=1./(N+1.);         // Step size
		float *x;   x=new float[N];   for(int i=0; i<N; i++){x[i]=h*(i+1.);} // Set x variable
		float *B;   B=new float[N];   for(int i=0; i<N; i++){B[i]=h*h*f(x[i]);} // Set B Matrix: AX=B
		
		float *X; X=new float[N];   float *Y; Y=new float[N];
		Y=ForwardSubstitution(L, Y, B, N);     // AX=B implies LUX=B implies LY=B if UX=Y
		X=BackSubstitution(U, X, Y, N);        // UX=Y

		stop=clock(); double time=(double)(stop-start)/(CLOCKS_PER_SEC); //Stop clock and find time taken in seconds
      cout<<"Time taken: "<<time<<" seconds\n"<<endl;
		tfile<<N<<"\t"<<time<<endl;
		
		if(N==4 || N==10 || N==100 || N==1000){
			string name("fileFor_");   string name2=to_string(N); name.append(name2); name.append(".dat");
			ofstream ofile(name); 														//Output file declaration		
			for(int i=0; i<N; i++)ofile<<x[i]<<"\t"<<X[i]<<"\t"<<u(x[i])<<"\t"<<abs((X[i]-u(x[i]))/u(x[i]))*100.<<endl; // Saving it to file
		}
   }
}// End of Main


