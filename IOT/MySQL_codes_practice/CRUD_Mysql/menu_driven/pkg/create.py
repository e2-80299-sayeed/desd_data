import pkg.connection

def create_employee(empid,name,loc,salary):
	conn1 = pkg.connection.conn()
	query = f"insert into employee values({empid},\"{name}\",\"{loc}\",{salary});"
	cursor = conn1.cursor()
	cursor.execute(query)
	conn1.commit()

	cursor.close()
	conn1.close()
	print("Employee is added successfully into database\n")