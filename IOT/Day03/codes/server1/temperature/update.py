import database.connection as db

def update_temps(loc,temp):
    conn = db.get_connection()

    query = f"update temperature set temperature = {temp} where location = \"{loc}\";"
    
    cursor = conn.cursor()
    cursor.execute(query)
    conn.commit()
    cursor.close()
    conn.close()