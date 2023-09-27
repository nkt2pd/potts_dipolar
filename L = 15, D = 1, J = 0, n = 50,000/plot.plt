set xrange [0.01:10]
set yrange [0:1.1]

set logscale x
unset logscale y

plot "Potts_Metrop15_fb.dat" using 1:2 with points
pause -1  "Stripe Order graph for L=15, D = 1, J = 0. Hit return to continue"