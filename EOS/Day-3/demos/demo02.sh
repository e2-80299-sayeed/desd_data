#!/bin/bash

# addition of two numbers

# shell variables
# 	Shell scripts are type-less. There is no concept of data types.
#	Also no need to declare variables before using them.

# expr command -- integer arithmetic
#	terminal> expr 12 + 5
#	terminal> expr 12 - 5
#	terminal> expr 12 / 5
#	terminal> expr 12 \* 5

# assign value to variable
# 	varname=value

# read value from variable
#	$varname

# assign output of command to variable
#	varname=`command ...`
# OR
#	varname=$(command ...)

num1=10
num2=4

res=`expr $num1 + $num2`

echo "result of addition = $res"






