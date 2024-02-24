# In until loop, if condition is false, loop body is repeated.
# If condition is true, it comes out of loop.

echo -n "Enter Num : "
read num
i=1
until [ $i -gt $num ]
do
    echo -n " $i "
    i=`expr $i + 1`
done
echo ""