
# dictonary
# - collection of data in the from of key value pairs
# - key is string
def funtion1():
    person={
        "name":"abc",
        "address" : "pune",
        "age" : 20,
        "mobile" :"987656787"
    }
    print(f"person info={person}")
    print(f"type of person={type(person)}")

    print(f"Name of person={person['name']}")
    print(f"address of person={person['address']}")
    print(f"age of person={person['age']}")
    print(f"mobile of person={person['mobile']}")
    
funtion1() 