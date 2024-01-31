import mysql.connector

def insert_temperature(temperature, location):
    conn = mysql.connector.connect(
            host = "localhost",
            port = 3306,
            user = "root",
            password ="root",
            database = "iot_sept23"
    )

    query = f"insert into temperatures(temperature, location) values({temperature}, \"{location}\");"
    cursor = conn.cursor()
    cursor.execute(query)
    conn.commit()

    cursor.close()
    conn.close()
    print("Temperature is added successfully into database\n")

def get_temperatures():
    conn = mysql.connector.connect(
            host = "localhost",
            port = 3306,
            user = "root",
            password ="root",
            database = "iot_sept23"
    )

    query = f"select * from temperatures;"
    cursor = conn.cursor()
    cursor.execute(query)
    temps = cursor.fetchall()

    cursor.close()
    conn.close()

    return temps

# to insert temp into table
temp = float(input("Enter temperature : "))
loc = input("Enter location : ")
insert_temperature(temp, loc)

# to get all temperatures from database
temp_list = get_temperatures()

# to print all temperatures opn console
print("Temperatures are : \n")
for temp in temp_list:
    print(temp)