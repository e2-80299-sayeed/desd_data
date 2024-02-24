#!/bin/bash

# check if given year is leap year or not.
#	y % 4 == 0 && y % 100 != 0 || y % 400 == 0

# if [ condition ]
# then
#	...
# fi

# if [ condition ]
# then
#	...
# else
#	...
# fi

# if [ condition ]
# then
#	...
# else
#	if [ condition ]
# 	then
#		...
# 	else
#		...
# 	fi
#	...
# fi

# if [ condition ]
# then
#	...
# elif [ condition ]
# then
#	...
# else
#	...
# fi

# condition
#	written in [ ... ]

# 	internally it is evaluated using "test" command


# relational operators (integer comparision)
#	-eq 	-ne		-gt		-lt		-ge		-le
#   ==       !=      >       <       >=      <=	       
#Home Work on terminal : man test   (To know more information about)
# logical operator
#	-a		-o		!
#   &&      ||     NOT

echo -n "enter year: "
read y

# if( y % 4 == 0 && y %100 != 0  ||  y % 400 == 0 )
 if [ `expr $y % 4` -eq 0 -a `expr $y % 100` -ne 0 -o `expr $y % 400` -eq 0 ]
 	then
		echo "Leap Year "
 else
	        echo "Not Leap year"
 fi      		
