#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   9
#define SS_PIN    10

MFRC522 mfrc(SS_PIN, RST_PIN); 

int LED_B = 3;
int LED_R = 4;
int PIEZO = 6;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  
  pinMode(LED_B, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(PIEZO, OUTPUT);
}

void loop() {
  if ( !mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial() ) {
    delay(500);        
    return;
  }

  // 특정 UUID에 해당하는 흰 카드
  if(mfrc.uid.uidByte[0] == 33 && mfrc.uid.uidByte[1] == 32 
       && mfrc.uid.uidByte[2] == 26 && mfrc.uid.uidByte[3] == 2) {
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_R, LOW);
    Serial.println("Hello, Blue LED Pin!");
    digitalWrite(PIEZO, HIGH);
    delay(300);
    digitalWrite(PIEZO, LOW);
    digitalWrite(LED_B, LOW);
    
  } else { // 다른 태그일 경우, 빨간색 LED와 부저 2번
    digitalWrite(LED_R, HIGH); 
    digitalWrite(LED_B, LOW);
    Serial.println("Error!");
    digitalWrite(PIEZO, HIGH); 
    delay(300);
    digitalWrite(PIEZO, LOW);
    delay(200);
    digitalWrite(PIEZO, HIGH);
    delay(500);
    digitalWrite(PIEZO, LOW);
    digitalWrite(LED_R, LOW); 
  }  
}