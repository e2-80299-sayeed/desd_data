# import moudle of mysql connector
import mysql.connector 

#create connection with mysql server
connection = mysql.connector.connect(
    host = "localhost",   #your mysql host name or ip address
    port = 3306,
    user = "root",       #username for your mysql database
    password = "root",     #password for the above username
    database = "iot_sept2023"      #name of your database
)

print(f"type = {type(connection)}")

#create select query
query = "select * from temperature;"

#create cursor through connnection 
cursor = connection.cursor()

# using cursor execute query 
cursor.execute(query)

# get all records from cursor (list of records)
temp_list = cursor.fetchall()   #list as tuples

#display all temperatures on console
#print(temp_list)

for record in temp_list:
    print(temp_list)

#close the cursor 
cursor.close()

#close the connection
connection.close()
