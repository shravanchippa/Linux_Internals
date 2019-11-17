#!/bin/bash
#PS3 is a teritary prompt variable
#PS3="welcome to llc"
OPTIONS="Hello Quit"
select opt in $OPTIONS; do
     if [ "$opt" = "Quit" ]; then
       echo done
       exit
     elif [ "$opt" = "Hello" ]; then
       echo Hello World
     else
       clear
       echo bad option
     fi
done

