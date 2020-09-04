#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std; 

float **SetSize(float **A, int N){
   A=new float*[N];
       for(int i=0;i<N;i++){
         A[i]=new float[N];
       }
   return A;
}


void LUDecomposition(float **mat, float **lower, float **upper, int N){
    cout<<setw(7)<<"Matrix is:"<<endl;
    for (int i = 0; i < N; i++){ 
        for (int j = 0; j < N; j++){
            cout <<setw(7)<< mat[i][j] << "\t";  
        }
    cout<<endl; 
    }

    for (int i = 0; i < N; i++){
        // Compute the Upper Triangular Matrix
        for (int k = i; k < N; k++){
            // Summation of L(i, j) * U(j, k)
            float sum = 0.;
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
                    float sum = 0.;
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
    cout<<" Lower Triangular"<<endl;
                                                                                   
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
	{
            cout << L[i][j] << "\t";
        }
	cout<<endl;
     }

    cout<<"Upper Triangular"<<endl;

       for (int i = 0; i < N; i++){

        for (int j = 0; j < N; j++)
	{
            cout << U[i][j] << "\t";
        }
	cout<<endl;
      }
    
}


int main(){

    int n,m;
    //Input number of rows and columns
    cout<<"Enter No. of rows: ";
    cin>>n;
    cout<<"Enter No. of columns: ";
    cin>>m;
    cout<<endl;
    int N = n;        // Size For square matrix N=n=m.

    float **A;  // 2D square Matrix
    float **L;  // Lower Triangular Matrix
    float **U;  // Upper Triangular Matrix

   //Set Dimensions of Matrices
    A=SetSize(A, N);
    L=SetSize(L, N);
    U=SetSize(U, N);

   //Creating A matrix

   int entry;
			
   for(int i=0;i<N;i++)
   {

   for(int j=0;j<N;j++)
	{ cout<<"Enter the"<<i+1<<" " <<j+1<<"term:";
	 cin>>entry;
	 A[i][j] = entry;
	}

   }


    LUDecomposition(A, L, U, N);       // This will return L and U of A
    ShowLUMatrix(L, U, N);             // This will Print decomposed matrix
    

}//End of Main Funtion

