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
	printf("SGA_DEMO\r\n");

	//PA6初始为0% PA7为100%
	Drv_PWM_DutyFactorSet(&tPWMDemo[0],0);
    Drv_PWM_DutyFactorSet(&tPWMDemo[1],100);

	Drv_Delay_Ms(2000);

	//2s后，PA6变为7.5% PA7变为7.5%
	Drv_PWM_HighLvTimeSet(&tPWMDemo[0],1500);	//高电平时间为1.5ms，换算成百分比就是7.5
	Drv_PWM_DutyFactorSet(&tPWMDemo[1],7.5);

	while(1)
	{

	}
}
