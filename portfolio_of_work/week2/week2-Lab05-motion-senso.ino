#include <Adafruit_NeoPixel.h>

#define PIN            13
#define NUMPIXELS      24
int delayval = 50;
int currentColor = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int pirPin = 2;                 // PIR Out pin 
int pirStat = 0;                   // PIR status
void setup() {     
 pinMode(pirPin, INPUT);
 pixels.begin(); // This initializes the NeoPixel library.
 pixels.setBrightness(200); // 100/255 brightness (about 40%)
 pixels.show();             // Initialize all pixels to 'off'
 Serial.begin(9600);
}
void loop(){
  uint32_t red = pixels.Color(255, 0, 0); //red
  uint32_t orange = pixels.Color(255, 100, 10); //orange
  uint32_t yellow = pixels.Color(255, 255, 0); //yellow
  uint32_t green = pixels.Color(0, 255, 0);//green
  uint32_t dkgreen = pixels.Color(0, 115, 0);//dark green
  uint32_t cyan = pixels.Color(0, 255, 255); //cyan
  uint32_t blue = pixels.Color(0, 0, 255); //blue
  uint32_t magenta = pixels.Color(255, 0, 255); //magenta
  uint32_t purple = pixels.Color(50, 0, 50); //purple
  //put the colors in an array
  uint32_t colors [9] = {red, orange, yellow, green, dkgreen, cyan, blue, magenta, purple};
  pirStat = digitalRead(pirPin); 
  if (pirStat == HIGH) {            // if motion detected
	for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, colors[currentColor]);
      
      pixels.show();
      delay(delayval);
      currentColor++;
      if (currentColor >= 9) currentColor = 0;
    }	
  } 
  else {
    for( int i = 0; i<NUMPIXELS; i++){
        pixels.setPixelColor(i, red);
        pixels.show();
    }   
    //delay(1000);
  }
}