#!/bin/bash

echo -n "Enter a Number : "
read num

facts=`factor $num`

echo "Factor of $facts"
