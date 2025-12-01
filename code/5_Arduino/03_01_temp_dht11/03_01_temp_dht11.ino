#include "DHT.h"
#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  delay(2000);
  float h = dht.readHumidity();        // 습도
  float c = dht.readTemperature();     // 온도(섭씨)
  float f = dht.readTemperature(true); // 온도(화씨)

  if (isnan(h) || isnan(c) || isnan(f))
  { // 측정 실패 시 값을 무시하는 코드
    Serial.println("Fail to read form DHT sensor");
    return;
  }

  Serial.print("Humidity: "); // 측정된 온습도 값을 시리얼 모니터에 출력
  Serial.print(h);
  Serial.print("% Temperature: ");
  Serial.print(c);
  Serial.print("°C ");
  Serial.print(h);
  Serial.println("°F");
}