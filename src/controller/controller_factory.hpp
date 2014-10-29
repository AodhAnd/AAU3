/*
 * controller_factory.hpp
 *
 *  Created on: 28/10/2014
 *      Author: benjaminkrebs
 */

#ifndef CONTROLLER_FACTORY_HPP_
#define CONTROLLER_FACTORY_HPP_

#include "../shell_if/shell_client.hpp"

class ControllerFactory : public ShellClientInterface{
public:
	typedef bool (*createFunc)(string&);
	static ControllerFactory* getInstance();
	~ControllerFactory();

	static void registerController(createFunc);

public:
	void receiveShellCommand(string* argv,unsigned int& argc);
	const char* getClientName();

private:
	ControllerFactory();

	static ControllerFactory* mInstance;
	ShellClient mShell;


	static createFunc functions[100];
	static unsigned int mNumControllers;
	const char* mName;

};



#endif /* CONTROLLER_FACTORY_HPP_ */
