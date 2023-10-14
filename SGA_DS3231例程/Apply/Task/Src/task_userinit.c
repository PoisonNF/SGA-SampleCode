#include "task_conf.h"
#include "ocd_conf.h"
#include "config.h"

void Task_UserInit(void)
{
    Drv_Uart_ITInit(&demoUart);
    
    OCD_DS3231_Init(&tDS3231);
}
