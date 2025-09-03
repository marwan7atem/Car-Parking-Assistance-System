/*
 * main.c
 *
 *  Created on: ١٠‏/١٠‏/٢٠٢٤
 *      Author: LENOVO
 */
#include"gpio.h"
#include"led.h"
#include"icu.h"
#include"ultrasonic.h"
#include"lcd.h"
#include"buzzer.h"
#include<util/delay.h>
#include<avr/io.h>

int main(void)
{
	LCD_init();
	Buzzer_init();
	LEDS_init();
	Ultrasonic_init();
	uint16 distance=0;
	SREG |= (1<<7);
	LCD_moveCursor(0,0);
	LCD_displayString("Distance=     CM");

	while(1)
	{
		 distance = Ultrasonic_readDistance();
		 LCD_moveCursor(0,9);
		 LCD_intgerToString(distance);
		 LCD_displayString("   ");

	 	 if(distance<=5)
	 	 {
	 		Buzzer_on();
	 		LED_on(LED_RED);
	 		LED_on(LED_GREEN);
	 		LED_on(LED_BLUE);
	 		_delay_ms(200);
	 		LED_off(LED_RED);
	 		LED_off(LED_GREEN);
	 		LED_off(LED_BLUE);
	 		_delay_ms(200);
	 		LCD_moveCursor(1,5);
	 		LCD_displayString("STOP!");
	 	 }
	 	 else if(distance<=10)
	 	 {
	 		Buzzer_off();
	 		LED_on(LED_RED);
	 		LED_on(LED_GREEN);
	 	    LED_on(LED_BLUE);
	 	   LCD_moveCursor(1,5);
	 	  LCD_displayString("     ");
	 	 }
	 	 else if(distance<=15)
	 	 {
	 		Buzzer_off();
	 	    LED_on(LED_RED);
	  		LED_on(LED_GREEN);
	 	    LED_off(LED_BLUE);
	 	   LCD_moveCursor(1,5);
	 	   LCD_displayString("     ");
	 	 }
	 	else if(distance<=20)
	 		 	 {
	 		 		Buzzer_off();
	 		 	    LED_on(LED_RED);
	 		  		LED_off(LED_GREEN);
	 		 	    LED_off(LED_BLUE);
	 		 	   LCD_moveCursor(1,5);
	 		 	   LCD_displayString("     ");
	 		 	 }
	 	else
	 		 	 {
	 		 		Buzzer_off();
	 		 	    LED_off(LED_RED);
	 		  		LED_off(LED_GREEN);
	 		 	    LED_off(LED_BLUE);
	 		 	   LCD_moveCursor(1,5);
	 		 	   LCD_displayString("      ");
	 		 	 }
	}

}
