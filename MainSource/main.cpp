/*
 * main.cpp
 *
 *  Created on: 2017Äê3ÔÂ2ÈÕ
 *      Author: zhangyu
 */

#define _MAIN_ (1)
#include "main.h"
#include "ATparser.h"

LaputaConfig myConfig;
AT_parser myAT;
/*****************Timer Callback**********************************************************************************/
inline void low_loop(word interval)
{
	static unsigned long ISRmoment = 0;

	if ((millis() - ISRmoment) > interval)
	{
		ISRmoment = millis();
	}
	else return;
#ifdef DEBUG_MODE
	uint32_t last_time=millis();
#endif


#ifdef DEBUG_MODE
	Serial.println(millis()-last_time);
#endif
	myTimer.processTimer();
	if(Serial.available())
	{
		delay(10);//receive all the bytes
		if(Serial.read() == 'A' && Serial.read() == 'T')
		{
			myAT.length=0;
			while(Serial.available()>0)
			{
				myAT.string_buffer[myAT.length++]=Serial.read();
			}
			switch(myAT.parse())
			{
			case PARSE_OK:
				Serial.println("OK");
				break;
			case PARSE_SET_CH:
				myConfig.context.room_addr=myAT.parsed_para;
				Serial.print("OK+C");
				Serial.println(myConfig.context.room_addr);
				myConfig.save_config();
				break;
			case PARSE_SET_NUM:
				myConfig.context.me_addr=myAT.parsed_para;
				Serial.print("OK+N");
				Serial.println(myConfig.context.me_addr);
				myConfig.save_config();
				break;
			case PARSE_READ_PARA:
				Serial.print("OK+C");
				Serial.println(myConfig.context.room_addr);
				Serial.print("    +N");
				Serial.println(myConfig.context.me_addr);
				break;
			case PARSE_ERROR:
			default:
				Serial.println("ERROR");
				break;
			}
		}
		else
		{
			Serial.flush();
		}
	}
}
//The setup function is called once at startup of the sketch
void timerIsr()
{

}
void setup()
{
// Add your initialization code here
	resetMyself();
	if(myConfig.load_config())
	{
		//nothing in EEPROM or checksum failed
		myConfig.context.me_addr=ME_ADDRESS;
		myConfig.context.room_addr=ROOM_ADDRESS;
	}

	Serial.begin(9600);
	myComm.begin(myConfig.context.room_addr, 57600);
	//check the addr change needs
	if(0)
	{
		myConfig.save_config();
	}
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
	switch (myComm.state)
	{
	case STATE_WAITING:
		stateWaiting();
		break;
	case STATE_ACTING:
		stateActing();
		break;
	case STATE_RECOVERING:
		stateRecovering();
		break;
	case STATE_RETRY:
		stateRetry();
		break;
	default:
		myComm.state = STATE_WAITING;
		break;
	}

	low_loop(100); // low speed required tasks
	timerIsr();
	if (myComm.receiveCMD())
	{
		switch (myComm.rxBuffer[Frame_CMD])
		{
		case 0x00:
			myComm.txBuffer.bit.length = 3;
			myComm.sendCMD();
			break;
		case 0x05:
			myComm.cmd_ACK(STATUS_OK);
			break;
		default:
			myComm.cmd_ACK(STATUS_UNSUPPORT_CMD);
			break;
		}
	}
}
