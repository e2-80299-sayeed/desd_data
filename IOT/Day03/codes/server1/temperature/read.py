import server1.database.connection as db

def get_temperatures():
    connection = db.get_connection()
    
    query = f"select * from temperature;"
    cursor = connection.cursor()
    cursor.execute(query)
    temps = cursor.fetchall()

    cursor.close()
    connection.close()
    return temps