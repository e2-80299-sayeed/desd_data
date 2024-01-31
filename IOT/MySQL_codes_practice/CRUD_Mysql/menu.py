
import hw_Multi_file.create as c
import hw_Multi_file.read as r
import hw_Multi_file.update as u
import hw_Multi_file.delete as d

choice = 1
while choice != 0:
	print("\n1.Add employee\n 2.Show employee\n 3.Update employee\n 4.Delete employee\n 0.EXIT\n")
	choice = int(input("Enter choice :"))
	if choice == 1 :
		empid = int(input("Enter empid : "))
		name = input("Enter Name : ")
		loc = input("Enter location : ")
		salary = float(input("Enter Salary : "))
		c.create_employee(empid,name,loc,salary)
	
	elif choice == 2 :
		emps = r.read_employee()
		print("\nEmployee List :")
		for emp in emps:
			print(emp)
	elif choice == 3:
		empid = int(input("Enter empid : "))
		salary = float(input("Enter updated Salary : "))
		u.update_employee(empid,salary)

	elif choice == 4:
		empid = int(input("Enter empid you want to delete : "))
		d.delete_employee(empid)

	else:
		print("Thankyou!!")