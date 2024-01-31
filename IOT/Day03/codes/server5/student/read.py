import student.connection as db_con

def get_students():
    conn = db_con.get_connection()

    query = f"select * from students;"
    cur = conn.cursor()
    cur.execute(query)
    studs = cur.fetchall()

    cur.close()
    conn.close()
    return studs
