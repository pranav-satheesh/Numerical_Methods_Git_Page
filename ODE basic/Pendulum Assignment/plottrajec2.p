
unset label                            # remove any previous labels
set term pdf
set output "timestep_comparison.pdf"
set key autotitle columnhead

set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Simple Pendulum (A=0, k=0) for various timestep (with fixed N)"
set xlabel "time"
set ylabel "Theta(t)"

set style data lines

plot "RK4dt05data.txt" using 1:2 title 'dt =0.5',"RK4dt1data.txt" using 1:2 title 'dt = 1',"RK4dt2data.txt" using 1:2 title 'dt =2'
