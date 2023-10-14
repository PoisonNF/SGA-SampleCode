#include "task_conf.h"
#include "ocd_conf.h"
#include "config.h"

void Task_UserInit(void)
{
	Drv_GPIO_Init(demoGPIO, 3);
    
    Drv_Uart_ITInit(&demoUart);
    
    Drv_ADC_Init(demoADC,2);

    Drv_DAC_Init(demoDAC,2);
}
