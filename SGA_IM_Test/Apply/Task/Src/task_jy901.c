#include "task_jy901.h"
#include "config.h"

void Task_JY901_Test(void)
{
    //如果数据获得并且处理完成
	if(OCD_JY901_DataProcess(&JY901S))
    {
        OCD_JY901_DataConversion(&JY901S);	//数据转换
        OCD_JY901_Printf(&JY901S); 			//数据打印
        printf("\r\n");
    }
}

