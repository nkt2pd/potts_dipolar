set xrange [0.01:10]
set yrange [0:2]

set logscale x

plot "Potts_Metrop10_binder4.dat" using 1:2 with points
