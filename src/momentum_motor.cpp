/*
 * momentum_motor.cpp
 *
 *  Created on: 04/09/2014
 *      Author: benjaminkrebs
 */

#define RPM_MAX 1000

#include "../inc/momentum_motor.hpp"

MomentumMotor::MomentumMotor(const char* idName, BbbGpio::gpio_port_t gpioPort, BbbAdc::analog_in_t analogIn)
:
mState(MOTOR_STATE_IDLE),
mName(idName),
mShellClient(mName,this),
mEnableGpio(gpioPort,false,BbbGpio::BBB_GPIO_DIRECTION_OUT),
mRpmAdc(analogIn)
{
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

signed int MomentumMotor::getRpm()
{
	signed int rv = 0;
	//ADD SOME CALCULATIONS OF RPM
	rv = mRpmAdc.get();
	return rv;
}

void MomentumMotor::emergencyBreak()
{

}

void MomentumMotor::setRpm(unsigned int rpm)
{

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
