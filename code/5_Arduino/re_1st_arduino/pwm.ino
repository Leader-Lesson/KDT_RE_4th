int ledPin = 9; // PWM 지원 핀
int brightness = 0; // LED 밝기
int fadeAmount = 5; // 밝기 증감량

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    analogWrite(ledPin, brightness); // 현재 밝기 설정
    brightness += fadeAmount; // 밝기 증가 또는 감소
    
    // 밝기가 0 또는 255에 도달하면 방향 변경
    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
    }
    
    delay(30); // 부드러운 변화 효과
}