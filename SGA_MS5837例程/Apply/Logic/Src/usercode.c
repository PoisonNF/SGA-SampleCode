#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/*  每隔100ms读取一次ms5837的数据，并显示在OLED上
	没有OLED可以通过串口1接到电脑显示数据
*/

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");
	OCD_OLED_Clear(&tOLED);

	while(1)
	{
		//获取MS5837温度和压力数据
		OCD_MS5837_GetData(&MS5837);

		//打印相关数据
		printf("Temp1:%.2fC Press1:%.2fmBar\r\n",MS5837.fTemp1,MS5837.fPress1);
		printf("Temp:%.2fC Press:%.2fmBar\r\n",MS5837.fTemp2,MS5837.fPress2);
		printf("%.2fcm\r\n",MS5837.fDepth);

		//以下有OLED才能正常显示
		OCD_OLED_ShowString(&tOLED,0,0,"temp:",8);
		OCD_OLED_ShowFNum(&tOLED,10,1,MS5837.fTemp2,8);
		OCD_OLED_ShowString(&tOLED,50,1,"C",8);

		OCD_OLED_ShowString(&tOLED,0,2,"press:",8);
		OCD_OLED_ShowFNum(&tOLED,10,3,MS5837.fPress2,8);
		OCD_OLED_ShowString(&tOLED,60,3,"mBar",8);

		OCD_OLED_ShowString(&tOLED,0,4,"depth:",8);
		OCD_OLED_ShowFNum(&tOLED,10,5,MS5837.fDepth,8);
		OCD_OLED_ShowString(&tOLED,50,5,"cm",8);

		Drv_Delay_Ms(100);
	}
}
