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
#include <util/delay.h>
#include "../Includes/Switch.h"
#include "../Includes/timer.h"
#include "../Includes/shiftreg.h"

/*!<-- Defines <--*/
/*****************************************************************/

#define GET_DDR( _PORTx )				( * ( &_PORTx - 1 ) )

#define LED_PORT						PORTB

#define	LED_INIT						( GET_DDR( LED_PORT ) |= 1<<LED_BP )

#define	KEY_PORT						PORTB
#define KEY_BP							4


typedef struct  
{
	uint16_t uiMilli;
}sTime_t;

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
	// Puls		Pause      Index		 
	{ 50	,	2000	}, //[0]
	{ 100	,	2000	}, //[1]
	{ 150	,	2000	}, //[2]
	{ 150	,	150		}, //[3]
	{ 250	,	250		}, //[4]
	{ 500	,	500		}, //[5]
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


