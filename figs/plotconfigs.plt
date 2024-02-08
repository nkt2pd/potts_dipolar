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

unset object

unset title
set ylabel "Stripe Region"

plot "./hist_configs/L=60/DJ0.675000/T=0.700000thermed_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1.5 pt var lc rgb var

