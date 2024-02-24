#!/bin/bash

echo -n "Enter the number : "
read num

i=2
flag=0
while [ $i -lt $num ]
do
	if [ `expr $num % $i` -eq 0 ]
	then
		flag=1
		echo "$num is not a prime no."
		break
	fi
	i=`expr $i + 1`	 
done

if [ $flag -eq 0 ]
then 
	echo "$num is prime no. "
fi
echo ""
