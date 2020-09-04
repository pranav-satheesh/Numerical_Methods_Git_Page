// Look for 'LUDecomposition.cpp' for definition of following function declarations

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; 

//---------------------------------------------------------------------------
//Function declarations starts here:

// This returns decomposed matrix into Lower Triangular and Upper Triangular matrix.

float **SetSize(float **A, int N);
float **SetValues(float **A, int N);
void ShowLUMatrix(float **L, float **U, int N);
void LUDecomposition(float **mat, float **L, float **U, int N);

// This functions returns value of a function f(x). For definition check file 'LUDecomposition.cpp'
/*double f(double x);*/
float f(float x);
float u(float x);    //Analytical Solution
