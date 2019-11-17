#!/bin/bash
declare -i sum
declare -i c=1 
declare -i d=2
declare -i e 
a=10
b=20
echo `expr $a + $b `
sum=$a+$b
echo $sum
echo $[ $a + $b]
echo $(($a+$b))
e=c+d
echo $e
