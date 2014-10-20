/*
 * controller.hpp
 *
 *  Created on: 26/08/2014
 *      Author: benjaminkrebs
 */

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_
#include <imu.hpp>

class controller {

	/* Class should inherit from Thread.
	 *
	 * New controllers should inherit this class and define the control loop.
	 *class PIcontroller : public controller {
	 *	void loop(){
	 *		bla bla bla
	 *	}
	 *}
	 *
	 *The below is a suggestion for behavior.
	 *
	 *
	 */
public:
	controller(controller&);
	controller(Imu* pImu[], MomentumMotor* pMotor[]);
	~controller();
	void setPeriod(int time); // set period time in us.
	int getPeriod();
	virtual void loop(); // Define control loop. May contain awesome controller as default.
	int start(); //Start Control loop. Returns 0 if no error?
	void stop(); //Stop Control loop.


private:
	int _time;
	Imu *_pImus[];
	MomentumMotor *_pMotors[];

	int getImu(int imu); // Potentially split into different variables instead with a behind the scenes update function to guarantee that all IMUs are sampled at the same time?
	int setMotor(int motor, int speed); //Same thing, should another function be called which actually writes motor values at the same time, at the end of the loop function?

};



#endif /* CONTROLLER_HPP_ */
