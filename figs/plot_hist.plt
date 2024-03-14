set xrange [-1.1:1.1]
set yrange [-1.1:1.1]
set size 1,1
unset key

#set terminal qt font "Times,20"
#unset terminal

set multiplot layout 1,4 rowsfirst title "Histograms"
# unset multiplot
# set terminal qt

# set size square

set xlabel "Emergent FM Potts Order"
plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
     "bwFOnKT_rot0_hist.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/bwFOnKT_rot1_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/bwFOnKT_rot2_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/bwFOnKT_rot3_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/bwFOnKT_rot4_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/bwFOnKT_rot5_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red"
pause -1 "hit return to continue"

set xlabel "FM Potts Order"
plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
     "a2KT_rot0_hist.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/a2KT_rot1_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/a2KT_rot2_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/a2KT_rot3_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/a2KT_rot4_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/a2KT_rot5_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red"
pause -1 "hit return to continue"

set xlabel "Critical KT"
plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
     "bwKT_rot0_hist.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/bwKT_rot1_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/bwKT_rot2_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/bwKT_rot3_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/bwKT_rot4_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_data_simmed/bwKT_rot5_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red"
pause -1 "hit return to continue"

set xlabel "Disorder"
plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
     "disordered_hist.dat" using 1:2 with points pt 7 lc rgb "red"
pause -1 "hit return to continue"
     