int data;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  while (Serial.available()) { // 데이터가 수신된 게 있는지 계속 검사 진행
    data = Serial.read();
  }

  if (data == '1') {
    digitalWrite(13, HIGH);
  } else if (data == '0') {
    digitalWrite(13, LOW);
  }
}
