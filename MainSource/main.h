/*
 * main.h
 *
 *  Created on: 2017Äê3ÔÂ2ÈÕ
 *      Author: zhangyu
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "Variables.h"
//#include "Buzz.h"
//#include "LaputaMp3.h"
//#include "LaputaLEDController.h"
#include "LaputaConfig.h"

//#define DEBUG_MODE

void resetMyself(void);
void stateWaiting();
void stateActing();
void stateRecovering();
void stateRetry();


//extern Buzz myBuzz;
//extern LaputaLEDController myLed;
//extern LaputaMp3 myMp3;
extern LaputaConfig myConfig;
#endif /* MAIN_H_ */
