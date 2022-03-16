#include <dht.h> // library I uploaded externally for this sensor


// given three states for germination, ideal ranges of values
      int mintemp = 20;
      int maxtemp = 28;
      int minhumidity = 40;
      int maxhumidity = 70;
      
// these will be updated with sensor readings from the DHT11 module
      float temp = 0;
      float humidity = 0;
      
// DEFINE LED PINS FOR INDICATING HUMIDITY/ TEMP LEVELS
      int DRYLED = 8;
      int GOODLED = 9;
      int WETLED = 10;
      int GOODTEMP = 11;
      
// attach sensor
      dht DHT;
      
// Define pins connecting to the L293D
      const byte ENABLE_PIN = 5;
      const byte DIR_PIN_A = 3;
      const byte DIR_PIN_B = 4;
      int pinA0 = A0; // this is connected to DHT11 sensor

void setup(){
      Serial.begin(9600);
      Serial.println("These are the readings from DHT11: Humidity & Temperature");
      pinMode(ENABLE_PIN, OUTPUT);
      pinMode(DIR_PIN_A, OUTPUT);
      pinMode(DIR_PIN_B, OUTPUT); 
}
 
void loop(){
      // read temperature and humidity values every three seconds
      
      DHT.read11(pinA0);
      humidity = DHT.humidity;
      temp     = DHT.temperature;
  
      
                      // for filtering purposes 
                      delay(2000); // wait2 sec
                      DHT.read11(pinA0);
                      float temptwo = DHT.temperature;
                      volatile float changetemp = abs(temp - temptwo); 
                      int t = millis();
  
                      
      // print these values to the serial monitor
      Serial.print(temp);
      Serial.print(",");
      Serial.print(t);
      Serial.println();
      digitalWrite(DIR_PIN_A, HIGH);
      digitalWrite(DIR_PIN_B, LOW);   
       
      if ( changetemp < 2 ) {
      // only respond with controls if the humidity changes less than 2 % humidity over a 2 second sampling period. Removes sudden changes to system
      // This is the data conditioning
              if (humidity < minhumidity) {
                    // Serial.println("TOO DRY");
                    digitalWrite(DRYLED, HIGH);
                    digitalWrite(WETLED, LOW);
                    digitalWrite(GOODLED, LOW);
                    // turn motor on, set direction forwards. 0 speed when too dry
                    analogWrite(ENABLE_PIN, 0); 
                  } else if (humidity > maxhumidity) {
                    //Serial.println("TOO MOIST");
                    digitalWrite(DRYLED, LOW);
                    digitalWrite(WETLED, HIGH);
                    digitalWrite(GOODLED, LOW);
                    // turn motor on, set direction forwards
                    analogWrite(ENABLE_PIN, 255); //enable on
                  } else {
                    //Serial.println("Good Range");
                    digitalWrite(DRYLED, LOW);
                    digitalWrite(WETLED, LOW);
                    digitalWrite(GOODLED, HIGH);
                    // turn motor on, set direction forwards
                    analogWrite(ENABLE_PIN, 180); //enable on
                  }
              
                  // if the temp is in a good range, turn WHITE LED ON
                  if (temp > mintemp) {
                    if (temp < maxtemp) {
                      digitalWrite(GOODTEMP, HIGH);
                    } else{
                      digitalWrite(GOODTEMP, LOW);
                    }
                  }
                    
      } else {
      Serial.println("temp change is too drastic");    
}
