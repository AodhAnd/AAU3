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
	return 5000*2;
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
	int xAcc = args->mImu1->getAccX();
	int yAcc = args->mImu1->getAccY();
	int zAcc = args->mImu1->getAccZ();


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
