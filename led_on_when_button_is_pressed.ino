const int LED = 12;

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

}

void loop(){
digitalWrite(LED, HIGH);
delay(1000);
digitalWrite(LED, LOW);

}
