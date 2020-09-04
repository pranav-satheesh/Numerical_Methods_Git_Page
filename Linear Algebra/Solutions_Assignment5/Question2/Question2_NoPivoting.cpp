/*============================================================================
Program     : Gauss Elimination Method Without Pivoting
Description : This program calculates solution of simultaneous equations using 
              Gauss Elimination Method. Matrix A from AX=B is written in Augmented form [A|B]
              
              Number of Floating Point Operations:: 
                  Calculate Number of times we need to do floating operations(addition, subtraction, 
                  multiplication, division, etc...) to get the solution..
=============================================================================*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int n=3;     // Save number of eqautions. Or size of Matrix A
    int i, j, k; // Dummy variables for iterations
    int p=0;     // Float Point operations counter
    cout<<">> Number of Equations are: "<<n<<endl;   
    
    //Declare and Set an array to the elements of Augmented-matrix         
    double A[n][n+1]={{-1., 1., -4., 0.},
                       {2., 2., 0.,  1.},
                       {3., 3., 2., 0.5}};
    double X[n];  //This is array to store solution       
    
    cout<<">> Matrix Elements are:\n";
    for(i=0;i<n;i++){for(j=0;j<=n;j++)cout<<A[i][j]<<"\t\t"; cout<<"\n";}   
     
    //Gauss Elimination without chosing Pivot element
    for (i=0;i<n-1;i++)for(j=i+1;j<n;j++){
               double mult=A[j][i]/A[i][i]; p+=1; for(k=i+1;k<n+1;k++){p+=2; A[j][k]-=(mult*A[i][k]);}
               A[j][i]=0.; //We Don't need to perform operations on lower part of the matrix as we know it is going to be zero.
            }
    
    cout<<"\n>> The Matrix after Gauss Elimination:\n";
    for (i=0;i<n;i++){for(j=0;j<=n;j++)cout<<A[i][j]<<setw(16);  cout<<"\n";  }
    
    //Back-Substitution    
    for (i=n-1;i>=0;i--){                        
        X[i]=A[i][n];                
        for(j=i+1;j<n;j++){p+=2; X[i]-=A[i][j]*X[j];}
        X[i]=X[i]/A[i][i]; p+=1;          
    }
    
    cout<<"\n>> The Solution is: \n";
    for(i=0;i<n;i++)cout<<"x"<<i<<": "<<X[i]<<endl;
    
    cout<<"\n>> Number of Floating Point Operations: "<<p<<endl<<endl;
    return 0;
}//End of Main
