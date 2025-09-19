// 아두이노 버튼과 LED 제어 실습

#define BUTTON_COUNT 5
int ledPins[BUTTON_COUNT] = {2, 3, 4, 5, 6};
int buttonPins[BUTTON_COUNT] = {7, 8, 9, 10, 11};
bool ledStates[BUTTON_COUNT] = {false};

void setup() {
    for (int i = 0; i < BUTTON_COUNT; i++) {
        pinMode(ledPins[i], OUTPUT);
        pinMode(buttonPins[i], INPUT_PULLUP); // 내부 풀업 저항 사용
    }
}

// 실습1: 버튼을 누르면 LED 점등, 버튼을 떼면 LED 소등
void buttonControlLED() {
    for (int i = 0; i < BUTTON_COUNT; i++) {
        int buttonState = digitalRead(buttonPins[i]);
        digitalWrite(ledPins[i], buttonState == LOW ? HIGH : LOW);
    }
}

// 실습2: 버튼을 누를 때마다 LED ON/OFF 토글
void toggleLEDOnPress() {
    static bool lastButtonStates[BUTTON_COUNT] = {HIGH};
    for (int i = 0; i < BUTTON_COUNT; i++) {
        int buttonState = digitalRead(buttonPins[i]);
        if (buttonState == LOW && lastButtonStates[i] == HIGH) {
            ledStates[i] = !ledStates[i];
            digitalWrite(ledPins[i], ledStates[i] ? HIGH : LOW);
            delay(200); // 디바운싱을 위한 지연
        }
        lastButtonStates[i] = buttonState;
    }
}

void loop() {
    buttonControlLED(); // 실습1 실행
    toggleLEDOnPress(); // 실습2 실행
}