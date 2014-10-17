/*
 * test.cpp
 *
 *  Created on: 12/10/2014
 *      Author: benjaminkrebs
 */

#include "shell_server.hpp"
#include "shell_client.hpp"

class testClass : public ShellClientInterface
{

public:
	void receiveShellCommand(const char* cmd){
		if(strcmp(cmd,"test")==0)
		{
			cout<<"TestClass received test command!"<<endl;
		}
		else
		{
			cout << "TestClass received unknown command" << endl;
		}
	}

private:
	ShellClient mShellClient;
public:
	testClass():mShellClient("TestClass",this){

	}

};


int main()
{
	ShellServer* shellServer = ShellServer::getInstance();
	shellServer->setShellName("testShell");

	testClass test;

	shellServer->startShell();


	return 0;
}
