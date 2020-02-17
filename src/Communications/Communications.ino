#include "Communications.h"

unsigned long baudRate = 115200;

bool silentMode = false;
bool sonarIsOn = false;

/** IMU communications. */
MPU9250 imuDevice (Wire, IMU_ADDRESS);
TimeInterval imuClock (IMU_PERIOD);
int imuStatus;

/** IMU data. */
byte imuSampleNumber = IMU_SAMPLE_BEGIN_NUMBER;
double velocity = IMU_INITIAL_VELOCITY;
double depth = IMU_INITIAL_DEPTH;
double acceleration = IMU_INITIAL_ACCELERATION;
double roll;
double pitch;
double yaw;
double orientation;



/** IMU data transfer. */
#define IMU_ADDRESS  0x68
#define IMU_ERROR    0x00

/** IMU data accuracy. */
#define IMU_G                   9.80665

/**

*/
void setupImu () {
  /** Start communication with imuDevice. */
  imuStatus = imuDevice.begin();

  while (imuStatus < IMU_ERROR) {
    Serial.println ("IMU initialization unsuccessful!");
    Serial.println ("Check IMU wiring or try cycling power");
    Serial.print ("Status: ");
    Serial.println (imuStatus);

    imuStatus = imuDevice.begin ();
  }

  imuDevice.calibrateAccel ();
  imuDevice.setAccelRange (MPU9250::ACCEL_RANGE_8G);
  imuDevice.setGyroRange (MPU9250::GYRO_RANGE_500DPS);
  imuDevice.setDlpfBandwidth (MPU9250::DLPF_BANDWIDTH_20HZ);
  imuDevice.setSrd (IMU_SRD);
}

/**

*/
void readFromImu () {
  double ax;
  double ay;
  double az;
  double newAcceleration;
  double newOrientation;

  if (imuClock.isElapsed ()) {
    imuDevice.readSensor();

    /** Get raw acceleration on axis. */
    ax = imuDevice.getAccelX_mss();
    ay = imuDevice.getAccelY_mss();
    az = imuDevice.getAccelZ_mss();

    Serial.print ("\ta = ");
    Serial.print (ax, SERIAL_DECIMALS_NUMBER);
    Serial.print ("\t");
    Serial.print (ay, SERIAL_DECIMALS_NUMBER);
    Serial.print ("\t");
    Serial.print (az, SERIAL_DECIMALS_NUMBER);

    /** Rotations. */
    ax *= 3.9;
    ay *= 3.9;
    az *= 3.9;
    roll = 180.0 * atan (ay / sqrt(ax * ax + az * az)) / M_PI;
    pitch = 180.0 * atan (ax / sqrt(ay * ay + az * az)) / M_PI;
    yaw = 180.0 * atan (az / sqrt(ax * ax + az * az)) / M_PI;

    newOrientation = imuDevice.getMagZ_uT();

    if (1 < imuSampleNumber) {
      orientation = (orientation * imuSampleNumber + newOrientation) / (imuSampleNumber + 1);
    }
    else {
      orientation = newOrientation;
    }

    /** Get motion variables. */
    ax = imuDevice.getAccelX_mss();
    ay = imuDevice.getAccelY_mss();
    az = imuDevice.getAccelZ_mss();
    
    acceleration = IMU_DIRECTION * (az - (sqrt(ax * ax + ay * ay) * sin (M_PI * yaw / 180.0)));
    // acceleration = trunc (acceleration * IMU_DECIMALS_PRECISION) / IMU_DECIMALS_PRECISION;

//    if (1 < imuSampleNumber) {
//      acceleration = (acceleration * imuSampleNumber + newAcceleration) / (imuSampleNumber + 1);
//    }
//    else {
//      acceleration = newAcceleration;
//    }

    /** Get speed. */
    velocity += acceleration * imuClock.elapsedTimeFromStart () / SECOND;

    Serial.print ("\tRoll = ");
    Serial.print (roll, SERIAL_DECIMALS_NUMBER);
    Serial.print ("\tPitch = ");
    Serial.print (pitch, SERIAL_DECIMALS_NUMBER);
    Serial.print ("\tYaw = ");
    Serial.print (yaw, SERIAL_DECIMALS_NUMBER);

    Serial.print ("\ta = ");
    Serial.print (acceleration, SERIAL_DECIMALS_NUMBER);

    Serial.print ("\tv = ");
    Serial.print (velocity, SERIAL_DECIMALS_NUMBER);

    Serial.print ("\tt = ");
    Serial.print (imuDevice.getTemperature_C(), SERIAL_DECIMALS_NUMBER);

    Serial.print ("\tOrientation: ");
    Serial.print (imuDevice.getMagX_uT(), SERIAL_DECIMALS_NUMBER);
    Serial.print ("\t");
    Serial.print (imuDevice.getMagY_uT(), SERIAL_DECIMALS_NUMBER);
    Serial.print ("\t");
    Serial.print (orientation, SERIAL_DECIMALS_NUMBER);

    Serial.println("");

    imuSampleNumber ++;

    if (IMU_SAMPLE_END_NUMBER <= imuSampleNumber) {
      imuSampleNumber = IMU_SAMPLE_BEGIN_NUMBER;
    }

    imuClock.restart ();
  }
}

/**
 *  @brief: Setup function initializes important objects of software.
 */
void setup() {
  Serial.begin (baudRate);

  setupImu ();
}

/**
 *  @brief: This function repeats until the board stop working.
 */
void loop() {
  readFromImu ();
}
