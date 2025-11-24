#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <LiquidCrystal_I2C.h>

// BMP280 센서 객체 생성 (SPI 모드 사용)
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10

Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);

// I2C LCD 객체 생성 (0x27 주소, 16x2 LCD)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();

  if (!bmp.begin()) {
    Serial.println("BMP280 센서를 찾을 수 없습니다!");
    lcd.setCursor(0, 0);
    lcd.print("BMP280 Error!");
    while (1);
  }

  lcd.setCursor(0, 0);
  lcd.print("Altitude Display");
}

void loop() {
  float altitude = bmp.readAltitude(1013.25); // 해수면 기압 기준 (hPa)
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Altitude: ");
  lcd.print(altitude);
  lcd.print("m");

  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println(" m");

  delay(2000); // 2초마다 업데이트
}
