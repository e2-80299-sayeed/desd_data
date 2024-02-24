#!/bin/bash

#   *
#  * *
# * * *
#* * * *

echo -n "Enter len  : "
read len

i=1

while [ $i -le $len ]
 do
    
# Print       Space
    b=`expr $len - $i`
    while [ $b -gt 0 ]
        do
            echo -n " "
        b=`expr $b - 1`
    done        


# print      star
    num=1
    while [ $num -le $i ]
    do
        echo -n "* "
        num=`expr $num + 1`
    done
#    Modification
    i=`expr $i + 1 `
    echo " "
 done