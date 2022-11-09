/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ATmega32 ADC driver with POLLING and INTERRUPTS
 *
 * Author: Mohamed  Mostafa
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* Selecting the Reference voltage */
typedef enum
{
	AREF=0x3F,AVCC=0x7F,INTERNAL_AVREF=0xFF
}Reference_Selection_Bits;

/* Selecting the ADC prescalar */

typedef enum
{
	F_CPU_2=0xF8,F_CPU_4=0xFA,F_CPU_8=0xFB,F_CPU_16=0xFC,F_CPU_32=0xFD,F_CPU_64=0xFE,F_CPU_128=0xFF
}ADC_Prescaler_Selections;
/* Selecting ADC Technique*/
typedef struct
{
	Reference_Selection_Bits voltageUsed;
	ADC_Prescaler_Selections prescalerUsed;
}ADC_CONFIG;
#define ADC_REFERENCE_VOLTAGE                2.56
#define ADC_MAXIMUM_DIGITAL_VALUE            1023
#define POLLING                                0
#define INTERRUPT                              1
#define ADC_TECHNIQUE                       POLLING

extern volatile uint16 g_ADCResult;
/*******************************************************************************
 *                           Functions Prototypes                              *
 *******************************************************************************/

void ADC_init(ADC_CONFIG (*config_Ptr));


#if(ADC_TECHNIQUE == POLLING)

uint16 ADC_readChannel(uint8 channel);

#elif(ADC_TECHNIQUE == INTERRUPT)

void ADC_readChannel(uint8 channel);

#endif


#endif /* ADC_H_ */
