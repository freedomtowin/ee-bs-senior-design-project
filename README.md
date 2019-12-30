Project Name: Automatic Speed Control

Video: [https://youtu.be/lSIhfu3V6t0](https://youtu.be/lSIhfu3V6t0)

Automatic Speed Control looks to use speed coordination and safety techniques such as collision avoidance in order to assist drivers in specific situations and make the daily driving experience more enjoyable. This product will make our roads significantly safer resulting in a decreased number of automobile accidents. 

Operating a vehicle often requires skill and a high level of awareness. At times drivers may become distracted while behind the wheel creating the potential for an accident. Over confidence and impaired judgement are other traits that often lead to accident on roadways. ASC takes these driving deficiencies in to consideration and provides a system that prevents potential accidents due to these types of driving deficiencies. A distracted driver may not see a vehicle braking in front of him/her. Using various sensors, ASC will alert the driver of an object detected at a certain distance and the vehicle will automatically adjust the speed of the vehicle and prevent a collision. Once the speed has been reduced and the vehicles are a safe distance apart, the vehicle with ASC will adjust the speed again in order to continue on at a safe speed and distance relative to the vehicle in front of it. 

Other features of ASC are lane detection, blind spot monitoring, and vehicle overtake assistance. Operating a vehicle in one lane seems to be a very trivial aspect of driving, but at times remaining in one lane may become difficult due to certain road conditions or weather. ASC assists driver by using sensors to alert drivers when they are veering out of the designated lane of travel. This works hand in hand with the blind spot monitoring. 360 degree sensors will detect any object that may be hard to see due to lack of visibility and alert drivers when an object is detected. The vehicle overtake assistance uses lane detection, speed control coordination, and blind spot monitoring in order to allow the vehicle to safely overtake a vehicle on a one way road. 


Scope of Work
The ideas and steps that were taken in to account in order to build ASC, automatic speed control, were complex and dependent of each other. The testing process followed a specific order of checkpoints that were required to meet in order to have everything working as expected.

**Equipment:**
      ZUMO robots
      Ultrasonic sensor (4pin or 3pin)
      Reflectance sensors (6)
      NewPing library
      Ardunio Micro-controllers
      Mount for sensors
      Equipment:
      Solder/Solder pen
      Printed circuit board
      Printed breadboard
      Nylon accessories
      Drill
      Acrylic sheet
      Arduino IDE
      Equipment:
      Computer

1 Assemble ZUMO if came un-assembled. Change the jumper cables on the ZUMO shield and reflectance sensor for Arduino UNO.

2. Drill holes in the printed circuit board to match the existing holes in the Arduino UNO. Cut a piece of acrylic the same shape and size of the Arduino UNO. Fit the printed circuit board on the Arduino with nylon nuts and bolts with the Arduino facing with pins up. Hot glue the printed bread board on the tops of the printed circuit board. Hot glue the acrylic to the bottom of the Arduino.


Line following & Obstacle Avoidance

3. Use the existing ZUMO libraries and examples to create a line following ZUMO. Remove the code for the buzzer to enable using pin 6.


4. Test obstacle avoidance by assign pin 6 to send and receive sensor data. Control the motors with ZUMO libraries to turn away when an object is detected. Otherwise, the ZUMO is to go straight.



5. The ZUMO should line follow until an object is detected. If an object is detected, the ZUMO will change lanes, and 0nce a safe distance is reached the ZUMO will change back to the right lane and continue to follow the line. Vectored interrupts are used for efficient responses.


6. Use the NewPing library to get data from two sensors. Use the library’s timer to set intervals of sending and receiving sensor signals.

7. Create a for loops to send numbers from one Arduino to the other. Use the RX, pin0, to receive and TX, pin1, to send signals. 

8. The two sensors should be interfaced to one Arduino UNO. That Arduino will information about the both sensor data in one byte to the other Arduino UNO.
