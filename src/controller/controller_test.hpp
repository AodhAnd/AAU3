/*
 * controller_test.hpp
 *
 *  Created on: 28/10/2014
 *      Author: benjaminkrebs
 */

#ifndef CONTROLLER_TEST_HPP_
#define CONTROLLER_TEST_HPP_

#include "controller_base.hpp"

class ControllerTest: public ControllerBase {
public:
	ControllerTest();

	static string getControllerNameStatic();

public: //Implementing ControllerBase
	string getControllerName();
	void writeDebug();
	void runController();

private:
	string mControllerName;
};



#endif /* CONTROLLER_TEST_HPP_ */
