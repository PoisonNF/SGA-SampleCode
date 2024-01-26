#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/*
	F4 DAC实验，使用的是探索者开发板，设置PA4输出3.3V，设置PA5输出2V
*/

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	//设置PA4输出3.3V
	Drv_DAC_SetValue(&demoDAC[0],3.3);

	//设置PA5输出2V
	Drv_DAC_SetValue(&demoDAC[1],2);

	while(1)
	{


	}
}
