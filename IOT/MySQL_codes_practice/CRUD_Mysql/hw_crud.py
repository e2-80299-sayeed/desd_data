import mysql.connector

def conn():
	conn = mysql.connector.connect(
		host = "localhost",
		port = 3306,
		user = "root",
		password = "root",
		database ="iot_sept2023"	
	) 
	return conn
#==================================================================================================	

def create_employee(empid,name,loc,salary):
	conn1 = conn()
	query = f"insert into employee values({empid},\"{name}\",\"{loc}\",{salary});"
	cursor = conn1.cursor()
	cursor.execute(query)
	conn1.commit()

	cursor.close()
	conn1.close()
	print("Employee is added successfully into database\n")

#=============================================================================================

def read_employee():
	conn1 = conn()
	query = f"select * from employee;"
	cursor = conn1.cursor()
	cursor.execute(query)
	emps = cursor.fetchall()
	
	cursor.close()
	conn1.close()
	return emps

#=============================================================================================

def update_employee(empid, salary):
	conn1 = conn()
	query = f"update employee set salary = {salary}  where empid = {empid};"
	cursor = conn1.cursor()
	cursor.execute(	query)
	conn1.commit()
	
	cursor.close()
	conn1.close()
	print("Employee is updated successfully into database\n")

#================================================================================================

def delete_employee(empid):
	conn1 = conn()
	query = f" delete from employee where empid = {empid};"
	cursor = conn1.cursor()
	cursor.execute(query)
	conn1.commit()
	cursor.close()
	conn1.close()
	print("Employee is deleted successfully from database\n")

#===============================================================================================

choice = 1
while choice != 0:
	print("\n1.Add employee\n 2.Show employee\n 3.Update employee\n 4.Delete employee\n 0.EXIT\n")
	choice = int(input("Enter choice :"))
	if choice == 1 :
		empid = int(input("Enter empid : "))
		name = input("Enter Name : ")
		loc = input("Enter location : ")
		salary = float(input("Enter Salary : "))
		create_employee(empid,name,loc,salary)
	
	elif choice == 2 :
		emps = read_employee()
		print("\nEmployee List :")
		for emp in emps:
			print(emp)
	elif choice == 3:
		empid = int(input("Enter empid : "))
		salary = float(input("Enter updated Salary : "))
		update_employee(empid,salary)

	elif choice == 4:
		empid = int(input("Enter empid you want to delete : "))
		delete_employee(empid)

	else:
		print("Thankyou!!")
