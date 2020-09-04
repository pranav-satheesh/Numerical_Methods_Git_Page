SHELL=/bin/sh

SRCS=Question6.cpp

OBJ=Question6.o

EXE=a.out
run:
	g++ -std=c++17 -o $(EXE) $(SRCS) -lgsl -lgslcblas -lm
#	g++ -g -c $(SRCS) -o $(OBJ) -lgsl -lgslcblas -lm
#	g++ -o $(EXE) $(OBJ)
	./$(EXE)
	gnuplot gnuplot.sh
	
