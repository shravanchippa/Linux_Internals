#!/bin/bash
var1="Testing"
var2=12345
var3=6.789
printf "var1 is %10.5s\n" $var1
printf "var1 is %7.7s and\n " $var1
printf "var2 is %9.6e\n" $var2
printf "var3 is $%05.2f\n" $var3

