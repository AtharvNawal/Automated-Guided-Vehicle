#include <AFMotor.h>

const int trigPin = A4;
const int echoPin = A5;
const int leftIR = A1;
const int rightIR = A2;


AF_DCMotor motor1(1, MOTOR12_1KHZ); // Left
AF_DCMotor motor4(4, MOTOR34_1KHZ); // Right 


const int blackThreshold = 1005;


unsigned long lastDistancePrintTime = 0;
unsigned long lastIRPrintTime = 0;
const unsigned long distancePrintInterval = 1250; 
const unsigned long irPrintInterval = 1250; 


void setup() {
    
    motor1.setSpeed(250);
    motor4.setSpeed(250);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(leftIR, INPUT);
    pinMode(rightIR, INPUT);


    Serial.begin(9600);
}


long measureDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    return (duration * 0.034) / 2; // Distance in cm
}


void loop() {
    
    long distance = measureDistance();
    
    
    int leftStatus = analogRead(leftIR);   
    int rightStatus = analogRead(rightIR); 
    
    
    if (millis() - lastDistancePrintTime >= distancePrintInterval) {
        Serial.print("\n\nDistance: ");
        Serial.println(distance);
        lastDistancePrintTime = millis();
    }

    
    if (millis() - lastIRPrintTime >= irPrintInterval) {
        Serial.print("Left IR: ");
        Serial.println(leftStatus);
        Serial.print("Right IR: ");
        Serial.println(rightStatus);
        lastIRPrintTime = millis();
    }

    
  if (leftStatus < blackThreshold || 
      rightStatus < blackThreshold || 
      distance <= 20) 
  {   
      motor1.run(RELEASE);
      motor4.run(RELEASE);
  }

  else if (leftStatus < blackThreshold) 
  {   
      motor1.run(FORWARD);
      motor4.run(RELEASE);
  }

  else if (rightStatus < blackThreshold) //when right can't deetct anything
  {   
      motor1.run(RELEASE);
      motor4.run(FORWARD);
  }

  else 
  {
      motor1.run(FORWARD);
      motor4.run(FORWARD);
  }



    delay(100); 

    /*    


    
    Serial.print("Distance: ");
    Serial.println(distance);

    
    if (distance < 20) {
        motor1.run(RELEASE);
        motor4.run(RELEASE);
    } else {
        motor1.run(FORWARD);
        motor4.run(FORWARD);
    }

    delay(100); 


    */
}
