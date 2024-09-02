set xrange [0:2]
set yrange [0:2]


set xtics
set ytics

unset multiplot 

unset title
unset ylabel

# plot "./L=48/DJ0.150000/fb.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
#      "./L=48/DJ0.450000/fb.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
#      "./L=48/DJ0.750000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF
# pause -1

# plot "./L=48/DJ0.150000/fb.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
#      "./L=48/DJ0.450000/fb.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
#      "./L=48/DJ0.750000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF
# pause -1

set title "Specific Heat Curves Overlay"

plot "./L=48/DJ0.050000/heat.dat" using 1:2 title "0.05" with points lc rgb 0xFC00FF, \
     "./L=48/DJ0.075000/heat.dat" using 1:2 title "0.075" with points lc rgb 0xEFFF00, \
     "./L=48/DJ0.150000/heat.dat" using 1:2 title "0.15" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.300000/heat.dat" using 1:2 title "0.3" with points lc rgb 0x00FF00, \
     "./L=48/DJ0.750000/heat.dat" using 1:2 title "0.75" with points lc rgb 0x0000FF
     
pause -1

# set title "D = 0"

# plot "./L=48/DJ0.000000/heat.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
#      "./L=48/DJ0.000000/Potts_m.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
#      "./L=48/DJ0.000000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF
# pause -1

set title "D = 0.05"

plot "./L=48/DJ0.050000/heat.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.050000/Potts_m.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
     "./L=48/DJ0.050000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF
pause -1

set title "D = 0.075"

plot "./L=48/DJ0.075000/heat.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.075000/Potts_m.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
     "./L=48/DJ0.075000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF
pause -1

set title "D = 0.15"

plot "./L=48/DJ0.150000/heat.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.150000/Potts_m.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
     "./L=48/DJ0.150000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF
pause -1

set title "D = 0.3"

plot "./L=48/DJ0.300000/heat.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.300000/Potts_m.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
     "./L=48/DJ0.300000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF
pause -1

set title "D = 0.75"
plot "./L=48/DJ0.750000/heat.dat" using 1:2 title "Specific Heat" with points lc rgb 0xFF0000, \
     "./L=48/DJ0.750000/Potts_m.dat" using 1:2 title "Potts Order" with points lc rgb 0x00FF00, \
     "./L=48/DJ0.750000/fb.dat" using 1:2 title "Stripe Order" with points lc rgb 0x0000FF

# plot "./L=36/DJ0.025000/heat.dat" using 1:2 title "L = 36" with points lc rgb 0xFF0000, \
#      "./L=48/DJ0.025000/heat.dat" using 1:2 title "L = 48" with points lc rgb 0x00FF00, \
#      "./L=60/DJ0.025000/heat.dat" using 1:2 title "L = 60" with points lc rgb 0x0000FF
