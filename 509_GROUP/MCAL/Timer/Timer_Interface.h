/*
 * Timer_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

#include "Timer_Config.h"
#include "Timer_Private.h"
#include "DIO_Interface.h"
#include "STD.h"
#include "BitMath.h"
#include <avr/interrupt.h>
#include <avr/delay.h>


#define TIMER0_CHANNEL          0
#define TIMER1_CHANNEL          1
#define TIMER2_CHANNEL          2
#define PWM_PIN					PB3_PIN
#define ON_PIN					PD2_PIN

void M_Timer_Void_TimerInit(void);
void M_Timer_Void_TimerSetTime(u8,u32);
void M_Timer_Void_TimerStart(void);
void M_Timer_Void_TimerStop(void);
void M_Timer_Void_PWMInit(void);
void M_Timer_Void_PWMSetDutyCycle(u8);
void M_Timer_Void_PWMSetFrequency(u8);
void M_Timer_Void_PWMStart(void);
void M_Timer_Void_PWMStop(void);
void M_Timer_Void_PWMDutyOsc(void);


#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
