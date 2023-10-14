#ifndef __CONFIG_H_
#define __CONFIG_H_

#include "drv_hal_conf.h"
#include "ocd_conf.h"
#include "algo_conf.h"
#include "dev_conf.h"

/* 用户句柄声明包含区 */

extern tagGPIO_T demoGPIO[];

extern tagUART_T demoUart;

extern tagMS5837_T MS5837;

extern tagOLED_T tOLED;

#endif
