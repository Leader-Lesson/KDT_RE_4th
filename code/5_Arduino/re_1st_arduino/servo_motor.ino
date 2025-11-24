#include<Servo.h>
Servo servo;
int speed = 0;
bool flag = false;
char ch_arr[50] = {0,};
int i = 0;
void setup()
{
  Serial.begin(9600);
  servo.attach(6);
}
void loop()
{
  if(Serial.available())
  {
    char ch = Serial.read();
    if(ch == '\n')
    {
      ch_arr[i] = NULL;
      flag = true;
      i = 0;
    }else{
    if(i < 3){
      ch_arr[i] = ch;
      i++;
      Serial.println(i);
    }
    else{
      Serial.println("범위를 초과하였습니다.");
      i = 0;
    }
    }
  }
  if(flag)
  {
    speed = atoi(ch_arr);
    Serial.print("입력된 속도: ");
    Serial.println(speed);
    servo.write(speed);
    flag = false;
  }
}