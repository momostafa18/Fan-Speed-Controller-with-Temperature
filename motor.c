/******************************************************************************
 *
 * Module: MOTORS
 *
 * File Name: motor.h
 *
 * Description: SOURCE file for MOTORS
 *
 * Author: Mohamed  Mostafa
 *******************************************************************************/

#include"gpio.h"
#include"common_macros.h"
#include <avr/io.h>
#include"motor.h"

void PWM_Timer0_init(uint8 set_duty_cycle,TIMER0_CLOCK clock)
{
	/* Selecting wave generation mode on Fast PWM*/
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
	/* Selecting output comapre mode on Fast PWM*/
	SET_BIT(TCCR0,COM01);
	/* Selecting the needed prescaler*/
	TCCR0=(clock)|(TCCR0 & 0xF8);
	/* Making TCNT=0 to start counting from 0*/
	TCNT0=0;
	/* Set Compare value*/
	OCR0=set_duty_cycle;
	//set PB3/OC0 as output pin --> where the PWM signal is generated from MC.
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
}
void DcMotor_Init(void)
{
	/* Setting the Input pins of the motor*/
	GPIO_setupPinDirection(MOTOR_INPUT1_PORT_ID,MOTOR_INPUT1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_INPUT2_PORT_ID,MOTOR_INPUT2_PIN_ID,PIN_OUTPUT);
	/* Making the motor initially stopped*/
	GPIO_writePin(MOTOR_INPUT1_PORT_ID,MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
	GPIO_writePin(MOTOR_INPUT2_PORT_ID,MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
}
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if(state == STOPPED)
	{
		GPIO_writePin(MOTOR_INPUT1_PORT_ID,MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_INPUT2_PORT_ID,MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
	}
	else if(state == ROTATING_CLOCK_WISE)
	{
		GPIO_writePin(MOTOR_INPUT1_PORT_ID,MOTOR_INPUT2_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(MOTOR_INPUT2_PORT_ID,MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
	}
	else if(state == ROTATING_ANTI_CLOCK_WISE)
	{
		GPIO_writePin(MOTOR_INPUT1_PORT_ID,MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
		GPIO_writePin(MOTOR_INPUT2_PORT_ID,MOTOR_INPUT1_PIN_ID,LOGIC_HIGH);
	}
	PWM_Timer0_init((speed*2.55),F_CPU_CLOCK_8);
}
