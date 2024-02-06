set xrange [0:0.75]
set yrange [0:2]

set xlabel "D/J"
set ylabel "T/J"
unset y2label
unset y2tics
unset y2range
unset title

unset logscale x

plot "phases.dat" u 1:2 title 'dipolar' w lp pt 1 lc rgb "blue", \
     "phases.dat" u 1:3 title 'kt 1' w lp pt 2 lc rgb "red", \
     "phases.dat" u 1:4 title 'kt 2' w lp pt 5 lc rgb "green", \