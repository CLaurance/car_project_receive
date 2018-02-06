#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

// direction
const int NO_ORDER = 0;
const int FORWARD = 1;
const int BACKWARD = 2;
const int TURN_RIGHT = 4;
const int TURN_LEFT = 8;

// propulsion
const int motor1 = 6;
const int motor2 = 7;
const int PWMPropulsionPin = 5;

// direction
const int motor3 = 8;
const int motor4 = 9;

void setup()
{
  Serial.begin(9600); // Debugging only
  Serial.println("Setup");
  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  //uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  int orders[4] = {0};
  uint8_t buflen = sizeof(orders);

  //if (driver.recv(buf, &buflen)) // Non-blocking
  if (driver.recv((uint8_t*)orders, &buflen)) //if data is not an array, use &receivedData
  {
    for (byte i = 0; i < 4; i++)
    {
      Serial.print(orders[i]);
      Serial.print('\t');
      Serial.println(orders[i],HEX);
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
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);  }


  if (propulsion == BACKWARD) {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);  }



  if (direction == TURN_RIGHT) {
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);  }

  if (direction == TURN_LEFT) {
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);  }
  }
}
