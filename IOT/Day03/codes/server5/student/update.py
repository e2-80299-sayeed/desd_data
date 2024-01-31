import student.connection as db_conn

def update_student(rollno, marks):
    conn = db_conn.get_connection()

    query = f"update students set marks={marks} where rollno={rollno};"
    cur = conn.cursor()
    cur.execute(query)
    conn.commit()

    cur.close()
    conn.close()

