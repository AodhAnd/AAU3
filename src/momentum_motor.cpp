/*
 * momentum_motor.cpp
 *
 *  Created on: 04/09/2014
 *      Author: benjaminkrebs
 */

#define RPM_MAX 1000

#include "../inc/momentum_motor.hpp"

MomentumMotor::MomentumMotor(const char* idName, unsigned int cwPin, unsigned int ccwPin,unsigned int breakServoPwmPin)
:
mState(MOTOR_STATE_IDLE),
mName(idName),
mShellClient(mName,this)
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
	switch (dir) {
		case MOTOR_DIRECTION_CCW:

			break;
		case MOTOR_DIRECTION_CW:

			break;
	}
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


void MomentumMotor::receiveShellCommand(string* argv,unsigned int& argc)
{
	if(argc == 0)
	{
		cout<<endl<<mName<<" commands:"<<endl;
		cout<<"+"<<"stop"<<endl;
		cout<<"+"<<"rpm <value>"<<endl;

		cout<<endl;
	}
	else if(argv[1].compare("stop") == 0)
	{
		setRpm(0);
	}
	else if(argv[1].compare("rpm") == 0)
	{
		setRpm(atoi(argv[2].c_str()));
	}
	else
	{
		cout << mName << " received an unknown command"<<endl;
	}
}

const char* MomentumMotor::getClientName()
{
	return mName;
}
