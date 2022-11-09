/******************************************************************************
 *
 * Module: MOTORS
 *
 * File Name: motor.h
 *
 * Description: Header file for MOTORS
 *
 * Author: Mohamed  Mostafa
 *******************************************************************************/
#ifndef MOTOR_H_
#define MOTOR_H_
#include"std_types.h"

#define MOTOR_INPUT1_PORT_ID       PORTB_ID
#define MOTOR_INPUT1_PIN_ID        PIN0_ID

#define MOTOR_INPUT2_PORT_ID       PORTB_ID
#define MOTOR_INPUT2_PIN_ID        PIN1_ID

typedef enum
{
	STOPPED,ROTATING_CLOCK_WISE,ROTATING_ANTI_CLOCK_WISE
}DcMotor_State;
typedef enum
{
	F_CPU_NO_CLOCK,F_CPU_CLOCK_1,F_CPU_CLOCK_8,F_CPU_CLOCK_64,F_CPU_CLOCK_256,F_CPU_CLOCK_1024
}TIMER0_CLOCK;



void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);
#endif /* MOTOR_H_ */
