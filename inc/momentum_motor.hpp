/*
 * momentumMotor.hpp
 *
 *  Created on: 26/08/2014
 *      Author: benjaminkrebs
 */

#ifndef MOMENTUMMOTOR_HPP_
#define MOMENTUMMOTOR_HPP_

#include "break_servo.hpp"
#include "adc_dac.hpp"


class MomentumMotor {
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

	MomentumMotor(unsigned int cwPin, unsigned int ccwPin,unsigned int breakServoPwmPin, AdcDac* adcDac);
	~MomentumMotor();

	bool hasState(motor_state state);
	void setBreak();
	void setDirection(motor_direction dir);
	void emergencyBreak();
	void setRpm(unsigned int rpm);
	void startMotorController(void);
	void stopMotorController(void);
private:
	motor_state mState;
	BreakServo mServo;
	AdcDac* mAdcDac; //for setting the speed and reading the motorcontroller outputs
	struct directionPins mDirectionsPins;

	//Motorcontrol
	void motorController(void);
	unsigned int mRpmSetPoint;

};



#endif /* MOMENTUMMOTOR_HPP_ */
