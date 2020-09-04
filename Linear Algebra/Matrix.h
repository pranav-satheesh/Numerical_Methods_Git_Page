#include <asset.h>

class Matrix{

public:

//Default constructor. Creates a 1X1 matrix of value zeros.

Matrix(){

nRow = 1;
nCol = 1;
data = new double[1]; //Allocate memory
set(0.0);  //Set value of data[0] to 0.0

}

//Regular Constructor. Creates nR by nC matrix,values set to zero.
//If number of columns is not prescribed, it is set to 1

Matrix(int nR,int nC = 1){

assert(nR>0 && nC>0); //Check that nC and nR both >0
nRow = nR;
nCol = nC;
data = new double[nR*nC]; //Allocate memory
assert(data!=0); // check memory was allocated
set(0.0); // Set values of data[] to 0.0
}


//Destructor. Called when a Matrix object goes out of scope.
~Matrix(){
delete [] data_;
}


int nRow()
{return nRow_;}

int nCol()
{return nCol_;}


void set(double value)
{ 
int i, idata = nRow_*nCol_;
for(int i=0; i<idata, i++)
	data_[i] = value;
}

void matrix_enter()
{
for(int i=0;i<nRow_;i++)
{
for(int j=0;j<nCol_;j++)

cout<<"Enter the"<<i+1<<"\t"<<j+1<<"term:"<<endl;
cin>>data

}|
void show_matrix();


private:

//Matrix data
int nRow_,nCol_;
double* data_

}




























this->copy(mat); //Call private copy function.
}

//Destructor. Called when a Matrix object goes out of scope.

~Matrix(){
delete [] data; //Release allocated memory
}


