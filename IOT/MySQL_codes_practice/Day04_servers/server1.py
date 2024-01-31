from flask import Flask

import utils.response as response
import utils.database as db

server = Flask(__name__)

@server.route("/welcome")
def welcome():
    return response.create_response("welcome to IoT Application")

@server.route("/temperature", methods = {'GET'})
def temperature_methods():
    #To get data from database form a query
    query = f"select * from temperature;"

    #execute query to get all temps from database
    temps = db.execute_select_query(query)

    #return
    return response.create_response(temps)

#run server
server.run(debug=True)