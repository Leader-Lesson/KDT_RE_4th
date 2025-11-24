#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(10);
}

void loop() {
  for (int angle=0; angle<=180; angle++) {
    servo.write(angle);
    Serial.print("angle : ");
    Serial.print(angle);
    Serial.println("");
    delay(100);
  }
}
