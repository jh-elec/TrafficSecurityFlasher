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


#include <stdio.h>
#include <avr/io.h>
#include <avr/sleep.h>
#include "../Includes/Switch.h"
#include "../Includes/timer.h"


/*!<-- Defines <--*/
/*****************************************************************/

#define GET_DDR( _PORTx )				( * ( &_PORTx - 1 ) )

#define LED_PORT
#define LED_BP


#define LED_HIGH						( LED_PORT |= 1<<LED_BP )
#define LED_LOW							( LED_PORT &= ~(1<<LED_BP ) )
#define LED_TGL							( LED_PORT ^= 1<<LED_BP )

#define	LED_INIT						( GET_DDR( LED_PORT ) |= 1<<LED_BP )

#define	KEY_PORT
#define KEY_BP

/*****************************************************************/
/*!<-- Defines // Ende <--*/



/*!<-- Globale Variablen <--*/
/*****************************************************************/

sSwitch_t sKey; /*!<-- Prozess Variable für die Vearbeitung der Taste(n) Signale <--*/

/*****************************************************************/
/*!<-- Globale Variablen // Ende <--*/




/*!<-- Funktions Prototypen <--*/
/*****************************************************************/



/*****************************************************************/
/*!<-- Funktions Prototypen // Ende <--*/



// end of file



#endif // __MAIN_H__


