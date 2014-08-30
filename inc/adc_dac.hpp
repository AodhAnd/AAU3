/*
 * adc_dac.hpp
 *
 *  Created on: 25/08/2014
 *      Author: benjaminkrebs
 *
 *  Notes:
 *  	Made especially to interface with the PCF8591
 */

#ifndef ADC_DAC_HPP_
#define ADC_DAC_HPP_

#include "types.hpp"
#include "i2c.hpp"

class AdcDac {
public:
	AdcDac(U8 i2cAddr);
	~AdcDac();
	U8 readAdc(void);
	void setDac(U8 val);

private:
	I2C mI2C;
};



#endif /* ADC_DAC_HPP_ */
