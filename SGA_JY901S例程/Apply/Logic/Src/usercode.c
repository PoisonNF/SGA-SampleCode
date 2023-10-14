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
	while(1)
	{
        //如果数据获得并且处理完成
		if(OCD_JY901_DataProcess(&JY901S))
        {
            OCD_JY901_DataConversion(&JY901S);	//数据转换
            OCD_JY901_Printf(&JY901S); 			//数据打印
            printf("\r\n");
        }
	}
}
