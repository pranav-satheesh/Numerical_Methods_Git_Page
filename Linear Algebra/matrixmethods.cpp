#include "matrixmethods.h"
 
// Allocate memory for a matrix
double **SetSize(double **A, int N){
   A=new double*[N];
       for(int i=0;i<N;i++){
         A[i]=new double[N];
       }
   return A;
}


double *SetVector(double *vec,int N)
{
vec = new double[N];
return vec;
}

void entervector(double *vec, int N)
{

for(int i=0;i<N;i++)
{
cout<<"Enter the element"<<"\t"<<i+1<<":of the vector"<<endl;
cin>>vec[i];
}

}

void showvector(double *vec,int N)
{

for(int i=0;i<N;i++)
cout<<vec[i]<<endl;

}


//Enter the matrix elements
void entermatrix(double **mat, int N){

double value;
for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
	{cout<<"Enter the "<<i+1<<" "<<j+1<<"element of the matrix:"<<endl;
	cin>>value;
	mat[i][j] = value;
	}

}

}

//Write out the matrix
void showmatrix(double **mat,int N){

for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
	cout<<mat[i][j]<<"\t";
cout<<endl;
}

}

/*
The function LUDecomposition takes the matrix which undergoes LU decomposition and two pointers to L and U matrices memory.
*/
void LUDecomposition(double **mat, double **lower, double **upper, int N){
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

void LUbackwardsub(double **l,double **u,double *w,double *x,int N)
{

double *y;
int sum=0;
y=new double[N];

y[0] = w[0];

for(int i=1;i<N;i++)
{
	for(int j=0;j<i;j++)
	{	
	 sum = sum + l[i][j]*y[j];
	}
y[i] = w[i] - sum;
}

x[N-1] = y[N-1]/(u[N-1][N-1]);
sum =0;
for(int i=N-2;i>=0;i--)
{

for(int j=i+1;j<N;j++)
{sum = sum + u[i][j]*x[j];
}

x[i] = (y[i]-sum)/(u[i][i]);
}

}

 
double determinant(double **u,int N)
{

double det = 1;

for(int i=0;i<N;i++)
{
det = det * u[i][i];
}

return det;
}


//The Inverse of the Matrix is found by solving each column by column.
void inverse(double **u,double **l,double **Ainv,int N)
{

double *col;
double *x;

for(int i=0;i<N;i++)
{
col = new double[N];
x = new double[N];

for(int j=0;j<N;j++)
{col[j] = 0;}

col[i] =1;

LUbackwardsub(l,u,col,x,N);

for(int k=0;k<N;k++)
{
Ainv[k][i] = x[k];
}

}

}


