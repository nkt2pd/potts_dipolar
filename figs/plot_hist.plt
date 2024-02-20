set xrange [-1.1:1.1]
set yrange [-1.1:1.1]
set size 1,1
unset key

#set terminal qt font "Times,20"
#unset terminal

set multiplot layout 1,4 rowsfirst title "Histograms"
unset multiplot
set terminal qt

set size square

set xlabel "Emergent FM Potts Order"
plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
     "bwFOnKT_7_hist.dat" using 1:2 with points pt 7 lc rgb "red"
pause -1 "hit return to continue"

set xlabel "FM Potts Order"
plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
     "a2KT_hist.dat" using 1:2 with points pt 7 lc rgb "red"
pause -1 "hit return to continue"

set xlabel "Critical KT"
plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
     "bwKT_hist.dat" using 1:2 with points pt 7 lc rgb "red"
pause -1 "hit return to continue"

set xlabel "Disorder"
plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
     "disordered_hist.dat" using 1:2 with points pt 7 lc rgb "red"
pause -1 "hit return to continue"
     