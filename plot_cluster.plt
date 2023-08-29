set xrange [0.01:10]
set yrange [0:2]

set logscale x
unset logscale y

#plot "Potts_Metrop10_energyParts.dat" using 1:2 with points, \
     "Potts_Metrop10_energyParts.dat" using 1:3 with points lc rgb "blue"

plot "Potts_Metrop12_heat.dat" using 1:2 with points
pause -1  "Specific heat graph for L=12. Hit return to continue"

plot "Potts_Metrop12Potts_m.dat" using 1:2 with points
pause -1 "Potts Order graph for L=12. Hit return to continue"

plot "Potts_Metrop12Ising_m.dat" using 1:2 with points
pause -1 "Ising Order graph for L=12. Hit return to continue"