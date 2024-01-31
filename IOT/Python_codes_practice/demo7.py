
# function = Set of instructions in block for reusability of code/ faster development/ Debugging 

# Functions in Python

# simple function

def function1():
	print("Inside function1 body")


function1()
print()
# ==================================================================================================

# function with 1 parameter

def function2(param):
	print(f"Value of Param = {param}")
	print(f"type of Param = {type(param)}")

function2(22)	
print()
function2('F')
print()
function2("PUNE")
print()
function2(2.44)
print()
function2(True)
print()
# ===================================================================================================	

# function with 2 parameter return result

def function3(param1,param2):
	return param1 + param2

res = function3(20,10)
print(f"Result from  function3 = {res}")

print( )

res = function3(2.5,3.4)
print(f"Result from  function3 = {res}")

print( )

#res = function3(11,'a')			=> error
#print(f"Result from  function3 = {res}")

res = function3('sunbeam ','pune')
print(f"Result from  function3 = {res}")
