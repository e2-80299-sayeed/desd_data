#!/bin/bash

# write a function to print fibonacci series
# write a function to do sum of two integers

# function definition:
# function fn_name()
# {
#	args are accessed as $1, $2, $3, ...
#	...
# }

# function call:
# fn_name arg1 arg2 arg3 

# function definition:
# function fn_name()
# {
#	args are accessed as $1, $2, $3, ...
#	...
#	echo result
# }

# function call:
# var=$(fn_name arg1 arg2 arg3) 

# function definition
function fibonacci()
{
	a=1
	b=1
	i=1 # init
	while [ $i -le $1 ] # condition
	do
		c=`expr $a + $b`
		echo -n "$a, "
		a=$b
		b=$c
		i=`expr $i + 1` # modification
	done
	echo ""
}

# function definition
function sum()
{
	res=`expr $1 + $2`
	echo "$res"
}

# function definition
function factorial()
{
	res=1
	num=$1
	while [ $num -gt 0 ]
	do
		res=`expr $res \* $num`
		num=`expr $num - 1`
	done
	echo "$res"
}

# function definition
function is_prime()
{
	i=2
	while [ $i -lt $1 ]
	do
		if [ `expr $1 % $i` -eq 0 ]
		then
			echo "0"
			return
		fi
		i=`expr $i + 1`
	done
	echo "1"
}

# function call
fibonacci 8

# function call
result=$(sum 14 6)
echo "sum result: $result"

result=$(factorial 5)
echo "factorial result: $result"

flag=$(is_prime 17)
echo "is prime : $flag"

if [ $flag -eq 1 ]
then
	echo "Prime number"
else
	echo "Not prime number"
fi











function fun_name()
{
    a=$1
    echo "$a"
    sqr=`expr $a \* $a`
    echo "$sqr"  
}

res=$(fun_name 8)

echo "res = $res"



