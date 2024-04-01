set xrange [0:4]
set yrange [0:2]

set xtics
set ytics

unset title
unset ylabel

plot "./DJ0.150000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1
plot "./DJ0.300000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
