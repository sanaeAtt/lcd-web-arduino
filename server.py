from flask import Flask, request, send_from_directory
from flask_cors import CORS
import serial

app = Flask(__name__)
CORS(app)

arduino = serial.Serial('COM3', 9600)

@app.route('/')
def index():
    return send_from_directory('static', 'index.html')

@app.route('/message', methods=['POST'])
def message():
    data = request.get_json()
    msg = data.get('message', '')[:32]
    arduino.write((msg + '\n').encode())
    return {'status': 'ok', 'message': msg}

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
