# import flask module
from flask import Flask, request, jsonify

# import mqtt client
import paho.mqtt.client as mqtt
import utils.database as db
import utils.response as response

# create client for mqtt
client = mqtt.Client("Publisher")

# create a server
server = Flask(__name__)

@server.route("/all", methods = {'GET'})
def get_health():
    query = f"select * from health;"
    temps = db.execute_select_query(query)
    client.connect("localhost")
    client.publish("/health/status","GET : success")
    client.disconnect()
    return response.create_response(temps)

@server.route("/add", methods = {'POST'})
def add_health():   
    name = request.form.get('name')
    age = request.form.get('age')
    city = request.form.get('city')
    steps = request.form.get('steps')
    pulse = request.form.get('pulse')
    blood_oxygenation = request.form.get('blood')
    body_temperature = request.form.get('temp')

    #query = f"insert into health (name, age, city, steps, pulse, blood_oxygenation, body_temperature ) values(\"{name}\",{age},\"{city}\",{steps},{pulse},{blood_oxygenation},{body_temperature});"
    query = f"insert into health values(\"{name}\",{age},\"{city}\",{steps},{pulse},{blood_oxygenation},{body_temperature});"
    db.create_query(query)
    client.connect("localhost")
    client.publish("/health/status","POST : success")
    client.disconnect()
    return response.create_response(f"Data inserted successfully")

@server.route("/info", methods = {'POST'})
def info_health():
    name = request.form.get('name')
    
    query = f"select * from health where name = \"{name}\" ;"
    temps = db.execute_select_query(query)
    client.connect("localhost")
    client.publish("/health/status","POST : success")
    client.disconnect()
    return response.create_response(temps)   

@server.route("/update", methods = {'PUT'})
def update_health():   
    name = request.form.get('name')
    city = request.form.get('city')

    query = f"update health set city =\"{city}\" where name = \"{name}\";"
    db.create_query(query)
    
    client.connect("localhost")
    client.publish("/health/status","PUT : success")
    client.disconnect()
    return response.create_response(f"Data updated successfully")

@server.route("/steps", methods = {'GET'})
def steps():
    
    query = f"select MAX(steps) FROM health;"
    temps = db.execute_select_query(query)
    client.connect("localhost")
    client.publish("/health/status","GET : success")
    client.disconnect()
    return response.create_response(temps)

# run the server
server.run(port =4000, debug=True)
