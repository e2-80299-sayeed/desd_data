#import Flask
from flask import Flask, request

import student.create
import student.read
import student.update
import student.delete

#create server 
app = Flask(__name__)

@app.route("/student/add", methods = {'POST'})
def add_student():
    rollno = request.form.get('rollno')
    name = request.form.get('name')
    std = request.form.get('std')
    marks = request.form.get('marks')
    
    #insert data into database
    student.create.insert_student(rollno,name,std,marks)

    return "student is added into database successfully"

@app.route("/student/read",methods ={'GET'})
def read_students():
    studs = student.read.get_studnets()

    print("students list :")
    for stud in studs:
        print(stud)
    return studs

@app.route("/student/update", methods = {'PUT'})
def update_students():
    rollno = request.form.get('rollno')
    marks = request.form.get('marks') 

    student.update.update_student(rollno,marks)

    return "students is updated into database successfully"

@app.route("/student/delete", methods = {'DELETE'})
def delete_student():
    rollno = request.form.get('rollno')

    student.delete.delete_student(rollno)

    return "student is deleted successfully"

#run server
app.run(debug=True)