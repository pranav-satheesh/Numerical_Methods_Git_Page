
unset label                            # remove any previous labels
set term pdf
set output"lagrangeinterpol.pdf"


set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Lagrange interpolated data"
set xlabel "x"
set ylabel "y"

set style data lines

plot "outputdatapoints.txt" every ::1 using 1:2 title "f(x)"

