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
	int i;
	while(1)
	{
		for(i = 0;i<4;i++)
			OCD_RM3100_GetData(&RM3100[i]);

        printf("R 1 %d %d %d\r\n",RM3100[0].tMagData.MAG_X,RM3100[0].tMagData.MAG_Y,RM3100[0].tMagData.MAG_Z);
		printf("R 2 %d %d %d\r\n",RM3100[1].tMagData.MAG_X,RM3100[1].tMagData.MAG_Y,RM3100[1].tMagData.MAG_Z);
		printf("R 3 %d %d %d\r\n",RM3100[2].tMagData.MAG_X,RM3100[2].tMagData.MAG_Y,RM3100[2].tMagData.MAG_Z);
		printf("R 4 %d %d %d\r\n",RM3100[3].tMagData.MAG_X,RM3100[3].tMagData.MAG_Y,RM3100[3].tMagData.MAG_Z);

		for(i = 0;i<4;i++)
			OCD_RM3100_ModeConfig(&RM3100[i]);
		//printf("SGA_DEMO\r\n");
		Drv_Delay_Ms(1000);
	}
}
