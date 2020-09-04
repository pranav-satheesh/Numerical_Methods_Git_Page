  # Gnuplot script file for plotting lorentz 3D model"

unset label                            # remove any previous labels
set term pdf
set output"3dplot.pdf"
set key autotitle columnhead
set title "Lorentz 3D model plot"
set xlabel "x(t)"
set ylabel "y(t)"
set zlabel "z(t)"

set ticslevel 0
splot "Lorenzdata.txt" using 2:3:4 title 'trajectory' with lines, \
	"stationary.txt" using 1:2:3 title 'steady' with points pt 2 ps 1

