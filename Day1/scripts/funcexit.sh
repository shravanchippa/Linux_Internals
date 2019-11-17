#!/bin/bash
function quit {
	echo " i am exiting"
     exit
}
function add {
	c=`expr $1 + $2`
	echo $c
	}
function hello {

	echo "Hello!! the operation is completed"
	add 2 4
	quit
}
hello


