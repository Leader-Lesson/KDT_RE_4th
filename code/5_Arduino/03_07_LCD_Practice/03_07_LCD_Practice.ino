#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;
int angle = 0;

void setup() {
  servo.attach(8);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int val = analogRead(A0);
  angle = map(val, 0, 1023, 0, 180);

  servo.write(angle);

  lcd.setCursor(2,0);
  lcd.print("Servo Motor");
  lcd.setCursor(6,1);
  lcd.print(angle);
  delay(100);

  lcd.clear();
}
