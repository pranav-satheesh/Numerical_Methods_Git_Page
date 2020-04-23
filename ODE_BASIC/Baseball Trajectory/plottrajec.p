  # Gnuplot script file for plotting baseball trajectory"


unset label                            # remove any previous labels
set term pdf
set output"trajectory.pdf"

set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Baseball Trajectory"
set xlabel "x"
set ylabel "y"

set style data linespoints


plot	"plot.txt" using 1:2 title 'With Air resistance', \
	"noair.txt" using 1:2 title 'Theoretical(without air reistance)'
	


