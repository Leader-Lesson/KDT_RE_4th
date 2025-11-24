int PIEZO = 13;
int SWITCH = 12;

void setup() {
  Serial.begin(9600);
  pinMode(PIEZO, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);
}

void loop() {
  int SW1 = digitalRead(SWITCH);
  digitalWrite(PIEZO, LOW);

  if (SW1 == LOW){
    Serial.println("Switch : PIEZO");
    digitalWrite(PIEZO, HIGH);
    delay(100);
  }
}
