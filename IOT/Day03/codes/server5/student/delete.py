import student.connection as db_conn

def delete_student(rollno):
    conn = db_conn.get_connection()

    query = f"delete from students where rollno={rollno};"
    cur = conn.cursor()
    cur.execute(query)
    conn.commit()

    cur.close()
    conn.close()