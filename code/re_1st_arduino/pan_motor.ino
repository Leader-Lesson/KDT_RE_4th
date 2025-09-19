int pan = 3;
int ina = 8;
int inb = 9;
int btn1 = 4;
int btn2 = 5;
int btn3 = 6;
int btn4 = 7;
int btn1_last = 1;
int btn2_last = 1;
int btn3_last = 1;
int btn4_last = 1;
int work = 0;
bool on_off = false;
void setup()
{
  Serial.begin(9600);
  pinMode(pan, OUTPUT);
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
}
void loop()
{
  int btn1_state = digitalRead(btn1);
  int btn2_state = digitalRead(btn2);
  int btn3_state = digitalRead(btn3);
  int btn4_state = digitalRead(btn4);
  if(btn1_state == 0 && btn1_last==1)
  {
    on_off = !on_off;
    if(on_off)
    {
      Serial.println("ON!");
      work = 1;
    }
    else
    {
      Serial.println("OFF!");
      work = 0;
    }
  }
  btn1_last = btn1_state;
  if(btn2_state == 0 && btn2_last==1)
  {
    work = 2;
  }
  btn2_last = btn2_state;
  if(btn3_state == 0 && btn3_last==1)
  {
    work = 3;
  }
  btn3_last = btn3_state;
  if(work==0){
    analogWrite(pan, 0);
    digitalWrite(ina, LOW);
    digitalWrite(inb, LOW);
    Serial.println("MOTOR OFF!");
  }else if(work==1)
  {
    analogWrite(pan, 200);
    digitalWrite(ina, HIGH);
    digitalWrite(inb, LOW);
    Serial.println("MOTOR ON!");
  }else if(work==2)
  {
    analogWrite(pan, 150);
    digitalWrite(ina, HIGH);
    digitalWrite(inb, LOW);
    Serial.println("MOTOR STEP1!");
  }
  else if(work==3)
  {
    analogWrite(pan, 200);
    digitalWrite(ina, HIGH);
    digitalWrite(inb, LOW);
    Serial.println("MOTOR STEP2!");
  }
}