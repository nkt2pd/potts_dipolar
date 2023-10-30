#Green = 1 + square
#Red = -1 + circle

unset logscale
set xrange [0:90]
set yrange [-15:75]

set size square

myPt(col)    = column(col)==1 ? 5 : 5
myColor(col) = column(col)==1 ? 0x00ff00 : 0xff0000
unset key
set grid x,y

plot "./config_dtest.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

# plot "./DJ1.250000/T=0.300000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ1.250000/T=0.800000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

