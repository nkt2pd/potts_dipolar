set xrange [0:0.6]
set yrange [0:1]


set xtics
set ytics

unset multiplot 

unset title
unset ylabel

plot "./L=36/DJ0.025000/heat.dat" using 1:2 title "L = 36" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.025000/heat.dat" using 1:2 title "L = 48" with points lc rgb 0x00FF00, \
     "./L=60/DJ0.025000/heat.dat" using 1:2 title "L = 60" with points lc rgb 0x0000FF
pause -1

plot "./L=48/DJ0.150000/fb.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.450000/fb.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
     "./L=48/DJ0.750000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF
pause -1

plot "./L=48/DJ0.150000/heat.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.450000/heat.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
     "./L=48/DJ0.750000/heat.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF
pause -1

plot "./L=48/DJ0.150000/heat.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.150000/Potts_m.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
     "./L=48/DJ0.150000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF
pause -1
plot "./L=48/DJ0.450000/heat.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.450000/Potts_m.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
     "./L=48/DJ0.450000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF
pause -1
plot "./L=48/DJ0.750000/heat.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.750000/Potts_m.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
     "./L=48/DJ0.750000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF

plot "./L=36/DJ0.025000/heat.dat" using 1:2 title "L = 36" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.025000/heat.dat" using 1:2 title "L = 48" with points lc rgb 0x00FF00, \
     "./L=60/DJ0.025000/heat.dat" using 1:2 title "L = 60" with points lc rgb 0x0000FF
