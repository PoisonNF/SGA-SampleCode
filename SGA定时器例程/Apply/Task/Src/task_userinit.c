#include "task_conf.h"
#include "ocd_conf.h"
#include "config.h"

/* 外设初始化函数 */
void Task_UserInit(void)
{
    Drv_Uart_ITInit(&demoUart);

    Drv_GPIO_Init(demoGPIO,3);

    Drv_GPIO_Set(&demoGPIO[0]);
    Drv_GPIO_Set(&demoGPIO[1]);
    Drv_GPIO_Set(&demoGPIO[2]);

    Drv_Timer_Init(&tTimer2);   //初始化定时器
    Drv_Timer_Enable(&tTimer2); //启动定时器
}
