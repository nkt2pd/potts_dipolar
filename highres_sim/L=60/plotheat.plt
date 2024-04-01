set xrange [0:4]
set yrange [0:2]

set xtics

set multiplot layout 1,2 rowsfirst 

unset title
unset ylabel

plot "./DJ0.025000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
plot "./DJ0.300000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000