
unset label                            # remove any previous labels
set term pdf
set output "damped_pendulum.pdf"
set key autotitle columnhead

set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Damped Pendulum (A=0)"
set xlabel "time"
set ylabel "Theta(t)"

set style data lines

plot "RK4k1data.txt" using 1:2 title 'k=1',"RK4k5data.txt" using 1:2 title 'k=5',"RK4dt001k10data.txt" using 1:2 title 'k=10'
