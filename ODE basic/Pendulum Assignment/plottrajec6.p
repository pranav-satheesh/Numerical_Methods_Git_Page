
unset label                            # remove any previous labels
set term pdf
set output "driven_pendulum.pdf"
set key autotitle columnhead

set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Driven-damped Pendulum (k=0.5, Driving frequency = 2/3)"
set xlabel "time"
set ylabel "Theta(t)"

set style data lines

plot "RK4A05data.txt" using 1:2 title 'A=0.5,k=0.5,Omega = 2/3',"RK4A12data.txt" using 1:2 title 'A=1.2,k=0.5,Omega = 2/3'
