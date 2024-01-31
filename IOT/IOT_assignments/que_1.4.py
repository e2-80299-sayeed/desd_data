# 4] Write a Python function to find the maximum of three numbers.

num1 = int(input("Enter number1: "))
num2 = int(input("Enter number2: "))
num3 = int(input("Enter number3: "))
max = 0
def max_of_3(num1,num2,num3):
    if num1 > num2 and num1 > num3:
        print("num1 is greater")
        max = num1
    elif num2 >num3:
        print("num2 is greater")
        max = num2
    else:
        print("num3 is greater")
        max = num3
    
    return max

    
max = max_of_3(num1,num2,num3)    
print(f"max number is = {max}")

