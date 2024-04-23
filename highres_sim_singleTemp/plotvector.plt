#Green = 1 + square
#Red = -1 + circle

unset logscale
set xrange [20:40]
set yrange [15:35]
# set xrange [0:48]
# set yrange [0:41]

set size square

myPt(col)    = column(col)==1 ? 7 : 7
myColor(col) = column(col)==1 ? 0x0030FF : 0xFF0000
myShift(col) = column(col)>47  ? column(col) - 48 : column(col)
unset key
unset terminal
unset tics
unset title
set grid x,y

unset style
unset object 1

unset multiplot

unset title
unset ylabel

set terminal qt font "Helvetica,20"

set title "D = 0.025 after 2 KT"
plot "./L=48/DJ0.025000/T=0.500000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "D = 0.75 Critical KT Region"
plot "./L=48/DJ0.750000/T=0.800000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "D = 0.75 Between First Order and KT"
plot "./L=48/DJ0.750000/T=0.200000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "D = 0.75 After First Order"
plot "./L=48/DJ0.750000/T=0.070000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
