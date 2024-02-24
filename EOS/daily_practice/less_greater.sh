#!/bin/bash

echo -e -n "Enter Number1 :"
read a 
echo -e -n "Enter Number2 :"
read b

if [ "$a" -gt  "$b" ]
then
	echo "num1 is greater"
else
	echo "num2 is greater"
fi
