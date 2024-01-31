
def fun1():
	person = { 		# person is a dictionary
		"name":"sayeed", #here "name"is a key and "sayeed" is a value key is always string
		"Address":"pune",
		"age" : 22,
		"mobile": "9860444521"
		}
	print(f"person info = {person}")
	print(f"type of person = {type(person)}")
	
	print(f"address of person = {person['Address']}") #while printing specific value of key we need to write in single quote ''
		
fun1()


num = 98604
print(f"num = ",end="")
while num != 0:
	
	rem = num % 10
	num = num //10
	print(f"{rem}",end="")
