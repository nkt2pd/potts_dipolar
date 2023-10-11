#Green = 1 + square
#Red = -1 + circle

set xrange [-15:67.5]
set yrange [-25:57.5]

set size square

myPt(col)    = column(col)==1 ? 5 : 5
myColor(col) = column(col)==1 ? 0x00ff00 : 0xff0000
unset key
set grid x,y

plot "config_T0.010000_L36_n4500.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var

# plot "Potts_Metrop36_heat.dat" u 1:2 w p
