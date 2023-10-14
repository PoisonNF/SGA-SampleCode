#include "task_conf.h"
#include "ocd_conf.h"
#include "config.h"

void Task_UserInit(void)
{
	Drv_GPIO_Init(demoGPIO, 3);
    
    Drv_Uart_ITInit(&demoUart);

    if(OCD_MS5837_Init(&MS5837) == 0)
        printf("MS5837 error\r\n");
    
    OCD_OLED_Init(&tOLED);
}
