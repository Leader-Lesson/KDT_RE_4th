char melody[] = "3232321111312111";
int spk = 4;
void setup(){
  Serial.begin(115200);
  pinMode(spk, OUTPUT);
}
void loop(){
  for(int i = 0; i < sizeof(melody)/sizeof(melody[0])-1; i++)
  {
    char t = melody[i];
    switch(t)
    {
      case '1':
        t = 1046;
      break;
      case '2':
        t = 1174;
      break;
      case '3':
        t = 1318;
      break;
      default:
        t = 0;
    }
    tone(spk, t);
    delay(500);
    noTone(spk);
    delay(100);
  }
}