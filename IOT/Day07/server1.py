# import flask module
from flask import Flask, request, jsonify

# create a server
server = Flask(__name__)

@server.route("/temperature", methods = {'POST'})
def add_temperature():
    temp = request.get_json().get('temperature')
    
    # insert temp and loc into database
    print(f"Recieved Temperature : {temp}")
    # if temp is above threshould then turn on the fan
    return "Temp is received"

# run the server
server.run(host="0.0.0.0", port=4000, debug=True)