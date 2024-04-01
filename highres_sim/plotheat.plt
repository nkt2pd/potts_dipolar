set xrange [0.5:2.5]
set yrange [0:2]

set xtics
set ytics

unset multiplot 

unset title
unset ylabel

plot "./L=36/DJ0.025000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000, \
     "./L=36/DJ0.025000/Potts_m.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x00FF00
pause -1
plot "./L=48/DJ0.025000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000, \
     "./L=48/DJ0.025000/Potts_m.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x00FF00
pause -1
plot "./L=60/DJ0.025000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000, \
     "./L=60/DJ0.025000/Potts_m.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x00FF00
