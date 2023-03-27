/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "Projects.h"
#define F_CPU 16000000UL

int main()
{
	M_DIO_Void_SetPinDirection(ON_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(PWM_PIN,OUTPUT);

	M_Timer_Void_PWMInit();
	H_LCD_Void_LCDInit();

		while (1)
		{
			M_Timer_Void_PWMStart();
			M_Timer_Void_PWMDutyOsc();
			H_LCD_Void_LCDClear();
			_delay_ms(10);
		}

	return 0;
}
