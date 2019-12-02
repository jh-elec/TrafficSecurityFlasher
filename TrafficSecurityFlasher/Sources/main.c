/*
 * TrafficSecurityFlasher.c
 *
 * Created: 02.12.2019 06:12:58
 * Author : Hm
 */ 

#define F_CPU	1000000

#include "../Includes/main.h"

typedef union
{
	&PORTB;
	uint8_t x;	
}unT;


void Timer1ms	( void )
{
}


int main(void)
{
	SwitchInit( &sKey , &PORTB , 1<<PB0 , 0 , 0 );
	
	Timer0CompAInit( &sTimer0OcieSettings[2] , Timer1ms );

    while (1) 
    {
    }
}

