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
	setSleep(false);
	printf("IMU at 0x%X says hello..\n",i2cAddr);
}

Imu::~Imu()
{
	setSleep(true);
}

void Imu::setSleep(bool mode)
{
	U8 val = mode?0x40:0x00;
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

signed int Imu::getAccX(void)
{
	U8 Acc[2] = {0,0};
	readData(Acc,2,MPU6050_ACCEL_X_H);
	return Acc;
}

signed int Imu::getAccY(void)
{
	U8 Acc[2] = {0,0};
	readData(Acc,2,MPU6050_ACCEL_Y_H);
	return Acc;
}


signed int Imu::getAccZ(void)
{
	U8 Acc[2] = {0,0};
	readData(Acc,2,MPU6050_ACCEL_Z_H);
	return Acc;
}

/*
Imu::accAll_t Imu::getAccAll(void)
{
	accAll_t accel;
	U8 buffer[6];
	readData(buffer,6,MPU6050_ACCEL_X_H);
	accel.X = convertFromTwosComplement(buffer[0],buffer[1]);
	accel.Y = convertFromTwosComplement(buffer[2],buffer[3]);
	accel.Z = convertFromTwosComplement(buffer[4],buffer[5]);
	return accel;
}
*/
