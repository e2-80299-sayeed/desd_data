from flask import Flask,request
import utils.database as db
import utils.response as response

server = Flask(__name__)

@server.route("/temperature", methods = {'GET','POST','PUT','DELETE'})
def temperature_methods():
    if(request.method == 'GET'):
        query = f"select * from temperature;"

        temps = db.execute_select_query(query)
        return response.create_response(temps)
    elif(request.method == 'POST'):
        temp = request.get_json().get('temperature')
        loc = request.get_json().get('location')

        query = f"insert into temperature (temperature,location) values({temp},\"{loc}\");"

        db.execute_query(query)
        return response.create_response("Temperature is added successfully")
    
        








server.run(debug=True)