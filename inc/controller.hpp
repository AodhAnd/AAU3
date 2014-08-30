/*
 * controller.hpp
 *
 *  Created on: 26/08/2014
 *      Author: benjaminkrebs
 */

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

class controller {
/*
 * Everything that is needed to interface with the python controller.
 * The constructor could specify whether a python script is used or one
 * wants to implement the controller in cpp
 */
public:
	controller(controller&);
	controller(Imu* pImu1, Imu* pImu2, MomentumMotor* pMotor, bool pythonImpl);
	~controller();

private:
	bool isPython;
};



#endif /* CONTROLLER_HPP_ */
