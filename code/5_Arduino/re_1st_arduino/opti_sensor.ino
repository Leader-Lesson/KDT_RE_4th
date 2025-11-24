const int ldrPin = A0;  // 조도센서 입력 핀
const int ledPin = 9;   // LED 출력 핀
const int threshold = 500; // 임계값 설정 (0~1023 범위)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // 시리얼 모니터 출력용
}

void loop() {
  int ldrValue = analogRead(ldrPin); // 조도 센서 값 읽기 (0~1023)
  Serial.println(ldrValue); // 시리얼 모니터에 출력

  if (ldrValue < threshold) { 
    digitalWrite(ledPin, HIGH); // 어두우면 LED 켜기
  } else {
    digitalWrite(ledPin, LOW); // 밝으면 LED 끄기
  }
  
  delay(100); // 짧은 딜레이로 안정적인 읽기
}
