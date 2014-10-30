/*
 * set.cpp
 *
 *  Created on: 30/10/2014
 *      Author: frederik
 */

#include "shell_client.hpp"
#include "shell_server.hpp"

class setClass : public ShellClientInterface{

public:
	void receiveShellCommand(string* argv, unsigned int& argc){
		if(argc == 0){
			cout << "set commands:"<<endl;
			cout << "set <num> active_low 0/1" << endl;
			cout << "set <num> direction in/out" <<endl;
			cout << "set <num> value 0/1" << endl;
		}
		else if(argc == 3){
			string num = argv[1];
			string cmd = argv[2];
			string val = argv[3];

			cout << "Received: " << argv[1] << argv[2] << argv[3] << endl;

		}
		else{
			cout << "set: Command not recognized" << endl;
		}
	}

	const char* getClientName(){
		return mName;
	}
private:
	ShellClient mShellClient;
	const char* mName;

public:
	setClass(const char* name="set"):mShellClient(mName,this){
		mName = "set";
	}

};

int main(){
	ShellServer* shellServer = ShellServer::getInstance();
	shellServer->setShellName("aaush");

	setClass set();

	shellServer->startShell();

	return 0;
}


