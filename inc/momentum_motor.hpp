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
	typedef enum
	{	MOTOR_STATE_IDLE,
		MOTOR_STATE_ROTATING,
		MOTOR_STATE_BREAKING
	} state_t;

	MomentumMotor(unsigned int cwPin, unsigned int ccwPin,unsigned int breakServoPwmPin, U8 adcDacI2cAddr);
	~MomentumMotor();

	bool hasState(state_t state);
	void setBreak();
	void emergencyBreak();
private:
	BreakServo mServo;
	AdcDac mAdcDac; //for setting the speed and reading the motorcontroller outputs
};



#endif /* MOMENTUMMOTOR_HPP_ */
