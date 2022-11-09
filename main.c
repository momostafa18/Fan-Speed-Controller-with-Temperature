/*
 ============================================================================
 Name        : main.c
 Author      : Mohamed Mostafa
 Description : Mini Project 3
 Date        : 6/10/2022
 ============================================================================
 */
#include"lcd.h"
#include"motor.h"
#include"adc.h"
#include"lm35_sensor.h"
#include"common_macros.h"

int main(void)
{
	/* Local variable to get the value of the temperature sensor */
	uint8 temp=0;
	/* Configure structure to set the value of the reference voltage of the ADC and to set the prescalar*/
	ADC_CONFIG ADC_config={INTERNAL_AVREF,F_CPU_8};
	/* Initializing the ADC*/
	ADC_init(&ADC_config);
	/* Initializing the DC Motor*/
	DcMotor_Init();
	/* Initializing the LCD*/
	LCD_init();
	/* Displaying a fixed string "FAN IS"*/
	LCD_displayStringRowColumn(0,3,"FAN IS ");
	while(1)
	{
		/* First we get the value of the temperature measured by the LM35 sensor and depending on that
		   the speed of the DC Motor is adjusted.*/
		temp=LM35_GetTemperature();
        /* If the temperature <30  , we stop the fan and write on the LCD that the fan is OFF and display
           the value of the temperature*/
		if(temp < 30)
		{
			DcMotor_Rotate(STOPPED,0);
			LCD_moveCursor(0,10);
			LCD_displayString("OFF!");
			LCD_moveCursor(1,3);
			LCD_displayString("Temp = ");
			LCD_integerToString((int)temp);
			if(temp<10)
			{
				LCD_moveCursor(1,11);
				LCD_displayCharacter(' ');
			}
			LCD_displayCharacter(' ');
			LCD_displayCharacter(' C');
		}
		/* If the temperature >=30 and <60  , we turn on the fan with 25% of the speed and write on the
		   LCD that the fan is on and display the value of the temperature*/
		else if(temp >=30 && temp <60)
		{
			DcMotor_Rotate(ROTATING_CLOCK_WISE,25);
			LCD_moveCursor(0,10);
			LCD_displayString("ON!");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,3);
			LCD_displayString("Temp = ");
			LCD_integerToString((int)temp);
			LCD_displayCharacter(' ');
			LCD_displayCharacter('C');
		}
		/* If the temperature >=60 and <90  , we turn on the fan with 50% of the speed and write on the
		   LCD that the fan is on and display the value of the temperature*/
		else if(temp >=60 &&  temp <90)
		{
			DcMotor_Rotate(ROTATING_CLOCK_WISE,50);
			LCD_moveCursor(0,10);
			LCD_displayString("ON!");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,3);
			LCD_displayString("Temp = ");
			LCD_integerToString((int)temp);
			LCD_displayCharacter(' ');
			LCD_displayCharacter('C');
		}
		/* If the temperature >=60 and <90  , we turn on the fan with 75% of the speed and write on the
		   LCD that the fan is on and display the value of the temperature*/
		else if(temp >=90 && temp <120)
		{
			DcMotor_Rotate(ROTATING_CLOCK_WISE,75);
			LCD_moveCursor(0,10);
			LCD_displayString("ON!");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,3);
			LCD_displayString("Temp = ");
			LCD_integerToString((int)temp);
			if(temp < 100)
			{
				LCD_displayCharacter(' ');
			}
			LCD_displayCharacter('C');
		}
		/* If the temperature >=120  , we turn on the fan with 100% of the speed and write on the
		   LCD that the fan is on and display the value of the temperature*/
		else if(temp >= 120)
		{
			DcMotor_Rotate(ROTATING_CLOCK_WISE,100);
			LCD_moveCursor(0,10);
			LCD_displayString("ON!");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1,3);
			LCD_displayString("Temp = ");
			LCD_integerToString((int)temp);
			LCD_displayCharacter('C');
		}
	}
}

