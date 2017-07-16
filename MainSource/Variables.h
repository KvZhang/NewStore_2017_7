/*
 * Variables.h
 *
 *  Created on: 2016Äê11ÔÂ2ÈÕ
 *      Author: admin
 */

#ifndef VARIABLES_H_
#define VARIABLES_H_
#include "LaputaTimer.h"
#include "Config.h"
#include "LaputaCommSWV2.h"

#ifdef _MAIN_
#define EXTERN
#else
#define EXTERN extern
#endif

typedef union{
	unsigned char all;
	struct{
		unsigned char is_need_reset:1;
		unsigned char bit1:1;
		unsigned char bit2:1;
		unsigned char bit3:1;
		unsigned char bit4:1;
		unsigned char bit5:1;
		unsigned char bit6:1;
		unsigned char bit7:1;
	}bit;
}SYS_FLAG;

typedef struct{
	unsigned char timer[TOTAL_TIMER_NUM];
	volatile SYS_FLAG flag;
}_LAPUTA_GLOBLE_VARIABLE;

EXTERN _LAPUTA_GLOBLE_VARIABLE gV;

#ifdef ON_BOARD_433MHz_SW
#ifdef _MAIN_
LaputaComm myComm(ME_ADDRESS);
#else
extern LaputaComm myComm;
#endif
#endif

EXTERN LaputaTimer myTimer;

#ifdef ON_BOARD_OUTPUT
#ifdef _MAIN_
char outputPin[ON_BOARD_OUTPUT]=OUTPUT_PINS;
#else
extern char outputPin[ON_BOARD_OUTPUT];
#endif
#endif

#ifdef ON_BOARD_INPUT
#ifdef _MAIN_
char inputPin[ON_BOARD_INPUT]=INPUT_PINS;
#else
extern char inputPin[ON_BOARD_INPUT];
#endif
#endif

#endif /* VARIABLES_H_ */
