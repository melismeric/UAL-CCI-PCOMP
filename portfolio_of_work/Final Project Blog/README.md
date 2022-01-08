# PCOMP FINAL PROJECT - WETMIXER

## Project Description
This project aims to create sounds and turn on LEDs by touching the water.  I aim to use water as an interface and use the conductivity of both water and skin. I built a set using two metal bowls, a LED strip, and speakers. Inside the bowls, I put salty water to increase the conductivity. When someone touches the water in one bowl it increases the number of LEDs turning on. According to the electrical charge of that person the number of LEDs turning on changes. Also if multiple people touch the water they have a chance to turn up more LEDs than one person. Using the potentiometer the sensitivity of the LEDs can be changed. If a person touches the water in the other bowl and also touches the conductive surface near it, it activates the analog synthesizer and creates sound. The sound changes according to the electrical charge of the person touching it and their interaction with water. If someone else touches that person or water it creates a different sound. 

The project consists of two parts. The first part is the LED strip circuit consisting of a LED strip, Arduino Leonardo, resistors, a potentiometer, a conductive surface to put water in it. The second part is the analog synthesizer which consists of a CD40106BE chip, two conductive surfaces (creates sound when you touch both of them), speakers, and a capacitor. I used cardboard to build the housing.

In the project, the sound is both an input and output, which makes the circuit a feedback system. By touching the water and the conductive surface we create sound. The sound detector takes the sound and changes the color of LEDs accordingly. This makes sound input for the color of the LEDs. Also by touching the water we increase the number of LEDs turning on which makes the water touch an input and LEDs an output. The potentiometer is connected as an analog input to the circuit, we use it to change. the sensitivity of the LED strip. Higher values make it easier to turn on more LEDs.

[Video](https://youtu.be/l-3fNC-Wu9g)

Resources:
* [DIY Conductive Touch Sensor](https://www.instructables.com/Capacitive-Sensing-for-Dummies/)
* [Smoothing values](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Smoothing)
* [Analog Synthesizer](https://www.youtube.com/watch?time_continue=2197&v=PbP58k8USOE&feature=emb_title)
* [Sound Visualization](https://www.youtube.com/watch?v=G-zCNkNp4RY)
