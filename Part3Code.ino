//int digPIN = 2;
int anaPIN = A0;

void setup() {
  Serial.begin(9600);
  //pinMode(digPIN, INPUT);
  pinMode(anaPIN, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  volatile float anasensorValue = analogRead(anaPIN);
  // strobe light at 3.9 Hz and 234 RPM
  delay(10);        // delay in between reads as 10 ms to not overload ourselves with data
  Serial.print(anasensorValue);
  Serial.println("");
  
}
