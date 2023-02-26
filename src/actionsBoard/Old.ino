/*

#include "controller.h"

// Variables used for control.
static bool flood = false;
static byte humidityLimit = 100;
static unsigned timeTest = 200;

// Objects used to control motors.
Motor propeller (PIN_PROPELLER_A, PIN_PROPELLER_B);
Motor ballast (PIN_BALLAST_A, PIN_BALLAST_B);

// Objects used to control rudders and planes.
Servomotor rudderBottom;
Servomotor rudderTop;
Servomotor planeLeft;
Servomotor planeRight;

// Objects used for communications.
IrDevice irReceiver (PIN_IR_RECEIVER);


// This function stops move of rudders and planes
// and sets them on middle angle.
 
void stabilize () {
  rudderBottom.disableTest ();
  rudderTop.disableTest ();
  planeLeft.disableTest ();
  planeRight.disableTest ();
  
  rudderBottom.middle ();
  rudderTop.middle ();
  planeLeft.middle ();
  planeRight.middle ();
}


// This function stop motors and
// stabilize the servomotors.
 
void wait () {
  propeller.stop ();
  ballast.stop ();
  stabilize ();
}


// This function sets angle of rudders.
// 
// @param angle new orientation of servomotors.
 
void setRudderAngle (int angle) {
  rudderBottom.write (ANGLE_MIDDLE - angle);
  rudderTop.write (ANGLE_MIDDLE + angle);
}


// This function sets angle of planes.
// 
// @param: angle new orientation of servomotors.
 
void setPlaneAngle (int angle) {
  planeLeft.write (ANGLE_MIDDLE + angle);
  planeRight.write (ANGLE_MIDDLE - angle);
}


// This function maintain angle of rudders and planes.
 
void loopServo () {
  rudderBottom.loop ();
  rudderTop.loop ();
  planeLeft.loop ();
  planeRight.loop ();
}


// This function makes links between 
// communication with hardware parts.
 
void command() {
  // Infra-red communication
  unsigned long value = irReceiver.check();
  if (value) {
    Serial.print ("Command: ");
    Serial.println (value, HEX);
    irReceiver.resume ();
    
    switch (value) {
      // Propeller speed
      case C_FASTER:
        propeller.increaseVelocity (RATE_MEDIUM);
        break;
      case C_SLOWER:
        propeller.decreaseVelocity (RATE_MEDIUM);
        break;
      case C_STOP:
        propeller.stop ();
        break;
      case C_WAIT:
        wait ();
        break;
      // Direction and angle
      case C_LEFT:
        setRudderAngle (ANGLE_ACUTE);
        break;
      case C_RIGHT:
        setRudderAngle (-ANGLE_ACUTE);
        break;
      case C_DOWN:
        setPlaneAngle (-ANGLE_ACUTE);
        break;
      case C_UP:
        setPlaneAngle (ANGLE_ACUTE);
        break;
      case C_STABILIZE:
        stabilize ();
        break;
      // Test of servomotors
      case C_TEST_RUDDER_BOTTOM:
        rudderBottom.toggleTest (timeTest);
        break;
      case C_TEST_RUDDER_TOP:
        rudderTop.toggleTest (timeTest);
        break;
      case C_TEST_PLANE_LEFT:
        planeLeft.toggleTest (timeTest);
        break;
      case C_TEST_PLANE_RIGHT:
        planeRight.toggleTest (timeTest);
        break;      
    }
  }

  // Check of humidity inside of submarine.
  if (analogRead (PIN_SENSOR_HUMIDITY) > humidityLimit) {
    flood = true;
  }
  else {
    flood = false;
  }
}


// This function is called at 
// initialization of Arduino Board.
 
void setup() {
  rudderBottom.attach (PIN_RUDDER_BOTTOM);
  rudderTop.attach (PIN_RUDDER_TOP);
  planeLeft.attach (PIN_PLANE_LEFT);
  planeRight.attach (PIN_PLANE_RIGHT);
  
  
  wait();

  unsigned long standardValue[] = {
    C_FASTER,
    C_SLOWER,
    C_STOP,
    C_WAIT,
    C_LEFT,
    C_RIGHT,
    C_DOWN,
    C_UP,
    C_STABILIZE,
    C_TEST_RUDDER_TOP,
    C_TEST_RUDDER_BOTTOM,
    C_TEST_PLANE_LEFT,
    C_TEST_PLANE_RIGHT    
  };
  
  irReceiver.enableIRIn ();
  irReceiver.setInputLoopTime (INPUT_CICLE_MEDIUM);
  irReceiver.setStandardValue (
    standardValue, 
    sizeof (standardValue) / sizeof (standardValue[0])
  );

  Serial.begin(9600);
}


// This function runs until Arduino Board is stopped.
 
void loop() {
  propeller.loop();
  loopServo();
   
  command();
}


*/