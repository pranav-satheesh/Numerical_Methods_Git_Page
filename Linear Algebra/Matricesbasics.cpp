#include<iostream.h>
using namespace std;

void subfunction(int row, int col, int vec[], int matr[][5]); // line d
{
int k, m;
// write out the vector
cout << `` Content of vector vec in subfunction:'' << endl;
for (k = 0; k < col; k++){
cout << vec[k] << endl;
}
// Then write out the matrix
cout << `` Content of matrix matr in subfunction:'' << endl;
for (m = 0; m < row; m++){
for (k = 0; k < col ; k++){
cout << matr[m][k] << endl;
}
}
} // end of function subfunction



int main()
{
int k,m, row = 3, col = 5;
int vec[5];
// Declaring a vector of size 5

int matr[3][5]; //Here we declared a twwo index object of size 3x5

// Fill in vector vec
for (k = 0; k < col; k++) vec[k] = k;

// fill in matrix
for (m = 0; m < row; m++){
for (k = 0; k < col ; k++) matr[m][k] = m + 10*k;
}
// write out the vector
cout <<"Content of vector vec:"<< endl;
for (k = 0; k < col; k++){
cout << vec[k] << endl;
}
// Then write out the matrix
cout << `` Content of matrix matr:'' << endl;
for (m = 0; m < row; m++){
for (k = 0; k < col ; k++){
cout << matr[m][k] << endl;
}
}
subfunction(row, col, vec, matr); // line c
return 0;
} // end main function

