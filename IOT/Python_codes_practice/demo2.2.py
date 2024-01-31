#defualt argument, named parameter 

def function1(p1, p2 = 1, p3 = 2):          #assignment of default value is from right to left 
	print(f"p1 = {p1}, p2 = {p2}, p3 = {p3}") 

function1(11, 22 ,33)
function1(11, 22 )
function1(11)

function1(11, p2 = 66)    			#Named Argument	
function1(p1 = 10, p2 = 20, p3 = 30 )
