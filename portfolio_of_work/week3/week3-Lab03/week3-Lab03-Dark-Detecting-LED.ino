// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int LightPin = 2;

int Photo_Pin = A0;

int readPhoto;
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(LightPin, OUTPUT);
  
  pinMode(Photo_Pin, INPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  readPhoto = analogRead(Photo_Pin);
  Serial.println(readPhoto);

  if (readPhoto < 518) {
  digitalWrite(LightPin, HIGH);
  }else{
      digitalWrite(LightPin, LOW);
  }
  
  delay(1);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);               // wait for a second
}
