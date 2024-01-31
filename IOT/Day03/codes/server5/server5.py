# import flask
from flask import Flask, request
import student.create
import student.read
import student.update
import student.delete

# create server
app = Flask(__name__)

@app.route("/student", methods = {'POST'})
def add_student():
    # retrieve data from form
    rollno = request.form.get('rollno')
    name = request.form.get('name')
    std = request.form.get('std')
    marks = request.form.get('marks')

    # insert data into database
    student.create.insert_student(rollno, name, std, marks)

    # return some response to the client
    return "student is added into database successfully"

@app.route("/student", methods = {'GET'})
def read_students():
    studs =  student.read.get_students()

    print("Students list :\n")
    for stud in studs:
        print(stud)

    return studs

@app.route("/student", methods = {'PUT'})
def update_student():
    rollno = request.form.get('rollno')
    marks = request.form.get('marks')

    student.update.update_student(rollno, marks)

    return "student is updated successfully into database"

@app.route("/student", methods = {'DELETE'})
def delete_student():
    rollno = request.form.get('rollno')

    student.delete.delete_student(rollno)

    return "student is deleted successfully from database"

# run server
app.run(debug=True)