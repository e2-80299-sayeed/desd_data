#!/bin/bash

# How to use while loop

# syntax

# initalisation
# while [ Condition ]
# do
#    ....
#   Mofification
# done

# hear break is keyword and continue also keyword
# In while loop, if condition is true, loop body is repeated.
# If condition is false, it comes out of loop.

echo -n "Enter Num : "
read num
i=1
while [ $i -le $num ]
do
    echo -n " $i "
    i=`expr $i + 1`
done
echo ""



#until demo

# In until loop, if condition is false, loop body is repeated.
# If condition is true, it comes out of loop.

echo -n "Enter Num : "
read num
i=1
until [ $i -ge $num ]
do
    echo -n " $i "
    i=`expr $i + 1`
done
echo ""

