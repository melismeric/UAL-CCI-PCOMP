const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 9;        // pin that the LED is attached to
const int ledPin2 = 8; 
const int ledPin3 = 10; 


int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

const int WAITTIME = 20;
const int STEP = 5;

void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
      int i;

    i = 0;
    while ( i <= 255 ){
        analogWrite( ledPin, i );
        analogWrite( ledPin3, i );
        sensorValue = analogRead(sensorPin);
        delay( WAITTIME );
        i = i + STEP;
        analogWrite(ledPin2, sensorValue);

    }

    i = 255;
    while ( i >= 0 ){
        analogWrite( ledPin, i );
        analogWrite( ledPin3, i );
        delay( WAITTIME );
        i = i - STEP;
        analogWrite(ledPin2, sensorValue);
    }

     Serial.println(sensorValue);


  

  
}
  
