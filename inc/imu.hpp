/*
 * imu.hpp
 *
 *  Created on: 25/08/2014
 *      Author: benjaminkrebs
 */

#ifndef IMU_HPP_
#define IMU_HPP_

#include "types.hpp"
#include "i2c.hpp"

/* Register Addresses*/
#define MPU6050_ACCEL_CONFIG	0x1C
#define MPU6050_ACCEL_X_H 		0x3B
#define MPU6050_ACCEL_X_L 		0x3C
#define MPU6050_ACCEL_Y_H 		0x3D
#define MPU6050_ACCEL_Y_L 		0x3E
#define MPU6050_ACCEL_Z_H 		0x3F
#define MPU6050_ACCEL_Z_L 		0x40

#define MPU6050_GYRO_CONFIG		0x1B
#define MPU6050_GYRO_X_H  		0x43
#define MPU6050_GYRO_X_L  		0x44
#define MPU6050_GYRO_Y_H  		0x45
#define MPU6050_GYRO_Y_L  		0x46
#define MPU6050_GYRO_Z_H  		0x47
#define MPU6050_GYRO_Z_L  		0x48


#define MPU6050_TEMP_H    		0x41
#define MPU6050_TEMP_L    		0x42

#define MPU6050_INT_STATUS    	0x3A

#define MPU6050_SMPLRT_DIV	    0x19

#define MPU6050_PWR_MGMT_1		0x6B
#define MPU6050_PWR_MGMT_2		0x6C



class Imu
{
public:
	Imu(U8 i2cAddr,I2C* i2cObj);
	~Imu();

	typedef struct{
		U16 X;
		U16 Y;
		U16 Z;
	} accAll_t;

	typedef struct{
		U16 X;
		U16 Y;
		U16 Z;
	} gyroAll_t;

	typedef struct{
		gyroAll_t gyro;
		accAll_t acc;
	}allSens_t;


	//get'ers
	U16 getAccX(void);
	U16 getAccY(void);
	U16 getAccZ(void);
	accAll_t getAccAll(void);


	U16 getGyroX(void);
	U16 getGyroY(void);
	U16 getGyroZ(void);
	gyroAll_t getGyroAll(void);

	allSens_t getAllSens(void);

	U16 getTemp(void);

	//set'ers
	void setSleepMode(bool mode);
	U8 getSleepMode();

private:
	I2C* mpI2C;
	U8 mI2cAddr;

	void writeByte(U8 val, U8 fromReg);
	void writeWord(U8 val, U8 fromReg);
	void readByte(U8* buffer, U8 fromReg);
	void readData(U8* buffer, unsigned int readLength, U8 fromReg);



};



#endif /* IMU_HPP_ */
