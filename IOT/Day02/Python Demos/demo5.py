# set 
# - collection of unique values

def function1():
    s1={10,20,30,40,50}
    s2={40,50,60,70}
    print(f"s1={s1}")
    print(f"type of s1={type(s1)}")
    print(f"s2={s2}")

    print(f"intersection of s1 and s2 = {s1.intersection(s2)}")
    print(f"union of s1 and s2 = {s1.union(s2)}")

function1()
