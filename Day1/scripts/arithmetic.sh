#!/bin/bash
echo enter one number
read a
echo enter another number
read b
# first method
sum=$(($a+$b))
echo the sum is $sum 


#second method

sum=$[$a + $b]
echo the sum is $sum 

#third method

sum=`expr $a + $b`
echo the sum is $sum

#fourth method
let sum=$a+$b
echo the sum is $sum
 
