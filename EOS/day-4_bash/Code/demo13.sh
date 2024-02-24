#!/bin/bash

# print positional params and print script name

# positional parameters (like command line args in C)
# while executing shell script on command line, we can pass additional information.
# it is called as "positional parameters".
# terminal> ./demo13.sh one two three four

# To access positional params in the script: $1 $2 $3 $4 ... $9
# List of all positional params: $*
# Shell script name: $0
# Number of positional params: $#

# shift N command is used to skip N params from left
# This will enable access to the next params.
# N+1 param will become $1
# N+2 param will become $2
# ...

echo "running shell script: $0"

echo "number of pos params: $#"

echo "all pos params: $*"

for parm in $*
do
	echo "pos param = $parm"
done

echo "param1 : $1"
echo "param2 : $2"
shift 2
echo "param1 after shift : $1"
echo "param2 after shift : $2"

