#!/bin/bash
while getopts  "abc:" flag
do
  echo "$flag" $OPTIND $OPTARG
done


