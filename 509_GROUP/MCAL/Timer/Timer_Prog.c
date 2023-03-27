/*
 * Timer_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "Timer_Interface.h"
#include "Timer_Private.h"

u32 Timer_U32_NumOfOverFlows    = 0;
u8  Timer_U8_RemTicks           = 0;
u32 Timer_U32_NumOfCompareMatch = 0;


void M_Timer_Void_TimerInit()
{
#if   TIMER0_MODE   ==   NORMAL_MODE
		CLR_BIT(TCCR0_REG,WGM00_BIT);
		CLR_BIT(TCCR0_REG,WGM01_BIT);
		/* TO ENABLE TIMER0 OVERFLOW INT */
		SET_BIT(TIMSK_REG,TOIE0_BIT);
#elif TIMER0_MODE   ==   CTC_MODE
		CLR_BIT(TCCR0_REG,WGM00_BIT);
		SET_BIT(TCCR0_REG,WGM01_BIT);
		/* TO ENABLE TIMER0 COMPARE MATCH INT */
		SET_BIT(TIMSK_REG,OCIE0_BIT);
#endif
}

void M_Timer_Void_TimerStart()
{
#if   TIMER_PRESCALER_DV   ==   1024
		SET_BIT(TCCR0_REG,CS00_BIT);
		CLR_BIT(TCCR0_REG,CS01_BIT);
		SET_BIT(TCCR0_REG,CS02_BIT);
#elif TIMER_PRESCALER_DV   ==   256
		CLR_BIT(TCCR0_REG,CS00_BIT);
		CLR_BIT(TCCR0_REG,CS01_BIT);
		SET_BIT(TCCR0_REG,CS02_BIT);
#endif
}

void M_Timer_Void_TimerStop()
{
		CLR_BIT(TCCR0_REG,CS00_BIT);
		CLR_BIT(TCCR0_REG,CS01_BIT);
		CLR_BIT(TCCR0_REG,CS02_BIT);
}

void M_Timer_Void_PWMInit()
{
		M_DIO_Void_SetPinDirection(PWM_PIN,OUTPUT);

#if   PWM0_MODE   ==   FAST_PWM
		SET_BIT(TCCR0_REG,WGM00_BIT);
		SET_BIT(TCCR0_REG,WGM01_BIT);
#elif PWM0_MODE   ==   PHASE_CORRECT_PWM
		SET_BIT(TCCR0_REG,WGM00_BIT);
		CLR_BIT(TCCR0_REG,WGM01_BIT);
#endif


#if   PWM0_MODE2   ==   NON_INVERTED
		CLR_BIT(TCCR0_REG,COM00_BIT);
		SET_BIT(TCCR0_REG,COM01_BIT);
#elif PWM0_MODE2   ==   INVERTED
		SET_BIT(TCCR0_REG,COM00_BIT);
		SET_BIT(TCCR0_REG,COM01_BIT);
#endif
}

void M_Timer_Void_PWMSetDutyCycle(u8 Copy_U8_DutyCycle)
{
#if   PWM0_MODE   ==   FAST_PWM
#if   PWM0_MODE2   ==   NON_INVERTED
		if(Copy_U8_DutyCycle == 0)
		{
			OCR0_REG = 0;
		}
		else
		{
			OCR0_REG = ((Copy_U8_DutyCycle * 256) / 100)  -1;
		}
#elif   PWM0_MODE2   ==   INVERTED
		if(Copy_U8_DutyCycle == 0)
				{
					OCR0_REG = 0;
				}
				else
				{
					OCR0_REG = (255	-	((256*Copy_U8_DutyCycle)/100));
				}

#endif

#elif PWM0_MODE   ==   PHASE_CORRECT_PWM

#if   PWM0_MODE2   ==   NON_INVERTED
		OCR0_REG = (Copy_F32_DutyCycle * 255) / 100;
#elif   PWM0_MODE2   ==   INVERTED
		if(Copy_U8_DutyCycle == 0)
					{
						OCR0_REG = 0;
					}
					else
					{
						OCR0_REG = Copy_U8_DutyCycle;
					}
#endif
#endif

}
void M_Timer_Void_PWMSetFrequency(u8 Copy_U8_Freq)
{
	ICR1_REG = ((F_OSC * 1000000 / 256) / Copy_U8_Freq);
}
void M_Timer_Void_PWMStart()
{
	M_Timer_Void_TimerStart(); //prescalar set
}
void M_Timer_Void_PWMStop()
{
	M_Timer_Void_TimerStop();
}
/*void M_Timer_Void_PWMDutyOsc()
{
	u8 Local_U8_Duty=0, Local_U8_Counter=0;
	while  (Local_U8_Duty<=100)
	{
		M_DIO_Void_SetPinValue(ON_PIN,HIGH);
		M_Timer_Void_PWMSetDutyCycle(Local_U8_Duty);
		H_LCD_Void_LCDWriteString("Duty Cycle");
		H_LCD_Void_LCDGoTo(1,0);
		H_LCD_Void_LCDWriteNumber(Local_U8_Duty);

		while (POLLING_TIME>Local_U8_Counter)
		{Local_U8_Counter++;}

		M_DIO_Void_SetPinValue(ON_PIN,LOW);
		H_LCD_Void_LCDClear();
		Local_U8_Duty= Local_U8_Duty + 10;

	}

	if (Local_U8_Duty=100)
		{	M_Timer_Void_PWMDutyOsc();	}

}*/
void M_Timer_Void_PWMDutyOsc()
{
	int LocalCounterDC		=	10;
	int LocalCounterLoopUp	=	1;
	int LocalCounterUpper	=	0;
	int LocalCounterLower	=	0;
	int LocalCounterLoopDown	=	0;
	M_DIO_Void_SetPinValue(ON_PIN,HIGH);


			while (LocalCounterDC <=100)
		{
			M_Timer_Void_PWMSetDutyCycle(LocalCounterDC);
			H_LCD_Void_LCDGoTo(1,0);
			LocalCounterUpper = LocalCounterDC /10;

			for (LocalCounterLoopUp= 1; LocalCounterLoopUp<=LocalCounterUpper; LocalCounterLoopUp++)
				{
				H_LCD_Void_LCDWriteString("-");
				}

			LocalCounterLoopDown = 10 - LocalCounterUpper;
			for (LocalCounterLower= LocalCounterLoopDown; LocalCounterLower>=0; LocalCounterLower--)
			{
			H_LCD_Void_LCDWriteString("_");
			}

			H_LCD_Void_LCDGoTo(0,0);
			H_LCD_Void_LCDWriteString("DC=");
			H_LCD_Void_LCDGoTo(0,5);
			//H_LCD_Void_LCDWriteNumber(LocalCounterDC); canceled because it prints random numbers
			H_LCD_Void_LCDGoTo(0,8);
			H_LCD_Void_LCDWriteString("3.8Hz");
			_delay_ms(250);
			H_LCD_Void_LCDClear();
			LocalCounterDC +=10;
		}

}


