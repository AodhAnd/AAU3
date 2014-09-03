/*
 * momentum_motor.cpp
 *
 *  Created on: 31/08/2014
 *      Author: benjaminkrebs
 */

#include <stdio.h>
#include <iostream>
#include <boost/thread.hpp>

#include "../inc/break_servo.hpp"
#include "../inc/adc_dac.hpp"
//this
#include "../inc/momentum_motor.hpp"

MomentumMotor::MomentumMotor(unsigned int cwPin, unsigned int ccwPin,unsigned int breakServoPwmPin, AdcDac* adcDac)
:
mAdcDac(adcDac),
mServo(new BreakServo(breakServoPwmPin))
{
	mDirectionsPins.ccw = ccwPin;
	mDirectionsPins.cw = cwPin;
}

MomentumMotor::~MomentumMotor()
{

}

void MomentumMotor::setRpm(unsigned int rpm, unsigned int direction) //1: cw, 0:ccw
{

}

void MomentumMotor::startMotorController(void)
{
	mControlThread(motorController);
}


void MomentumMotor::motorController(void)
{
	std::cout << "motor controller called" <<std::endl;
}

void MomentumMotor::stopMotorController(void)
{
	mControlThread.join();
}

bool MomentumMotor::hasState(motor_state state)
{

}

void MomentumMotor::setBreak()
{

}

void MomentumMotor::emergencyBreak()
{

}
