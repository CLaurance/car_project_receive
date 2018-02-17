#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

// direction
const int NO_ORDER = 0;
const int FORWARD = 1;
const int BACKWARD = 2;
const int TURN_RIGHT = 4;
const int TURN_LEFT = 8;

void setup()
{
  Serial.begin(9600); // Debugging only
  Serial.println("Setup");
  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  //uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  int orders[4];
  uint8_t buflen = sizeof(orders);

  //if (driver.recv(buf, &buflen)) // Non-blocking
  if (driver.recv((uint8_t*)orders, &buflen)) //if data is not an array, use &receivedData
  {

    for (byte i = 0; i < 4; i++)
    {
      Serial.println(orders[i]);
    }

    int propulsion;
    int vitesse;
    int direction;
    int braquage;

    propulsion=orders[0];
    vitesse=orders[1];
    direction=orders[2];
    braquage=orders[3];

    if (propulsion == FORWARD) {
      // Serial.println("avant");
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      analogWrite(A0, vitesse);
    }
    else if (propulsion == BACKWARD) {
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      analogWrite(A0, vitesse);
    }
    else if (propulsion == NO_ORDER) {
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      analogWrite(A0, vitesse);
    }
    if (direction == TURN_RIGHT) {
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      analogWrite(A1, braquage);
    }
    if (direction == TURN_LEFT) {
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      analogWrite(A1, braquage);
    }
    if (direction == NO_ORDER) {
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      analogWrite(A1, braquage);
    }
  Serial.println("====RECEIVED=========");
  }
  else {
    Serial.println("====NO MESS=========");
}
  delay(1000);
}
