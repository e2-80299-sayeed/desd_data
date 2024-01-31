#import flask module
from flask import Flask,request,jsonify

#import mqtt client
import paho.mqtt.client as mqtt

#create client for mqtt
client = mqtt.Client("Publisher")


#create a server
server = Flask(__name__)

@server.route("/temperature",methods = {'POST'})
def add_temperature():
    temp = request.form.get('temperature')
    loc = request.form.get('location')

    #insert temp and loc into database

    #if temp is above threshold then turn on the fan
    d = dict()

    if float(temp) >= 35.0:
        client.connect("localhost")
        client.publish("room/fan", "ON")
        client.disconnect()
        d = {
            "status":"Success",
            "Fan Status":"ON"
        }
    else:
        client.connect("localhost")
        client.publish("room/fan", "OFF")
        client.disconnect()
        d = {
            "status":"Success",
            "Fan Status":"OFF"
        }
    return jsonify(d)


#run server
server.run(debug=True)