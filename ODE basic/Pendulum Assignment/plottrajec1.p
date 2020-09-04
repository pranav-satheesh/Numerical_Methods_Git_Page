
unset label                            # remove any previous labels
set term pdf
set output "method_comparison.pdf"
set key autotitle columnhead

set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Simple Pendulum (A=0, k=0)"
set xlabel "time"
set ylabel "Theta(t)"

set style data lines

plot "Eulerdt05data.txt" using 1:2 title 'Euler',"Taylor05data.txt" using 1:2 title 'Taylor',"RK205data.txt" using 1:2 title 'RK2',"RK405data.txt" using 1:2 title 'RK4'


