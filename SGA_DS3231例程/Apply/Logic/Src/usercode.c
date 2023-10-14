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
    
    tagDS3231Time_T time;
    tagDS3231TimeASCII_T Atime;
   
	while(1)
	{
        //以十六进制获取时间
        if(OCD_DS3231_TimeGetHex(&tDS3231,&time))
        {
            printf("From Hex time\r\n");
            printf("20%02x年%02x月%02x日 %02x时%02x分%02x秒 周%02x\r\n",
                    time.ucYear,time.ucMonth,time.ucDate,
                    time.ucHour,time.ucMinute,time.ucSecond,
                    time.ucWeek);
        }
        //以ASCII获取时间
        if(OCD_DS3231_TimeGetASCII(&tDS3231,&Atime))
        {
            printf("From ASCII time\r\n");
            printf("20%c%c年%c%c月%c%c日 %c%c时%c%c分%c%c秒 周%c%c\r\n",
                     Atime.ucYear[0],Atime.ucYear[1],Atime.ucMonth[0],Atime.ucMonth[1],Atime.ucDate[0],Atime.ucDate[1],
                     Atime.ucHour[0],Atime.ucHour[1],Atime.ucMinute[0],Atime.ucMinute[1],Atime.ucSecond[0],Atime.ucSecond[1],
                     Atime.ucWeek[0],Atime.ucWeek[1]);
        }
        Drv_Delay_Ms(1000);
        printf("\r\n");
	}
}
