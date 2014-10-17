/*
 * shell_server.cpp
 *
 *  Created on: 12/10/2014
 *      Author: benjaminkrebs
 */


#include "shell_server.hpp"

ShellServer* ShellServer::mInstance = NULL;

ShellServer* ShellServer::getInstance()
{
	if(mInstance == NULL)
	{
		mInstance = new ShellServer;
	}

	return mInstance;
}


ShellServer::ShellServer()
:
mNofRegisteredClients(0),
mShellName("shell")
{

}

void ShellServer::setShellName(const char* shellName)
{
	mShellName = shellName;
}

void ShellServer::startShell()
{
	bool shellRunning = true;
	char cmdIn[10000];

	while(shellRunning)
	{
		cout << mShellName << "# ";
		cin >> cmdIn;
		cout << "Command received: " << cmdIn << endl;

		if(strcmp(cmdIn,"stop") == 0)
		{
			shellRunning = false;
		}
		else if(strcmp(cmdIn,"shellStatus") == 0)
		{
			cout << "Shell Name: " << mShellName << endl;
			cout << "Nof Client: " << mNofRegisteredClients << endl;
		}
		else
		{
			for(unsigned int i=0;i<mNofRegisteredClients;i++)
			{
				//if(strcmp(mClients[i].clientName,cmdIn) == 0)
				{
					mClients[i].shellIf->receiveShellCommand(cmdIn);
				}
			}
		}



		memset(&cmdIn,0,10000);
	}
}



bool ShellServer::registerNewClient(const char* clientName, ShellClientInterface* shell_if)
{
	for(unsigned int i=0;i<mNofRegisteredClients;i++)
	{
		if(strcmp(mClients[i].clientName,clientName) == 0)
		{
			cout<<"Clients name already registered: "<< clientName << endl;
			return false;
		}
	}

	mClients[mNofRegisteredClients].clientName = clientName;
	mClients[mNofRegisteredClients++].shellIf = shell_if;

	cout<<"Shell client registered: " << clientName << endl;

	return true;
}
