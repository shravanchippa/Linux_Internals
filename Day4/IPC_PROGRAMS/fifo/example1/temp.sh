#!/bin/bash

if test -p server
then
	echo "This  is a regular non zero file which has read and write ...." 
else
	echo "nothing"
fi
