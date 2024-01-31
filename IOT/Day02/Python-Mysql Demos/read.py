# import module of mysql connector
import mysql.connector

# create connection with mysql server
connection = mysql.connector.connect(
            host = "localhost",
            port = 3306,
            user = "root",
            password = "root",
            database = "iot_sept2023"
)

##print(f"type = {type(connection)}")
# create select query
query = "select * from students;"

# create cursor through connection
cursor = connection.cursor()

# using cursor execute query
cursor.execute(query)

# get all records from cursor (list of records)
stud_list = cursor.fetchall()

# display all temperatures on console
# print(stud_list)

#for record in stud_list:
#    print(record)

for (rollno, name, std, marks) in stud_list:
    print(f"rollno = {rollno}, name = {name}, std = {std}, marks = {marks}")

# close the cursor
cursor.close()

# close the connection
connection.close()
