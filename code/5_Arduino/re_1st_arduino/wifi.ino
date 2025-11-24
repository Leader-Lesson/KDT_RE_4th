#include <SoftwareSerial.h>
SoftwareSerial esp8266(2, 3);
const char* ssid = "";
const char* password = "";
const char* server = "";
void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
  Serial.println("ESP8266 초기화 중...");
  sendCommand("AT", "OK", 5000);
  sendCommand("AT+CWMODE=1", "OK", 5000);
  sendCommand("AT+CWJAP=\"" + String(ssid) + "\",\"" + String(password) + "\"", "OK", 15000);
  Serial.println("Wi-Fi 연결 완료!");
}
void loop() {
  sendDataToServer(25, 60);
  delay(10000);
}
void sendDataToServer(int temp, int hum) {
  String url = "/data?temperature=" + String(temp) + "&humidity=" + String(hum);
  sendCommand("AT+CIPSTART=\"TCP\",\"" + String(server) + "\",5000", "OK", 5000);
  sendCommand("AT+CIPSEND=" + String(url.length() + 4), ">", 5000);
  sendCommand("GET " + url + " HTTP/1.1\r\nHost: " + String(server) + "\r\n\r\n", "OK", 5000);
  sendCommand("AT+CIPCLOSE", "OK", 5000);
  Serial.println("데이터 전송 완료!");
}
void sendCommand(String command, const char* response, int timeout) {
  esp8266.println(command);
  long int time = millis();
  char tempResponse[20];
  strcpy(tempResponse, response);
  while ((millis() - time) < timeout) {
    if (esp8266.find(tempResponse)) {
      Serial.println(command + " 명령 성공!");
      return;
    }
  }
  Serial.println(command + " 실패...");
}