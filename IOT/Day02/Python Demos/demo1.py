# demo for global and local variable

num1=11     # global variable
def function1():
    global num1
    num2=22  # local vari
    num1=66
    num2=99
    print(f"value of num2={num2}")

function1()
print(f"value of num1={num1}")