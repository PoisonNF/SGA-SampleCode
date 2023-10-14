#include "task_conf.h"
#include "config.h"

extern uint8_t SDcardStatus;

/* 外设初始化函数 */
void Task_UserInit(void)
{
    Drv_Uart_DMAInit(&Uart1);

	Drv_GPIO_Init(LED, 3);
    Task_LED_AllOff();

    OCD_DS3231_Init(&tDS3231);
    
    if(OCD_FATFS_Init(&tFATFS) != 0)
    {
        printf("SDcard Error\r\n");
        SDcardStatus = 0;
    }
    else
        SDcardStatus = 1;

    OCD_AT24CXX_Init(&tAT24CXX);

    OCD_JY901_DMAInit(&JY901S);

}
