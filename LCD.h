#ifndef LCD
#define LCD

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

//#define MrLCDsCrib 		PORTB	//Data Port B0-->D0 of lcd
//#define DataDirCrib		DDRB	//direction, 1=output
#define MrLCDsCrib 		PORTA	//Data Port B0-->D0 of lcd
#define DataDirCrib		DDRA	//direction, 1=output

#define MrLCDsControl	PORTC	//control port, d5=enable,d7=R/W ,d2=RS
#define DataDirControl	DDRC	//direction
#define LightSwitch 	7		//Enable

//#define ReadWrite 		7		//1= Read, 0= Write
#define ReadWrite 		6		//1= Read, 0= Write
#define BipolarMood 	5		//1= data,0 = command

void Check_If_Busy(void);
void Peek_A_Boo(void);
void Send_A_Command(unsigned char command);
void Send_A_Character(unsigned char character);
void Send_A_String(char *StringOfCharacters);
void GotoLocation(uint8_t x,uint8_t y);
void initializeLCD(void);

#endif
