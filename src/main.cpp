#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;


const int xPin = A1;
const int yPin = A0;
const int buttonPin = 12;

// propulsion
const int motor1 = 6;
const int motor2 = 7;
const int PWMPropulsionPin = 5;


void setup() {
  Serial.begin(9600);
}

void loop(){
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    Serial.print("Message: ");
    Serial.println((char*)buf);
    // Message with a good checksum received, dump it.
  // if (buf == "avant") {
  //   digitalWrite(motor1, LOW);
  //   digitalWrite(motor2, HIGH);
  // }
}
}
