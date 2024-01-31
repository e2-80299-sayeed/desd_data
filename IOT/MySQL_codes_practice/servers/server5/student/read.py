import student.connection as db_conn

def get_studnets():
    conn = db_conn.get_connection()

    query = f"select * from students;"
    cur = conn.cursor()
    cur.execute(query)
    studs = cur.fetchall()

    cur.close()
    conn.close()
    return studs 