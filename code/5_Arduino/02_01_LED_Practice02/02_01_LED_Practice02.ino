// for 문
int leds[] = {12, 11, 10};
int count = 3;

void setup()
{
  for (int i = 0; i < count; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i < count; i++)
  {
    digitalWrite(leds[i], HIGH);
    delay(500);
  }

  for (int i = 0; i < count; i++)
  {
    digitalWrite(leds[i], LOW);
    delay(500);
  }
}

// 함수화
int leds[] = {12, 11, 10};
int count = 3;

void turnOnAll()
{
  for (int i = 0; i < count; i++)
  {
    digitalWrite(leds[i], HIGH);
    delay(500);
  }
}

void turnOffAll()
{
  for (int i = 0; i < count; i++)
  {
    digitalWrite(leds[i], LOW);
    delay(500);
  }
}

void setup()
{
  for (int i = 0; i < count; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  turnOnAll();
  turnOffAll();
}