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

	//期望值为150 初始值为50
	float ExpectValue = 50.0f;
	float CurrentValue = 50.0f;

	// 存储输出值，连续稳定才算稳定
	float Buffer[3] = {0};

	//PID系数值
	float PIDparameter[3] = {0.8, 0.25, 0.01};

	//更新PID系数，默认与结构体中相同
	Algo_PID_Update(&PID,PIDparameter);

	do
	{
		//进行PID计算，返回值赋给当前值
		CurrentValue = Algo_PID_Calculate(&PID,CurrentValue,ExpectValue);
		printf("%d\r\n",(int)CurrentValue);

		//数据寄存
		Buffer[2] = Buffer[1];
		Buffer[1] = Buffer[0];
		Buffer[0] = CurrentValue;

		//延时方便观察
		Drv_Delay_Ms(50);

	} while (!((Buffer[0] == Buffer[1]) 
			&& (Buffer[0] == Buffer[2])
			&& (Buffer[1] == Buffer[2])));	//连续稳定三拍跳出
    
    printf("达到稳定状态\r\n");
	return;
}
