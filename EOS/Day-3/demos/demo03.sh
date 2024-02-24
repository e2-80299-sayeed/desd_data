#!/bin/bash

# calculate area of rectangle.

# read command read input from user (like scanf).
#	read varname

echo "enter length and breadth: "
read len
read br

area=`expr $len \* $br`
echo "area of rect is $area"
