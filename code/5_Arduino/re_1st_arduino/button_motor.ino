// 버튼을 이용한 LED 및 모터 제어

#define LED_COUNT 3
int ledPins[LED_COUNT] = {2, 3, 4};
int motorPin = 5; // 모터드라이브 제어 핀
int buttonStart = 6; // 모터 및 LED 시작 버튼
int buttonStop = 7;  // 모터 정지 버튼

void setup() {
    for (int i = 0; i < LED_COUNT; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
    pinMode(motorPin, OUTPUT);
    pinMode(buttonStart, INPUT_PULLUP);
    pinMode(buttonStop, INPUT_PULLUP);
}

void loop() {
    // 버튼 1을 누르면 LED 점등 후 모터 동작
    if (digitalRead(buttonStart) == LOW) {
        for (int i = 0; i < LED_COUNT; i++) {
            digitalWrite(ledPins[i], HIGH);
            delay(1000);
        }
        delay(3000); // 3초 대기 후 모터 동작
        digitalWrite(motorPin, HIGH);
    }
    
    // 버튼 2를 누르면 모터 정지 및 LED 소등
    if (digitalRead(buttonStop) == LOW) {
        digitalWrite(motorPin, LOW);
        for (int i = 0; i < LED_COUNT; i++) {
            digitalWrite(ledPins[i], LOW);
        }
    }
}