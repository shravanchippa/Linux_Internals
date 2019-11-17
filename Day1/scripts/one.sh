#!/bin/bash
a=10
b=20

sum=` expr $a + $b ` 
ha=$((10 + 10))
echo $ha
echo $sum

echo "$(($a+$b)) hello"
