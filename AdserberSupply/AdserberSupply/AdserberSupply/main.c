/*
 * Код контроля за источником питания платы управления Адсорбером
 *
 * Created: 18.11.2022 23:24:07
 * Author : VladiBoy
 */ 

#include "main.h"

void setup() {
	INDECATION_INI;

	ADC_init();
	UART_init();
	
	GREEN_OFF;
	RED_OFF;
	POWER_OK_OFF;		
}

int main(void)
{
	setup();

	int IS_SPROTECT_MODE = 0;
	struct adcConfig conf;
	conf.r1Val = 2000;
	conf.r2Val = 800;
	conf.tranCof = 66.666d;

	while (1) 
    {

		int adc = 0;
		ADC_Get(&adc);
		int acVolts = 0;
		ADC_ToAC(&adc, &conf, &acVolts);
		UART_SendInt(&acVolts);
		_delay_ms(200);
		
		if((PINB & (1<<4)) == 0) {
			UART_Send("VOLTAGE RESET ");
			POWER_OK_OFF;
			IS_SPROTECT_MODE = 0;
		}
				
		if(acVolts == 0) {
			continue;
		}
					
		
		if (acVolts > 210 && acVolts < 230)
		{

			if(IS_SPROTECT_MODE == 0) {
				POWER_OK_OFF;
				GREEN_ON;
				RED_OFF;
			}
		} else {
			POWER_OK_ON;
			GREEN_OFF;
			RED_ON;
			IS_SPROTECT_MODE = 1;
		}


		adc = NULL;
		
    }
}

