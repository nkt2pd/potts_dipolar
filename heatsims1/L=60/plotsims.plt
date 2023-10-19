set xrange [0:4]
set yrange [0:2]

set logscale x
unset logscale y

plot "./DJ0.000000/heat.dat" using 1:2 with linespoints
pause -1 "Specific Heat graph. Hit return to continue"

plot "./DJ0.750000/heat.dat" using 1:2 with linespoints
pause -1 "Specific Heat graph. Hit return to continue"

plot "./DJ0.833333/heat.dat" using 1:2 with linespoints
pause -1 "Specific Heat graph. Hit return to continue"

plot "./DJ1.333333/heat.dat" using 1:2 with linespoints
pause -1 "Specific Heat graph. Hit return to continue"