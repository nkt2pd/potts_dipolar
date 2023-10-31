#Green = 1 + square
#Red = -1 + circle

unset logscale
set xrange [-8.5:67.5]
set yrange [-8:59.0955]

set size square

myPt(col)    = column(col)==1 ? 7 : 7
myColor(col) = column(col)==1 ? 0x0030FF : 0xFF0000
myShift(col) = column(col)>59  ? column(col)  - 60 : column(col)
unset key
unset terminal
unset tics
unset title
set grid x,y

plot "./DJ0.116667/T=0.000000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=0.060000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=0.065000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=0.070000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=0.075000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=0.080000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=0.085000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=0.090000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=0.550000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=0.600000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=0.650000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=1.750000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ0.116667/T=4.000000_config.dat" using 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"