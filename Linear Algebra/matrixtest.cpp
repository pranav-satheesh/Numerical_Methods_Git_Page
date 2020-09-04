#include <iostream>
#include <cmath>
#include "matrixmethods.h"
using namespace std;

int main()
{

double **A,*B;
int Na,Nb;

cout<<"Enter the size of matrix A:";
cin>>Na;

A = SetSize(A,Na);

cout<<"Enter matrix A:";

entermatrix(A,Na);
showmatrix(A,Na);

cout<<"Enter size of vector B:";
cin>>Nb;

B = SetVector(B,Nb);
cout<<"Enter vector B:";

entervector(B,Nb);
cout<<endl;
showvector(B,Nb);

double **L,**U;

L = SetSize(L,Na);
U = SetSize(U,Na);

LUDecomposition(A,L,U,Na);

cout<<"L:"<<endl;
showmatrix(L,Na);

cout<<"U:"<<endl;
showmatrix(U,Na);

return 0;
}
