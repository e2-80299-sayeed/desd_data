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
server.run(host="0.0.0.0", port=3000, debug=True)


# * Running on all addresses (0.0.0.0)
# * Running on http://127.0.0.1:3000
# * Running on http:<IP Address>:3000