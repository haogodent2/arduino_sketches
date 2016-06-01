int PIN_NUM = 3;
void setup(){
		pinMode(PIN_NUM, OUTPUT);
}

void loop(){
	digitalWrite(PIN_NUM, HIGH);
	delay(1000);
	digitalWrite(PIN_NUM, LOW);
	delay(1000);
}