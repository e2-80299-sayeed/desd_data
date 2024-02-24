#!/bin/bash

echo -n "Enter Number : "
read num

i=1

while [ $i -lt 11 ]
do
	res=`expr $num \* $i`
	echo "$num * $i = $res"
	i=`expr $i + 1`
done

echo ""
