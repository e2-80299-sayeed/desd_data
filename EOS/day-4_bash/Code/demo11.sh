#!/bin/bash

# area of circle

# floating point calculation -- bc commmand

echo -n "enter circle radius: "
read rad

area=`echo "3.1415 * $rad * $rad" | bc`

echo "area of circle: $area"
