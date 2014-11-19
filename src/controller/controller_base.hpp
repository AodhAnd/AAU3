/*
 * controller_base.hpp
 *
 *  Created on: 28/10/2014
 *      Author: benjaminkrebs
 */

#ifndef CONTROLLER_BASE_HPP_
#define CONTROLLER_BASE_HPP_

#include <iostream>
#include "../shell_if/shell_client.hpp"
#include "controller_factory.hpp"
#include "../posix_thread/posix_thread.hpp"
#include "../../inc/i2c.hpp"
#include "../../inc/imu.hpp"
#include "../../inc/momentum_motor.hpp"


using namespace std;

class ControllerCbIf;

class ControllerArgs
{
public:
	ControllerArgs(Imu *imu1,Imu *imu2,MomentumMotor *motor, BbbAdc *potAdc, ControllerCbIf* pControllerIf, bool *debugEnable)
	:
	mImu1(imu1),
	mImu2(imu2),
	mMotor(motor),
	mPotAdc(potAdc),
	mpControllerIf(pControllerIf),
	mDebugEnable(debugEnable)
	{

	}
	~ControllerArgs() {}

	ControllerCbIf* mpControllerIf;
	Imu *mImu1;
	Imu *mImu2;
	MomentumMotor *mMotor;
	BbbAdc *mPotAdc;
	bool *mDebugEnable;
};


class ControllerCbIf
{
public:
	virtual ~ControllerCbIf()
	{}

	virtual const char* getControllerName() = 0;
	virtual void writeDebug() = 0;
	virtual void runController(ControllerArgs* args) = 0;
	virtual unsigned int getPeriodicityMs() = 0;
};


class ControllerBase : public ShellClientInterface {
public:




	/*
	 * Controllers inheriting the base class must implement a creation function having this outline:
	 * static bool createController(string controllerName);
	 */
	ControllerBase(ControllerCbIf* pControllerIf);
	virtual ~ControllerBase();

	void* controller(void* args);
	static void* controllerStatic(void* args);

public: // Implementing ShellClientInterface
	void receiveShellCommand(string* argv,unsigned int& argc);
	const char* getClientName();

private:
	bool mDebugEnable;
	ControllerCbIf* mpControllerIf;
	ShellClient mShell;
	PosixThread* mpThread;
	I2C mI2c;
	Imu mImu1;
	Imu mImu2;
	BbbAdc mPotAdc;
	MomentumMotor mMotor;
	//Imu mImu2;

	ControllerArgs mControllerArgs;
};



#endif /* CONTROLLER_BASE_HPP_ */
