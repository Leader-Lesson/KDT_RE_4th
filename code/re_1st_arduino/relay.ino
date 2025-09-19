// 릴레이와 버튼을 이용한 PTC 히터 제어

int relayPin = 2;  // 릴레이 모듈 제어 핀
int buttonPin = 3; // 버튼 입력 핀
bool heaterState = false; // 히터 상태 저장

void setup() {
    pinMode(relayPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
    static bool lastButtonState = HIGH;
    int buttonState = digitalRead(buttonPin);
    
    if (buttonState == LOW && lastButtonState == HIGH) {
        heaterState = !heaterState; // 히터 상태 토글
        digitalWrite(relayPin, heaterState ? HIGH : LOW);
        delay(200); // 디바운싱을 위한 지연
    }
    
    lastButtonState = buttonState;
}