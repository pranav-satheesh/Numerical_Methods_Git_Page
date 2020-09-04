  # Gnuplot script file for plotting lorentz time series"

unset label                            # remove any previous labels
set term pdf
set output"trajectory.pdf"
set key autotitle columnhead

set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Lorentz model time series"
set xlabel "time"
set ylabel "x(t)"

set style data lines

plot "Lorenzdata.txt" using 1:2 title 'x(t)'


