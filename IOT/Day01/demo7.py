# Functions in Python

# ==================================
# Simple function
def function1():
    print("Inside function1 body")

# function1()
# ==================================

# ==================================
# function with 1 parameter
# def function2(param):
#     function1()
#     print(f"Value of param = {param}")
#     print(f"type of param = {type(param)}")

# function2(22)
# function2('F')
# function2('PUNE')
# function2(2.44)
# function2(True)
# ==================================

# function with 2 parameter return result

def function3(param1,param2):
    return param1+param2


result=function3(11,22)
print(f"result from function = {result}")

result=function3(11.44,22.33)
print(f"result from function = {result}")

#  result=function3(11,"a") #==> error
#  print(f"result from function = {result}")

result=function3('sunbeam ','pune')
print(f"result from function = {result}")

