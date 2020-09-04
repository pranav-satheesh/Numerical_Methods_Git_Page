
# This plots relative error
	set xlabel "x"
	set ylabel "log_{10}(|X_i-u_i|/u_i)"
	set title "LU Decomposition using GSL Libraries"
	
	set terminal pdfcairo enhanced color size 6in, 5in
	set output "Relative_error.pdf"
	
	plot [][:-1.7]	"fileFor_10.dat" u 1:(log10($2)) w lp pt 7 ps 0.3 t "Relative error N=10",\
	"fileFor_100.dat" u 1:(log10($2)) every 5 w lp pt 7 ps 0.3 t "Relative error N=100",\
	"fileFor_1000.dat" u 1:(log10($2)) every 50 w lp pt 7 ps 0.3 t "Relative error N=1000"

