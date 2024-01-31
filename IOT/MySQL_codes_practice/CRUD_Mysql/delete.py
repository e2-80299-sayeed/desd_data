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
roll_no = input("Enter roll_no of students : ")

#create delete query
query = f"delete from students where roll_no=\"{roll_no}\";"

#create cursor
cursor = connection.cursor()

#execute query using cursor
cursor.execute(query)

#commit your changes
connection.commit()

#close the cursor
cursor.close()

print("Data deleted successfully")
#close the connection
connection.close()