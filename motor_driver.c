/*
    Project name :  Motor Driver Module
    Modified Date: 14-06-2024
    Code by : Projectslearner
    Website :https://projectslearner.com/learn/arduino-mega-motor-driver-module 
*/

// Motor A connections (assuming L298N or similar motor driver)
const int motorPin1 = 2; // Motor A pin 1 (Input 1)
const int motorPin2 = 3; // Motor A pin 2 (Input 2)
const int enablePin = 9; // Motor A enable pin (PWM)

void setup() {
  // Set motor control pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Motor forward for 2 seconds
  motorControl(255, HIGH, LOW);
  Serial.println("Motor forward");
  delay(2000);
  
  // Motor backward for 2 seconds
  motorControl(255, LOW, HIGH);
  Serial.println("Motor backward");
  delay(2000);
  
  // Motor stop for 2 seconds
  motorControl(0, LOW, LOW);
  Serial.println("Motor stopped");
  delay(2000);
}

// Function to control the motor speed and direction
void motorControl(int speed, int dir1, int dir2) {
  analogWrite(enablePin, speed); // Set motor speed via PWM
  digitalWrite(motorPin1, dir1); // Set motor direction 1
  digitalWrite(motorPin2, dir2); // Set motor direction 2
}
