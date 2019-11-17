#!/bin/bash
ping 192.168.0.0 -b -c2 > test2 2> /dev/null
cat test2 | cut -d " " -f4 | cut -d: -f1 |sort | uniq > test4
num=`cat test4 | wc -l`
for ((w=1;w<=num;w++))
do
var=`sed -n ''$w'p' test4`
ssh $var	
done
