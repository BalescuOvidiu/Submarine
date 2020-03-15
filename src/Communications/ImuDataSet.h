/**
 *  ImuDataSet
 *
 *  Created 21 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 21 February 2020
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef IMU_DATA_SET_H_
#define IMU_DATA_SET_H_

/**
 *  @brief: 
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