/*
 * ultrasonic.c
 *
 *  Created on: ١٠‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */
#include<util/delay.h>
#include"ultrasonic.h"
#include"icu.h"
#include"gpio.h"

uint16 g_pulse_time=0;
ICU_ConfigType icu_config={F_CPU_8 ,RAISING};
uint8 edge_flag = 0;

void Ultrasonic_init(void)
{
	ICU_init(&icu_config);
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,PIN_OUTPUT);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
}
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_LOW);
}
uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();
	uint16 distance=(uint16)( g_pulse_time/117.6)+1;
	return distance;
}
void Ultrasonic_edgeProcessing(void)
{

	if(edge_flag==0)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
		edge_flag=1;
	}
	else
	{
		g_pulse_time=ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(RAISING);
		edge_flag=0;
	}
}


