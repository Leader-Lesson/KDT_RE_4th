const int melody[] = {
  // 도, 레, 미, 파, 솔, 라, 시, 도
  262, 294, 330, 349, 392, 440, 494, 523
}
const int PIEZO_PIN = 8;

void setup() {
  // '도레미파솔라시도'를 순서대로 출력
  // 음의 길이가 500ms, 간격이 500ms가 되도록 지연 시간 추가
  tone(PIEZO_PIN, melody[0], 500); delay(500);
  tone(PIEZO_PIN, melody[1], 500); delay(500);
  tone(PIEZO_PIN, melody[2], 500); delay(500);
  tone(PIEZO_PIN, melody[3], 500); delay(500);
  tone(PIEZO_PIN, melody[4], 500); delay(500);
  tone(PIEZO_PIN, melody[5], 500); delay(500);
  tone(PIEZO_PIN, melody[6], 500); delay(500);
  tone(PIEZO_PIN, melody[7], 500); delay(500);
}

void loop() {
}
