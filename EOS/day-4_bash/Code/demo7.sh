#!/bin/bash

# check number prime or not

echo -n "Enter num : "
read num


i=2
flag=0
while [ $i -lt $num ]
do
    if [ `expr $num % $i` -eq 0 ]
        then
            flag=1
            echo "$num not prime number "
            break
    fi
    i=`expr $i + 1`
done

if [ $flag -eq 0 ]
then
    echo "$num is prime number" 
fi          
