# list
# - collection of similar or different type of data
# - list is mutable
# - duplicate values are allowed

def function1():
    l1=[11,22,33,44]
    print(f"list l1={l1}")
    print(f"type of  l1 = {type(l1)}")
    print(f"l1[0]={l1[0]}")
    print(f"l1[2]={l1[2]}")
# function1()

def function2():
    l1=[11,22,33,44]
    
    for i in l1:
        print(i)
    
# function2()

def function3():
    l1=[11,22,33,44]
    
    print(f"length of l1={len(l1)}")
    l1.append(100)      # value get added at the last posi
    l1.insert(2,200)    # value get added at given index location
    l1.remove(33)       # remove value from list
    l1.pop()            #remove last value from list
    print(f"list l1={l1}")
    
function3()