#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/*
F4 CAN双FIFO接收实验，使用的是探索者开发板，使用CAN1，通过外部设备发送CAN消息进入板子。
            ID号为0x41、0x42、0x43从fifo0读出
            ID号为0x44、0x45从fifo1读出
*/

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	while(1)
	{
	}
}
