/**
 *  Imu.cpp
 *
 *  Created 18 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 24 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#include "Imu.h"

#define INITIAL_ACCELERATION 0.0
#define INITIAL_DEPTH        0.0
#define INITIAL_DATA_VALUE   0.0
#define INITIAL_ORIENTATION  0.0
#define INITIAL_SPEED        0.0
#define INITIAL_TEMPERATURE  0.0

#define FIRST_ADDRESS        0x00
#define FIRST_SAMPLE         0

#define DEFAULT_TIME_CLOCK   50

#define INITIALIZING_MESSAGE "IMU initializating... Status: "

/**
 *  @brief: This is constructor of class. This allocate memory for IMU device and
 *  initialize important parameters.
 *  
 *  @param: address - of IMU device connection.
 */
Imu::Imu (TwoWire &bus,uint8_t address) : MPU9250 (bus, address) {

	this->depth = INITIAL_DEPTH;
	this->divingSpeed = INITIAL_SPEED;
	this->speed = INITIAL_SPEED;

	this->dataChanged = false;
}

/**
 *  @brief: This method is destructor of class. 
 */
Imu::~Imu () {

}

/**
 *  @brief: This method calibrate electronic device and initialize data.
 *  
 *  @param: decimalsNumber - number decimals of final data numbers: speed, depth, orientation,
 *  @param: numberOfSamples - number of set of data (reads) until the final data is processed.
 */
void Imu::setup (byte decimalsNumber, byte numberOfSamples) {

	int imuStatus = this->begin ();

	while (imuStatus < FIRST_ADDRESS) {
		Serial.print (INITIALIZING_MESSAGE);
		Serial.println (imuStatus);

		imuStatus = this->begin ();
	}

	this->calibrateAccel ();
	this->setAccelRange (MPU9250::ACCEL_RANGE_8G);
	this->setGyroRange (MPU9250::GYRO_RANGE_500DPS);
	this->setDlpfBandwidth (MPU9250::DLPF_BANDWIDTH_20HZ);
	this->setSrd (__SRD);

	this->initializeRawData ();

	this->decimalsNumber = decimalsNumber;
	this->numberOfSamples = numberOfSamples;

	this->clock.restart (DEFAULT_TIME_CLOCK);
}

/**
 *  @brief: This method runs on loop function of program. This executes reads and
 *  run data interpretation at a set interval time.
 */
void Imu::loop () {
	if (this->clock.elapse ()) {

		this->read ();
		this->dataInterpretation ();

		if (this->theSample == this->numberOfSamples) {
			this->lastData = this->rawData;

			this->dataInterpretation ();
			this->initializeRawData ();
		}

		this->clock.restart ();
	}
}

/**
 *  @brief: This method initializes raw data with initial values.
 */
void Imu::initializeRawData () {
	this->theSample = FIRST_SAMPLE;

	this->rawData.ax = INITIAL_ACCELERATION;
	this->rawData.ay = INITIAL_ACCELERATION;
	this->rawData.az = INITIAL_ACCELERATION;

	this->rawData.ox = INITIAL_ORIENTATION;
	this->rawData.oy = INITIAL_ORIENTATION;
	this->rawData.oz = INITIAL_ORIENTATION;
	
	this->rawData.temperature = INITIAL_TEMPERATURE;
}

/**
 *  @brief: This function reads data from electronic 
 */
void Imu::read () {
	this->readSensor ();
}

/**
 *  @brief: This function make aritmethic of raw data by number of samples.
 */
void Imu::rawDataInterpretation () {

	byte newSample = this->theSample;

	newSample ++;

	this->rawData.ax = (this->rawData.ax * this->theSample + this->getAccelX_mss()) / newSample;
	this->rawData.ay = (this->rawData.ay * this->theSample + this->getAccelY_mss()) / newSample;
	this->rawData.az = (this->rawData.az * this->theSample + this->getAccelZ_mss()) / newSample;

	this->rawData.ox = (this->rawData.ox * this->theSample + this->getMagX_uT()) / newSample;
	this->rawData.oy = (this->rawData.oy * this->theSample + this->getMagY_uT()) / newSample;
	this->rawData.oz = (this->rawData.oz * this->theSample + this->getMagZ_uT()) / newSample;

	this->rawData.temperature = (this->rawData.temperature * this->theSample + this->getTemperature_C ()) / newSample;

	this->theSample = newSample;
}

/**
 *  @brief: This method calculates speed and depth.
 */
void Imu::dataInterpretation () {
	double ay = INITIAL_ACCELERATION;
	double az = INITIAL_ACCELERATION;

	double roll = this->getRoll ();
	double pitch = this->getPitch ();
	double yaw = this->getYaw ();

	ay += this->lastData.ax;
	ay += this->lastData.ay;
	ay += this->lastData.az;

	az += cos (roll) * this->lastData.ax;
	az += cos (yaw) * this->lastData.ay;
	az += cos (pitch) * this->lastData.az;

	this->divingSpeed += ay * this->clock.elapsedTimeFromStart ();
	this->speed += az * this->clock.elapsedTimeFromStart ();

	this->depth += this->divingSpeed * this->clock.elapsedTimeFromStart ();
}

/**
 *  @brief: This functions returns, speed in meters per second.
 *
 *  @return: calculated speed.
 */
double Imu::getSpeed () {
	return this->speed;
}

/**
 *  @brief: This functions returns depth of vehicle in meters.
 *
 *  @return: calculated depth.
 */
double Imu::getDepth () {
	return this->depth;
}

/**
 *  @brief: This function calculates and returns orientation
 *  of vehicle in degrees with: 
 *  -   0 on North,
 *  -  90 on East, 
 *  - 180 on South
 *  - 270 on West.
 *
 *  @return: calculated orientation.
 */
double Imu::getOrientation () {
	return 180.0 * atan2 (this->lastData.ox, this->lastData.oy) / M_PI;
}

/**
 *  @brief: This method calculates and returns roll in degrees.
 *
 *  @return: calculated roll.
 */
double Imu::getRoll () {
	double ax = 3.9 * this->lastData.ax;
	double ay = 3.9 * this->lastData.ay;
	double az = 3.9 * this->lastData.az;

	double roll = 180.0 * atan (ay / sqrt(ax * ax + az * az)) / M_PI;

	return roll;
}

/**
 *  @brief: This method calculates and returns pitch in degrees.
 *
 *  @return: calculated pitch.
 */
double Imu::getPitch () {
	double ax = 3.9 * this->lastData.ax;
	double ay = 3.9 * this->lastData.ay;
	double az = 3.9 * this->lastData.az;

	double pitch = 180.0 * atan (ax / sqrt(ay * ay + az * az)) / M_PI;

	return pitch;
}

/**
 *  @brief: This method calculates and returns yaw in degrees.
 *
 *  @return: calculated yaw.
 */
double Imu::getYaw () {
	double ax = 3.9 * this->lastData.ax;
	double az = 3.9 * this->lastData.az;

	double yaw = 180.0 * atan (az / sqrt(ax * ax + az * az)) / M_PI;

	return yaw;
}

/**
 *  @brief: This method returns temperature read by IMU.
 *
 *  @return: temperature read by IMU.
 */
double Imu::getTemperature () {
	return this->lastData.temperature;
}

/**
 *  @brief: This method returns if data wast changed after last
 *  last return of function.
 *
 *  @return: if data is different after last read.
 */
bool Imu::dataWasChanged () {
	if (this->dataChanged) {
		this->dataChanged = false;

		return true;
	}

	return false;
}