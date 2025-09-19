#include <Servo.h>  // 서보모터 라이브러리 포함

Servo myServo;      // 서보 객체 생성
const int potPin = A0;  // 가변저항 입력 핀
const int servoPin = 9; // 서보모터 제어 핀

void setup() {
  myServo.attach(servoPin);  // 서보모터를 9번 핀에 연결
}

void loop() {
  int potValue = analogRead(potPin);    // 0~1023 범위의 값 읽기
  int angle = map(potValue, 0, 1023, 0, 180); // 0~180도로 변환
  myServo.write(angle);  // 서보모터 회전
  delay(10);  // 빠른 변화를 방지하기 위한 약간의 지연
}
