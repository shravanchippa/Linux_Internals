#!/bin/bash
echo "enter some integer"
read a
echo "enter some integer"
read b
c=30
if test $(($a+$b)) -eq $c
then
	echo "equal"
	echo "it is 2nd line"
	echo " 3rd Line"
else
	echo "not equal"
fi
