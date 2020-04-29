from flask import Flask
import restful3

app = Flask(__name__)
@app.route('/', methods = ['POST', 'GET'])
@app.route('/index', methods = ['POST', 'GET'])
def index():
    #assigning a variable with the time request from endpoint
    iptime = restful3.RequestTime()
    return '''
<html>
    <head>
        <title>Javier Hernandez Week 8 - Python Restful </title>
    </head>
    <body>
        <h1>The time based on your IP is:</h1>
        <h3>''' +str(iptime)+'''</h3>
        </form>
    </body>
</html>'''