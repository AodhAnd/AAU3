/*
 * imu.cpp
 *
 *  Created on: 29/08/2014
 *      Author: benjaminkrebs
 */



#include <iostream>
#include <stdio.h>
#include "../inc/i2c.hpp"

//This
#include "../inc/imu.hpp"

Imu::Imu(U8 i2cAddr,I2C* i2cObj)
:
mpI2C(i2cObj),
mI2cAddr(i2cAddr)
{
	setSleepMode(false);
	printf("IMU at 0x%X says hello..\n",i2cAddr);
}

Imu::~Imu()
{
	setSleepMode(true);
}

void Imu::setSleepMode(bool mode)
{
	U8 val = mode?0x00:0x40;
	writeByte(val,MPU6050_PWR_MGMT_1);
}

U8 Imu::getSleepMode()
{
	U8 modeOut;
	readByte(&modeOut,MPU6050_PWR_MGMT_1);
	return modeOut;
}


void Imu::writeByte(U8 val, U8 fromReg)
{
	U8 buffer[] = {fromReg,val}; //First transmit the register address to write to, then the value
	mpI2C->writeI2C(buffer,2,mI2cAddr);
}

void Imu::readByte(U8* buffer, U8 fromReg)
{
	mpI2C->writeI2C(&fromReg,1,mI2cAddr);
	mpI2C->readI2C(buffer,1,mI2cAddr);
}

void Imu::readData(U8* buffer, unsigned int readLength, U8 fromReg)
{
	mpI2C->writeI2C(&fromReg,1,mI2cAddr);
	mpI2C->readI2C(buffer,readLength,mI2cAddr);
}

U16 Imu::getAccX(void)
{
	U8 xAcc[2] = {0,0};
	readData(xAcc,2,MPU6050_ACCEL_X_H);

	U16 X;

	return X;
}

