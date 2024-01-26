#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/*
	F4 PWM呼吸灯实验，使用的是探索者开发板，使用PF9的LED，实现呼吸灯效果
*/

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	//PF9初始为100%
	Drv_PWM_DutyFactorSet(&tPWMDemo[0],100);

	while(1)
	{
		for(uint8_t i = 0; i<100;i++)
		{
			Drv_PWM_DutyFactorSet(&tPWMDemo[0],100 - i);
			Drv_Delay_Ms(10);
		}

		for(uint8_t i = 0; i<100;i++)
		{
			Drv_PWM_DutyFactorSet(&tPWMDemo[0],i);
			Drv_Delay_Ms(10);
		}

	}
}
