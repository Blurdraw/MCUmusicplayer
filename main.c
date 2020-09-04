#include <REGX52.H>
#include "Timer0.h"
#include "delay.h"
#include "musicfreq.h"


unsigned int FreqTable[] = {0,
	63628,63737,63835,63933,64021,64107,64188,64264,64334,64400,64463,64524,
	64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
	65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283
};


unsigned char code music[] = {
//1
	M1,2,
	M2,2,
	M3,2,
	M1,2,
	M1,2,
	M2,2,
	M3,2,
	M1,2,
	M3,2,
	M4,2,
	M5,4,
	M3,2,
	M4,2,
	M5,4,
	M5,2,
	M6,2,
	M5,2,
	M4,2,
//2
	M3,4,
	M1,4,
	M5,2,
	M6,2,
	M5,2,
	M4,2,
	M3,4,
	M1,4,
	M2,4,
	L5,4,
	M1,8,
	//3
	M2,4,
	L5,4,
	M1,8,
	0xFF
};
	
unsigned char FreqSelect,musicselect;

void main ()
{
	Timer0_Init();
	while(1)
	{
		FreqSelect = music[musicselect];
		if(FreqSelect != 0xFF)
		{
			musicselect++;
			Delay(SPEED * music[musicselect]); //延迟多久进入下一个音符，此时musicselect代表音节长
			musicselect++;
			TR0 = 0;
			Delay(5);
			TR0 = 1;
		}
		else
		{
			TR0 = 0;
		}
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = FreqTable[FreqSelect] % 256;     //根据当前的音符设置频率
	TH0 = FreqTable[FreqSelect] / 256;
	P1_4 = ~P1_4;
}

