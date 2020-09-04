SHELL=/bin/sh

SRC=Main.cpp
SRC2=LUDecomposition.cpp

OBJ=Main.o
OBJ2=LUDecomposition.o

EXE=Output

run:
	g++ -c $(SRC) $(SRC2) 	  
	g++ -o $(EXE) $(OBJ) $(OBJ2)  
	./$(EXE)     
	gnuplot gnuplot.sh                 
	
#Hi:
#   echo "Hi"
