set xrange [0.01:10]
set yrange [0:1.1]

set logscale x
unset logscale y

plot "Potts_Metrop15_heat.dat" using 1:2 with points
pause -1 "Specific Heat graph for L=15, D = 1, J = 0. Hit return to continue"

plot "Potts_Metrop15_energy.dat" using 1:2 with points
pause -1 "Energy graph for L=15, D = 1, J = 0. Hit return to continue"

plot "Potts_Metrop15_energyParts.dat" using 1:2 with points
pause -1 "Energy Parts graph for L=15, D = 1, J = 0. Hit return to continue"

plot "Potts_Metrop15_fb.dat" using 1:2 with points
pause -1  "Stripe Order graph for L=15, D = 1, J = 0. Hit return to continue"

plot "Potts_Metrop15Potts_m.dat" using 1:2 with points
pause -1 "Potts Order graph for L=15, D = 1, J = 0. Hit return to continue"

plot "Potts_Metrop15Ising_m.dat" using 1:2 with points
pause -1 "Ising Order graph for L=15, D = 1, J = 0. Hit return to continue"

plot "Potts_Metrop15_binder4.dat" using 1:2 with points
pause -1 "Binder's 4th Cumulant graph for L=15, D = 1, J = 0. Hit return to continue"

plot "Potts_Metrop15_susceptibility.dat" using 1:2 with points
pause -1 "Susceptibility graph for L=15, D = 1, J = 0. Hit return to continue"

plot "Potts_Metrop15_time.dat" using 1:2 with points
pause -1 "Time graph for L=15, D = 1, J = 0. Hit return to continue"