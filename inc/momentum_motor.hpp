/*
 * momentumMotor.hpp
 *
 *  Created on: 26/08/2014
 *      Author: benjaminkrebs
 */

#ifndef MOMENTUMMOTOR_HPP_
#define MOMENTUMMOTOR_HPP_

#include "../src/shell_if/shell_client.hpp"
#include <iostream>

using namespace std;

class MomentumMotor: public ShellClientInterface
{
public:
	enum motor_state
	{	MOTOR_STATE_IDLE,
		MOTOR_STATE_ROTATING,
		MOTOR_STATE_BREAKING
	};
	enum motor_direction {
		MOTOR_DIRECTION_CW,
		MOTOR_DIRECTION_CCW
	};

	struct directionPins {
		unsigned int cw;
		unsigned int ccw;
	};

	MomentumMotor(const char* idName, unsigned int cwPin, unsigned int ccwPin,unsigned int breakServoPwmPin);
	~MomentumMotor();

	bool hasState(motor_state state);
	void setBreak();
	void setDirection(motor_direction dir);
	void emergencyBreak();
	void setRpm(unsigned int rpm);
	void startMotorController(void);
	void stopMotorController(void);

public: //Implementing Shell
	void receiveShellCommand(string* argv,unsigned int& argc);
	const char* getClientName();

private:
	motor_state mState;
	struct directionPins mDirectionsPins;

	//Motorcontrol
	void motorController(void);
	unsigned int mRpmSetPoint;
	const char* mName;
	ShellClient mShellClient;

};



#endif /* MOMENTUMMOTOR_HPP_ */
