
import mysql.connector

def insert_temperatures(temperature,location):
    conn = mysql.connector.connect(
        host = "localhost",
        port = 3306,
        user = "root",
        password = "root",
        database = "iot_sept2023"
    )

    query = f"insert into temperature(temperature, location) values( {temperature},\"{location}\");"
    cursor = conn.cursor()
    cursor.execute(query)
    conn.commit()

    cursor.close()
    conn.close()

    print("temperature is added successfully inti database")    

def get_temperatures():
    conn = mysql.connector.connect(
        host="localhost",
        port= 3306,
        user = "root",
        password = "root",
        database = "iot_sept2023"
    ) 
    query = f"select * from temperature;"
    cursor = conn.cursor()
    cursor.execute(query)
    temps = cursor.fetchall()
    cursor.close()
    conn.close()

    return temps

#to insert temp into table
temp = float(input("Enter temperature : "))
loc = input("Enter location : ")
insert_temperatures(temp,loc)

#to get all temperature from database
temp_list = get_temperatures()

#to print all temperature on console
print("Temperatures are :\n")
for temp in temp_list:
    print(temp)