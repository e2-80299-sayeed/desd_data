#import module of flask (FLASK is a class)
from flask import Flask

# create server object using Flask
server = Flask(__name__)      #name indicates name of the file, here server is a object

@server.route("/")    #REST-api/web-service, route is a # '@' is a decorater 
def homepage():
    return "This is homepage"

@server.route("/welcome")
def welcome():
    return "welcome to the world of IoT"

@server.route("/test")
def test():
    return "This is for testing"

#run your server continuously
server.run(host="0.0.0.0", port=3000, debug=True)  # run is method/function in class name server

