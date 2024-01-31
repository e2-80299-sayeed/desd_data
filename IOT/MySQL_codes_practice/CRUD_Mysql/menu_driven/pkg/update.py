import connection as conn

def update_employee(empid, salary):
	conn1 = conn.conn()
	query = f"update employee set salary = {salary}  where empid = {empid};"
	cursor = conn1.cursor()
	cursor.execute(	query)
	conn1.commit()
	
	cursor.close()
	conn1.close()
	print("Employee is updated successfully into database\n")