#Blue = 1 + square
#Red = -1 + circle

#pt 7 is circles, pt 5 is squares

unset border
unset logscale
set xrange [0:60]
set yrange [0:51.0995]

set size square
set lmargin 10
set tmargin 10

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

set terminal qt font "Helvetica,12"

set multiplot layout 4,2 columnsfirst

set title "Ising Variable"
set ylabel "Stripe Region"

plot "./DJ0.675000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"

unset title
set ylabel "FM Potts 1"

plot "./DJ0.675000/T=1.250000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"

set ylabel "FM Potts 2"

plot "./DJ0.675000/T=0.600000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"

set ylabel "In Between 2 KT"

plot "./DJ0.025000/T=0.600000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"

set title "Potts Variable"
unset ylabel

set xrange [20:40]
set yrange [15:35]

plot "./DJ0.675000/T=0.200000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

unset title

plot "./DJ0.675000/T=1.250000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

plot "./DJ0.675000/T=0.600000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"

plot "./DJ0.025000/T=0.600000_config.dat" using (myShift(1)):2:(0.8*cos($3*pi/3)):(0.8*sin($3*pi/3)) w vector
pause -1 "Hit return to continue"