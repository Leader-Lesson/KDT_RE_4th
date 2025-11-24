int Switch1= 12;
int Switch2= 11;
int GreenPIN = 4;
int RedPIN = 3;

void setup() {
   Serial.begin(9600);
   pinMode(Switch1, INPUT_PULLUP);
   pinMode(Switch2, INPUT_PULLUP);
   pinMode(GreenPIN , OUTPUT);
   pinMode(RedPIN , OUTPUT);
}

void loop() 
{
  int SW1 = digitalRead(Switch1);
  int SW2 = digitalRead(Switch2);
  digitalWrite(GreenPIN, LOW); 
  digitalWrite(RedPIN, LOW); 

  if(SW1 == LOW){
    Serial.print("Switch : ");
    Serial.println("GREEN");
    digitalWrite(GreenPIN, HIGH); 
  }
  if(SW2 == LOW){
    Serial.print("Switch : ");
    Serial.println("RED");
    digitalWrite(RedPIN, HIGH); 
  }
  delay(10);
}
