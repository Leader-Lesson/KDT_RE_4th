int ledPin = 3;
int brightness = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(brightness = 0; brightness < 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(10);
    Serial.println(brightness);
  }
}
