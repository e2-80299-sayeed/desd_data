#!/bin/bash

echo -n "Enter num : "
read num

i=1

until [ $i -ge $num ]
do
	echo -e -n "$i  "
	i=`expr $i + 1`	
done
echo ""

