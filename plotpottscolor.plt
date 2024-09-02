#Blue = 1 + square
#Red = -1 + circle

#pt 7 is circles, pt 5 is squares



unset logscale
set xrange [-7.5:55.5]
set yrange [-7.5:50]

set size square

myPt(col)    = column(col)==1 ? 5 : 5
myColor(col) = column(col)==0 ? 0x1000ff : column(col)==1 ? 0xEFFF00 : column(col)==2 ? 0x03FF00 : column(col)==3 ? 0xFC00FF : column(col)==4 ? 0x00FEFF : 0xFF0100
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
plot "./DJ0.750000_init_config2.dat" using (myShift(1)):2:(myPt(4)):(myColor(3)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

