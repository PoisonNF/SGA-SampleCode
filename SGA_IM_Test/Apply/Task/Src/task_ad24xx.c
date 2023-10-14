#include "task_ad24xx.h"
#include "config.h"

static uint8_t s_ucpAT24CXXData[] = "AT24CXX Test OK!!!\r\n";

void Task_AT24CXX_Test(void)
{
    if(OCD_AT24CXX_Check(&tAT24CXX))
	{
		printf("AT24CXX Check Right!\r\n");
		OCD_AT24CXX_WriteLenByte(&tAT24CXX, 0, s_ucpAT24CXXData, 20);
        printf("AT24CXX Write:%s", s_ucpAT24CXXData);
		memset(s_ucpAT24CXXData, 0, sizeof(s_ucpAT24CXXData));
		OCD_AT24CXX_ReadLenByte(&tAT24CXX, 0, s_ucpAT24CXXData, 20);
		printf("AT24CXX Read:%s\r\n", s_ucpAT24CXXData);
	}
	else
		printf("AT24CXX Error!\r\n");  
}

