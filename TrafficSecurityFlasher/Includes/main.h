/*************************************************************
*|
*|	\@file  	main.h
*|	\@brief 	-
*|	\@author 	J.H - Elec(C)
*|
*|	\@project	TrafficSecurityFlasher
*|
*|	\@date		02/12/2019 - first implementation
*|
*|	\@todo 		nothing
*|	\@test		not tested
*|	\@bug		no bug known
*|
*|
*|	\@version	1.0.021219
*|
*|**************************************************************/

#ifndef __MAIN_H__
#define __MAIN_H__

#define F_CPU	8000000

#include <stdio.h>
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include "../Includes/Switch.h"
#include "../Includes/timer.h"


/*!<-- Defines <--*/
/*****************************************************************/

#define GET_DDR( _PORTx )				( * ( &_PORTx - 1 ) )

#define LED_PORT						PORTA

#define	LED_INIT						( GET_DDR( LED_PORT ) |= 1<<LED_BP )

#define	KEY_PORT						PORTC
#define KEY_BP							3


typedef struct  
{
	uint16_t uiMilli;
	//uint8_t uiSecond;
}sTime_t;

typedef struct  
{
	uint8_t bLed1	:1;
	uint8_t bLed2	:1;
	uint8_t	bLed3	:1;
	uint8_t bLed4	:1;
}sLed_t;

typedef struct  
{
	uint8_t bLedIsOn	:1;
	uint8_t bLedIsOff	:1;
	uint8_t bCanSleep	:1;
}sState_t;

typedef struct  
{
	uint8_t bFlash  :1;
	uint8_t bBlink  :1;
	uint8_t bToggle :1;
}sEffect_t;

typedef struct
{
	uint16_t uiOnMs;
	uint16_t uiOffMs;
	
}sLedCnfg_t;

enum ePort
{
	ePORT_DDR,
	ePORT_PORT,
		
	__MAX_ePORT_ENTRYS__
};

enum eState
{
	eOFF,
	eON,
	
	__MAX_eSTATE_ENTRYS__	
};

/*****************************************************************/
/*!<-- Defines // Ende <--*/



/*!<-- Globale Variablen <--*/
/*****************************************************************/

volatile sLed_t *sLed[__MAX_ePORT_ENTRYS__] =
{
	[ePORT_DDR]		= (sLed_t*)&GET_DDR( LED_PORT )	,/*!<-- LED Port Mapping (DDR) <--*/
	[ePORT_PORT]	= (sLed_t*)&LED_PORT			,/*!<-- LED Port Mapping (Port) <--*/
};

sSwitch_t sKey; /*!<-- Prozess Variable für die Vearbeitung der Taste(n) Signale <--*/

volatile sTime_t sTime; /*!<-- Systemzeit <--*/

volatile sState_t sState =  /*!<-- Zustand der Leuchtdioden <--*/
{
	.bLedIsOff		= 0,
	.bLedIsOn		= 1,
	.bCanSleep		= 0,
};

volatile uint8_t uiLedCnfgIndex = 0;

sLedCnfg_t sLedCnfg[] = /*!<-- Puls / Pausen - Zeiten <--*/
{
	// Puls		Pause		 
	{ 50	,	2000	},
	{ 100	,	2000	},

	{ 150	,	150		},
	{ 250	,	250		},
	{ 500	,	500		},		

};

volatile sTime_t sLedTime; /*!<-- Led Zeit <--*/


volatile uint8_t uiDebounce; /*!<-- Entprell Zähler <--*/

/*****************************************************************/
/*!<-- Globale Variablen // Ende <--*/




/*!<-- Funktions Prototypen <--*/
/*****************************************************************/



/*****************************************************************/
/*!<-- Funktions Prototypen // Ende <--*/



// end of file



#endif // __MAIN_H__


