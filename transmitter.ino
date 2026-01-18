#include <Wire.h>
#include <SoftwareSerial.h>

#define BMI160_ADDR 0x68
#define THRESHOLD 5000

SoftwareSerial bt(2, 3); // RX, TX

int16_t ax, ay, az;

void bmi160Write(uint8_t reg, uint8_t data) {
  Wire.beginTransmission(BMI160_ADDR);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}

void bmi160Read(uint8_t reg, uint8_t *buf, uint8_t len) {
  Wire.beginTransmission(BMI160_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(BMI160_ADDR, len);
  for (uint8_t i = 0; i < len; i++) {
    buf[i] = Wire.read();
  }
}

void setup() {
  Wire.begin();
  Serial.begin(9600);
  bt.begin(9600);

  delay(100);

  bmi160Write(0x7E, 0xB6);   // soft reset
  delay(100);

  bmi160Write(0x7E, 0x11);   // accel normal mode
  delay(50);

  bmi160Write(0x41, 0x03);   // ±2g
}

void loop() {
  uint8_t data[6];
  bmi160Read(0x12, data, 6);

  ax = (int16_t)((data[1] << 8) | data[0]);
  ay = (int16_t)((data[3] << 8) | data[2]);
  az = (int16_t)((data[5] << 8) | data[4]);

  char cmd = 'S';

  // ✅ FIXED MAPPING
  if (ax < -THRESHOLD)        cmd = 'F';   // tilt forward
  else if (ax > THRESHOLD)   cmd = 'B';   // tilt backward
  else if (ay > THRESHOLD)   cmd = 'R';   // tilt right
  else if (ay < -THRESHOLD)  cmd = 'L';   // tilt left
  else                       cmd = 'S';

  bt.write(cmd);
  Serial.println(cmd);

  delay(80);
}
