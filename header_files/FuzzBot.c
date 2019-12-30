/* FuzzBot

Code for the ZumoBot, with Ping Sensor on Servo to do obstacle avoidance.

posted on Instructables

created 15 Apr 13
made by Quin (Qtechknow)
*/
void Ping::fire()
{
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(_pin, LOW);
  pinMode(_pin, INPUT);
  _duration = pulseIn(_pin, HIGH);
  
}

int Ping::microseconds()
{
  return _duration;
}

double Ping::inches()
{
  if(_duration != -1){
    return _duration / (74+_in) / 2;
  }else{
    return -1;
  }
}

double Ping::centimeters()
{
  if(_duration != -1){
    return _duration / (29+_cm) / 2;
  }else{
    return -1;
  }
}


// set speed for right motor; speed is a number between -400 and 400
void ZumoMotors::setRightSpeed(int speed)
{
  init(); // initialize if necessary
    
  boolean reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;
    
#ifdef USE_20KHZ_PWM
  OCR1A = speed;
#else
  analogWrite(PWM_R, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
#endif

  if (reverse ^ flipRight) // flip if speed was negative or flipRight setting is active, but not both
    digitalWrite(DIR_R, HIGH);
  else
    digitalWrite(DIR_R, LOW);
}



// set speed for left motor; speed is a number between -400 and 400
void ZumoMotors::setLeftSpeed(int speed)
{
  init(); // initialize if necessary
    
  boolean reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed; // make speed a positive quantity
    reverse = 1;    // preserve the direction
  }
  if (speed > 400)  // Max 
    speed = 400;
    
#ifdef USE_20KHZ_PWM
  OCR1B = speed;
#else
  analogWrite(PWM_L, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
#endif 

  if (reverse ^ flipLeft) // flip if speed was negative or flipLeft setting is active, but not both
    digitalWrite(DIR_L, HIGH);
  else
    digitalWrite(DIR_L, LOW);
}




#include <Ping.h>
#include <ZumoMotors.h>

Ping ping = Ping(4);

int left = 150;
int right = 80;
int center = 120;

int count = 0;

ZumoMotors motors;
 
void setup() {  
  pinMode(13, OUTPUT);
    
  Serial.begin(9600);    // start serial communication at 9600 baud
} 
 
 
void loop() 
{ 
  if(count == 0) {
    for(int i = 0; i<5; i++) {    // do this 5 times
    ping.fire();
    
    int inches = ping.inches();  // where is everything?
    int cm = ping.centimeters();
    int mseconds = ping.microseconds();
    
    Serial.print(inches);  // print values out on serial monitor
    Serial.print(" , ");
    Serial.print(cm);
    Serial.print(" , ");
    Serial.println(mseconds);

    motors.setRightSpeed(400);  // full speed ahead
    motors.setLeftSpeed(400);
    
    delay(100);
    
    if(inches <= 6) {    // if the FuzzBot gets too close...
            
    digitalWrite(13, HIGH);  // turn the other way

    motors.setLeftSpeed(-400);
    motors.setRightSpeed(400);
 
    delay(300);
  }else{
    digitalWrite(13, LOW);
    
    motors.setLeftSpeed(400);
    motors.setRightSpeed(400);
    count = 1;
    }
  }
}
   if(count == 1) {
     for(int i = 0; i<5; i++) {  // do this 5 times
         
    ping.fire();
    
    int inches = ping.inches();   // where are we???
    int cm = ping.centimeters();
    int mseconds = ping.microseconds();
    
    Serial.print(inches);  // print on the serial monitor
    Serial.print(" , ");
    Serial.print(cm);
    Serial.print(" , ");
    Serial.println(mseconds);

    motors.setRightSpeed(400);  // full speed
    motors.setLeftSpeed(400);
    
    delay(100);
    
    if(inches <= 6) {    // if the FuzzBot is too close, turn the other way
            
    digitalWrite(13, HIGH);

    motors.setLeftSpeed(-400);
    motors.setRightSpeed(400);
 
    delay(300);
  }else{
    digitalWrite(13, LOW);
    
    motors.setLeftSpeed(400);
    motors.setRightSpeed(400);
       }
     }
   }
}

  
