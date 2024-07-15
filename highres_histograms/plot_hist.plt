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

# set xlabel "Between First Order and KT"
# plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
#      "./hist_data_simmed/bwFOnKT_rot0_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/bwFOnKT_rot1_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/bwFOnKT_rot2_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/bwFOnKT_rot3_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/bwFOnKT_rot4_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/bwFOnKT_rot5_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red"
# pause -1 "hit return to continue"

# set xlabel "After 2 KT with D = 0.025"
# plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
#      "./hist_data_simmed/a2KT_rot0_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/a2KT_rot1_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/a2KT_rot2_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/a2KT_rot3_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/a2KT_rot4_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/a2KT_rot5_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red"
# pause -1 "hit return to continue"

# set xlabel "Critical KT Region"
# plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
#      "./hist_data_simmed/bwKT_rot0_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/bwKT_rot1_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/bwKT_rot2_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/bwKT_rot3_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/bwKT_rot4_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/bwKT_rot5_hist_simmed.dat" using 1:2 with points pt 7 lc rgb "red"
# pause -1 "hit return to continue"

# set xlabel "Stripe Region, After First Order"
# plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
#      "./hist_data_simmed/aFO_rot0_hist_simmed2.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/aFO_rot1_hist_simmed2.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/aFO_rot2_hist_simmed2.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/aFO_rot3_hist_simmed2.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/aFO_rot4_hist_simmed2.dat" using 1:2 with points pt 7 lc rgb "red", \
#      "./hist_data_simmed/aFO_rot5_hist_simmed2.dat" using 1:2 with points pt 7 lc rgb "red"

set xlabel "Stripe Region, After First Order"
plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
     "./hist_configs/7_14_24/aFO_rot0_hist.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_configs/7_14_24/aFO_rot1_hist.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_configs/7_14_24/aFO_rot2_hist.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_configs/7_14_24/aFO_rot3_hist.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_configs/7_14_24/aFO_rot4_hist.dat" using 1:2 with points pt 7 lc rgb "red", \
     "./hist_configs/7_14_24/aFO_rot5_hist.dat" using 1:2 with points pt 7 lc rgb "red"


# set xlabel "Disorder"
# plot "hex.dat" using 1:2 with lines dt 2 lc rgb "blue", \
#      "disordered_hist.dat" using 1:2 with points pt 7 lc rgb "red"
# pause -1 "hit return to continue"
     