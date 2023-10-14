#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

uint8_t Timeflag_100MS;
uint8_t Timeflag_1000MS;
uint8_t Timeflag_Count;

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	while(1)
	{
		//串口1一直打印
		printf("SGA_DEMO\r\n");

		if(Timeflag_100MS)
		{
			//红色LED翻转
			Drv_GPIO_Toggle(&demoGPIO[0]);
			//标志位清零
			Timeflag_100MS = 0;
		}

		if(Timeflag_1000MS)
		{
			//蓝色LED翻转
			Drv_GPIO_Toggle(&demoGPIO[2]);
			//标志位清零
			Timeflag_1000MS = 0;
		}
	}
}
