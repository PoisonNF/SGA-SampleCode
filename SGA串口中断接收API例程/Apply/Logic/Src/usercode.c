#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

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
			printf("接收到的数据为%s\n",buf);
			memset(buf,0,100);
		}
	}
}
