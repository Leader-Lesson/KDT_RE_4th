// #include <SPI.h>
// #include <Adafruit_Sensor.h>
// #include <Adafruit_BMP280.h>  // ← BME280이면 위 라이브러리/객체만 BME로 바꾸기

// #define PIN_SCK  13   // SCL
// #define PIN_MOSI 11   // SDA
// #define PIN_CS   10   // CSB
// #define PIN_MISO 12   // SDO

// Adafruit_BMP280 bmp(PIN_CS, PIN_MOSI, PIN_MISO, PIN_SCK);

// void setup() {
//   Serial.begin(9600);
//   if (!bmp.begin()) {
//     Serial.println(F("BMP280 인식 실패"));
//     while (1);
//   }
// }

// void loop() {
//   Serial.println("======================");
//   Serial.print("온도 = "); Serial.print(bmp.readTemperature()); Serial.println(" °C");
//   Serial.print("기압 = "); Serial.print(bmp.readPressure());    Serial.println(" Pa");
//   Serial.print("고도 = "); Serial.print(bmp.readAltitude(1013.25)); Serial.println(" m");
//   delay(1000);
// }


/*
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_CS   10  // CSB
#define BMP_MOSI 11  // SDI
#define BMP_MISO 12  // SDO
#define BMP_SCK  13  // SCK

Adafruit_BMP280 bmp(BMP_CS);

void setup() {
  Serial.begin(9600);

  if(!bmp.begin()) {
    Serial.println(F("센서가 인식되지 않습니다. 연결 상태를 확인해주세요."));
    while(1);
  }
}

void loop() {
  delay(100);
  Serial.println("======================");

  Serial.print(F("온도 = "));
  Serial.print(bmp.readTemperature()); // 온도 측정
  Serial.print("°C");

  Serial.print(F("기압 = "));
  Serial.print(bmp.readPressure()); // 기압 측정
  Serial.print("°C");

  Serial.print(F("고도 = "));
  Serial.print(bmp.readAltitude(1022.5)); // 고도 측정
  Serial.print("°C");

  delay(1000);
}
*/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_BMP280.h>

Adafruit_BME280 bme;
Adafruit_BMP280 bmp;
bool isBME = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // 주소 0x76 -> 0x77 순으로 시도
  if (bme.begin(0x76) || (isBME = bme.begin(0x77))) {
    isBME = true;
    Serial.println("Detected: BME280 (I2C)");
  } else if (bmp.begin(0x76) || bmp.begin(0x77)) {
    Serial.println("Detected: BMP280 (I2C)");
  } else {
    Serial.println("센서 인식 실패 (배선/전원/주소 확인)");
    while (1);
  }
}

void loop() {
  if (isBME) {
    Serial.print("T = "); Serial.print(bme.readTemperature()); Serial.println(" °C");
    Serial.print("P = "); Serial.print(bme.readPressure()/100.0); Serial.println(" hPa");
    Serial.print("H = "); Serial.print(bme.readHumidity()); Serial.println(" %");
  } else {
    Serial.print("T = "); Serial.print(bmp.readTemperature()); Serial.println(" °C");
    Serial.print("P = "); Serial.print(bmp.readPressure()/100.0); Serial.println(" hPa");
  }
  Serial.println();
  delay(1000);
}
