/*
 * main.cpp
 *
 *  Created on: 27/08/2014
 *      Author: benjaminkrebs
 */


#include <iostream>
#include <stdio.h>
//#include <boost/thread/thread.hpp>
#include "../inc/i2c.hpp"
#include "../inc/imu.hpp"


#define IMU1_ADDR 0x68

int main()
{
	std::cout << "/****************** AAU^3 ******************/" <<std::endl;
	//Create necessary objects
	I2C i2cIf("/dev/i2c-1");
	Imu imu1(IMU1_ADDR,&i2cIf);


	printf("sleepmode: %X\n",imu1.getSleepMode());
	imu1.setSleepMode(true);
	printf("sleepmode: %X\n",imu1.getSleepMode());



	for(int i=0;i<10000;i++)
	{
		std::cout << (int)imu1.getAccX() << std::endl;
	}

	//initiate the threads

	//wait for threads to get terminated

	return 0;
}
