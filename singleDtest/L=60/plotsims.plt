set xrange [0.01:4]
set yrange [-0.01:3]
set y2range [0:1]

set key

set xtics
set ytics nomirror
set y2tics nomirror
set logscale x
unset logscale y

set xlabel "T/J"
set ylabel "C/J"

set title "D/J = 10"

plot "./DJ10.000000/heat.dat" using 1:2 axes x1y1 title "Specific Heat" with linespoints lc rgb 0xFF0000, \
     "./DJ10.000000/fb.dat" using 1:2 axes x1y2 title "stripe order"  with linespoints lc rgb 0x0000FF, \
     "./DJ10.000000/Potts_m.dat" using 1:2 axes x1y2 title "Potts Order" with linespoints lc rgb 0x00FF00
pause -1 "Hit return to continue"