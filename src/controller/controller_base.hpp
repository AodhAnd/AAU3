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

using namespace std;

class controllerInterface
{
public:
	virtual ~controllerInterface();
	virtual string getControllerName() = 0;
	virtual void writeDebug() = 0;
	virtual void runController() = 0;
};

class ControllerBase : public ShellClientInterface {
public:
	/*
	 * Controllers inheriting the base class must implement a creation function having this outline:
	 * static bool createController(string controllerName);
	 */
	ControllerBase(controllerInterface* pControllerIf);
	virtual ~ControllerBase();



public: // Implementing ShellClientInterface
	void receiveShellCommand(string* argv,unsigned int& argc);
	const char* getClientName();

private:
	ShellClient mShell;
};



#endif /* CONTROLLER_BASE_HPP_ */
