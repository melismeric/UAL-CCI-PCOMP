## Project Blog

### Week 5 - Final Project Proposals
Project Idea ([PDF](https://git.arts.ac.uk/21004071/portfolio_of_work/blob/master/week4/Pcomp%20Final%20Project%20Proposal.pdf)):
</br>
The project aims to explore our senses and create an output expressing them.  It aims for the user to create a visual and auditory output using water as a tool.

It consists of an Arduino Leonardo board, a Capacitive touch sensor, sound sensor, LEDs, and a speaker. Capacitive touch sensor will take analog inputs from the water. When user touches the water the changing values will create sound. I am planing to use the tone() library of Arduino to create sounds. Different touches will create different sounds, for example one finger inside the water will create a lower frequency sound  than two fingers. I will use a speaker for the sound output.  Sound sensor will take  inputs from the sound (volume or counting beats) and adjust the colors according to the sound. LED strip will also take water touches as an input. Two fingers in the water will light up more LEDs than one finger. 

Users will interact with the water to create visual and audible effects. More than one person touching the water will create a different effect than one person touching it. Or if the user holds hands with another person and touch the water the value will also change, which will affect the outputs.

#### INPUTS:
Touch the water. 
Input will be taken   using a Capacitive touch sensor
Sound 
Values will be taken using a sound sensor and will be inputs for the LEDs.

#### OUTPUTS:
 LEDs: 
Water touch as input for the number of LEDs turned on 
Sound as input for the color of the LEDs
 Sound: 
Different touches to water will create different sounds.!


#### Prototype: 


![water-test](https://git.arts.ac.uk/storage/user/227/files/1c55f000-461e-11ec-88a9-b8eecc22e266)

![mpr121-test-values](https://git.arts.ac.uk/storage/user/227/files/152ee200-461e-11ec-9ade-f3bac969acb8)

### Week 5 - Change of ideas: DIY Capacative Sensor

After discussing my project in the class, I decided using a Capacitive Touch Sensor MPR121 would be an overkill. Rather than using it I can build one using resistors, a conductive bowl for the water. Hence I continued the project without using the MPR121 and built a capacitive touch sensor using 10 MOhm resistor and three jumper cables. When a conductive surface is connected or touched to the free end of the jumper cable it can be used as a touch sensor.

How does it work?
A capacitive touch sensor works in the same way as a capacitor. The sensor itself is only a conductive surface and will start working as a capacitor by the closeness of any other conductive surface, for example by skin, metal, water, etc.

When making a capacitive sensor with Arduino will have an output that transmits a pulse, and an input that receives the pulse and compares it to the transmitted pulse. When you put your finger on or near the sensor it creates a delay in the pulse. Using the CapSense library the delay is recalculated and a new value is generated which is used as the touch sensor value.

<img width="400" alt="Screen Shot 2021-11-29 at 19 27 42" src="https://git.arts.ac.uk/storage/user/227/files/712f5580-514a-11ec-8d63-a77030689ff8">

### Week 6 - First attempt with LEDs and Adding Potentiometer
After making the capacitive touch sensor, I connected it with a metal bowl to put water in it. I also added the LED strip to visualize the values of the touch sensor. However the values from the sensor were changing so rapidly that was hard to visualize. Hence after some research I constructed my code to smooth the values. To smooth the erratic values we need to sequentially store average of the specific number of readings from the sensor into arrays one by one.

In my project I used a potentiometer to decide a maximum value to map the average sensor readings to decide the number of LEDs to turn on. Using potetiometer we ca decide the sensitivity of the LED strip. If the potentiometer value increases it will be easier to turn on more lights.

Details of the code so far:
* Capacitive touch sensor reading are smoothed by 50 readings. The average value is mapped according to the potentiometer reading and this will decide the number of the LEDs to turn on.
```
 long total1 = cs_3_2.capacitiveSensor(30); // Capacitive touch sensor reading
 int top = analogRead(sensorPin1); // Potentiometer reading
 int topmap = map(top, 0, 1023, 50, 200); //Potentiometer is mapped according to the minimum and maximum capacitive touch sensor readings
  
 total = total - readings[index]; // subtract the last reading:
 readings[index] = total1; // value from the sensor:
 total = total + readings[index]; // add the new reading to the total:
 index = index + 1; // advance to the next position in the array:

  // if we're at the end of the array...
  if (index >= numReadings) { //numReadings is 50 in this case
    // ...wrap around to the beginning:
    index = 0;
  }

  average = total / numReadings; // calculate the average:
  
  int sensorReading = average;
  int ledLevel = map(sensorReading, 0, topmap, 0, NUM_LEDS); // map the average touch sensor reading for the LED strip
  
    for (int thisLed = 0; thisLed < NUM_LEDS; thisLed++) {

    if (thisLed < ledLevel) { // turn off the LEDs until the thisLed position
      strand.clear();
    }

    else {
      strand.setPixelColor(thisLed, 10,255, 0); // turn the LED on the thisLED position
      strand.show();
    }
  }

```
<img width="400" alt="Screen Shot 2021-11-15 at 14 30 17" src="https://git.arts.ac.uk/storage/user/227/files/91c2c000-4620-11ec-8b1d-5c943183b9c6">
<img width="400" alt="Screen Shot 2021-11-29 at 21 03 50" src="https://git.arts.ac.uk/storage/user/227/files/dccbef80-5157-11ec-8985-ecdf34f99fa0">

#### Before smoothing the values, it was harder to increase the number of LEDs turning on.

<img src="https://git.arts.ac.uk/storage/user/227/files/44ce0600-5157-11ec-9b9c-8db5b8cacddc" width="250" height="250"/>
 
#### After smoothing the values and adding a potentiometer it was easier to turning the LEDs on.

<img src="https://git.arts.ac.uk/storage/user/227/files/2830ce80-5155-11ec-891a-20a7a697c860" width="250" height="250"/>
<img src="https://git.arts.ac.uk/storage/user/227/files/87dba980-5156-11ec-8b54-e70710019f96" width="250" height="250"/>

### Week 7 - Analog Synth

* Playing with the sound - Can I make a synthesizer with water?
* Adding anolog synthesizer to make sound
* Improving LEDs

This week I started trying to make sound using water touch. My plan was to use a sound sensor to get the sound as an input and change the colors of the LED accordingly. First I tried using touch sensor values in the tone() function of Arduino. However it didn't produce the sounds I wanted. Hence I decided to build an analog synthesizer using a CD40106BE chip, a capacitor, and speakers. I connected the chip to the metal bowl to control the pitch. 

How does analog synthesizer work?
Analog synthesizers generate sounds by manipulating electric voltages. The oscillator shapes the voltage to produce a pitch at a given frequency, which constructs the waveform. The oscillator can be controlled by a tool on the synthesizer's interface (a touch sensor in our case). The sound passes to the amplifier, which controls the volume of the sound. 

To build an analog synthesizer I used this circuit. I tried the circuit with multiple capacitors to find the one that makes the pitch I wanted. In the end I decided to use a 10nF capacitor. There should be two conductive surfaces to create a sound. When we touch both of them we provide the flow of electricity. Hence I connected one cable to the metal bowl and the other to a conductive tape. The volume of pressure on the conductive tape changes the pitch of sound. I put water in the metal bowl and added salt to increase the conductivity. Then I tried to touch water while holding the other conductive surface and my interaction with them created sound.
![melo 2](https://git.arts.ac.uk/storage/user/227/files/33d9c080-5168-11ec-9b31-b4a53ffa0316)

Then I added a sound detecor to get the sound I produce and change the colors of the LED strip accordingly.
![melo](https://git.arts.ac.uk/storage/user/227/files/65528c00-5168-11ec-878d-c15339957b79)

#### Code Refactor
I added the sound sensor to the code to change the colors according to the sound detector readings. I pre-determined the sensor reading thresholds and decided the colors. For example higher values will make the color azure and cyan while lower values will make the color orange or red.

```
filteredSignalValues[] = {3.4, 3.1, 2.7, 2.4, 2.1, 1.7, 1.3, 0.9, 0.4}; // pre-determined sound sensor reading thresholds
volume = (float) analogRead(AUDIO_PIN) * (5.0 / 1024.0); //normalize the reading
FilterSignal(volume);
void FilterSignal(float sensorSignal) {
  filteredSignal = (0.945 * filteredSignal) + (0.0549 * sensorSignal);
}

void CompareSignalFiltered(int thisLed, float filteredSignal) { // change the color
  if (filteredSignal > filteredSignalValues[0]) {
    RGBColor(thisLed, 0, 0, 255);
    //Blue
  } else if (filteredSignal <= filteredSignalValues[0] && filteredSignal > filteredSignalValues[1]) { // high volumes
    //Azure
    RGBColor(thisLed, 0, 255, 255);
  } else if (filteredSignal <= filteredSignalValues[1] && filteredSignal > filteredSignalValues[2]) {
    RGBColor(thisLed, 0, 127, 255);
    //Cyan
  } else if (filteredSignal <= filteredSignalValues[2] && filteredSignal > filteredSignalValues[3]) {
    RGBColor(thisLed, 0, 255, 127);
    //Aqua marine
  } else if (filteredSignal <= filteredSignalValues[3] && filteredSignal > filteredSignalValues[4]) {
    RGBColor(thisLed, 0, 255, 0);
    //Green
  } else if (filteredSignal <= filteredSignalValues[4] && filteredSignal > filteredSignalValues[5]) {
    RGBColor(thisLed, 255, 255, 0);
    //Yellow
  } else if (filteredSignal <= filteredSignalValues[5] && filteredSignal > filteredSignalValues[6]) {
    RGBColor(thisLed, 255, 0, 255);
    //Magenta
  } else if (filteredSignal <= filteredSignalValues[6] && filteredSignal > filteredSignalValues[7]) {
    RGBColor(thisLed, 255, 0, 127);
    //Rose
  } else if (filteredSignal <= filteredSignalValues[7] && filteredSignal > filteredSignalValues[8]) { // low volumes
    RGBColor(thisLed, 255, 127, 0);
    //Orange
  } else if (filteredSignal <= filteredSignalValues[8]) {
    RGBColor(thisLed, 255, 0, 0);
    //Red
  } else {
    RGBColor(thisLed, 0, 0, 255);
    //Default: Blue
  }
}

void RGBColor(int thisLed, int Rcolor, int Gcolor, int Bcolor) {
  strand.setPixelColor(thisLed, Rcolor, Gcolor, Bcolor);
  strand.show();
} 
```
#### Feedback system
In the project, the sound is both an input and output, which makes the circuit a feedback system. By touching the water and the conductive surface we create sound. The pressure we make while holding the conductive surface changes the sound. The sound detector takes the sound and changes the color of LEDs accordingly. This makes sound input for the color of the LEDs. Also by touching the water we increase the number of LEDs turning on which makes the water touch an input and LEDs an output. The potentiometer is connected as an analog input to the circuit, we use it to change. the sensitivity of the LED strip. Higher values make it easier to turn on more LEDs.

Here are the videos of the process:
* Analog synthesizer first attempt: https://youtu.be/ThC20oKnXEQ
* Analog synthesizer with water: https://youtu.be/TMhhVPLtGmc
* Combining and testing LED strip and audio parts: https://youtu.be/VtEv0UP5T0E

### Week 8
* Soldering the LED strip part 
* Code refactor

This week I soldered the LED strip part of the circuit.
<img src="https://git.arts.ac.uk/storage/user/227/files/b19ecb80-516a-11ec-9a48-eb4586053157" width="250" height="250"/>
<img src="https://git.arts.ac.uk/storage/user/227/files/b499bc00-516a-11ec-8174-c97e00842882" width="250" height="250"/>

### Week 9
* Soldering the synthesizer part 
* Housing

This week firstly, I soldered the analog synth part of the project.
</br>

<img width="300" alt="Screen Shot 2021-11-29 at 23 28 13" src="https://git.arts.ac.uk/storage/user/227/files/0b53c580-516c-11ec-8af8-1737c35bfdaf">
<img width="300" alt="Screen Shot 2021-11-29 at 23 28 43" src="https://git.arts.ac.uk/storage/user/227/files/1ad30e80-516c-11ec-955b-7a04f732aa62">

Then I made the housing for the project to finalize it.
</br>
<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/3ee31f80-516d-11ec-9771-78f017f7123a">
<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/41457980-516d-11ec-9c62-2146a1521db1">
<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/430f3d00-516d-11ec-8ab4-f2def51d980d">
<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/44d90080-516d-11ec-8fa9-53a4613d0ab5">
<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/46a2c400-516d-11ec-80eb-bad5bfbdc387">
<img width="300" src="(https://git.arts.ac.uk/storage/user/227/files/486c8780-516d-11ec-85d2-214ead88eb8c">

<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/4efaff00-516d-11ec-991f-4d80e2846422">
<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/515d5900-516d-11ec-80aa-d9e787ab53c3">
<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/53271c80-516d-11ec-84c2-20d03beb09c5">

<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/57ebd080-516d-11ec-925a-beee69aa57ab">
<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/60440b80-516d-11ec-82af-14279986cc0b">
<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/6d60fa80-516d-11ec-9770-dea3b3498ec9">

### Final 

In conclusion I built a mixer and sound visualizer set that works with touching water. I built a set using two metal bowls, a LED strip, and speakers. Inside the bowls, I put salty water to increase the conductivity. When someone touches the water in one bowl it increases the number of LEDs turning on. According to the electrical charge of that person the number of LEDs turning on changes. Also if multiple people touch the water they have a chance to turn up more LEDs than one person. Using the potentiometer the sensitivity of the LEDs can be changed. If a person touches the water in the other bowl and also touches the conductive surface near it, it activates the analog synthesizer and creates sound. The sound changes according to the electrical charge of the person touching it and their interaction with water. If someone else touches that person or water it creates a different sound. 

Equipments:
* Two metal bowls
* Speakers
* One potentiometer 
* LED strip
* Arduino Leonardo
* Resistors (220 ohm, 10M ohm)
* Sound Detector
* Conductive tape
* 9V battery
* 10nF capacitor
* Cardboard

Inputs:
* Sound
* Water touch
* Potentiometer (analog input to change sensitivity of LED strip)

Outputs:
* LED strip
* Sound

[Video](https://youtu.be/l-3fNC-Wu9g)

### Future Work

Next I want to add a phototransistor to adjust the brightness of the LEDs according to the room's brightness. I alredy added the code for it however it is still a work in progress. 

I also want to create a wall of lights visualizing the touches to the water I think it will improve the experience.
