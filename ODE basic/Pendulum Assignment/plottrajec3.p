
unset label                            # remove any previous labels
set term pdf
set output "Simple_Pendulum.pdf"
set key autotitle columnhead

set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Simple Pendulum (A=0, k=0) using RK4 algorithm"
set xlabel "time"
set ylabel "Theta(t)"

set style data lines

plot "RK4dt05data.txt" using 1:2 title 'RK4'
