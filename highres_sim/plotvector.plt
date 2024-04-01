#Green = 1 + square
#Red = -1 + circle

unset logscale
set xrange [20:40]
set yrange [15:35]

set size square

myPt(col)    = column(col)==1 ? 7 : 7
myColor(col) = column(col)==1 ? 0x0030FF : 0xFF0000
myShift(col) = column(col)>59  ? column(col)  - 60 : column(col)
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

plot "./L=60/DJ0.025000/T=0.500000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"
