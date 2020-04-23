#include <asset.h>

class Matrix{

public:

//Defaullt constructor. Creates a 1X1 matrix of value zeros.

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

//Copy Constructor
//Used when a copy of an object is produced (e.g, passing to a function by value)

Matrix(const Matrix& mat){
this->copy(mat); //Call private copy function.
}

//Destructor. Called when a Matrix object goes out of scope.

~Matrix(){
delete [] data; //Release allocated memory
}


