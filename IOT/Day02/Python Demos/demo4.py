# Tuple
# - collection of similar or different type of data
# - tuple is immutable
# - duplicate values are allowed

def function1():
    t1=(11,22,33,44)
    print(f"t1={t1}")
    print(f"type of t1={type(t1)}")

    for i in t1:
        print(i)

    print(f"t1[0]={t1[0]}")
    print(f"t1[1]={t1[1]}")
    print(f"t1[2]={t1[2]}")
function1()    