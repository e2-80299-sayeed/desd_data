#!/bin/bash

# demo of bash arrays

# array is collection of values
# to print all values: ${arr[*]} or ${arr[@]}

arr=(11 22 33 44)
echo "arr elements: ${arr[*]}"
echo "arr[0] = ${arr[0]}"
echo "arr[1] = ${arr[1]}"
echo "arr[2] = ${arr[2]}"
echo "arr[3] = ${arr[3]}"

i=0
while [ $i -lt 4 ]
do 
	echo "$i ele = ${arr[i]}"
	i=`expr $i + 1`
done

for num in ${arr[*]}
do
	echo "ele = $num"
done
