/*
 * main.cpp
 *
 *  Created on: 27/08/2014
 *      Author: benjaminkrebs
 */


#include <iostream>
#include <stdio.h>
#include "../inc/converter.hpp"
//#include <boost/thread/thread.hpp>
#include "../inc/i2c.hpp"
#include "../inc/imu.hpp"
#include "../inc/io_service.hpp"


#define IMU1_ADDR 0x68

int main()
{

	std::cout << "/****************** AAU^3 ******************/" <<std::endl;
	//Create necessary objects

	I2C i2cIf("/dev/i2c-1");
	Imu imu1(IMU1_ADDR,&i2cIf);
	IoService* ioService = IoService::getInstance();

	ioService->tx("A hello! from AAU3\n");

/*
	for(int i=0;i<100000;i++)
	{
		std::cout << (int)imu1.getAccX() << std::endl;
	}
*/

	//initiate the threads

	//wait for threads to get terminated

	return 0;
}
