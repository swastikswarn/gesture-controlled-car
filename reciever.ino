#include <AFMotor.h>
#include <SoftwareSerial.h>

// Bluetooth
SoftwareSerial bt(0, 1); // RX, TX

// Motors
AF_DCMotor FL(1);
AF_DCMotor BL(2);
AF_DCMotor BR(3);
AF_DCMotor FR(4);

// Speed value (0–255)
#define SPEED 180

// ---------------- MOTOR FUNCTIONS ----------------

void stopMotors() {
  FL.setSpeed(0);
  BL.setSpeed(0);
  BR.setSpeed(0);
  FR.setSpeed(0);

  FL.run(RELEASE);
  BL.run(RELEASE);
  BR.run(RELEASE);
  FR.run(RELEASE);
}

void forward() {
  FL.setSpeed(SPEED);
  BL.setSpeed(SPEED);
  BR.setSpeed(SPEED);
  FR.setSpeed(SPEED);

  FL.run(FORWARD);
  BL.run(FORWARD);
  BR.run(FORWARD);
  FR.run(FORWARD);
}

void backward() {
  FL.setSpeed(SPEED);
  BL.setSpeed(SPEED);
  BR.setSpeed(SPEED);
  FR.setSpeed(SPEED);

  FL.run(BACKWARD);
  BL.run(BACKWARD);
  BR.run(BACKWARD);
  FR.run(BACKWARD);
}

void leftTurn() {
  FL.setSpeed(SPEED);
  BL.setSpeed(SPEED);
  BR.setSpeed(SPEED);
  FR.setSpeed(SPEED);

  FL.run(BACKWARD);
  BL.run(BACKWARD);
  FR.run(FORWARD);
  BR.run(FORWARD);
}

void rightTurn() {
  FL.setSpeed(SPEED);
  BL.setSpeed(SPEED);
  BR.setSpeed(SPEED);
  FR.setSpeed(SPEED);

  FL.run(FORWARD);
  BL.run(FORWARD);
  FR.run(BACKWARD);
  BR.run(BACKWARD);
}

// ---------------- SETUP ----------------

void setup() {
  Serial.begin(9600);
  bt.begin(9600);

  stopMotors();
  Serial.println("Bluetooth Car Ready");
}

// ---------------- LOOP ----------------

void loop() {
  if (bt.available()) {
    char cmd = bt.read();
    Serial.println(cmd);

    switch (cmd) {
      case 'F': forward();   break;
      case 'B': backward();  break;
      case 'L': leftTurn();  break;
      case 'R': rightTurn(); break;
      case 'S': stopMotors();break;
      default:  stopMotors();break;
    }
  }
}
