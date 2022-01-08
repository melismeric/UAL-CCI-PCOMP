# WEEK 2

## Lab 00 - Leds in Serial and Parallel:
Answer the following questions:

### How many leds can you hook up with a 220k resistor in serial before running out of voltage?

Resistor = (Battery Voltage – LED voltage * Number of LEDs) / desired LED current

It depends on the battery voltage we use and the colors of the leds. LED voltages vary from about 1.6 to 4.5. 

Let's assume;
LED Voltage = 2V
LED current = 20 mA
According to the Ohm's law we can say that approximately, 
* for 6V battery and a 220k resistor we can use 1 LED serially connected
* for 9V battery and a 220k resistor we can use 2 LEDS serially connected

### How many leds can you hook up with a 220k resistor in parallel before running out of voltage?

Resistor = (Battery Voltage – LED voltage) / desired LED current * Number of LEDs
* for 6V battery and a 220k resistor we can use 1 LED in a parallel circuit 
* for 9V battery and a 220k resistor we can use 1 LED in a parallel circuit  
* for 12V battery and a 220k resistorwe can use 2 LEDS in a parallel circuit  

## Lab 04 - Playing with Common Sensors

We leared how to use [IR LED / IR Receiver](https://learn.sparkfun.com/tutorials/ir-communication/all) and made a circuit that  turns on the led when IR Receiver receives signal. We use a button to control the IR led and receiver. When we click on the button it enables the receiver to receive signals. In the serial monitor the outputs can be seen, when signal is received the output is bigger than 0 which turns the led on.


![week2Lab4](https://git.arts.ac.uk/storage/user/227/files/41a2d480-2dba-11ec-98e4-d54062bdb60f)


![week2Lab4](https://git.arts.ac.uk/storage/user/227/files/f2f53a80-2db9-11ec-8124-4848e91fdfa6)



## Lab 05
### Let's Move - PIR Motion Sensor & Neopixel

I designed a device for being active at home. This device consists of a  PIR motion sensor and  NeoPixel 16 Led Ring. PIR sensors sense motion, they detect whether a human has moved in or out of the sensors range. When the user moves in the area that the sensor can detect, pixels on the LED ring cycle through each color of an array consists of rainbow colors. When the user stops moving LED ring's pixels turn red. The red color reminds the user that they should move. 

This device can be used when users exercise at their houses, when they stay in the same position without moving, the red color will remind them to move. Especially it will be fun to dance with the rainbow lights moving as the user moves. People who work hard can use this device on their desks, it will remind them to move if they stay in the same position for too long and it will light up the mood when they are working fast with their hands on the keyboard, drawing, or writing. Musicians can also use this device when they move the rainbow lights will dance with the songs as they play. 

Tinkercad Link: https://www.tinkercad.com/things/2diHLBkHXRT-dazzling-leelo-maimu/editel?sharecode=zRfZcaTkotMSM1FiRF5zZgHHEa76JD6w_ZJwAxHyeKw

![motion-neopixel](https://git.arts.ac.uk/storage/user/227/files/15ba0000-2bbc-11ec-8e80-b1364a05f190)

