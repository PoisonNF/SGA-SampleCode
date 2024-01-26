#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/*
	F4 串口中断接收实验，使用的是探索者开发板，使用串口1，完成XCOM发送什么，STM32返回什么，不超过100字节
*/

uint8_t num;
uint8_t buffer[20];

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");
	while(1)
	{
		memset(buffer,0,20);

		num = Drv_Uart_Receive_IT(&demoUart,buffer);
		if(num)
		{
			printf("%s",buffer);
			num = 0;
		}
	}
}
