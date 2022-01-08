const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 9;        // pin that the LED is attached to
const int ledPin2 = 8; 
const int ledPin3 = 10; 


int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);

  // signal the end of the calibration period
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // read the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  analogWrite(ledPin, sensorValue);
  delay(1000);
 
  if ( 30 <= sensorValue <= 140) { //one led is on
    analogWrite(ledPin2, sensorValue);
    analogWrite(ledPin3, sensorValue);
  }

   if (sensorValue <= 10) { //one led is on
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
  }

  
}
  
