#!/bin/bash

# Comments in shell script begin with # symbol.

echo "Printing Calendar of year 2020"
cal -y 2020

echo "Printing Directory contents of /"
ls /

echo -e -n "\nPrinting Linux kernel version --> "
uname -a

echo -e "\nPrinting factors of 24"
factor 24

# echo command
# 	-e : enable escape sequences e.g. \n, \t, ...
#	-n : no newline after echo.

# shebang line
#Line 1 of shell script should contain name of shell program which will execute that script followed by #!.
#While running script on terminal (./demo01.sh), OS reads first line and load corresponding shell program, which in turn execute that shell script.








