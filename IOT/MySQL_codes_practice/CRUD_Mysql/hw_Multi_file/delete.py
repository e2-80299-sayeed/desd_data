import connection

def delete_employee(empid):
	conn1 = connection.conn()
	query = f" delete from employee where empid = {empid};"
	cursor = conn1.cursor()
	cursor.execute(query)
	conn1.commit()
	cursor.close()
	conn1.close()
	print("Employee is deleted successfully from database\n")