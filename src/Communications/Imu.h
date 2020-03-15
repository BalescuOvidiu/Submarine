/**
 *  Imu.h
 *
 *  Created 18 February 2020
 *  By Balescu Ovidiu-Gheorghe
<<<<<<< HEAD
 *  Modified 21 February 2020
=======
 *  Modified 24 February 2020
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef IMU_H_
#define IMU_H_

#include <Arduino.h>

#include "ImuDataSet.h"
#include "MPU9250.h"
#include "TimeInterval.h"
<<<<<<< HEAD
#include "ImuDataSet.h"
=======
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21

/**
 *  @brief: This class controls a IMU device connected
 *  to Arduino with IC2. This has special functions to
 *  filters data, and to calculate differents parameters:
 *  orientation, speeds and depth.
 */
<<<<<<< HEAD
class Imu {

public:
	Imu (int address);
=======
class Imu : MPU9250 {

public:
	Imu (TwoWire &bus,uint8_t address);
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
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

<<<<<<< HEAD
=======
	double getTemperature ();

>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
	bool dataWasChanged ();

private:
	TimeInterval clock;
<<<<<<< HEAD
	MPU2950 device;
=======
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21

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