set xrange [0:2]
set yrange [0:2]

set xtics

unset multiplot

unset title
unset ylabel

plot "./L=60/DJ0.150000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000, \
     "./L=60/DJ0.150000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./L=60/DJ0.150000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0000FF

pause -1
set xrange [0.5:2.5]

plot "./L=36/DJ0.025000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000, \
     "./L=36/DJ0.025000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00

pause -1

plot "./L=48/DJ0.025000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000, \
     "./L=48/DJ0.025000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00

pause -1

plot "./L=60/DJ0.025000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000, \
     "./L=60/DJ0.025000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00

pause -1