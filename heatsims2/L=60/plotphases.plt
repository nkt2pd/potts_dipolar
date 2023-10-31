set xrange [0:2.5]
set yrange [0:4]

unset logscale x

plot "phases.dat" u 1:2 title 'dipolar' w lp pt 1 lc rgb "orange", \
     "phases.dat" u 1:3 title 'kt 1' w lp pt 2 lc rgb "red", \
     "phases.dat" u 1:4 title 'kt 2' w lp pt 5 lc rgb "green", \
     "phases.dat" u 1:5 title 'dipolar 2' w lp pt 2 lc rgb "pink", \
     "phases.dat" u 1:6 title 'dipolar 3' w lp pt 5 lc rgb "blue"