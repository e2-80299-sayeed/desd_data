import utils.connection as conn

def execute_query(query):
    conn1 = conn.get_connection()

    cursor = conn1.cursor()
    cursor.execute(query)
    conn1.commit()
    cursor.close()
    conn1.close()

def execute_select_query(query):
    conn1 = conn.get_connection()

    cursor = conn1.cursor()
    cursor.execute(query)
    data = cursor.fetchall()
    cursor.close()
    conn1.close()

    return data