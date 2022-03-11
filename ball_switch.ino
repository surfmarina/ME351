// Derived from example code provided by www.elegoo.com

// Define pins
const byte LED_PIN = LED_BUILTIN; // LED_BUILTIN = 13 on the Uno
const byte SENSOR_PIN = 2;
int state = 0;
int Step = 0;

void setup() {
  // Set up pins
  pinMode(LED_PIN, OUTPUT);//initialize the ledPin as an output
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  state = digitalRead(SENSOR_PIN);
  // Check the sensor state and act accordingly
  if (state == HIGH) {
    // Disconnected; turn the LED off
    // digitalWrite(LED_PIN, HIGH);
    // Everytime the tilt ball sensor goes HIGH, count it as a step
    Step = Step + 1;
    
  } else {
    // Connected; turn the LED on
    // digitalWrite(LED_PIN, LOW);
  }
    Serial.print(state);
    Serial.print(",");
    Serial.print(Step);
    Serial.println(" ");
    delay(300); // so we aren't overloading
}
