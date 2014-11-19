/*
 * controller_test.cpp
 *
 *  Created on: 29/10/2014
 *      Author: benjaminkrebs
 */


#include "controller_test.hpp"
#include "controller_factory.hpp"

ControllerTest::ControllerTest()
:
ControllerBase(this)
{
	ControllerFactory::registerController(&createController);
}

const char* ControllerTest::getControllerNameStatic()
{
	return "TestCtrl";
}

unsigned int ControllerTest::getPeriodicityMsStatic()
{
	return 5000;
}


//Implementing ControllerCbIf
const char* ControllerTest::getControllerName()
{
	return getControllerNameStatic();
}

unsigned int ControllerTest::getPeriodicityMs()
{
	return getPeriodicityMsStatic();
}

void ControllerTest::writeDebug()
{
	std::cout<<"This is DEBUG for TestCtrl"<<std::endl;
}

void ControllerTest::runController(ControllerArgs* args)
{
	static bool value = true;
	value=!value;
	std::cout<<"TestCtrl::runController()"<<std::endl;

	//Read parameters
	int xAcc1 = args->mImu1->getAccX();
	int yAcc1 = args->mImu1->getAccY();
	//int zAcc1 = args->mImu1->getAccZ();
	//int gyroX1 = args->mImu1->getGyroX();
	//int gyroY1 = args->mImu1->getGyroY();
	int gyroZ1 = args->mImu1->getGyroZ();

	int xAcc2 = args->mImu2->getAccX();
	int yAcc2 = args->mImu2->getAccY();
	//int zAcc2 = args->mImu2->getAccZ();
	//int gyroX2 = args->mImu2->getGyroX();
	//int gyroY2 = args->mImu2->getGyroY();
	int gyroZ2 = args->mImu2->getGyroZ();


	int potAdc = args->mPotAdc->get();
	int rpmAdc = args->mMotorAdc1->get();
	int powerAdc = args->mMotorAdc2->get();

	int potDeg = (-(potAdc-1800))*(470/90)-45;

	std::cout << "Power: " << powerAdc << " RPM: " << rpmAdc << " POT:" << potDeg <<  std::endl;
	std::cout << "X:" << xAcc1 << "/" << xAcc2 << " Y:" << yAcc1 << "/" << yAcc2 << std::endl;
	std::cout << "Z:" << gyroZ1 << "/" << gyroZ2 << std::endl;


	//Controller stuff
	double x=0,y=0;
	for(unsigned int i=0;i<1000;i++)
	{
		y++;
		x++;
		x = x*y;
	}


	//Set motor parameters

}

ControllerBase* ControllerTest::createController(string& name)
{
	return new ControllerTest;
}

//REGISTER_CONTROLLER(ControllerTest);
