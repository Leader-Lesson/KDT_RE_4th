//led1on3000 => led가 3초간 켜졌다 꺼지는 동작
#include<SoftwareSerial.h>
uint16_t cmd;
uint16_t arr[20] = {0,};
int i = 0;
bool led_flag = false;
#define BT_RXD 2
#define BT_TXD 3
int sum;
unsigned long current = 0;
SoftwareSerial hc06(BT_RXD, BT_TXD);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  hc06.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(hc06.available())
  {
    cmd = hc06.read();
    arr[i] = cmd;
    i++;
      if(i == 12 && arr[0]=='l'&&arr[1]=='e'&&arr[2]=='d'&&arr[3]=='1')
      {
        if(arr[4]=='o'&&arr[5]=='n')
        {
          Serial.println("LED ON");
          led_flag = true;
        } //led1off
        int s1 = arr[6] - 48;
        int s2 = arr[7] - 48;
        int s3 = arr[8] - 48;
        int s4 = arr[9] - 48;
        sum = (s1*1000) + (s2 * 100) + (s3 * 10) + (s4 * 1);
        Serial.println(sum);
        current = millis();
        i = 0;
      }
    if(i==9 && arr[4]=='o'&&arr[5]=='f'&&arr[5]=='f')
    {
      led_flag = false;
      Serial.println("LED OFF");
      i = 0;
    }
  }
  if(led_flag == true && millis() - current >= sum)
  {
    Serial.println("LED1_OFF");
    led_flag = false;
  }
}