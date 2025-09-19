// 아두이노 LED 5개 순차적 점등 및 랜덤 점등 실습

#define LED_COUNT 5
int ledPins[LED_COUNT] = {2, 3, 4, 5, 6};

void setup() {
    for (int i = 0; i < LED_COUNT; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
    randomSeed(analogRead(0)); // 랜덤 시드 초기화
}

// 실습1: LED 5개를 일정 시간 간격으로 순차적으로 점등
void sequentialLighting(int delayTime) {
    for (int i = 0; i < LED_COUNT; i++) {
        digitalWrite(ledPins[i], HIGH);
        delay(delayTime);
        digitalWrite(ledPins[i], LOW);
    }
}

// 실습2: LED 5개를 랜덤하게 점등
void randomLighting(int delayTime) {
    int randomLED = random(0, LED_COUNT);
    digitalWrite(ledPins[randomLED], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[randomLED], LOW);
}

void loop() {
    sequentialLighting(500); // 0.5초 간격으로 순차 점등
    delay(1000); // 1초 대기
    
    for (int i = 0; i < 5; i++) {
        randomLighting(500); // 랜덤 LED 점등 (5회 실행)
    }
    delay(1000); // 1초 대기
}
