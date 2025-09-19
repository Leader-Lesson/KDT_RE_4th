#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // 블루투스 모듈 (RX, TX)

const int ledPins[] = {4, 5, 6, 7, 8}; // 5개의 LED 핀
bool ledState[] = {false, false, false, false, false}; // 각 LED 상태 저장

void setup() {
  Serial.begin(9600);   // PC 시리얼 모니터용
  BTSerial.begin(9600); // 블루투스 시리얼 통신 시작
  
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  Serial.println("Bluetooth LED Control Ready");
}

void loop() {
  if (BTSerial.available()) { // 블루투스로 데이터 수신 여부 확인
    char receivedChar = BTSerial.read(); // 수신된 문자 읽기
    Serial.print("Received: ");
    Serial.println(receivedChar);

    if (receivedChar >= '1' && receivedChar <= '5') { // 1~5의 문자일 때만 처리
      int ledIndex = receivedChar - '1'; // 배열 인덱스로 변환 (0~4)
      
      // LED 상태 토글
      ledState[ledIndex] = !ledState[ledIndex];
      digitalWrite(ledPins[ledIndex], ledState[ledIndex] ? HIGH : LOW);

      // 현재 상태를 블루투스로 전송
      BTSerial.print("LED ");
      BTSerial.print(ledIndex + 1);
      BTSerial.println(ledState[ledIndex] ? " ON" : " OFF");
    }
  }
}
