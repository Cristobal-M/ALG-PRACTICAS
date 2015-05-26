#!/usr/bin/gnuplot
set terminal png size 1500,900 enhanced font "Helvetica" 20;
set output "grafica.png";
plot "tiempos_vor.dat" with lines title "Voraz", "tiempos_din.dat" with lines title "Dinamico";

#Ajuste de la eficiencia teórica
#######
##APO##
#######
#f(x) = (a*x + b)*(c + d*(log(x)/log(2)) )
#f(x) = (a*x + b);
#set fit logfile 'ajuste.txt'
#fit f(x) "tiempos.dat" via a, b;
#set output "grafica_ajustada.png";
#plot "tiempos.dat" title "Mariposas",f(x) lc 3 lw 2;
