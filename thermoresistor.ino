// Marina Keller. Thermoresistor lab 2 ME 351
int anaPIN = A0;
int Vin = 5;
int R2 = 10000;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(anaPIN, INPUT);
}

void loop() {
  float anasensorValue = analogRead(anaPIN);
  
  // convert from the raw value to volts
  float Vout = (5*anasensorValue/1023);
  
  // determine the resistance of the thermistor from the voltage (thermistor and resistor in a voltage divider pattern)
  float R1 = (R2*(Vin/Vout - 1));
  
  // convert resistance to temperature using Steinhart-Hart equ'n
  float tempC = (1 / (0.001129148 + 0.000234125 * log(R1) + 0.0000000876741 * pow(log(R1), 3))) - 273.15;

  // Record the temperature in Celsius with timestamps
  Serial.print(millis());
  Serial.print(",");
  Serial.print(tempC);
  Serial.println("");
  
  delay(500); // delay 500 ms so we aren't overloaded with readings
  
  
}
