#!/bin/bash

echo -e -n "Enter the month"
read m

case $m in
	1 | JAN | January ) echo "Jan Has 31 Days"
		;;
	2) echo "Feb Has 28 Days"
		;;
	*) echo "Invalid Month"
esac
