#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  delay(2000); // 측정 대기 시간

  float h = dht.readHumidity();        // 습도
  float c = dht.readTemperature();     // 온도 (°C)
  float f = dht.readTemperature(true); // 화씨(℉)

  if (isnan(h) || isnan(c) || isnan(f))
  { // 측정 실패 시 값을 무시하는 코드
    Serial.println("Fail to read form DHT sensor");
    return;
  }

  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temp: ");
  Serial.print(c);
  Serial.print("°C / ");
  Serial.print(f);
  Serial.println("℉");
}