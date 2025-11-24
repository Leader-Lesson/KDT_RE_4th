void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int photoresistor = analogRead(A0);
  Serial.println(photoresistor);

  if (photoresistor > 500)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
}
