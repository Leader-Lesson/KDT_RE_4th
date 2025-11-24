from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # 다른 출처(파일/로컬서버)에서 접근 허용

@app.route("/data", methods=["GET"], strict_slashes=False)
def getData():
    print("getData", dict(request.args)) 
    return jsonify(ok=True)             

if __name__ == "__main__":
    app.run(host="0.0.0.0",
            port=8080,
            debug=True,
            use_reloader=False,
            threaded=False)
