#!/bin/bash
echo "enter a number"
read num
while [ $num -ne 0 ]
do
rev=$(($num % 10))
num=$(($num / 10))
echo -n "$rev"
done


