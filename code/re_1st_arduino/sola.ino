//태양광 패널 or 리튬 폴리머 연결!
int led = 7;

void setup()
{
	Serial.begin(9600);
	pinMode(led, OUTPUT);
}

void loop()
{
	digitalWrite(led, HIGH);
	delay(1000);
	digitalWrite(led, LOW);
	delay(1000);
}