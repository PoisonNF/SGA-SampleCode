#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/* 	demoGPIO[0] PD13 R
	demoGPIO[1] PD14 G
	demoGPIO[2] PD15 B
*/

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
    printf("SGA_DEMO\r\n");

	//LED初始熄灭
	Drv_GPIO_Set(&demoGPIO[0]);
	Drv_GPIO_Set(&demoGPIO[1]);
	Drv_GPIO_Set(&demoGPIO[2]);

	while(1)
	{
		//红灯
		Drv_GPIO_Reset(&demoGPIO[0]);
		Drv_GPIO_Set(&demoGPIO[1]);
		Drv_GPIO_Set(&demoGPIO[2]);

		Drv_Delay_Ms(1000);

		//绿灯
		Drv_GPIO_Set(&demoGPIO[0]);
		Drv_GPIO_Reset(&demoGPIO[1]);
		Drv_GPIO_Set(&demoGPIO[2]);

		Drv_Delay_Ms(1000);

		//蓝灯
		Drv_GPIO_Set(&demoGPIO[0]);
		Drv_GPIO_Set(&demoGPIO[1]);
		Drv_GPIO_Reset(&demoGPIO[2]);

		Drv_Delay_Ms(1000);
	}
}
