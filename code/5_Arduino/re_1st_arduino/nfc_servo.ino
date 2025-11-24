#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>
#include <Servo.h>

// NFC 센서 핀 설정 (SPI 모드 사용)
#define PN532_SCK  13
#define PN532_MISO 12
#define PN532_MOSI 11
#define PN532_SS   10

Adafruit_PN532 nfc(PN532_SS, PN532_MOSI, PN532_MISO, PN532_SCK);

// 부저, LED, 서보모터 핀 설정
#define BUZZER_PIN 6
#define LED_PIN    7
#define SERVO_PIN  9

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  myServo.attach(SERVO_PIN);
  
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  myServo.write(0); // 서보모터 초기 위치

  // NFC 초기화
  nfc.begin();
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.println("NFC 센서 초기화 실패!");
    while (1);
  }
  nfc.SAMConfig();
  Serial.println("NFC 센서 준비 완료");
}

void loop() {
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength;

  if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength)) {
    Serial.println("NFC 태그 감지!");

    // LED 켜기
    digitalWrite(LED_PIN, HIGH);

    // 부저음 울리기
    tone(BUZZER_PIN, 1000, 500); // 1000Hz 소리 0.5초 울림

    // 서보모터 작동 (0도 → 90도)
    myServo.write(90);
    delay(1000);
    myServo.write(0);
    
    // LED 끄기
    digitalWrite(LED_PIN, LOW);

    delay(2000); // 태깅 후 대기 시간
  }
}
