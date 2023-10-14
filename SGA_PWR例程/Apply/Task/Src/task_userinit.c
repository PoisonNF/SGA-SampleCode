#include "task_conf.h"
#include "ocd_conf.h"
#include "config.h"

void Task_UserInit(void)
{
	Drv_GPIO_Init(demoGPIO, 4);
    
    Drv_Uart_ITInit(&demoUart);
    
    //两个LED默认都是熄灭状态
    Drv_GPIO_Set(&demoGPIO[2]);    
    Drv_GPIO_Set(&demoGPIO[3]);

}
