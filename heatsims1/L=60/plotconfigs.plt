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

plot "./DJ0.583333/T=0.095000_config.dat" using (myShift(1)):2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
pause -1 "Hit return to continue"

# plot "./DJ0.583333/T=0.150000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.583333/T=0.200000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.583333/T=0.300000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.583333/T=0.350000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.750000/T=0.085000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.750000/T=0.090000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.750000/T=0.095000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.750000/T=0.150000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ0.750000/T=0.200000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ1.083333/T=0.090000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ1.083333/T=0.100000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ1.083333/T=0.250000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ1.083333/T=0.500000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ1.083333/T=0.550000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

# plot "./DJ1.083333/T=0.650000_config.dat" u 1:2:(myPt(4)):(myColor(4)) w p ps 1 pt var lc rgb var
# pause -1 "Hit return to continue"

