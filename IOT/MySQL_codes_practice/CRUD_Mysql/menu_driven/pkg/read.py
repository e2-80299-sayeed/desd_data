import connection as conn

def read_employee():
	conn1 = conn.conn()
	query = f"select * from employee;"
	cursor = conn1.cursor()
	cursor.execute(query)
	emps = cursor.fetchall()
	
	cursor.close()
	conn1.close()
	return emps