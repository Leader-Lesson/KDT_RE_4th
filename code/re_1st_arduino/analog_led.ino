const int potPin = A0;  // 가변저항 연결 핀
const int ledPin = 9;   // PWM 출력 핀

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);    // 0~1023 범위의 아날로그 값 읽기
  int pwmValue = map(potValue, 0, 1023, 0, 255); // 0~255 범위로 변환
  analogWrite(ledPin, pwmValue);        // LED 밝기 조절
  delay(10);
}
