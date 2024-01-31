from flask import Flask,request, render_template
import utils.database as db
server =  Flask(__name__)

@server.route("/", methods = {'GET'})
def welcome():
    temp = 35.0
    return render_template("welcome.html",message = temp)

@server.route("/temperatures", methods = {'GET'})
def read_temperatures():
    temps = [ (32.0, "Nira"), (31.5, "Indrayani"),(33, "Warna")]
    return render_template("table.html", message = temps)

@server.route("/temperature" , methods = {'GET', 'POST'})
def add_temperature():
    if request.method == 'POST' :
        temp = request.form.get("temp")
        loc = request.form.get("loc")
        print(f"Temp = {temp}, Location = {loc}")
        query = f"insert into temperature(temperature,location) values( {temp}, \"{loc}\");"
        db.execute_query(query)
        print("Temperature is added into database successfully")
        return f"Temp = {temp}, Location = {loc}" 
    return render_template("form.html")

server.run(host="0.0.0.0", port=3000, debug=True)