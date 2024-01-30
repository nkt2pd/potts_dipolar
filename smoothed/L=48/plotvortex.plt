#Blue = 1 + square
#Red = -1 + square

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

plot "./DJ0.500000/init_config.dat" using (myShift(1)):2:(cos($3*pi/3)/1.1):(sin($3*pi/3)/1.1) w vector
pause -1 "Hit return to continue"

plot "./DJ0.500000/T=1.500000_config.dat" using (myShift(1)):2:(cos($3*pi/3)/1.1):(sin($3*pi/3)/1.1) w vector
pause -1 "Hit return to continue"