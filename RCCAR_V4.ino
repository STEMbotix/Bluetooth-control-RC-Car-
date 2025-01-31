#include "BluetoothSerial.h"  // Include Bluetooth Serial library

// Initialize Bluetooth Serial
BluetoothSerial SerialBT;

// Motor Pins
#define MOTOR_FL1 27 // Front-left motor IN1
#define MOTOR_FL2 12 // Front-left motor IN2
#define MOTOR_FR1 33 // Front-right motor IN1
#define MOTOR_FR2 18 // Front-right motor IN2
#define MOTOR_BL1 13 // Back-left motor IN1
#define MOTOR_BL2 15 // Back-left motor IN2
#define MOTOR_BR1 4 // Back-right motor IN1
#define MOTOR_BR2 2  // Back-right motor IN2


// Define PWM channels
const int pwmChannel = 1;    // Channel for analog-like signal

char command;  // Variable to store incoming Bluetooth command
int speed=255;
void setup() {
  // Set motor pins as outputs
  pinMode(MOTOR_FL1, OUTPUT);
  pinMode(MOTOR_FL2, OUTPUT);
  pinMode(MOTOR_FR1, OUTPUT);
  pinMode(MOTOR_FR2, OUTPUT);
  pinMode(MOTOR_BL1, OUTPUT);
  pinMode(MOTOR_BL2, OUTPUT);
  pinMode(MOTOR_BR1, OUTPUT);
  pinMode(MOTOR_BR2, OUTPUT);
  Serial.begin(115200);

  // Start Bluetooth Serial with a name for the ESP32
  SerialBT.begin("STEMbotix");
  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
  // Check if there's a Bluetooth command available
  if (SerialBT.available()) {
    command = SerialBT.read();  // Read the incoming command
    Serial.println(command);
    // Perform action based on command
    switch (command) {
      case 'u':  // Forward
        moveForward();
        break;
      case 'd':  // Backward
        moveBackward();
        break;
      case 'l':  // Left
        moveLeft();
        break;
      case 'r':  // Right
        moveRight();
        break;
      case 's':  // Stop
        stopMotors();
        break;
    }
  }
}

// Movement Functions

void moveForward() {
  analogWrite(MOTOR_FL1, speed);
  analogWrite(MOTOR_FL2, 0);
  analogWrite(MOTOR_FR1, speed);
  analogWrite(MOTOR_FR2, 0);
  analogWrite(MOTOR_BL1, speed);
  analogWrite(MOTOR_BL2, 0);
  analogWrite(MOTOR_BR1, speed);
  analogWrite(MOTOR_BR2, 0);
}

void moveBackward() {
  analogWrite(MOTOR_FL1, 0);
  analogWrite(MOTOR_FL2, speed);
  analogWrite(MOTOR_FR1, 0);
  analogWrite(MOTOR_FR2, speed);
  analogWrite(MOTOR_BL1, 0);
  analogWrite(MOTOR_BL2, speed);
  analogWrite(MOTOR_BR1, 0);
  analogWrite(MOTOR_BR2, speed);
}

void moveLeft() {
  analogWrite(MOTOR_FL1, 0);
  analogWrite(MOTOR_FL2, speed);
  analogWrite(MOTOR_FR1, speed);
  analogWrite(MOTOR_FR2, 0);
  analogWrite(MOTOR_BL1, speed);
  analogWrite(MOTOR_BL2, 0);
  analogWrite(MOTOR_BR1, 0);
  analogWrite(MOTOR_BR2, speed);
}

void moveRight() {
  analogWrite(MOTOR_FL1, speed);
  analogWrite(MOTOR_FL2, 0);
  analogWrite(MOTOR_FR1, 0);
  analogWrite(MOTOR_FR2, speed);
  analogWrite(MOTOR_BL1, 0);
  analogWrite(MOTOR_BL2, speed);
  analogWrite(MOTOR_BR1, speed);
  analogWrite(MOTOR_BR2, 0);
}

void stopMotors() {
  analogWrite(MOTOR_FL1, 0);
  analogWrite(MOTOR_FL2, 0);
  analogWrite(MOTOR_FR1, 0);
  analogWrite(MOTOR_FR2, 0);
  analogWrite(MOTOR_BL1, 0);
  analogWrite(MOTOR_BL2, 0);
  analogWrite(MOTOR_BR1, 0);
  analogWrite(MOTOR_BR2, 0);
}

