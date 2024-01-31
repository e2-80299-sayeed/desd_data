# import flask
from flask import Flask, request
import utils.response as response
import utils.database as db

# create server
server = Flask(__name__)

@server.route("/welcome")
def welcome():
    return response.create_response("Welcome to IoT Application");

@server.route("/temperature", methods = {'GET', 'POST', 'PUT', 'DELETE'})
def temperature_methods():
    if (request.method == 'GET'):
        # to get data from database form a query
        query = f"select * from temperature;"

        # execute query to get all temps from database
        temps = db.execute_select_query(query)

        # return temps into response
        return response.create_response(temps)
    elif(request.method == 'POST'):
        # retrieve data from request body
        temp = request.get_json().get('temperature')
        loc = request.get_json().get('location')

        # insert data into database
        query = f"insert into temperature (temperature, location) values({temp}, \"{loc}\");"
        db.execute_query(query)

        # return some response to the client
        return response.create_response("Temperature is added successfully")
    elif(request.method == 'PUT'):
        temp = request.get_json().get('temperature')
        loc = request.get_json().get('location')

        # insert data into database
        query = f"update temperature set temperature = {temp} where location = \"{loc}\";"
        db.execute_query(query)
       response.create_response("Temperature is added successfully")
    elif(request.method == 'DELETE'):
        pass


# run server
server.run(debug=True)
