/**
 *  ImuDataSet.h
 *
 *  Created 21 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 24 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef IMU_DATA_SET_H_
#define IMU_DATA_SET_H_

/**
 *  @brief: This structure stores data read by IMU: acceleration
 *  on each axe, orientation on each axe and temperature.
 */
struct ImuDataSet {
	double ax;
	double ay;
	double az;

	double ox;
	double oy;
	double oz;

	double temperature;
};

#endif