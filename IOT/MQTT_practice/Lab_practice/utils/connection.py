import mysql.connector 

def get_connection():
    Connection = mysql.connector.connect(
        host = "localhost",
        port = 3306,
        user = "root",
        password = "root",
        database = "iot_sept2023"
    )
    return Connection