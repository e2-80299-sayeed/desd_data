#!/bin/bash

s1="SunBeam"
s2="infotech"

echo "$s1 $s2"

# string concat
s3=$s1$s2
echo "$s3"
echo "${s3}"

# string splice - substring
str="SunBeam"
echo "${str:3}"
echo "${str:3:2}"

# convert string to upper/lower
echo "${str^^}"
echo "${str,,}"

echo "${s2^}"