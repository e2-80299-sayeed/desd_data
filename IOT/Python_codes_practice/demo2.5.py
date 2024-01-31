
#set {} collection of unique loop
#It cannot allow the duplicate value

def func1():
	s1 = {10, 20, 30, 40}
	s2 = {40, 50, 60, 70} 
	print(f"S1 = {s1}")
	print(f"type of s1 = {type(s1)}")	
	print(f"S2 = {s2}")	
	
	print(f"intersection of s1 and s2 = {s1.intersection(s2)}")
	print(f"union of s1 and s2 = {s1.union(s2)}")	

func1()
