/*
QUIZ - I (Numerical Methods & Programming PH5720)

C++ program (using pointers) to decompose a matrix
into lower and upper diagonal matrix

Date: 18 - 02 - 2020.

Goal: Use this code to decompose the given matrix in question.
*/

#include "LUDecomposition.h"

float **SetSize(float **A, int N){
   A=new float*[N];
       for(int i=0;i<N;i++){
         A[i]=new float[N];
       }
   return A;
}

float **SetValues(float **A, int N){
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         if(i==j)A[i][j]=2;
         if(abs(i-j)==1)A[i][j]=-1;
      }   
    }
  return A;
}

void LUDecomposition(float **mat, float **lower, float **upper, int N){
    for (int i = 0; i < N; i++){
        // Compute the Upper Triangular Matrix
        for (int k = i; k < N; k++){
            // Summation of L(i, j) * U(j, k)
            float sum = 0;
            for (int j = 0; j < i; j++){
                sum += (lower[i][j] * upper[j][k]);
            }
            // Evaluating U(i, k)
            upper[i][k] = mat[i][k] - sum;
        }
     
        // Compute the Lower Triangular Matrix
        for (int k = i; k < N; k++){
                if (i == k)
                    lower[i][i] = 1; // Choosen Diagonal elements as 1
                else{
                    // Summation of L(k, j) * U(j, i)
                    float sum = 0;
                    for (int j = 0; j < i; j++){
                       sum += (lower[k][j] * upper[j][i]);
                    }
                // Evaluating L(k, i)
                lower[k][i] = (mat[k][i] - sum) / upper[i][i];
            }
        }
    }

}//End of LUD function


//Print Matrix L and U
void ShowLUMatrix(float **L, float **U, int N){
    cout<<endl;
    cout << setw(6) << "      Lower Triangular"<< setw(45) << "Upper Triangular" << endl;
    // Displaying the result :                                                                                                      
    for (int i = 0; i < N; i++){
        // Lower Matrix
        for (int j = 0; j < N; j++){
            cout << setw(6) << L[i][j] << "\t";
        }
        cout << "\t";
        // Upper Matrix
        for (int j = 0; j < N; j++){
            cout << setw(6) << U[i][j] << "\t";
        }
        cout << endl;
    }
}

//Functions from Poisson Equation
double f(double x){ return (3.*x+(x*x))*exp(x);}
float f(float x){ return (3.*x+(x*x))*exp(x);}
float u(float x){ return x*(1.-x)*exp(x);}      //Analytical Solution


