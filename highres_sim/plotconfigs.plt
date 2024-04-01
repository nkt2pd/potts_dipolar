#Blue = 1 + square
#Red = -1 + circle

#pt 7 is circles, pt 5 is squares

unset logscale
set xrange [0:60]
set yrange [0:51.0995]

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

set terminal qt font "Helvetica,20"

#set object 1 rect from 20,15 to 40,35 lw 5 front fs empty border lc rgb "green"

plot "./L=60/DJ0.150000/T=0.000000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"
plot "./L=60/DJ0.150000/T=0.200000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"
plot "./L=60/DJ0.150000/T=0.500000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"
plot "./L=60/DJ0.150000/T=0.600000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"
plot "./L=60/DJ0.025000/T=0.500000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"
plot "./L=60/DJ0.025000/T=0.560000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"
plot "./L=60/DJ0.025000/T=0.580000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"
plot "./L=60/DJ0.025000/T=0.680000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"
plot "./L=60/DJ0.025000/T=1.000000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var
pause -1 "Hit return to continue"