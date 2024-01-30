#Green = 1 + square
#Red = -1 + circle

unset logscale
set xrange [-1:60]
set yrange [-0.5:52]

set size square

myPt(col)    = column(col)==1 ? 7 : 7
myColor(col) = column(col)==1 ? 0x0030FF : 0xFF0000
myShift(col) = column(col)>59  ? column(col)  - 60 : column(col)
unset key
unset terminal
unset tics
unset title
set grid x,y

set title "Stripe Region - Potts"

plot "./DJ0.675000/T=0.200000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "In between 2 KT - Potts"

plot "./DJ0.675000/T=1.250000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "FM Potts 2 - Potts"

plot "./DJ0.675000/T=0.600000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "FM Potts 1 - Potts"

plot "./DJ0.025000/T=0.600000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"