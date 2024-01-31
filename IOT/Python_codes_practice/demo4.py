
# if - elif - else

#find max number from 2

num1 = int(input("Enter num1 : "))
num2 = int(input("Enter num2 : "))  

max = 0

if num1 == num2 :
	print("num1 and num2 are equal")
	max = num1
elif num1 > num2 :
	print("num1 is greater")
else :
	print("num2 is greater")
	max = num2

print(f"Max number is {max}")
