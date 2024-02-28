#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/*
	F4 CAN回环实验，使用的是探索者开发板，使用CAN1，完成CAN的自发自收中断测试，并将CAN收到的数据通过串口1发给XCOM
*/

uint8_t num;
uint8_t SendBuffer[8] = "1234567";
uint8_t ReceBuffer[8];

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	while(1)
	{
        memset(ReceBuffer,0,8);

        //CAN发送数据
		if(Drv_CAN_SendMsg(&CAN,SendBuffer,8))
		{
			printf("Send Error\r\n");
		}

		Drv_Delay_Ms(1000);

        //CAN接收数据
		// num = Drv_CAN_ReceMsg(&CAN,ReceBuffer);
		// if(num != 0)
		// {
		// 	printf("num = %d  ReceBuffer = %s\r\n",num,ReceBuffer);
		// 	printf("TxID = %x\r\n",CAN.tCANRxHeader.StdId);
		// }

	}
}
