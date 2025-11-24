#include <SoftwareSerial.h>
SoftwareSerial esp8266(2,3);

const char* ssid = "cctv";
const char* password = "spreatics*";
const char* server = "192.168.200.100";
const int   port   = 8080;

bool sendCommand(const String& cmd, const char* expect = "OK", unsigned long timeout = 5000) {
  esp8266.print(cmd); esp8266.print("\r\n");
  unsigned long t = millis(); String buf;
  while (millis() - t < timeout) {
    while (esp8266.available()) {
      char c = (char)esp8266.read();
      buf += c;
      Serial.write(c);                // ← 로그로 확인
      if (expect && *expect && buf.indexOf(expect) != -1) return true;
    }
  }
  return false; 
}

void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
    sendCommand("AT", "OK", 1500);

  sendCommand("AT+CWMODE=1", "OK", 2000);
  sendCommand(String("AT+CWJAP=\"") + ssid + "\",\"" + password + "\"", "WIFI GOT IP", 20000);
  sendCommand("AT+CIPMUX=0", "OK", 2000);
}

void loop() {
  sendDataToServer(25, 60);
  delay(5000);
}

void sendDataToServer(int temp, int hum){
  String url = "/data?temperature=" + String(temp) + "&humidity=" + String(hum);

  if (!sendCommand(String("AT+CIPSTART=\"TCP\",\"") + server + "\"," + port, "CONNECT", 5000)) return;

  String req =
    String("GET ") + url + " HTTP/1.1\r\n"
    "Host: " + String(server) + ":" + String(port) + "\r\n"
    "Connection: close\r\n\r\n";

  if (sendCommand(String("AT+CIPSEND=") + req.length(), ">", 3000)) {
    esp8266.print(req);
    sendCommand("", "SEND OK", 4000);
  }

  sendCommand("AT+CIPCLOSE", "OK", 2000);
  Serial.println("\n[데이터 전송 시도 종료]");
}