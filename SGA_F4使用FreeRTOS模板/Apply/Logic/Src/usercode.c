#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

osThreadId_t task1Handle;
const osThreadAttr_t task1_atrributes = {
  .name = "task1",
  .stack_size = 128*4,
  .priority = (osPriority_t) osPriorityNormal,
};

osThreadId_t task2Handle;
const osThreadAttr_t task2_atrributes = {
  .name = "task2",
  .stack_size = 128*4,
  .priority = (osPriority_t) osPriorityNormal1,
};

//信号量配置
osSemaphoreId myBinarySem01Handle;
osSemaphoreDef(myBinarySem01);

//互斥量配置
osMutexId myMutexHandle;
osMutexDef(myMutex);

/* 用户逻辑代码 */
void UserLogic_Code(void)
{
    //创建信号量，初始值为1
    myBinarySem01Handle = osSemaphoreCreate(osSemaphore(myBinarySem01), 1);
    //创建互斥量
    myMutexHandle = osMutexCreate(osMutex(myMutex));

	task1Handle = osThreadNew(Task1,NULL,&task1_atrributes);
    task2Handle = osThreadNew(Task2,NULL,&task2_atrributes);
    printf("FreeRTOS 调度开始！\r\n");
    
	osKernelStart();
}

