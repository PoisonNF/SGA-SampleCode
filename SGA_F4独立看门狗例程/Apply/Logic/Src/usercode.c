#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/*
	F4 独立看门狗实验，使用的是探索者开发板，使用独立看门狗
    上电后每秒打印SGA_DEMO1，5s后喂一次狗，再5s后不喂狗触发复位
    独立看门狗触发时间设置为6s
*/

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	
    for(uint8_t i = 0;i < 5;i++)
    {
        printf("SGA_DEMO1\r\n");
        Drv_Delay_Ms(1000);
    }
    
    Drv_IWDG_Feed(&demoIWDG);
    printf("喂狗\r\n");
    
    for(uint8_t i = 0;i < 5;i++)
    {
        printf("SGA_DEMO2\r\n");
        Drv_Delay_Ms(1000);
    }   

    printf("即将复位\r\n");

}
