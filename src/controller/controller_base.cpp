/*
 * controller_base.cpp
 *
 *  Created on: 29/10/2014
 *      Author: benjaminkrebs
 */

#include "controller_base.hpp"

#define IMU1_PATH "/dev/i2c-1"

ControllerBase::ControllerBase(ControllerCbIf* pControllerIf)
:
mpControllerIf(pControllerIf),
mShell("",this),
mDebugEnable(false),
mpThread(NULL),
mI2c(IMU1_PATH),
mImu1(0x69,&mI2c),
mControllerArgs(&mImu1,mpControllerIf,&mDebugEnable)
{
//mShell(mpControllerIf->getControllerName(),this),

}

ControllerBase::~ControllerBase()
{
	delete mpThread;
}



// Implementing ShellClientInterface
void ControllerBase::receiveShellCommand(string* argv,unsigned int& argc)
{
	if(argc == 0)
	{
		cout<<endl<<mpControllerIf->getControllerName()<<" commands:"<<endl;
		cout<<"+"<<"stop"<<endl;
		cout<<"+"<<"run"<<endl;

		cout<<endl;
	}
	else if(argv[1].compare("stop") == 0)
	{

		if(mpThread!=NULL)
		{
			mpThread->stopThread();
			delete mpThread;
			mpThread = NULL;
		}

	}
	else if(argv[1].compare("run") == 0)
	{

		if(mpThread==NULL)
		{
			mpThread = new PosixThread(&controllerStatic,mpControllerIf->getPeriodicityMs(),2);
			mpThread->startThread((void*)&mControllerArgs);
		}
		else
			cout<<"Controller is already running... Stop it and run it again."<<endl;

	}
	else if(argv[1].compare("debug") == 0)
	{
		mDebugEnable = !mDebugEnable;

		if(mDebugEnable)
			cout<<"Debug Enabled"<<endl;
		else
			cout<<"Debug Disabled"<<endl;

		*mControllerArgs.mDebugEnable = mDebugEnable;
	}
	else
	{
		cout << mpControllerIf->getControllerName() << " received an unknown command"<<endl;
	}
}


void* ControllerBase::controllerStatic(void* args)
{

	ControllerArgs* controllerArgs = (ControllerArgs*)args;

	if(controllerArgs->mpControllerIf != NULL)
	{
		//controllerArgs->mpControllerIf->writeDebug();
		controllerArgs->mpControllerIf->runController(controllerArgs);
	}
	return NULL;
}

const char* ControllerBase::getClientName()
{
	return mpControllerIf->getControllerName();
}
