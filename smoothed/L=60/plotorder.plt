set xrange [0.01:4]
set yrange [-0.01:3]
set y2range [0:0.5]

set key

unset terminal 
unset output

set logscale x
unset logscale y

set xtics
set ytics nomirror
unset grid
set xlabel "T/J" 
set ylabel "C/J" 
set y2tics
set y2label "Stripe Order Parameter"


set title "D/J = 0"

plot "./DJ0.000000/Potts_m.dat" using 1:2 axis x1y2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.000000/heat.dat" using 1:2 axis x1y1 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.025"

plot "./DJ0.025000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.025000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.05"

plot "./DJ0.050000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.050000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.050000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.075"

plot "./DJ0.075000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.075000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.075000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.1"

plot "./DJ0.100000/fb.dat" using 1:2 axis x1y2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.100000/heat.dat" using 1:2 axis x1y1 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.125"

plot "./DJ0.125000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.125000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.125000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.15"

plot "./DJ0.150000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.150000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.150000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.175"

plot "./DJ0.175000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.175000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.175000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.2"

plot "./DJ0.200000/fb.dat" using 1:2 axis x1y2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.200000/heat.dat" using 1:2 axis x1y1 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.225"

plot "./DJ0.225000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.225000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.225000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.25"

plot "./DJ0.250000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.250000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.250000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.275"

plot "./DJ0.275000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.275000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.275000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.3"

plot "./DJ0.300000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.300000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.300000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.325"

plot "./DJ0.325000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.325000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.325000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.35"

plot "./DJ0.350000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.350000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.350000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.375"

plot "./DJ0.375000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.375000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.375000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.4"

plot "./DJ0.400000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.400000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.400000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.425"

plot "./DJ0.425000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.425000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.425000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.45"

plot "./DJ0.450000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.450000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.450000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.475"

plot "./DJ0.475000/fb.dat" using 1:2 axis x1y2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.475000/heat.dat" using 1:2 axis x1y1 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.5"

plot "./DJ0.500000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.500000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.500000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.525"

plot "./DJ0.525000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.525000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.525000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.55"

plot "./DJ0.550000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.550000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.550000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.575"

plot "./DJ0.575000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.575000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.575000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.6"

plot "./DJ0.600000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.600000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.600000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.625"

plot "./DJ0.625000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.625000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.625000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.65"

plot "./DJ0.650000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.650000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.650000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.675"

plot "./DJ0.675000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.675000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.675000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.7"

plot "./DJ0.700000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.700000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.700000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.725"

plot "./DJ0.725000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.725000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.725000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"

set title "D/J = 0.75"

plot "./DJ0.750000/fb.dat" using 1:2 title "Stripe Order" with linespoints lc rgb 0x0030FF, \
     "./DJ0.750000/Potts_m.dat" using 1:2 title "Potts Order" with linespoints lc rgb 0x00FF00, \
     "./DJ0.750000/heat.dat" using 1:2 title "Specific Heat" with linespoints lc rgb 0xFF0000
pause -1 "Hit return to continue"