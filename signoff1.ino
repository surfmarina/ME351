// Derived from example code provided by www.elegoo.com

// Define pins connecting to the L293D
const byte ENABLE_PIN = 5;
const byte DIR_PIN_A = 3;
const byte DIR_PIN_B = 4;
int anaPIN = A0;

void setup() {
  // Set up pins as outputs for controlling the motor
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(DIR_PIN_A, OUTPUT);
  pinMode(DIR_PIN_B, OUTPUT);
  Serial.begin(9600);
  pinMode(anaPIN, INPUT); // this is our photocell

}

void loop() {
  // read the input on analog pin 0:
  volatile float anasensorValue = analogRead(anaPIN);
  delay(10);        // delay in between reads as 10 ms to not overload ourselves with data
  int adjustedspeed = anasensorValue/255 + 150;

  Serial.println(adjustedspeed);
  // Set motor direction forwards
  digitalWrite(DIR_PIN_A, HIGH);
  digitalWrite(DIR_PIN_B, LOW);
  analogWrite(ENABLE_PIN, anasensorValue); //enable on

}
