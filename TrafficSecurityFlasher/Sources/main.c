/*
 * TrafficSecurityFlasher.c
 *
 * Created: 02.12.2019 06:12:58
 * Author : Hm
 */ 



#include "../Includes/main.h"

void GoSleep( void )
{
	set_sleep_mode( SLEEP_MODE_PWR_DOWN );
	cli();
	
	sLed[ePORT_PORT]->bLed1 = 1; //
	sLed[ePORT_PORT]->bLed2 = 1; //
	sLed[ePORT_PORT]->bLed3 = 1; //
	sLed[ePORT_PORT]->bLed4 = 1; // .. Leds ausschalten!
	
	sleep_enable();
	sei();
	sleep_cpu();
	sleep_disable();
}

void Timer1ms	( void )
{
	if ( sTime.uiMilli++ > 999 )
	{
		sTime.uiMilli = 0;
	}
	
	if ( uiDebounce++ > 24 )
	{
		uiDebounce = 0;
		SwitchRead( &sKey );
	}
	
	if ( sState.bLedIsOn )
	{
		if ( sLedTime.uiMilli++ < sLedCnfg[uiLedCnfgIndex].uiOnMs )
		{
			sLed[ePORT_PORT]->bLed1 = 0;
			sLed[ePORT_PORT]->bLed2 = 0;
			sLed[ePORT_PORT]->bLed3 = 0;
			sLed[ePORT_PORT]->bLed4 = 0;
		}
		else
		{
			sLedTime.uiMilli = 0;
			sState.bLedIsOn = 0;
			sState.bLedIsOff = 1;
		}
	}
	
	if ( sState.bLedIsOff )
	{
		if ( sLedTime.uiMilli++ < sLedCnfg[uiLedCnfgIndex].uiOffMs )
		{
			sLed[ePORT_PORT]->bLed1 = 1;
			sLed[ePORT_PORT]->bLed2 = 1;
			sLed[ePORT_PORT]->bLed3 = 1;
			sLed[ePORT_PORT]->bLed4 = 1;
		}
		else
		{
			sLedTime.uiMilli = 0;
			sState.bLedIsOff = 0;
			sState.bLedIsOn = 1;
		}
	}	
}



int main(void)
{
	SwitchInit( &sKey , &KEY_PORT , 1<<KEY_BP , 1<<KEY_BP , 0 );
	
	Timer0CompInit( &sTimer0OcieSettings[2] , Timer1ms );

//	wdt_enable( WDTO_500MS );

	sLed[ePORT_DDR]->bLed1 = 1;
	sLed[ePORT_DDR]->bLed2 = 1;
	sLed[ePORT_DDR]->bLed3 = 1;
	sLed[ePORT_DDR]->bLed4 = 1;

    while (1) 
    {
		if ( SwitchGet( &sKey , 1<<KEY_BP ) )
		{
			if ( uiLedCnfgIndex++ > 6 )
			{
				uiLedCnfgIndex = 0;
			}
		}
    }
}

