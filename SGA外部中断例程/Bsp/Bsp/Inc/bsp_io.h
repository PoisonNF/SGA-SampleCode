#ifndef __BSP_IO_H_
#define __BSP_IO_H_

#include "drv_hal_conf.h"
#include "ocd_conf.h"

/* 用户句柄声明包含区 */

extern tagGPIO_T demoGPIO[];

extern tagUART_T demoUart;

extern tagSPISoft_T SPI_soft[2];

extern tagSPI_T SPI[3]; 

#endif
