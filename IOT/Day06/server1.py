from flask import Flask, render_template, request

server = Flask(__name__)

@server.route("/", methods = {'GET'})
def welcome():
    temp = 35.0
    return render_template("welcome.html", message=temp)

@server.route("/temperatures", methods = {'GET'})
def read_temperatures():
    # read all temps from database
    temps = [ (32.0, "Nira"), (31.5, "Indrayani"), (33, "Warana")]

    return render_template("table.html", message=temps)

@server.route("/temperature", methods = {'GET', 'POST'})
def add_temperature():
    if request.method == 'POST':
        temp = request.form.get("temp")
        loc = request.form.get("loc")
        print(f"Temp = {temp}, Location = {loc}")
        return f"Temp = {temp}, Location = {loc}"
    return render_template("form.html")

server.run(debug=True)