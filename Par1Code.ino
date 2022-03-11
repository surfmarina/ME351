/*
4.2 in ME 351 Lab 1, Getting Started with Arduino
Setting up a logic gate such that the LED stays on when the switch is open, but off when you press the button. 
Basically a pull up resistor = 10k Ohm
*/
int LED = 7;
const int buttonPin = 2;
// variables will change:
int buttonState = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(LED, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(LED, HIGH);
    Serial.println("Button Not Pressed");
    delay(500); // add a delay for stability
  } else {
    // turn LED off:
    digitalWrite(LED, LOW);
    Serial.println("Button Pressed");
    delay(500); // add a delay for stability
  }
}
