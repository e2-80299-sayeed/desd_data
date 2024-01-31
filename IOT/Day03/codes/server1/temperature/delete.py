import database.connection as db
def delete_temp(loc):
    conn = db.get_connection()
    query = f"delete from temperature where location = \"{loc}\";"

    cursor = conn.cursor()
    cursor.execute(query)
    conn.commit()
    cursor.close()
    conn.close()
    

