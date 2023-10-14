#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/* 正点原子精英板 PE4 KEY0 外部中断例程*/
/* 按下KEY0 时 ，串口会发送"中断！\r\n" 和"回调！\r\n" */

/* 用户逻辑代码 */
void UserLogic_Code(void)
{ 
	while(1)
	{
		printf("SGA_DEMO\r\n");
		Drv_Delay_Ms(1000);
	}
}
