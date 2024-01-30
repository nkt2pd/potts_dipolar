#Blue = 1 + square
#Red = -1 + circle

#pt 7 is circles, pt 5 is squares



unset logscale
set xrange [-8.5:67.5]
set yrange [-8:59.0955]

set size square

myPt(col)    = column(col)==1 ? 5 : 5
myColor(col) = column(col)==1 ? 0x0030FF : 0xFF0000
myShift(col) = column(col)>59  ? column(col)  - 60 : column(col)
unset key
unset terminal
unset tics
unset title
unset xlabel
unset ylabel
unset y2label
set grid x,y

plot "./DJ10.000000/init_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ10.000000/T=0.070000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ10.000000/T=0.090000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ10.000000/T=0.100000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ10.000000/T=0.150000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ10.000000/T=0.400000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

plot "./DJ10.000000/T=0.650000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

# plot "./DJ10.066667/T=0.090000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ10.066667/T=0.100000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ10.066667/T=0.150000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ10.066667/T=0.250000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.166667/T=0.450000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.166667/T=0.550000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.166667/T=0.700000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.166667/T=1.750000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.166667/T=4.000000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"