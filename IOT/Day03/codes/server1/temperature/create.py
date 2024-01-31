import database.connection as db

def insert_temperature(temp, loc):
    connection = db.get_connection()
    
    query = f"insert into temperature(temperature, location) values({temp}, \"{loc}\");"
    cursor = connection.cursor()
    cursor.execute(query)
    connection.commit()

    cursor.close()
    connection.close()