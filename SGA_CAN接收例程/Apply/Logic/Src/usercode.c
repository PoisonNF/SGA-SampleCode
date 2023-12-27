#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/* 
    本例程完成CAN接收数据，如果要显示数据，需要使用CAN分析仪或者另一块板子烧录SGA_CAN发送例程
    使用的是PA11 PA12，注意使用正点原子开发板需要使用跳线帽将两个IO口连接到CAN芯片上
    
    完成CAN接收，接收CAN数据后，通过串口1提示
*/

uint8_t ReceBuffer[8];
uint8_t num;

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	Drv_CAN_ModeConfig(&CAN,CAN_MODE_NORMAL);       //切换为正常模式

	while(1)
	{
        memset(ReceBuffer,0,8);
		num = Drv_CAN_ReceMsg(&CAN,ReceBuffer);
		if(num != 0)
		{
			printf("num = %d  ReceBuffer = %s\r\n",num,ReceBuffer);
			printf("ID = %x\r\n",CAN.tCANRxHeader.StdId);
		}

		Drv_Delay_Ms(1000);
    }
}
