#include "task_ds3231.h"
#include "config.h"

tagDS3231Time_T s_tSysTime = {
    .ucYear		= 0x22,
	.ucMonth	= 0x03,
	.ucDate		= 0x29,
	.ucHour		= 0x09,
	.ucMinute	= 0x16,
	.ucSecond	= 0x00,
};

void Task_DS1337_Test(void)
{
	printf("Write Time:20%02x/%02x/%02x %02x:%02x:%02x\r\n", s_tSysTime.ucYear, s_tSysTime.ucMonth, s_tSysTime.ucDate, s_tSysTime.ucHour, s_tSysTime.ucMinute, s_tSysTime.ucSecond);
	OCD_DS3231_TimeSetHex(&tDS3231, &s_tSysTime);

	printf("Delay 2S!\r\n");
	Drv_Delay_Ms(2000);

    if(OCD_DS3231_TimeGetHex(&tDS3231,&s_tSysTime))
    {
        printf("Read Time:");
        printf("20%02x/%02x/%02x %02x:%02x:%02x\r\n",
                s_tSysTime.ucYear,s_tSysTime.ucMonth,s_tSysTime.ucDate,
                s_tSysTime.ucHour,s_tSysTime.ucMinute,s_tSysTime.ucSecond);
    }
	printf("\r\n");
}
