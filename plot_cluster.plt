set xrange [0.01:10]
set yrange [0:2]

set logscale x

plot "Potts_Metrop10_energyParts.dat" using 1:2 with points, \
     "Potts_Metrop10_energyParts.dat" using 1:3 with points lc rgb "blue"
