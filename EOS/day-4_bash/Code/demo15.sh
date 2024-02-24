#!/bin/bash

# add all pos param values passed to the script
# ./demo14.sh 11 22 33 44 55 66 77 88

total=0
for num in $*
do
	total=`expr $total + $num`
done

echo "result: $total"
