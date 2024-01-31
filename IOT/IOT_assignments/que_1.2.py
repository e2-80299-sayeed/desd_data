"""2] Write a program to accept a 4 digit number and
a. Display face value of each decimal digit
b. Display place value of each decimal digit
c. Display no in reverse order by changing decimal place values If user enters a 4 digit number 9361 outp
ut should be
a. 9 3 6 1
b. 9361 = 9 000 + 300 + 60 + 9
c. 1639	"""

num = int(input("Enter Number "))

print(f"face value of each decimal digit: ",end="")
while num !=0:
	




print(f"Number in reverse order:",end="")
rev = 0
while num != 0:
	rem = num % 10
	rev = rev *10 + rem
	num = num // 10

print(rev) 
