#ifndef	__USERCODE_H_
#define	__USERCODE_H_

#include "drv_hal_conf.h"

#ifdef FREERTOS_ENABLE
extern osSemaphoreId myBinarySem01Handle;
extern osMutexId myMutexHandle;
#endif

#ifdef RTT_ENABLE
extern rt_thread_t thread1;
extern rt_thread_t thread2;

//–≈∫≈¡ø
extern rt_sem_t sem;
//ª•≥‚¡ø
extern rt_mutex_t mut;

#endif

void UserLogic_Code(void);

#endif
