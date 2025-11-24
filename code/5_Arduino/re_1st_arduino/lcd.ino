#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// LCD 설정 (0x27 또는 0x3F, 모델에 따라 다름)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// DHT 센서 설정
#define DHTPIN 2       // DHT 데이터 핀
#define DHTTYPE DHT11  // DHT11 사용 (DHT22 사용 시 변경)
DHT dht(DHTPIN, DHTTYPE);

const int ldrPin = A0; // 조도 센서 핀

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature(); // 온도 읽기 (℃)
  float humidity = dht.readHumidity();       // 습도 읽기 (%)
  int ldrValue = analogRead(ldrPin);         // 조도 값 (0~1023)

  // 센서 값이 유효한지 확인
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT 센서 오류!");
    lcd.setCursor(0, 0);
    lcd.print("DHT Sensor Err!");
  } else {
    // LCD 출력
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temperature);
    lcd.print("C H:");
    lcd.print(humidity);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("Light:");
    lcd.print(ldrValue);
  }

  Serial.print("Temp: "); Serial.print(temperature); Serial.print("°C ");
  Serial.print("Hum: "); Serial.print(humidity); Serial.print("% ");
  Serial.print("Light: "); Serial.println(ldrValue);

  delay(2000); // 2초마다 업데이트
}
