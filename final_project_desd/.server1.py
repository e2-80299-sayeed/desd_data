# import flask module
from flask import Flask, request, jsonify

# create a server
server = Flask(__name__)

@server.route("/slot", methods = {'POST'})
def add_slot():
    slot = request.get_json().get('slot')
    
    # insert slot no. and slot status into database~
    print(f"Recieved slot status : {slot}")
    # if slot=empty, then turn on the green light
    return "Slot status is received"

# run the server
server.run(host="0.0.0.0", port=4000, debug=True)
