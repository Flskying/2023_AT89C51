#include "LCD.h"

void main(void)//Ö÷º¯Êý
{
	lcd_initial();
	while(1)
	{
		string(0x8f,"Happy New Year");
		delay(100);
		string(0xd9,"Welcome to HIT");
		delay(500);
		write_command(0x01);
		delay(100);
	}
}