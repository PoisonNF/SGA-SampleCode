#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

//翻转LED函数，num值为翻转次数
void LED_Toggle(tagGPIO_T *tGPIO,uint8_t num)
{
	for(int i = 0;i < num;i++)
	{
		Drv_GPIO_Reset(tGPIO);
		Drv_Delay_Ms(500);
		Drv_GPIO_Set(tGPIO);
		Drv_Delay_Ms(500);
	}
}

/* 用户逻辑代码 */
void UserLogic_Code(void)
{

	while(1)
	{
		printf("SGA_DEMO\r\n");

		//绿灯翻转5次
		LED_Toggle(&demoGPIO[2],5);

		printf("正在进入睡眠模式\r\n");
        
		Drv_PWR_EnterSleepMode();	//进入睡眠模式
        
		printf("从睡眠模式醒来\r\n");

		//红灯翻转1次
		LED_Toggle(&demoGPIO[3],1);

		printf("正在进入停止模式\r\n");
        
        Drv_Delay_Ms(10);	//防止未打印完成就停止了
		Drv_PWR_EnterStopMode();	//进入停止模式
        
		printf("从停止模式醒来\r\n");

		//红灯翻转1次
		LED_Toggle(&demoGPIO[3],1);

		printf("正在进入待机模式\r\n");

		Drv_PWR_EnterStandByMode();	//进入待机模式
        
		//以下代码将不会运行
		printf("该部分不会运行\r\n");
		LED_Toggle(&demoGPIO[3],1);
	}
}

