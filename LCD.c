#include "LCD.h"

void Check_If_Busy(void){
	DataDirCrib  = 0;
	MrLCDsControl |= 1 << ReadWrite;
	MrLCDsControl &= ~1<<BipolarMood;
	while(MrLCDsCrib >= 0x80){	//Pin D7 on lcd 1=busy 0x80
	Peek_A_Boo();
	}
	
	
	DataDirCrib = 0xFF; //
}

void Peek_A_Boo(void){
	
	MrLCDsControl |= 1 << LightSwitch;
	asm volatile ("nop");
	asm volatile ("nop");
	MrLCDsControl &= ~ 1 << LightSwitch;

}

void Send_A_Command(unsigned char command){
	Check_If_Busy();
	MrLCDsCrib = command;
	MrLCDsControl &= ~ (1 <<ReadWrite | 1<< BipolarMood);
	Peek_A_Boo();
	MrLCDsCrib = 0;

}
void Send_A_Character(unsigned char character){
	Check_If_Busy();
	MrLCDsCrib = character;
	MrLCDsControl &= ~ (1 <<ReadWrite);
	MrLCDsControl |= 1<< BipolarMood;
	Peek_A_Boo();
	MrLCDsCrib = 0;

}
void Send_A_String(char *StringOfCharacters){
	while(*StringOfCharacters >0){
		Send_A_Character(*StringOfCharacters++);
	}
}
char firstColumnPosition[2] = {0,64}; //ref pg 19 DOT MATRIX CHARACTER LCD MODULE USER’S MANUAL
void GotoLocation(uint8_t x,uint8_t y){
	Send_A_Command(0x80 + firstColumnPosition[y-1] + x);
}

void initializeLCD(void){
	DataDirControl |= 1<< LightSwitch | 1<<ReadWrite | 1 <<BipolarMood;
	_delay_ms(15);
	
	Send_A_Command(0x01); //0x01 clear screen
	_delay_ms(2);
	Send_A_Command(0x38); //8BIT MODE
	_delay_us(50);
	Send_A_Command(0b00001110); 
	_delay_us(50);
}


/*							//66 108 97 99 107 32 67 111 114 112		
	Send_A_Character(66);	//B
	Send_A_Character(108);	//l
	Send_A_Character(97);	//a
	Send_A_Character(99);	//c
	Send_A_Character(107);	//k
	Send_A_Character(32);	//space
	Send_A_Character(67);	//C
	Send_A_Character(111);	//o
	Send_A_Character(114);	//r
	Send_A_Character(112);	//p
*/
