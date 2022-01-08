int redPin = 11; // red pin is connected to 11
int greenPin = 10; // green pin is connected to 10
int bluePin = 9; // blue pin is connected to 9

const int sensorPin = A0;
const int sensorPin2 = A1;
const int sensorPin3 = A2;

void setup() {
 pinMode(redPin, OUTPUT); // set all three pins as outputs
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
}
void loop() {
 int sensorValue = analogRead(sensorPin);
 int sensorValue2 = analogRead(sensorPin2);
 int sensorValue3 = analogRead(sensorPin3);
  
 setColor(sensorValue, sensorValue2, sensorValue3); 
}
void setColor(int red, int green, int blue) {
 // set the three pins:
 analogWrite(redPin, red); // brightness of redPin
 analogWrite(greenPin, green); // brightness of greenPin
 analogWrite(bluePin, blue); // brightness of bluePin
}