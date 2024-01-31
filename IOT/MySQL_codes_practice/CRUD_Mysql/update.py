#import mysql connector 
import mysql.connector

#create connection with mysql server
connection = mysql.connector.connect(
    host="localhost",
    user="root",
    password="root",
    database="iot_sept2023"
)

#create update query 
name = input("Enter name of students : ")
marks = float(input("Enter updated marks : "))

query = f"update students set marks = {marks} where name=\"{name}\";"

#create cursor
cursor = connection.cursor()

#execute query using cursor
cursor.execute(query)

#commit your changes
connection.commit()

print("Data updated successfully")

#close the cursor 
cursor.close()

#close the connection
connection.close()