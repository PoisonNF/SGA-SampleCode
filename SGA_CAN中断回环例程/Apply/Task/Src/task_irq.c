#include "task_conf.h"
#include "usercode.h"
#include "config.h"


/**
 * @brief 外部中断5-9服务函数
 * @retval Null
*/
void EXTI9_5_IRQHandler(void)
{
    //Drv_GPIO_EXTI_IRQHandler(&DS3231_ALARM_IRQ);	/* 必须加，参数需修改 */
}

/**
 * @brief 外部中断10-15服务函数
 * @retval Null
*/
void EXTI15_10_IRQHandler(void)
{
    //Drv_GPIO_EXTI_IRQHandler(&tPCUart.tGPIO[1]);	/* 必须加，参数需修改 */
}

/**
 * @brief 串口1中断服务函数
 * @retval Null
*/
void USART1_IRQHandler(void)
{
	/* 示例 */
    //Drv_Uart_IRQHandler(&tPCUart);		/* 必需部分 */
}

/**
 * @brief 串口2中断服务函数
 * @retval Null
*/
void USART2_IRQHandler(void)
{
	/* 示例 */
    //Drv_Uart_IRQHandler(&tJY901B.tUART);		/* 必需部分 */
}

/**
 * @brief 串口3中断服务函数
 * @retval Null
*/
void USART3_IRQHandler(void)
{

}

/**
 * @brief 串口4中断服务函数
 * @retval Null
*/
void UART4_IRQHandler(void)
{

}

/**
 * @brief 串口5中断服务函数
 * @retval Null
*/
void UART5_IRQHandler(void)
{

}

/**
 * @brief 定时器2中断服务函数
 * @retval Null
*/
void TIM2_IRQHandler(void)
{
	/* 示例 */
    //Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief 定时器3中断服务函数
 * @retval Null
*/
void TIM3_IRQHandler(void)
{
	/* 示例 */
    //Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief 定时器4中断服务函数
 * @retval Null
*/
void TIM4_IRQHandler(void)
{
    /* 示例 */
    //Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief 定时器5中断服务函数
 * @retval Null
*/
void TIM5_IRQHandler(void)
{
    /* 示例 */
    //Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief 定时器6中断服务函数
 * @retval Null
*/
void TIM6_IRQHandler(void)
{
    /* 示例 */
    //Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief 定时器7中断服务函数
 * @retval Null
*/
void TIM7_IRQHandler(void)
{
	/* 示例 */
    //Drv_Timer_IRQHandler(&demoTIM);
}

/**
 * @brief CAN1发送中断服务函数
 * @retval Null
*/
void CAN1_TX_IRQHandler(void)
{
    Drv_CAN_IRQHandler(&CAN);
    printf("TX IRQ\r\n");
}

/**
 * @brief CAN1接收0中断服务函数
 * @retval Null
*/
void CAN1_RX0_IRQHandler(void)
{
    Drv_CAN_IRQHandler(&CAN);
    printf("RX IRQ\r\n");
}

/* 邮箱0发送完成回调函数 */
void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan)
{
    /* 
        加入发送完成后的操作 
    */

    //发送完成提示
    printf("TX Complete\r\n");
}

extern uint8_t num;
extern uint8_t ReceBuffer[8];

/* FIFO0接收完成回调函数 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    if(hcan->Instance == CAN.tCANHandle.Instance)
    {
        /* CAN中断接收，并打印 */
        num = Drv_CAN_ReceMsg(&CAN,ReceBuffer);
        if(num) printf("RX %s\r\n\r\n",ReceBuffer);
    }
}

