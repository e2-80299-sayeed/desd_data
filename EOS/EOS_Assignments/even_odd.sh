#!/bin/bash

echo -n "Enter the number :"
read n

if [ `expr $n % 2` -eq 0 ]
then
echo "The Number is even"
else 
echo "The Number is odd"
fi
