#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int btnpin1 = 6;  // analog pin used to connect the potentiometer
int btnpin2 = 7;
int val1;    // variable to read the value from the analog pin
int val2;
int servoLocation = 0;
bool flip = false;
bool same1 = false;
bool same2 = false;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(btnpin1, INPUT);
  pinMode(btnpin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  val1 = digitalRead(btnpin1);
  val2 = digitalRead(btnpin2);

  
  if (val1 == 1) {
    
    if (same1 == false) {
      servoLocation += 20;
    }
    
    same1 = true;
    
  } else {
    same1 = false;
  }

  if (val2 == 1) {
    
    if (same2 == false) {
      servoLocation -= 20;
    }
    
    same2 = true;
    
  } else {
    same2 = false;
  }

  if (servoLocation <= 0) {
    servoLocation = 0;
  }

  if (servoLocation >= 180) {
    servoLocation = 180;
  }
  
  myservo.write(servoLocation);        // sets the servo position according to the scaled value
             
  delay(15);                           // waits for the servo to adjust
}
