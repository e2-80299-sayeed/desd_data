from flask import jsonify

def create_response(data, error = None):  # here error is a default argument(we donot need to pass while calling)
    # create empty dictionary
    d = dict()
    if error == None:
        d = {
            "status": "success",
            "data":data
        }
    else :
        d = {
            "status": "failure"
        }
    return jsonify(d)    