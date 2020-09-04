// Look for 'matrixmethods.cpp' for definition of following function declarations

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; 

double **SetSize(double **A, int N);
double *SetVector(double *vec,int N);
void entervector(double *vec, int N);
void showvector(double *vec,int N);
void entermatrix(double **mat, int N);
void showmatrix(double **mat,int N);
void LUDecomposition(double **mat, double **L, double **U, int N);
void LUbackwardsub(double **l,double **u,double *w,double *x,int N);
double determinant(double **u,int N);
void inverse(double **u,double **l,double **Ainv,int N);
void pivot(double**mat,int N);
