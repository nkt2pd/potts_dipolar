#Blue = 1 + square
#Red = -1 + circle

#pt 7 is circles, pt 5 is squares



unset logscale
set xrange [-7.5:55.5]
set yrange [-7.5:50]

set size square

myPt(col)    = column(col)==1 ? 5 : 5
myColor(col) = column(col)==1 ? 0x0030FF : 0xFF0000
myShift(col) = column(col)>47  ? column(col) - 48 : column(col)
unset key
unset terminal
unset tics
unset title
unset xlabel
unset ylabel
unset y2label
set grid x,y

unset multiplot

set title "D = 0.025 after 2 KT"
plot "./L=48/DJ0.025000/T=0.500000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "D = 0.75 Critical KT Region"
plot "./L=48/DJ0.750000/T=0.800000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "D = 0.75 Between First Order and KT"
plot "./L=48/DJ0.750000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "D = 0.75 After First Order"
plot "./L=48/DJ0.750000/T=0.070000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var