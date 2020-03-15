#include "Communications.h"

unsigned long baudRate = 115200;

bool silentMode = false;
bool sonarIsOn = false;

/**
 *  @brief: Setup function initializes important objects of software.
 */
void setup() {
  Serial.begin (baudRate);

}

/**
 *  @brief: This function repeats until the board stop working.
 */
void loop() {

}