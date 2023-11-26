#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/**
 * 该例程实现从串口1DMA接收数据，并从串口1使用DMA发送的方式返还数据。
 * 
 */

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	uint8_t num;					//记录存储字节数
	uint8_t ReceBuffer[100];		//接收数据buffer
	uint8_t SendBuffer[200];		//发送数据buffer

	printf("SGA_DEMO\r\n");

	while(1)
	{
		//从串口1DMA接收数据，存放到buffer中
		num = Drv_Uart_Receive_DMA(&demoUart,ReceBuffer);

        //接收到的数据个数不为0
		if(num != 0)
		{
			//printf("num = %d\r\n",num);
			memcpy(SendBuffer,ReceBuffer,num);						//内存拷贝
            Drv_Uart_Transmit_DMA(&demoUart,SendBuffer,num);		//DMA发送
        
			num = 0;
		}
	}
}
