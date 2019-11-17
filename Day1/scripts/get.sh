#!/bin/bash
while getopts "abc"  var
do
	case $var in
	a) echo service network $var;;
	b) echo service network $var;;
	c) echo service network $var;;
	*) echo  wrong usage;;
	esac
done
