/**************************************************************************/
/**************************************************************************/
/********************** Glyn GmbH & Co. KG GmbH ***************************/
/**************************************************************************/
/**************************************************************************/
/*  DISCLAIMER:                                                           */
/*  We (Glyn GmbH & Co.KG) do not warrant that the Software               */
/*  is free from claims by a third party of copyright, patent, trademark, */
/*  trade secret or any other intellectual property infringement.         */
/*                                                                        */
/*  Under no circumstances are we liable for any of the following:        */
/*                                                                        */
/*  1. third-party claims against you for losses or damages;              */
/*  2. loss of, or damage to, your records or data; or                    */
/*  3. economic consequential damages (including lost profits or          */
/*     savings) or incidental damages, even if we are informed of         */
/*     their possibility.                                                 */
/*                                                                        */
/*  We do not warrant uninterrupted or error free operation of the        */
/*  Software. We have no obligation to provide service, defect            */
/*  correction, or any maintenance for the Software. We have no           */
/*  obligation to supply any Software updates or enhancements to you      */
/*  even if such are or later become available.                           */
/*                                                                        */
/*  IF YOU DOWNLOAD OR USE THIS SOFTWARE YOU AGREE TO THESE TERMS.        */
/*                                                                        */
/*  THERE ARE NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING THE            */
/*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A               */
/*  PARTICULAR PURPOSE.                                                   */
/**************************************************************************/
/**************************************************************************/
/*                                                                        */
/*  File:        R8C_Jingle_Bells.c                                       */
/*  Description: Main-Modul.                                              */
/*               Starts the internal 8 MHz High Speed Ozcillator and      */
/*               play Jingle Bells at Port 1.0                            */
/*               on GLYN EVBR8C/13 Carrier Board.                         */
/*  Date:        11.10.2005                                               */
/*  Author:      Dipl.-Ing. G.Ewald @ Glyn GmbH & Co. KG                  */
/*  Change:      (Date)  (Author)  (Description)                          */
/*                                                                        */
/**************************************************************************/  
                 
#include "sfr_r813.h";

int i;
long t;
unsigned char p1dummy;
#pragma INTERRUPT Timer_X_interrupt	

void Timer_X_interrupt(void)
{
	p1dummy++;
    p1 = ~p1dummy;
}

void sound8(void)
{
txs = 1;		// Timer on
for (t=0; t<20000; t++);
txs = 0;		// Timer off
}

void sound4(void)
{
txs = 1;		// Timer on
for (t=0; t<40000; t++);
txs = 0;		// Timer off
}

void sound2(void)
{
txs = 1;		// Timer on
for (t=0; t<90000; t++);
txs = 0;		// Timer off
}

void delay8(void)
{
for (t=0; t<5000; t++);
}

void delay4(void)
{
for (t=0; t<5000; t++);
}

void delay2(void)
{
for (t=0; t<10000; t++);
}

void delay1(void)
{
for (t=0; t<60000; t++);
}


void main(void)
{
prc0 = 1;		// Enable High Speed Ozcillator ( 8MHz )
hr00 = 1;
asm("NOP");
asm("NOP");
hr01 = 1;

asm( "FSET I");
cm06 = 0;		// MCU Division /1 Mode
prc0 = 0;

txmr = 0x00;
prex = 64;		// 8MHz / 64 = 125KHz 
tx = 189;		//  
tcss = 0x00;    // Timerclock = 8MHz
txic = 0x03;
txs = 0;		// Timer off

pd1 = 0x01;		// output P1.0
drr0 = 1;
p1dummy = 0x01;


while(1)
	{
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound2();
	delay2();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound2();
	delay2();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 159;		//   g
	sound4();
	delay4();
	tx = 240;		//   c
	sound4();
	delay4();
	tx = 213;		//   d
	sound4();
	tx = 189;		//   e
	sound2();
	tx = 189;		//   e
	sound2();
	delay2();
	delay2();

//  2
	tx = 180;		//   f
	sound4();
	delay4();
	tx = 180;		//   f
	sound4();
	delay4();
	tx = 180;		//   f
	sound4();
	delay4();
	tx = 180;		//   f
	sound4();
	delay4();
	tx = 180;		//   f
	sound4();
	delay4();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound8();
	delay8();
	tx = 189;		//   e
	sound8();
	delay4();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 213;		//   d
	sound4();
	delay4();
	tx = 213;		//   d
	sound4();
	delay4();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 213;		//   d
	sound2();
	sound8();
	tx = 159;		//   g
	sound2();
	delay2();
	delay2();

//  3
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound2();
	delay2();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound2();
	delay2();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 159;		//   g
	sound4();
	delay2();
	tx = 240;		//   c
	sound4();
	delay4();
	tx = 213;		//   d
	sound4();
	tx = 189;		//   e
	sound2();
	tx = 189;		//   e
	sound2();
	delay2();

// 4
	tx = 180;		//   f
	sound4();
	delay4();
	tx = 180;		//   f
	sound4();
	delay4();
	tx = 180;		//   f
	sound4();
	delay4();
	tx = 180;		//   f
	sound4();
	delay4();
	tx = 180;		//   f
	sound4();
	delay4();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound4();
	delay4();
	tx = 189;		//   e
	sound8();
	delay8();
	tx = 189;		//   e
	sound8();
	delay4();
	tx = 159;		//   g
	sound4();
	delay4();
	tx = 159;		//   g
	sound4();
	delay4();
	tx = 180;		//   f
	sound4();
	delay4();
	tx = 213;		//   d
	sound4();
	delay4();
	tx = 240;		//   c
	sound2();
	tx = 240;		//   c
	sound2();
	delay1();
	delay1();
	delay1();
	delay1();
	}	
}
