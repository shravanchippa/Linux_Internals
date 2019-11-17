#!/bin/bash
echo "enter dob"
read birthday
today=`date -I`
if test "$birthday" = "$today"
then
echo "hello happy birthday"
else
echo
echo "sorry to dissappoint you"
fi

