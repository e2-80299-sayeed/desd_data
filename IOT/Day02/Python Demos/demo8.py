def funtion1():
    l1=[[1,2,3],[4,5,6],[7,8,9]]
    print(l1)

    for l in l1:
        print(l)

    for l in l1:
        for ele in l:
            print(ele) 

    print(l1[1][2])        
# funtion1()  

def funtion2():
    l1=[(1,2,3),(11,22,33),(10,20,30)]
    print(l1)

    for t in l1:
        print(t)

    for t in l1:
        for ele in t:
            print(ele)

# funtion2()

def funtion3():
    l1=[
        ("abc",11),
        ("pqr",22),
        ("xyz",33),
    ]

    for t in l1:
        print(t)

    for (name,age) in l1:
        print(f"name={name}  age={age}")    


# funtion3()   
 
def funtion4():
    student={
        "name" : "abc",
        "mark" : [89,70,60,88]
    }
    print(student)
    print(f"Name={student['name']}")
    print(f"Marks=")
    for m in student['mark']:
        print(m)
funtion4()    