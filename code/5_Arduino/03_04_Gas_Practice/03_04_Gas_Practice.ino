#define GAS_A A0
#define GAS_D 8
#define PIEZO 12
#define LED 13

void setup() {
  pinMode(PIEZO, OUTPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600); 
  Serial.println("히터 가열");
  delay(1000); 
}

void loop() {
  digitalWrite(PIEZO, LOW);
  digitalWrite(LED, LOW);

  float sensorValue = analogRead(GAS_A); 
  float sensorDValue = digitalRead(GAS_D);
  
  Serial.print("센서입력: ");
  Serial.print(sensorValue);

  if(sensorValue > 300) {
    Serial.print(" |연기감지!");
    Serial.println("");
    digitalWrite(PIEZO, HIGH);
    digitalWrite(LED, HIGH);
  }
  
  Serial.print("센서 디지털: ");
  Serial.print(sensorDValue);
  Serial.println("");

  delay(1000);
}