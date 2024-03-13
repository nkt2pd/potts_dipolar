set xrange [0.7:2.5]
set yrange [0:2]

set multiplot layout 2,1 rowsfirst

plot "./L=36/DJ0.025000/heat.dat" using 1:2 title "Specific Heat L = 36" with linespoints lc rgb 0xFF0000, \
     "./L=48/DJ0.025000/heat.dat" using 1:2 title "Specific Heat L = 48" with linespoints lc rgb 0x00FF00

plot "./L=36/DJ0.025000/Potts_m.dat" using 1:2 title "Potts Order L = 36" with linespoints lc rgb 0xFF0000, \
     "./L=36/DJ0.025000/Potts_m.dat" using 1:2 title "Potts Order L = 48" with linespoints lc rgb 0x00FF00