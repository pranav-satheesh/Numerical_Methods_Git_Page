set term pdf size 6in, 5in
set out "Plots.pdf"
set xlabel "x"
set ylabel "Log of Relative error %"
plot "fileFor_4.dat" using 1:(log10($4)) w lp t "N=4", "fileFor_10.dat"  u  1:(log10($4)) w lp t "N=10", "fileFor_100.dat" u 1:(log10($4)) every 10 w lp t "N=100"

set ylabel "Solutions"
plot "fileFor_4.dat" using 1:2 w lp t "N=4: Numerical Sol", "fileFor_4.dat" using 1:3 w lp t "N=4: Analytical Sol" 
plot "fileFor_10.dat" using 1:2 w lp t "N=10: Numerical Sol", "fileFor_10.dat" using 1:3 w lp t "N=10: Analytical Sol" 
plot "fileFor_100.dat" using 1:2 every 10 w lp t "N=100: Numerical Sol", "fileFor_100.dat" using 1:3 every 10 w lp t "N=100: Analytical Sol" 
 
set ylabel "log_{10}(|X_i-u_i|/u_i)" 
set out "LUDecompositionErrN-1000.pdf" 
set title "LU Decomposition Method N=1000"
plot "fileFor_1000.dat" using 1:(log10($4)) every 50 w lp t "N=1000" 
  
#Fitting time frame
set xl "Log_{10}N"
set yl "Time"
set title "Time Plot for LU decomposition method"
a=0.4
b=0.1
c=0.3
set term pdf size 6in, 5in
set key top center
set out "TimePlot.pdf"
set fit quiet
f(x)=a*exp(b*x)+c #Fit function

fit f(x) "timedata.dat" using (log10($1)):2 via a, b, c #Fit
time=f(5)/3600/24 
set label 1 sprintf("Time prediction for to get solution for 10^5×10^5 matrix = %3.5g days",time) at graph 0.01,0.5 left
plot [:][-1:] f(x) t "f(x)=ae^{bx}+c", "timedata.dat" u (log10($1)):2 w p t "Log_{10}(N) vs time"		  #Plot

print "Time it would take to run for LU-decomposition and 10^5 cross 10^5 Matrix: ", f(3.77815125), " days"
