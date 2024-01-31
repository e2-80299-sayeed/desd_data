# default argument , named parameter
# 

def funtion1(p1=1,p2=1,p3=1):
    print(f"p1 = {p1} , p2={p2} , p3={p3}")

funtion1(11,22,33)   
funtion1(11,22)  
funtion1(11) 
funtion1()


funtion1(p2=66)
funtion1(p3=10,p1=20,p2=30)
