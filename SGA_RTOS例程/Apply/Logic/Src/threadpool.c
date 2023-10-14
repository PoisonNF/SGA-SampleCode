#include "usercode.h"		/* usercode头文件 */
#include "drv_hal_conf.h"   /* SGA库头文件配置 */
#include "task_conf.h"      /* task层头文件配置 */
#include "ocd_conf.h"       /* OCD层头文件配置 */
#include "dev_conf.h"		/* Dev层头文件配置 */
#include "algo_conf.h"		/* Algo层头文件配置 */
#include "config.h"			/* I/O配置头文件配置 */


/* 线程入口函数 */

void Task1(void *argument)
{
    while(1)
    {
#ifdef FREERTOS_ENABLE
        osSemaphoreWait(myBinarySem01Handle,0xffff); //信号量减一
            printf("线程1获得信号量\r\n");
#endif

#ifdef RTT_ENABLE
        if(rt_sem_take(sem,RT_WAITING_FOREVER) == RT_EOK)
        {
            printf("线程1获得信号量\r\n");
            if(rt_mutex_take(mut,RT_WAITING_FOREVER) == RT_EOK)
            {
                printf("线程1获得互斥量\r\n");
#endif

            HAL_UART_Transmit(&demoUart.tUARTHandle,"线程1执行\r\n",sizeof("线程1执行\r\n"),1000);
            Drv_Delay_Ms(1000);

#ifdef RTT_ENABLE
                rt_mutex_release(mut);
            }
            rt_sem_release(sem);
        }
#endif

#ifdef FREERTOS_ENABLE
        osSemaphoreRelease(myBinarySem01Handle);

        osThreadYield();
#endif
    }

}

void Task2(void *argument)
{
    while(1)
    {
#ifdef FREERTOS_ENABLE
        osSemaphoreWait(myBinarySem01Handle,0xffff); //信号量减一
            printf("线程2获得信号量\r\n");
        if(osMutexAcquire(myMutexHandle,osWaitForever) == osOK)
        {
            printf("线程2获得互斥量\r\n");
#endif

#ifdef RTT_ENABLE
        if(rt_sem_take(sem,RT_WAITING_FOREVER) == RT_EOK)
        {
            printf("线程2获得信号量\r\n");
            if(rt_mutex_take(mut,RT_WAITING_FOREVER) == RT_EOK)
            {
                printf("线程2获得互斥量\r\n");
#endif

                HAL_UART_Transmit(&demoUart.tUARTHandle,"线程2执行\r\n",sizeof("线程2执行\r\n"),1000);
                Drv_Delay_Ms(1000);

#ifdef RTT_ENABLE
                rt_mutex_release(mut);
            }
            rt_sem_release(sem);
        }
#endif

#ifdef FREERTOS_ENABLE
            osMutexRelease(myMutexHandle);
        }
        osSemaphoreRelease(myBinarySem01Handle);

        osDelay(1);
#endif

    }

}
