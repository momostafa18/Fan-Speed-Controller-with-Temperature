/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: lm35.h
 *
 * Description: Header file for LM35
 *
 * Author: Mohamed  Mostafa
 *******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SENSOR_MAXIMUM_TEMPERATURE                      150
#define SENSOR_MAXIMUM_VOLTAGE                          1.5
#define SENSOR_CHANNEL_ID                                2

/*******************************************************************************
 *                           Functions Prototypes                              *
 *******************************************************************************/
uint8 LM35_GetTemperature(void);

#endif /* LM35_SENSOR_H_ */
