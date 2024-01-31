# import flask
from flask import Flask
import utils.response as response
import utils.database as db

# create server
server = Flask(__name__)

@server.route("/welcome")
def welcome():
    return response.create_response("Welcome to IoT Application");

@server.route("/temperature", methods = {'GET'})
def temperature_methods():
    # to get data from database form a query
    query = f"select * from temperature;"

    # execute query to get all temps from database
    temps = db.execute_select_query(query)

    # return temps into response
    return response.create_response(temps)


# run server
server.run(debug=True)