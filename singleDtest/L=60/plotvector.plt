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

set title "T = 0.5"

plot "./DJ10.000000/T=0.500000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 0.55"

plot "./DJ10.000000/T=0.550000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 0.6"

plot "./DJ10.000000/T=0.600000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 0.65"

plot "./DJ10.000000/T=0.650000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 0.7"

plot "./DJ10.000000/T=0.700000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 0.75"

plot "./DJ10.000000/T=0.750000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 0.8"

plot "./DJ10.000000/T=0.800000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 0.85"

plot "./DJ10.000000/T=0.850000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 0.9"

plot "./DJ10.000000/T=0.900000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 0.95"

plot "./DJ10.000000/T=0.950000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 1.0"

plot "./DJ10.000000/T=1.000000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 1.25"

plot "./DJ10.000000/T=1.250000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 1.5"

plot "./DJ10.000000/T=1.500000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 1.75"

plot "./DJ10.000000/T=1.750000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 2.0"

plot "./DJ10.000000/T=2.000000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

set title "T = 4.0"

plot "./DJ10.000000/T=4.000000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

