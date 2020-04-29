import Flask
from flask import request

import requests

app = Flask(__name__)

@app.route('/get_time')
def get_time():
    #getting get request
    zone = request.arg.get('time_zone')
    if zone is None:
        return 400
    
    #using worldclockapi.org
    response = requests.get('http://worldclockapi.com/api/json/{}/now' .format(zone))
    if response.status_code != 200:
        return response.status_code
    if response.json()['currentDateTime'] is None:
        return 500
    
    return(response.json()['currentDateTime'])

if __name__ == "__main__":
    app.run()