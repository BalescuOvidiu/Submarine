/**
 *  Imu.h
 *
 *  Created 18 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 24 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef IMU_H_
#define IMU_H_

#include <Arduino.h>

#include "ImuDataSet.h"
#include "MPU9250.h"
#include "TimeInterval.h"

/**
 *  @brief: This class controls a IMU device connected
 *  to Arduino with IC2. This has special functions to
 *  filters data, and to calculate differents parameters:
 *  orientation, speeds and depth.
 */
class Imu : MPU9250 {

public:
	Imu (TwoWire &bus,uint8_t address);
	~Imu ();

	void setup (byte decimalsNumber, byte numberOfSamples);
	void loop ();

	void initializeRawData ();
	void read ();
	void rawDataInterpretation ();
	void dataInterpretation ();

	double getSpeed ();
	double getDepth ();
	double getOrientation ();

	double getRoll ();
	double getPitch ();
	double getYaw ();

	double getTemperature ();

	bool dataWasChanged ();

private:
	TimeInterval clock;

	ImuDataSet rawData;
	ImuDataSet lastData;

	byte decimalsNumber;
	byte numberOfSamples;
	byte theSample;

	bool dataChanged;

	double speed;
	double divingSpeed;
	double depth;
};

#endif