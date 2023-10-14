#include "task_conf.h"

#include "config.h"

/**
 * @brief 外部中断5-9任务函数
 * @param null
 * @retval Null
*/
__weak void Task_EXTI9_5_IRQHandler(void)
{
	
}

/**
 * @brief 外部中断5-9服务函数
 * @param null
 * @retval Null
*/
void EXTI9_5_IRQHandler(void)
{
//	Drv_GPIO_EXTI_IRQHandler(&DS3231_ALARM_IRQ);	/* 必须加，参数需修改 */
	
	Task_EXTI9_5_IRQHandler();
}

/**
 * @brief 外部中断10-15任务函数
 * @param null
 * @retval Null
*/
__weak void Task_EXTI15_10_IRQHandler(void)
{
	
}

/**
 * @brief 外部中断10-15服务函数
 * @param null
 * @retval Null
*/
void EXTI15_10_IRQHandler(void)
{
//	Drv_GPIO_EXTI_IRQHandler(&tPCUart.tGPIO[1]);	/* 必须加，参数需修改 */
	
	Task_EXTI15_10_IRQHandler();
}

/**
 * @brief 串口1中断任务函数
 * @param null
 * @retval Null
*/
__weak void Task_USART1_IRQHandler(void)
{
	
}

/**
 * @brief 串口1中断服务函数
 * @param null
 * @retval Null
*/
void USART1_IRQHandler(void)
{
	/* 示例 */
//	Drv_Uart_IRQHandler(&tPCUart);		/* 必需部分 */
	
	Task_USART1_IRQHandler();
	Drv_Uart_IRQHandler(&demoUart);
}

extern uint8_t rData[100];
extern int rDataFlag;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    //如果接收到了'\n'
	if(demoUart.tRxInfo.ucpRxBuffer[0] == '\n')
  	{
      	rData[rDataFlag] = '\0';    //最后一位替换为'\0'（字符串结束符）
      	printf("%s\n",rData);       //打印rData中存储的数据
      	rDataFlag = 0;              //接收数量标识符清零

		/***************其他标志位赋值**********************/
  	}
  	else    //还没接收到'\n'
  	{
        //且接收数据量没有到达上限
      	if(rDataFlag <100)
      	{
            //将数据保存，且标识符加一
          	rData[rDataFlag] = demoUart.tRxInfo.ucpRxBuffer[0];
          	rDataFlag += 1;
      	}
  	}
    
    //等待再接收到一个字节数据
  	while(HAL_UART_Receive_IT(&demoUart.tUARTHandle, demoUart.tRxInfo.ucpRxBuffer, 1) != HAL_OK); 
}


/**
 * @brief 串口2中断任务函数
 * @param null
 * @retval Null
*/
__weak void Task_USART2_IRQHandler(void)
{
	
}

/**
 * @brief 串口1中断服务函数
 * @param null
 * @retval Null
*/
void USART2_IRQHandler(void)
{
		/* 示例 */
//	Drv_Uart_IRQHandler(&tJY901B.tUART);		/* 必需部分 */
//	
//	Task_USART2_IRQHandler();
}

/**
 * @brief 串口3中断服务函数
 * @param null
 * @retval Null
*/
void USART3_IRQHandler(void)
{

}

/**
 * @brief 串口4中断服务函数
 * @param null
 * @retval Null
*/
void UART4_IRQHandler(void)
{

}

/**
 * @brief 串口5中断服务函数
 * @param null
 * @retval Null
*/
void UART5_IRQHandler(void)
{

}

/**
 * @brief 定时器2中断服务函数
 * @param null
 * @retval Null
*/
void TIM2_IRQHandler(void)
{
	/* 示例 */
//    Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief 定时器3中断服务函数
 * @param null
 * @retval Null
*/
void TIM3_IRQHandler(void)
{
	/* 示例 */
//    Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief 定时器4中断服务函数
 * @param null
 * @retval Null
*/
void TIM4_IRQHandler(void)
{
    /* 示例 */
//    Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief 定时器5中断服务函数
 * @param null
 * @retval Null
*/
void TIM5_IRQHandler(void)
{
    /* 示例 */
//    Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief 定时器6中断服务函数
 * @param null
 * @retval Null
*/
void TIM6_IRQHandler(void)
{
    /* 示例 */
//    Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief 定时器7中断服务函数
 * @param null
 * @retval Null
*/
void TIM7_IRQHandler(void)
{
	/* 示例 */
//    Drv_Timer_IRQHandler(&demoTIM);
}



