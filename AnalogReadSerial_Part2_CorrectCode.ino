/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
int digPIN = 2;
int anaPIN = A0;
unsigned long myTime;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(digPIN, INPUT);
  pinMode(anaPIN, INPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  float anasensorValue = analogRead(anaPIN);
  int digsensorValue = digitalRead(digPIN);

  // each unit returned by analogRead() is valued at 0.00488 V
  // int scale = 5/1023;
  anasensorValue = (anasensorValue * 5 / 1023) ; 
  
  myTime = millis();
  // print out the value you read:
  // Serial.println(anasensorValue);
  delay(1);        // delay in between reads for stability
  // Print the time, analog value, and digital value on one line
  // 5 / 1023
  Serial.print(myTime);
  Serial.print(",");
  Serial.print(anasensorValue);
  Serial.print(",");
  Serial.print(digsensorValue);
  Serial.println(" ");
  delay(500);

}
