import student.connection as db_con

def insert_student(rollno, name, std, marks):
    conn = db_con.get_connection()

    query = f"insert into students values({rollno}, \"{name}\", {std}, {marks});"
    cur = conn.cursor()
    cur.execute(query)
    conn.commit()

    cur.close()
    conn.close()