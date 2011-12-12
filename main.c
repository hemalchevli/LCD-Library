#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"

int  main (void){
	initializeLCD();
	GotoLocation(0,1);
	Send_A_String("This is Line 1");
	GotoLocation(0,2);
	Send_A_String("This is line 2");
	_delay_ms(2000);
	
	GotoLocation(0,1);
	Send_A_String("This is Line 3");
	GotoLocation(0,2);
	Send_A_String("This is line 4");
	_delay_ms(2000);

	GotoLocation(0,1);
	Send_A_String("This is Line 5");
	GotoLocation(0,2);
	Send_A_String("This is line 6");
	_delay_ms(2000);

	GotoLocation(0,1);
	Send_A_String("This is Line 7");
	GotoLocation(0,2);
	Send_A_String("This is line 8");
	_delay_ms(2000);

	GotoLocation(0,1);
	Send_A_String("This is Line 9");
	GotoLocation(0,2);
	Send_A_String("This is line10");
	_delay_ms(2000);

	while(1){
	
	}
}

