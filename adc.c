/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver with POLLING and INTERRUPT
 *
 * Author: Mohamed  Mostafa
 *******************************************************************************/

#include"adc.h"
#include<avr/io.h>
#include"std_types.h"
#include <avr/interrupt.h> /* For ADC ISR */

#if(ADC_TECHNIQUE == INTERRUPT)
volatile uint16 g_ADCResult=0;
#endif
/*******************************************************************************
 *                           Functions definitions                             *
 *******************************************************************************/

void ADC_init(ADC_CONFIG (*config_Ptr))
{
	    ADMUX= 0;
		/* Selecting the Reference voltage */
		ADMUX = (config_Ptr->voltageUsed & 0xC0) | (ADMUX & 0x3F);
		ADCSRA=0;
		/* Enabling the ADC*/
		ADCSRA |= (1<<ADEN);
       #if(ADC_TECHNIQUE == INTERRUPT)
        ADCSRA |= (1<<ADIE);
       #endif
		/* Selecting the Prescalar*/
		ADCSRA = (config_Ptr->prescalerUsed & 0x07) | (ADCSRA & 0xF8);
}
#if(ADC_TECHNIQUE == POLLING)
uint16 ADC_readChannel(uint8 channel)
{
	ADMUX=(channel & 0x07 )|(ADMUX & 0xE0);
	ADCSRA|=(1<<ADSC);
	while(!(ADCSRA|(1<<ADIF)));
	ADCSRA|=(1<<ADIF);
	return ADC;
}
#elif(ADC_TECHNIQUE == INTERRUPT)
ISR(ADC_vect)
{
	g_ADCResult=ADC;
}
void ADC_readChannel(uint8 channel)
{
	ADMUX=(channel & 0x07 )|(ADMUX & 0xE0);
	ADCSRA|=(1<<ADSC);
}
#endif
