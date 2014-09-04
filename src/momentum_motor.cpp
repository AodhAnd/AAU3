/*
 * momentum_motor.cpp
 *
 *  Created on: 04/09/2014
 *      Author: benjaminkrebs
 */

#define RPM_MAX 1000

#include <pigpio.h>

MomentumMotor::MomentumMotor(unsigned int cwPin, unsigned int ccwPin,unsigned int breakServoPwmPin, AdcDac* adcDac)
:
mAdcDac(adcDac),
mServo(breakServoPwmPin),
mState(MOTOR_STATE_IDLE)
{
	mDirectionsPins.ccw = ccwPin;
	mDirectionsPins.cw = cwPin;

	//Set all the motor stuff such that it doesn't run!
	stopMotorController();
	setBreak();
	setRpm(0);

}

MomentumMotor::~MomentumMotor()
{

}


bool MomentumMotor::hasState(motor_state state)
{
	return mState;
}

void MomentumMotor::setDirection(motor_direction dir)
{

}

void MomentumMotor::setBreak()
{

}

void MomentumMotor::emergencyBreak()
{

}

void MomentumMotor::setRpm(unsigned int rpm)
{
	if(rpm>RPM_MAX)
		mRpmSetPoint = RPM_MAX;
	else
		mRpmSetPoint = rpm;
}

void MomentumMotor::startMotorController(void)
{

}

void MomentumMotor::stopMotorController(void)
{

}

void MomentumMotor::motorController(void)
{

}

