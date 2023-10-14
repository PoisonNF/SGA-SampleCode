#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/*	本例程使用了独立看门狗。
	通过改变demoIWDG.usResetTime的取值调整溢出时间。本例程默认10s。
	现在规定内喂两次狗，后续不再喂狗，当溢出时间达到时将会重启系统。
*/

//计算已经逝去的秒数
uint8_t time = 0;

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

	Drv_IWDG_Feed(&demoIWDG);
	printf("第一次喂狗\r\n");
    
    Drv_Delay_Ms(1000);

	Drv_IWDG_Feed(&demoIWDG);
	printf("第二次喂狗\r\n");

	while(1)
	{
		printf("已经%ds没喂狗了,%ds后系统将会重启\r\n",time,demoIWDG.usResetTime/1000 - time);
        
		//当下一秒就是溢出时间点，打印系统即将重启
        if ((time + 1) == demoIWDG.usResetTime/1000)
			printf("系统即将重启！\r\n\r\n");

		//延时1s,秒数加一
		Drv_Delay_Ms(1000);
		time += 1;	
	}
}
