# # 6) Write a Python function to calculate the factorial of a number (a non-negative integer). 
# The function accepts the number as an argument.


def factorial(num):
    fact = 1
    while num != 0 :
        fact = fact * num
        num = num -1
        
    return fact
num = int(input("Enter a Number: "))
    
fact = factorial(num)
print (f"Factorial is {fact}")
