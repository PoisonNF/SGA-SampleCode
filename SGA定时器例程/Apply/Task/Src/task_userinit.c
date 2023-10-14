#include "task_conf.h"
#include "ocd_conf.h"
#include "config.h"

void Task_UserInit(void)
{
    Drv_Uart_ITInit(&demoUart);

    Drv_GPIO_Init(demoGPIO,3);

    Drv_GPIO_Set(&demoGPIO[0]);
    Drv_GPIO_Set(&demoGPIO[1]);
    Drv_GPIO_Set(&demoGPIO[2]);

    Drv_Timer_Init(&tTimer2);
    Drv_Timer_Enable(&tTimer2);
}
