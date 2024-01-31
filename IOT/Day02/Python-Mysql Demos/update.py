# import mysql connector
import mysql.connector

# create connection with mysql server
connection = mysql.connector.connect(
            host = "localhost",
            port = 3306,
            user = "root",
            password = "root",
            database = "iot_sept23"
)

# create update query
name = input("Enter name of student : ")
marks = float(input("Enter updated marks : "))

query = f"update students set marks={marks} where name=\"{name}\";"

# create cursor
cursor = connection.cursor()

# execute query using cursor
cursor.execute(query)

# commit your changes
connection.commit()

# close the cursor
cursor.close()

# close the connection
connection.close()