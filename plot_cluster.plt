set xrange [0.01:10]
set yrange [0:2]

set logscale x
unset logscale y

plot "Potts_cls12_heat.dat" using 1:2 with points
pause -1  "Specific heat graph for L=10. Hit return to continue"

plot "Potts_cls12_m.dat" using 1:2 with points
pause -1 "Potts Order graph for L=10. Hit return to continue"

plot "Potts_Metrop10Ising_m.dat" using 1:2 with points
pause -1 "Ising Order graph for L=10. Hit return to continue"