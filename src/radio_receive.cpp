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
    // do something
  }
  }
}
