# import module of flask
from flask import Flask

# create server object using Flask
server = Flask(__name__)

@server.route("/")      # decorator
def homepage():
    return "This is homepage"

@server.route("/welcome")
def welcome():
    return "Welcome to the world of IoT"

@server.route("/test")
def test():
    return "This is for testing"

# run your server continuously
server.run()

# * Running on http://127.0.0.1:3000