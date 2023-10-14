#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/* 本例程使用了两路ADC和两路DAC，需要使用杜邦线完成以下连接
    DAC通道1 PA4 接 ADC1 通道0 PA0
    DAC通道2 PA5 接 ADC1 通道1 PA1

    DAC采用两种不同的输出方式进行输出
 */

//存放当前电压值
float Value1 = 0.0f;
float Value2 = 0.0f;

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
	printf("SGA_DEMO\r\n");

    //通道1和2电压设置
    Drv_DAC_SetValue(&demoDAC[0],3);
    Drv_DAC_SetData(&demoDAC[1],2047);

	while(1)
	{
        //使用ADC读取电压值并打印
		Value1 = Drv_ADC_PollGetValue(&demoADC[0]);
		printf("Channel1 :%fV\r\n",Value1);
        Value2 = Drv_ADC_PollGetValue(&demoADC[1]);
        printf("Channel2 :%fV\r\n",Value2);
        printf("\r\n");
              
        Drv_Delay_Ms(500);

	}
}
