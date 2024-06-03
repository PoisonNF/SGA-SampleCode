#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/*
    串口普通中断接收实验，使用的是串口一，通过XCOM向STM32发送字符串
    （需要有特定结尾符，可在task_irq.c中的Drv_Uart_IT_RxHandler函数中调整第二个参数）
    本例中检测以'5'为结尾的字符串
*/

uint8_t buf[100];
uint16_t ReciveNum;

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");
	Drv_Delay_Ms(1000);
    
	while(1)
	{
        /* 将中断接收到的数据放入buf中，并且记录ReciveNum */
		if((ReciveNum = Drv_Uart_Receive_IT(&demoUart,buf)) != 0)
		{
			printf("接收到的长度为%d\r\n",ReciveNum);
			printf("接收到的数据为%s",buf);
			memset(buf,0,100);
		}
	}
}
