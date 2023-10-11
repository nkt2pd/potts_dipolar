#Green = 1 + square
#Red = -1 + circle

# myPt(col)    = column(col)==1 ? 5 : 7
# myColor(col) = column(col)==1 ? 0x00ff00 : 0xff0000
# unset key
# set grid x,y

# plot "config_T0.350000_L36_n4500.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var

plot "Potts_Metrop36_heat.dat" u 1:2 w p
