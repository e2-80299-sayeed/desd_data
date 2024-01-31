from flask import jsonify

def create_response(data) :
    d = dict()

    d = {
        "status": "success",
        "data": data
    }
    
    return jsonify(d)
    