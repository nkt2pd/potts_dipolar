set xrange [0:4]
set yrange [0:2]

set xtics
set ytics

unset multiplot layout 1,2 rowsfirst 

unset title
unset ylabel

plot "./L=60/DJ0.150000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000