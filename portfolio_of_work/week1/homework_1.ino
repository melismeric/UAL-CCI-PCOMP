const int BUTTON = 3;
const int redLed = 13;
const int yellowLed = 12;
const int blueLed = 11;
int BUTTONstate = 0;

int count_value =0;
int prestate =0;

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  BUTTONstate = digitalRead(BUTTON);

  if (BUTTONstate == HIGH  && prestate == 0)
  {
    count_value++;
    Serial.println(count_value);
    
    if (count_value == 1) {
      digitalWrite(redLed, HIGH);
      digitalWrite(yellowLed, LOW);
      digitalWrite(blueLed, LOW);
      delay(500);
      prestate = 1;
    } else if (count_value == 2) {
      digitalWrite(yellowLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(blueLed, LOW);
      delay(500);
      prestate = 1;
    }
    else if (count_value == 3) {
      digitalWrite(blueLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, LOW);
      delay(500);
      count_value = 0;
      prestate = 1;
    }
    
  } 
  else{
    prestate = 0;
  }
}