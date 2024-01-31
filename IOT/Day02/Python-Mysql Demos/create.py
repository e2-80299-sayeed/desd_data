# import mysql connector
import mysql.connector

# create connection with mysql server
connection = mysql.connector.connect(
        host = "localhost",
        port = 3306,
        user = "root",
        password = "root",
        database = "iot_sept2023"
)

# create insert query
rollno = int(input("Enter rollno : "))
name = input("Enter name : ")
std = int(input("Enter std : "))
marks = float(input("Enter marks : "))

query = f"insert into students values({rollno}, \"{name}\", {std}, {marks});"

# create cursor using connection
cursor = connection.cursor()

# execute query using cursor
cursor.execute(query)

# update changes on mysql server using connection
connection.commit()

# close the cursor
cursor.close()

# close the connection
connection.close()
