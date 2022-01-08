# WEEK 3 - LAB

## Lab00: Soldering

<img width="200" alt="Screen Shot 2021-10-15 at 13 43 54" src="https://git.arts.ac.uk/storage/user/227/files/fc80a180-2dbd-11ec-9bef-78784cdedb1a">

<img width="200" alt="Screen Shot 2021-10-15 at 13 43 42" src="https://git.arts.ac.uk/storage/user/227/files/fdb1ce80-2dbd-11ec-92e0-2824f3b514fe">

## Lab 01: PWM - Playing with fades
This circuit demonstrates the usage of analog output with Pulse Width Modulation (PWM) to fade an LED. PWM is a technique for getting an analog-like behavior from a digital output by switching it off and on very fast and with different ratios. 

In the code, there are two loops to increase and then decrease the brightness of the led to create a fade effect.
[CODE](https://git.arts.ac.uk/21004071/portfolio_of_work/blob/master/week3/week3-Lab01/week3-Lab01-PWM.ino) 
<br />![week3-lab1](https://git.arts.ac.uk/storage/user/227/files/e1ad2d80-2dbb-11ec-8f67-44c1c0b50292)

## Lab 02: Voltage Dividers

A voltage divider is a circuit that turns a large voltage into a smaller one. Using multiple resistors and an input voltage, we can create an output voltage that is a fraction of the input. In this example, we used 3 light-dependent resistors to divide the voltage going through the RGB led. The sensor values are the inputs for the red, blue, and green colors of the led.

<img width="400" alt="Screen Shot 2021-10-18 at 21 03 49" src="https://git.arts.ac.uk/storage/user/227/files/e8a39c80-3056-11ec-9a16-7f4c1b38321d"> <br />
![week3-lab2-voltage divider](https://git.arts.ac.uk/storage/user/227/files/cc0d7000-30fb-11ec-81ae-8349715e8953)<br />
[CODE&BOARD](https://git.arts.ac.uk/21004071/portfolio_of_work/tree/master/week3/week3-Lab02)
[Tinkercad](https://www.tinkercad.com/things/bbHabsg4EVu-brave-allis-esboo/editel?sharecode=FwAD5RaG2OvSq63aN_oCrH9ZAQ0qRGbPaF4Nf9LMUAg)

## Lab 03: Dark detecting Circuit for your pumpkins
In this example, I used a photoresistor, 10K ohm resistor, 2N3904 NPN transistor to build a dark detecting circuit. As shown in the circuit schematic below, when there is light, the particles of light hit the phototransistor, which enables the current to pass through the transistor, and with it the LED is switched off. When there is no light current freely passes through the transistor, lighting up the LED. Then I carved a pumpkin and placed it on the circuit. The pumpkin lights up when it is dark.

![dark-sensor](https://git.arts.ac.uk/storage/user/227/files/12b89580-310f-11ec-9bb1-94623895c4c4)
<br />
<img width="400" alt="Screen Shot 2021-10-19 at 21 59 47" src="https://git.arts.ac.uk/storage/user/227/files/e4937f80-3127-11ec-8fa0-e44e29a113bd">
![pumpkin](https://git.arts.ac.uk/storage/user/227/files/9763dd80-3128-11ec-9258-2af37e59a60f)
![pumpkin2](https://git.arts.ac.uk/storage/user/227/files/99c63780-3128-11ec-9fcb-7e3f54218c42)
<br />
[CODE](https://git.arts.ac.uk/21004071/portfolio_of_work/blob/master/week3/week3-Lab03/week3-Lab03-Dark-Detecting-LED.ino)
[VIDEO]()

## Lab 03b: Touch Sensor
<img width="300" src="https://git.arts.ac.uk/storage/user/227/files/2f979d80-30fc-11ec-818f-79c1881cdfeb"> ![week3-lab3-touch](https://git.arts.ac.uk/storage/user/227/files/142b9300-30fa-11ec-8c1a-e6a73fab0889)

## Lab 04: Feedback systems

![w3-l4-feedback](https://git.arts.ac.uk/storage/user/227/files/3e874b80-310e-11ec-8758-1feddb19fbb9)<br />
A feedback system is one in which the output signal is sampled and then fed back to the input to form an output that drives the system. Meaning, a feedback systems gets input on itself. 
I designed two Feedback systems using multiple LEDs and a LDR the circuit is same for both of them but the codes are different. LDR reads the input from the flashed LEDs and according to that input turns on or off other LEDs.


Basic Feedback System:
In this circuit red and yellow leds' brightness change through time and LDR uses their brightness as input and flashes the green led. I used analogWrite(ledPin,sensorValue) to change the brightness of the green led. Green led's brightness change according to the LDR sensor's value. So, it changes according to other two leds brightness. That way the circuit takes input from itself.
[Code](https://git.arts.ac.uk/21004071/portfolio_of_work/blob/master/week3/week3-Lab04/week3-lab04-feedback.ino)
<br />
[Feedback System Video](https://youtu.be/Ws6_Eic4cso)

GAME: Turn The Lights On!
This circuit can be used as a game that the player is trying to turn on all the leds moving the LDR closer or further from the LEDs. The red light is always on but it's brightness change according to the LDR's value, so when we move LDR closer to the red LED it's brightness increase. When the LDR's value is in between 30 and 140 all the LEDs turn on. But LDR's value is calculated with a delay of 1000 miliseconds, so it will be tricky to get the value at the right time to turn on all the lights.
[Code](https://git.arts.ac.uk/21004071/portfolio_of_work/blob/master/week3/week3-Lab04/week3-lab04-game.ino)
<br />
[Feedback System Game Video](https://youtu.be/tLD5xPyZH94)





