/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: lm35.h
 *
 * Description: Source file for LM35
 *
 * Author: Mohamed  Mostafa
 *******************************************************************************/
#include "lm35_sensor.h"
#include "adc.h"

/*******************************************************************************
 *                           Functions definitions                              *
 *******************************************************************************/
uint8 LM35_GetTemperature(void)
{
	uint8 temp_value=0;
	uint16 adc_value=0;
	adc_value= ADC_readChannel(SENSOR_CHANNEL_ID);
	temp_value=(uint8)(((uint32)adc_value*SENSOR_MAXIMUM_TEMPERATURE*ADC_REFERENCE_VOLTAGE)/(ADC_MAXIMUM_DIGITAL_VALUE*SENSOR_MAXIMUM_VOLTAGE));
	return temp_value;
}
