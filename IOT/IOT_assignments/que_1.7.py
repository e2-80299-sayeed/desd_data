#7) Using for loop, write and run a Python program to find factorial from 0 to 10

def factorial(num):
    fact = 1
    while num != 0 :
        fact = fact * num
        num = num -1
        
    return fact


num = 0
for i in range(0,11):       
        print(f"factorial of {num} =",factorial(num))
        num = num +1
        