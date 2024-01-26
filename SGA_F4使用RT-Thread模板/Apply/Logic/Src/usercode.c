#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */

/* 线程句柄 */
rt_thread_t thread1 = RT_NULL;
rt_thread_t thread2 = RT_NULL;

/* 用户逻辑代码 */
void UserLogic_Code(void)
{

    /* 创建线程 */
	thread1 = rt_thread_create("Thread1",Thread1,NULL,1024,1,20);


	thread2 = rt_thread_create("Thread2",Thread2,NULL,512,4,20);
    
    rt_thread_startup(thread1);		//线程1 
	rt_thread_startup(thread2);		//线程2 
}
