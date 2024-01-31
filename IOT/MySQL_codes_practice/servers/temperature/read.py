import database.connection as db

def get_temp():
    connection = db.get_connection()
    query = f"select * from temperature;"
    cursor = connection.cursor()
    cursor.execute(query)
    temps = cursor.fetchall()
    cursor.close()
    connection.close()
    return temps