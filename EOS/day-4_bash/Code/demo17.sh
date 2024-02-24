#!/bin/bash

# declare array and input values from user.
# add all elements and display result.

# declaration is optional
declare -a arr

i=0
while [ $i -lt 5 ]
do
	echo -n "enter element $i: "
	read arr[$i]
	i=`expr $i + 1`
done

echo "number of elements: ${#arr[*]}"

sum=0
for num in ${arr[*]}
do
	sum=`expr $sum + $num`
done
echo "result: $sum"
