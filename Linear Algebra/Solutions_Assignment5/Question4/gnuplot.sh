set term pdf size 6in, 5in

set xl "x"
set yl "Solution"
set title "N=10 Tridiagonal Method"
set out "TridSolN-10.pdf"
plot [][:.50] "fileFor_10.dat" u 1:2 w lp t "Numerical Solution","fileFor_10.dat" u 1:3 w lp t "Analytical Solution" 

set title "N=100 Tridiagonal Method"
set out "TridSolN-100.pdf"
plot [][:.50] "fileFor_100.dat" u 1:2 every 5 w lp t "Numerical Solution","fileFor_100.dat" u 1:3 every 5 w lp t "Analytical Solution" 

set title "N=1000 Tridiagonal Method"
set out "TridSolN-1000.pdf"
plot [][:.50] "fileFor_1000.dat" u 1:2 every 50 w lp t "Numerical Solution","fileFor_1000.dat" u 1:3 every 50 w lp t "Analytical Solution" 

set title "Tridiagonal Method: Relative Error"
set yl "log_{10}(|X_i-u_i|/u_i)"
set out "TridRelativeError.pdf"
plot [][:0.1] "fileFor_10.dat" u 1:4 w lp pt 7 ps 0.3 t "N=10", "fileFor_100.dat" u 1:4 every 5 w lp pt 7 ps 0.3 t "N=100", "fileFor_1000.dat" u 1:4 every 50 w lp pt 7 ps 0.3 t "N=1000"


set title "Relative Error Comparison"
set out "RelErrComp.pdf"
plot [][] "fileFor_1000.dat" u 1:4 every 50 w lp pt 7 ps 0.3 t "Tridiagonal Method: N=1000", "/home/pk/Desktop/CERNbox/Programming/Latex/PH5720LAB/Week5/Solution_Programs/Question5/fileFor_1000.dat" u 1:(log10($4)) every 50 w lp t "LU Decomposition Method N=1000"











