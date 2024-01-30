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

set title "Stripe Region - Ising"

plot "./DJ0.675000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "In Between 2 KT - Ising"

plot "./DJ0.675000/T=1.250000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "FM Potts 2 - Ising"

plot "./DJ0.675000/T=0.600000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

set title "FM Potts 1 - Ising"

plot "./DJ0.025000/T=0.600000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"