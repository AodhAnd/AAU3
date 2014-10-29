/*
 * main.cpp
 *
 *  Created on: 27/08/2014
 *      Author: benjaminkrebs
 */


#include <iostream>
#include <stdio.h>
using namespace std;

#include "shell_if/shell_server.hpp"
#include "../inc/momentum_motor.hpp"
//#include "beaglebone_black/beaglebone_black.hpp"


#define IMU1_ADDR 0x68

int main()
{
	cout << "/****************** AAU^3 ******************/" <<endl<<endl;
	//Create necessary objects
	ShellServer* shell = ShellServer::getInstance();
	shell->setShellName("AAU3");
	MomentumMotor motor("motor1",1,1,1);


	//initiate the threads

	//Always start the shell as the last module
	shell->startShell();

	//wait for threads to get terminated

	return 0;
}
