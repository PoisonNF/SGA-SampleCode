#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_IM_Test!\r\n");
	printf("Enter @ + num to start!\r\n");
	printf("0:All 1:LED 2:DS1337 3:TATFS 4:AT24CXX 5:JY901\r\n");
	
	while(1)
	{
		//监听PC的命令
		Task_PCUartListen();
	}
}
