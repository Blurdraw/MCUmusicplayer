#include <REGX52.H>

void Timer0_Init()
{
	TMOD = 0x01;
	TF0 = 0;  
	TR0 = 1; //start
	TL0 = 64536 % 256;
	TH0 = 64536 / 256;
	ET0 = 1;
	EA = 1;
}

//void Timer0_Routine() interrupt 1
//{
//	TL0 = 64536 % 256;
//	TH0 = 64536 / 256;	
//}