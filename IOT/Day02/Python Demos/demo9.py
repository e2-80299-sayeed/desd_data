#  use of mymath module in code

def function1():
    import mymath
    

    print(f"PI={mymath.PI}")

    sum=mymath.add(11,22)
    print(f"sum={sum}")

    print(f"diff={mymath.sub(44,23)}")

# function1()   

def function2():
    import mymath as m

    print(f"PI={m.PI}")

    sum=m.add(11,22)
    print(f"sum={sum}")

    print(f"diff={m.sub(44,23)}")
# function2()  

def function2():
    from mymath import add
    from mymath import sub as diff

    sum=add(11,22)
    print(f"sum={sum}")

    print(f"diff={diff(44,23)}")
function2()  
