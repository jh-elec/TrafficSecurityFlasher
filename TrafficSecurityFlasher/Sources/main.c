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

		}
		else
		{
			sLedTime.uiMilli = 0;
			sState.bLedIsOff = 0;
			sState.bLedIsOn = 1;
		}
	}	
	
	ShiftRegSend( ShiftRegGet(eSHIFT_REG_1).pRegStart , 1 );
}



int main(void)
{
	SwitchInit( &sKey , &KEY_PORT , 1<<KEY_BP , 1<<KEY_BP , 0 );
	
	Timer0CompAInit( &sTimer0OcieSettings[2] , Timer1ms );

	for ( uint8_t x = 0 ; x < 8 ; x++ )
	{
		ShiftRegSetBit( x ); // Initalisieren
	}

    while (1) 
    {
		if ( SwitchGet( &sKey , 1<<KEY_BP ) )
		{
			if ( uiLedCnfgIndex++ > 6 )
			{
				uiLedCnfgIndex = 0;
			}
		}
		
		static uint8_t uiIndex = 0;
		
		if ( sTime.uiMilli > 250 )
		{
			sTime.uiMilli = 0;
			
			if ( uiIndex++ < 8 )
			{
				ShiftRegSetBit( uiIndex & 0x08 ); // Led x an
			}
			else
			{
				uiIndex = 0;
				ShiftRegSet( 0x00 , eSHIFT_REG_1 );
			}
			
		}

    }
}

