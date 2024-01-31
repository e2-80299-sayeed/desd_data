#import flask
from flask import Flask

# create server
app = Flask(__name__)

#web service
@app.route("/temperature/<temp>")
def add_temperature(temp):
    return f"Recieved temp :{temp} "

#run server
if __name__ == '__main__':
    app.run(host="0.0.0.0",port=4000,debug=True)