#!/bin/bash
yesno ()  {
	while true 
	do	
	echo "$*"
	echo "please answer by entering y or n:"
	read answer
case $answer in
y|Y) return 0;;
n|N) return 1;;
*)echo "I cant unserstnd";;
esac
done
} 
yesno

