void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int resistor = analogRead(A0);
  Serial.println(resistor);
  resistor = map(resistor, 0, 1023, 0, 255); // 입력값을 출력값으로 변경
  analogWrite(10, resistor);
  delay(100);
}
