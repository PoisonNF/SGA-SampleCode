#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/* 
    使用一块板子即可完成回环实验
    使用的是PA11 PA12，注意使用正点原子开发板需要使用跳线帽将两个IO口连接到CAN芯片上
    
    完成CAN自发自收测试，收到CAN数据后通过串口1发出
    发送内容为CAN数据，发送者CAN的ID号
    
*/

uint8_t SendBuffer[8] = "1234567";
uint8_t ReceBuffer[8];
uint8_t num;

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
		num = Drv_CAN_ReceMsg(&CAN,ReceBuffer);
		if(num != 0)
		{
			printf("num = %d  ReceBuffer = %s\r\n",num,ReceBuffer);
			printf("TxID = %x\r\n",CAN.tCANRxHeader.StdId);
		}

	}
}
