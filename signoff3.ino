
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte LED_PIN = LED_BUILTIN; // LED_BUILTIN = 13 on the 

const byte SENSOR_PIN = 7; // this is our interrupt pin for the tilt sensor
int state = 0;
int Step = 0;
int previousState = 0;
volatile float time = 0;
volatile float timediff = 0;


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("HI");
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  Serial.begin(9600); // for debugging purposes
}

void loop() {
  time = millis();
  state = digitalRead(SENSOR_PIN);
  Serial.println(state);
  if (state == HIGH) {
      // debouncing code
      timediff = (millis() - time);
      if (timediff > 3) 
        Step = Step + 1;
  }
  else {
  }
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(Step);
  

}






  
