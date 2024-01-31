#import mysql connector
import mysql.connector

#create connection with mysql server 
Connection = mysql.connector.connect(
    host = "localhost",
    port = 3306,
    user = "root",
    password = "root",
    database = "iot_sept2023"
)

#create insert query
roll_no =int(input("Enter rollno :"))
name = input("Enter name : ")
std = int(input("Enter std :"))
marks = float(input("Enter marks : "))

query = f"insert into students values({roll_no}, \"{name}\", {std},{marks});"

#create cursor using connection
cursor = Connection.cursor()

#execute query using cursor
cursor.execute(query)

#update changes on mysql server using connection (commit the transaction)
Connection.commit()

#close the cursor
cursor.close()

print("Data inserted successfully") 
#close the connection
Connection.close()
