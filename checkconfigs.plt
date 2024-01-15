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

set title "DJ 0 initial"

plot "./heatsims3/L=60/DJ0.000000/init_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0 smoothed"

plot "./smoothed/L=60/DJ0.000000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.025 initial"

plot "./heatsims3/L=60/DJ0.025000/init_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.025 smoothed"

plot "./smoothed/L=60/DJ0.025000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.05 initial"

plot "./heatsims3/L=60/DJ0.050000/T=0.150000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.05 smoothed"

plot "./smoothed/L=60/DJ0.050000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.075 initial"

plot "./heatsims3/L=60/DJ0.075000/T=0.400000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.075 smoothed"

plot "./smoothed/L=60/DJ0.075000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.1 initial"

plot "./heatsims3/L=60/DJ0.100000/T=0.400000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.1 smoothed"

plot "./smoothed/L=60/DJ0.100000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.125 initial"

plot "./heatsims3/L=60/DJ0.125000/T=0.400000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.125 smoothed"

plot "./smoothed/L=60/DJ0.125000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.15 initial"

plot "./heatsims3/L=60/DJ0.150000/T=0.400000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.15 smoothed"

plot "./smoothed/L=60/DJ0.150000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.175 initial"

plot "./heatsims3/L=60/DJ0.175000/T=0.300000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.175 smoothed"

plot "./smoothed/L=60/DJ0.175000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.2 initial"

plot "./heatsims3/L=60/DJ0.200000/T=0.300000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.2 smoothed"

plot "./smoothed/L=60/DJ0.200000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.225 initial"

plot "./heatsims3/L=60/DJ0.225000/T=0.350000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.225 smoothed"

plot "./smoothed/L=60/DJ0.225000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.25 initial"

plot "./heatsims3/L=60/DJ0.250000/T=0.350000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.25 smoothed"

plot "./smoothed/L=60/DJ0.250000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.275 initial"

plot "./heatsims3/L=60/DJ0.275000/T=0.350000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.275 smoothed"

plot "./smoothed/L=60/DJ0.275000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.3 initial"

plot "./heatsims3/L=60/DJ0.300000/T=0.350000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.3 smoothed"

plot "./smoothed/L=60/DJ0.300000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.325 initial"

plot "./heatsims3/L=60/DJ0.325000/T=0.350000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.325 smoothed"

plot "./smoothed/L=60/DJ0.325000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.35 initial"

plot "./heatsims3/L=60/DJ0.350000/T=0.350000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.35 smoothed"

plot "./smoothed/L=60/DJ0.350000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.375 initial"

plot "./heatsims3/L=60/DJ0.375000/T=0.350000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.375 smoothed"

plot "./smoothed/L=60/DJ0.375000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.4 initial"

plot "./heatsims3/L=60/DJ0.400000/T=0.350000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.4 smoothed"

plot "./smoothed/L=60/DJ0.400000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.425 initial"

plot "./heatsims3/L=60/DJ0.425000/T=0.350000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.425 smoothed"

plot "./smoothed/L=60/DJ0.425000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.45 initial"

plot "./heatsims3/L=60/DJ0.450000/T=0.400000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.45 smoothed"

plot "./smoothed/L=60/DJ0.450000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.475 initial"

plot "./heatsims3/L=60/DJ0.475000/T=0.300000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.475 smoothed"

plot "./smoothed/L=60/DJ0.475000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.5 initial"

plot "./heatsims3/L=60/DJ0.500000/T=0.400000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.5 smoothed"

plot "./smoothed/L=60/DJ0.500000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.525 initial"

plot "./heatsims3/L=60/DJ0.525000/T=0.400000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.525 smoothed"

plot "./smoothed/L=60/DJ0.525000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.55 initial"

plot "./heatsims3/L=60/DJ0.550000/T=0.350000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.55 smoothed"

plot "./smoothed/L=60/DJ0.550000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.575 initial"

plot "./heatsims3/L=60/DJ0.575000/T=0.250000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.575 smoothed"

plot "./smoothed/L=60/DJ0.575000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.6 initial"

plot "./heatsims3/L=60/DJ0.600000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.6 smoothed"

plot "./smoothed/L=60/DJ0.600000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.625 initial"

plot "./heatsims3/L=60/DJ0.625000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.625 smoothed"

plot "./smoothed/L=60/DJ0.625000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.65 initial"

plot "./heatsims3/L=60/DJ0.650000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.65 smoothed"

plot "./smoothed/L=60/DJ0.650000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.675 initial"

plot "./heatsims3/L=60/DJ0.675000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.675 smoothed"

plot "./smoothed/L=60/DJ0.675000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.7 initial"

plot "./heatsims3/L=60/DJ0.700000/T=0.350000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.7 smoothed"

plot "./smoothed/L=60/DJ0.700000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.725 initial"

plot "./heatsims3/L=60/DJ0.725000/T=0.300000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.725 smoothed"

plot "./smoothed/L=60/DJ0.725000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.75 initial"

plot "./heatsims3/L=60/DJ0.750000/T=0.300000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "DJ 0.75 smoothed"

plot "./smoothed/L=60/DJ0.750000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"