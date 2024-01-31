
#List = collection of similar or dissimilar elements in []
def function():
	l1 = [11, 22, 33, 44]
	print(f"list l1 = {l1}")
	print(f"type of 11 = {type(l1)}")
	print(f"l1[0]  = {l1[0]}")

function()

def function2():
	i = 0
	l1 = [11, 22, 33, 44]

	for i in l1:
		print(i)


def function3():
	i = 0
	l1 = [11, 22, 33, 44]
	
	print(f"length of l1 = {len(l1)}")
	l1.append(100) #value get added at last position
	l1.insert(2,200) #value is added at 2nd position 
	l1.remove(33) #remove value 
	l1.pop() #remove last value

	for i in l1:
		print(i)				

function3()
