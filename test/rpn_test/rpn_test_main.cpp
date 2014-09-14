/*
 * rpn_test_main.cpp
 *
 *  Created on: 13/09/2014
 *      Author: benjaminkrebs
 */


#include "../../inc/reverse_polish_notation_calculator.hpp"
#include "../../inc/shunting_yard.hpp"
#include <iostream>
#include <vector>

int main()
{


	std::string mathString = std::string("3*3/(2+2)");

	ShuntingYardParser syParser;
	std::vector<ShuntingYardToken> mathVec = syParser.parseExpression(mathString);

	/*
	std::vector<ShuntingYardToken> mathVec;
	mathVec.push_back(ShuntingYardToken(10));
	mathVec.push_back(ShuntingYardToken(3));
	mathVec.push_back(ShuntingYardToken(ShuntingYardToken::operators::MINUS));
	mathVec.push_back(ShuntingYardToken(3));
	mathVec.push_back(ShuntingYardToken(ShuntingYardToken::operators::MINUS));
	mathVec.push_back(ShuntingYardToken(ShuntingYardToken::operators::SQRT));
*/

	RpnCalculator rpnCalc;

	rpnCalc.setEquation(mathVec);

	double eval = rpnCalc.evaluateExpression();

	std::cout<< "Expression evaluated to: " << eval << std::endl;
}
