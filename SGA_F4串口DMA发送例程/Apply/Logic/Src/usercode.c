#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/*
	F4 串口DMA接收实验，使用的是探索者开发板，使用串口1，完成XCOM发送什么，STM32返回什么，不超过100字节
*/

uint8_t num;
uint8_t ReceBuffer[50];
uint8_t SendBuffer[50];

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");
	while(1)
	{
		memset(ReceBuffer,0,50);

		num = Drv_Uart_Receive_DMA(&demoUart,ReceBuffer);
		if(num)
		{
			
			memcpy(SendBuffer,ReceBuffer,num);						//内存拷贝
			Drv_Uart_Transmit_DMA(&demoUart,SendBuffer,num);
			num = 0;
		}
	}
}
