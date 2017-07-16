/*
 * Config.h
 *
 *  Created on: 2015Äê11ÔÂ5ÈÕ
 *      Author: zhangyu
 */

#ifndef CONFIG_H_
#define CONFIG_H_

/*******Peripheral******************************************************************************/
#ifndef _PERIPHERALS
#define _PERIPHERALS

#define ON_BOARD_OUTPUT		(1)
#define OUTPUT_PINS			{7}

#define ON_BOARD_INPUT		(1)
#define INPUT_PINS			{A2}

#define ON_BOARD_433MHz_SW

//#define ON_BOARD_IIC
#endif
/*******Comm address******************************************************************************/
#define ROOM_ADDRESS 		(0x01)
#define ME_ADDRESS			(0xFF)
#define CHANGE_ADDR_EN		(1)
/********Other define**********************************************************************************/
#define MOS_INIT_STATE		0
#define MOS_ACTIVE_STATE	1
/********ENUM************************************************************************************************/
typedef enum {
	STATE_WAITING, STATE_ACTING, STATE_RECOVERING, STATE_RETRY,
} _ME_STATE;
//Timer type
typedef enum{
	TIMER_overTime,
	TIMER_openDoor,
	TIMER_light,
	TOTAL_TIMER_NUM,
} _SYS_TIMER;
#endif /* CONFIG_H_ */
