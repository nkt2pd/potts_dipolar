set yrange[1:150]
set xrange[0:0.33]
set logscale y

plot "DJvH.dat" using 1:2 with lp lc "red"