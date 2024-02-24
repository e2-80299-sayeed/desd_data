#!bin/bash

echo -e "1.Addition\n2.Subtraction\n3.Multiplication\n4.Divide\n"
read choice

res=0
case $choice in 
	
	1) 
	    
	   echo  "Enter Num1 and Num2 : "
	   read num1
	   read num2
	   res=`expr $num1 + $num2`
	   ;;
	2) 
	   
	   echo  "Enter Num1 and Num2 : "
	   read num1
	   read num2
	   res=`expr $num1 - $num2`
	   ;;
	3)
	   echo  "Enter Num1 and Num2 : "
	   read num1
           read num2
	   res=`expr $num1 \* $num2`
	   ;;	
	4) 
	   echo  "Enter Num1 and Num2 : "
	   read num1
	   read num2
	   res=`expr $num1 / $num2`
	   ;;
	*)
	  echo "Invalid Choice"
esac

if [ $res != 0 ]
then
	echo "Result = $res"
fi
