#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/*
	F4 LED实验，使用的是探索者开发板，500ms翻转一次，使用的是PF9,PF10两个LED
*/

/* 用户逻辑代码 */
void UserLogic_Code(void)
{

	while(1)
	{
		Drv_GPIO_Reset(&demoGPIO[0]);
        Drv_GPIO_Reset(&demoGPIO[1]);

		Drv_Delay_Ms(500);
        
        Drv_GPIO_Set(&demoGPIO[0]);
        Drv_GPIO_Set(&demoGPIO[1]);
        
        Drv_Delay_Ms(500);

	}
}
