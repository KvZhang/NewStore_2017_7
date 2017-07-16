/*
 * Util.cpp
 *
 *  Created on: 2016Äê11ÔÂ2ÈÕ
 *      Author: admin
 */
#include"Variables.h"
#include "Config.h"
#include "EEPROM.h"
#include "main.h"
static void initIO()
{

#ifdef ON_BOARD_OUTPUT
	for (unsigned char i = 0; i < sizeof(outputPin); i++)
	{
		pinMode(outputPin[i], OUTPUT);
		digitalWrite(outputPin[i], MOS_INIT_STATE);
	}
#endif

#ifdef ON_BOARD_INPUT
	for (unsigned char i = 0; i < sizeof(inputPin); i++)
	{
		pinMode(inputPin[i], INPUT_PULLUP);
	}
#endif

}

static void initVariables()
{
	gV.flag.all = 0;
	for (unsigned char i = 0; i < TOTAL_TIMER_NUM; i++)
	{
		if (gV.timer[i]) myTimer.KillTimer(&gV.timer[i]);
	}
}

void resetMyself(void)
{
	initIO();
	initVariables();
}

void get_addr()
{

}

void Serial_debugger()
{

}
