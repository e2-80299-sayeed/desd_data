# import flask
from flask import Flask
import server1.temperature.read as temp
import server1.database.connection as db

# create server
app = Flask(__name__)

@app.route("/temperature/<temp>")
def add_temperature(temp):
    return f"received temp : {temp}"

# #temps = temp.get_temperatures()
# for temp in temps:
#     print(temp)
if __name__ == '__main__':
    app.run(host="0.0.0.0", port=3000, debug=True)
    # app.run(debug=True)