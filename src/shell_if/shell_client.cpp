/*
 * shell_client.cpp
 *
 *  Created on: 14/10/2014
 *      Author: benjaminkrebs
 */


#include "shell_client.hpp"
#include "shell_server.hpp"

ShellClient::ShellClient(const char* clientName, ShellClientInterface* shell_if)
{
	mShellServer = ShellServer::getInstance();

	if(mShellServer != NULL)
	{
		mShellServer->registerNewClient(clientName,shell_if);
	}
	else
	{
		DEBUG_MSG("ShellClient(" << clientName << ")","ShellServer Instance returned NULL");
	}
}

ShellClient::~ShellClient()
{
	mShellServer = NULL;
}
