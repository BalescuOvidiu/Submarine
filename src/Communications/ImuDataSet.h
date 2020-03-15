/**
<<<<<<< HEAD
 *  ImuDataSet
 *
 *  Created 21 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 21 February 2020
=======
 *  ImuDataSet.h
 *
 *  Created 21 February 2020
 *  By Balescu Ovidiu-Gheorghe
 *  Modified 24 February 2020
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
 *  By Balescu Ovidiu-Gheorghe
 */

#ifndef IMU_DATA_SET_H_
#define IMU_DATA_SET_H_

/**
<<<<<<< HEAD
 *  @brief: 
=======
 *  @brief: This structure stores data read by IMU: acceleration
 *  on each axe, orientation on each axe and temperature.
>>>>>>> 634d4fed421c6f6c78d502a595731b23bf906e21
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