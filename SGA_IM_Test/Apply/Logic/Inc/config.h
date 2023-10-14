#ifndef __CONFIG_H_
#define __CONFIG_H_

#include "drv_hal_conf.h"
#include "ocd_conf.h"
#include "algo_conf.h"
#include "dev_conf.h"

#define LED_RED LED[0]
#define LED_GREEN LED[1]
#define LED_BLUE LED[2]

/* 用户句柄声明包含区 */

extern tagGPIO_T LED[];

extern tagUART_T Uart1;

extern tagDS3231_T tDS3231;

extern tagFATFS_T tFATFS;

extern tagAT24CXX_T tAT24CXX;

extern tagJY901_T JY901S;
#endif
