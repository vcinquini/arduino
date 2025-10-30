#include <Servo.h>

Servo myservo1;  	// create servo object to control a servo
//Servo myservo2;  	// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int rand_max = 180;


void setup() {
  Serial.begin(9600);
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo1.write(0);              // tell servo to go to position in variable 'pos'
}

void loop() {
  	myservo1.write(90);             // tell servo to go to position in variable 'pos'
    Serial.println(90);
    delay(3000);                       // waits 15ms for the servo to reach the position

   	myservo1.write(0);             // tell servo to go to position in variable 'pos'
    Serial.println(0);
    delay(3000);                       // waits 15ms for the servo to reach the position

}