int RED_LED = 12;
int GREEN_LED = 11;
int BLUE_LED = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED_LED, HIGH);
  delay(500);
  digitalWrite(GREEN_LED, HIGH);
  delay(500);
  digitalWrite(BLUE_LED, HIGH);
  delay(500);
  digitalWrite(RED_LED, LOW);
  delay(500);
  digitalWrite(GREEN_LED, LOW);
  delay(500);
  digitalWrite(BLUE_LED, LOW);
  delay(500);
}
