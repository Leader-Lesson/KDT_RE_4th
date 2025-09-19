// 초음파 센서를 이용한 후방 감지 센서 (부저 비프음 간격 조절)

#define TRIG_PIN 9  // 초음파 센서 트리거 핀
#define ECHO_PIN 10 // 초음파 센서 에코 핀
#define BUZZER_PIN 3 // 부저 핀

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
}

// 초음파 센서를 이용해 거리 측정
long getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    long duration = pulseIn(ECHO_PIN, HIGH);
    long distance = duration * 0.034 / 2; // cm 단위 거리 계산
    return distance;
}

void loop() {
    long distance = getDistance();
    Serial.print("거리: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    if (distance < 10) {
        tone(BUZZER_PIN, 1000, 100); // 가장 빠른 비프음
        delay(100);
    } else if (distance < 20) {
        tone(BUZZER_PIN, 1000, 200);
        delay(200);
    } else if (distance < 30) {
        tone(BUZZER_PIN, 1000, 300);
        delay(300);
    } else {
        noTone(BUZZER_PIN); // 일정 거리 이상일 때 부저 끄기
    }
}
