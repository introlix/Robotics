#include <Arduino.h>

// configuration constants
const int CHANNEL = 0;
const int SERVO_PIN = 13;
const int FREQUENCY = 50; // Hz
const int RESOLUTION = 16; // bits
const int PERIOD_US = 20000; // microseconds (1,000,000 / 50Hz)
const int MAX_DUTY = 65535; // 2^16 - 1

const int ANCHOR_PULSE_US = 1500; // microseconds at 0°
const float RATE = 1500.0 / 90.0; // microseconds per degree

int servoControl(int);

void setup() {
  ledcSetup(CHANNEL, FREQUENCY, RESOLUTION);
  ledcAttachPin(SERVO_PIN, CHANNEL);
}

void loop() {
  for (int angle = 0; angle <=180; angle += 1) {
    ledcWrite(CHANNEL, servoControl(angle));
    delay(15);
  }

  for (int angle = 180; angle >= 0; angle -= 1) {
    ledcWrite(CHANNEL, servoControl(angle));
    delay(15);
  }
}

// put function definitions here:
int servoControl(int angle) {
  int pulse_us = ANCHOR_PULSE_US + (angle - 90) * RATE;

  int duty = (pulse_us / static_cast<float>(PERIOD_US)) * MAX_DUTY;
  return duty;
}