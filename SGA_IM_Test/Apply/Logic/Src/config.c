#include "config.h"


/* LED三基色 */
tagGPIO_T LED[] =
{
	
	[0]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_13,				/* GPIO引脚 */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIO模式 */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
		.tGPIOPort 			= GPIOD,					/* GPIO分组 */
	},
    [1]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_14,				/* GPIO引脚 */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIO模式 */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
		.tGPIOPort 			= GPIOD,					/* GPIO分组 */
	},
    [2]=
	{ 
		.tGPIOInit.Pin 		= GPIO_PIN_15,				/* GPIO引脚 */
		.tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIO模式 */
		.tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
		.tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
		.tGPIOPort 			= GPIOD,					/* GPIO分组 */
	},
    
};

/* 串口句柄示例 */
tagUART_T Uart1 = 
{
	//串口工作模式配置
	.tUARTHandle.Instance 				= USART1,					/* STM32 串口设备 */
	.tUARTHandle.Init.BaudRate   		= 115200,					/* 串口波特率 */
	.tUARTHandle.Init.WordLength 		= UART_WORDLENGTH_8B,
	.tUARTHandle.Init.StopBits   		= UART_STOPBITS_1,
	.tUARTHandle.Init.Parity     		= UART_PARITY_NONE,
	.tUARTHandle.Init.HwFlowCtl  		= UART_HWCONTROL_NONE,
	.tUARTHandle.Init.Mode       		= UART_MODE_TX_RX,
	.tUARTHandle.Init.OverSampling 		= UART_OVERSAMPLING_16,

#if defined (STM32L4_SGA_ENABLE)
	.tUARTHandle.Init.OneBitSampling 	= UART_ONE_BIT_SAMPLE_DISABLE,
	.tUARTHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT,
#endif
	
	.ucPriority							= 1,						/* 中断优先级 */
	.ucSubPriority						= 3,						/* 中断子优先级 */
	
	//串口DMA接收参数配置
	.tUartDMA.bRxEnable					= true,						/* DMA接收使能 */
	.tUartDMA.tDMARx.Instance			= DMA1_Channel5,
	.tUartDMA.tDMARx.Init.Direction		= DMA_PERIPH_TO_MEMORY,
	.tUartDMA.tDMARx.Init.PeriphInc		= DMA_PINC_DISABLE,
	.tUartDMA.tDMARx.Init.MemInc		= DMA_MINC_ENABLE,
	.tUartDMA.tDMARx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE,
	.tUartDMA.tDMARx.Init.MemDataAlignment	  = DMA_MDATAALIGN_BYTE,
	.tUartDMA.tDMARx.Init.Mode			= DMA_CIRCULAR,
	.tUartDMA.tDMARx.Init.Priority		= DMA_PRIORITY_LOW,

	.tRxInfo.usDMARxMAXSize             	= 100,              	/* 接收数据长度 长度保持在协议最长字节*2以上，确保缓存池一定能够稳定接收一个完整的数据帧*/

	.tUartDMA.ucDMARxPriority				= 1,					/* DMA接收中断优先级 */
	.tUartDMA.ucDMARxSubPriority			= 1,					/* DMA接收中断子优先级 */
	
	//串口DMA发送参数配置
	.tUartDMA.bTxEnable					= true,						/* DMA发送使能 */
	.tUartDMA.tDMATx.Instance			= DMA1_Channel4,
	.tUartDMA.tDMATx.Init.Direction		= DMA_MEMORY_TO_PERIPH,
	.tUartDMA.tDMATx.Init.PeriphInc		= DMA_PINC_DISABLE,
	.tUartDMA.tDMATx.Init.MemInc		= DMA_MINC_ENABLE,
	.tUartDMA.tDMATx.Init.PeriphDataAlignment	= DMA_PDATAALIGN_BYTE,
	.tUartDMA.tDMATx.Init.MemDataAlignment		= DMA_MDATAALIGN_BYTE,
	.tUartDMA.tDMATx.Init.Mode			= DMA_NORMAL,
	.tUartDMA.tDMATx.Init.Priority		= DMA_PRIORITY_LOW,

	.tTxInfo.usDMATxMAXSize				= 50,						/* 最大发送数据长度 */
	
	.tUartDMA.ucDMATxPriority				= 1,					/* DMA发送中断优先级 */
	.tUartDMA.ucDMATxSubPriority			= 1,					/* DMA发送中断子优先级 */

	//串口GPIO配置
	.tGPIO[0].tGPIOInit.Pin 			= GPIO_PIN_9,				/* GPIO引脚 */
	.tGPIO[0].tGPIOInit.Mode 			= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tGPIO[0].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tGPIO[0].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tGPIO[0].tGPIOPort 				= GPIOA,					/* GPIO分组 */
	.tGPIO[0].ucAFMode					= NO_REMAP,					/* GPIO重映射 */
	
	.tGPIO[1].tGPIOInit.Pin 			= GPIO_PIN_10,				/* GPIO引脚 */
	.tGPIO[1].tGPIOInit.Mode 			= GPIO_MODE_INPUT,			/* GPIO模式 */
	.tGPIO[1].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tGPIO[1].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tGPIO[1].tGPIOPort 				= GPIOA,					/* GPIO分组 */
	.tGPIO[1].ucAFMode					= NO_REMAP,					/* GPIO重映射 */
};

/* DS3231示例 */
tagDS3231_T tDS3231 = 
{
	/* SCL线 */
	.tIICSoft.tIICSoft[0].tGPIOInit.Pin 	= GPIO_PIN_5,				/* GPIO引脚 */
	.tIICSoft.tIICSoft[0].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,		/* GPIO模式 */
	.tIICSoft.tIICSoft[0].tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tIICSoft.tIICSoft[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tIICSoft.tIICSoft[0].tGPIOPort 		= GPIOE,					/* GPIO分组 */
	
	/* SDA线 */
	.tIICSoft.tIICSoft[1].tGPIOInit.Pin 	= GPIO_PIN_4,				/* GPIO引脚 */
	.tIICSoft.tIICSoft[1].tGPIOInit.Mode 	= GPIO_MODE_INPUT,			/* GPIO模式 */
	.tIICSoft.tIICSoft[1].tGPIOInit.Pull 	= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tIICSoft.tIICSoft[1].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tIICSoft.tIICSoft[1].tGPIOPort 		= GPIOE,					/* GPIO分组 */
};

/* SD卡，FATFS文件系统示例 */
tagFATFS_T tFATFS = 
{
	.tSPI.tSPIHandle.Instance 				= SPI1,
	.tSPI.tSPIHandle.Init.Mode 				= SPI_MODE_MASTER,
	.tSPI.tSPIHandle.Init.Direction 		= SPI_DIRECTION_2LINES,
	.tSPI.tSPIHandle.Init.DataSize 			= SPI_DATASIZE_8BIT,
	.tSPI.tSPIHandle.Init.CLKPolarity 		= SPI_POLARITY_HIGH,
	.tSPI.tSPIHandle.Init.CLKPhase 			= SPI_PHASE_2EDGE,
	.tSPI.tSPIHandle.Init.NSS 				= SPI_NSS_SOFT,
	.tSPI.tSPIHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256,
	.tSPI.tSPIHandle.Init.FirstBit 			= SPI_FIRSTBIT_MSB,
	.tSPI.tSPIHandle.Init.TIMode 			= SPI_TIMODE_DISABLE,
	.tSPI.tSPIHandle.Init.CRCCalculation 	= SPI_CRCCALCULATION_DISABLE,
	.tSPI.tSPIHandle.Init.CRCPolynomial 	= 7,	
#if defined (STM32L4_SGA_ENABLE)
	.tSPI.tSPIHandle.Init.CRCLength 		= SPI_CRC_LENGTH_DATASIZE,
	.tSPI.tSPIHandle.Init.NSSPMode 			= SPI_NSS_PULSE_ENABLE,	
#endif
	
	.tSPI.tGPIO[0].tGPIOInit.Pin 			= GPIO_PIN_5,				/* GPIO引脚 */
	.tSPI.tGPIO[0].tGPIOInit.Mode 			= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tSPI.tGPIO[0].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tSPI.tGPIO[0].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tSPI.tGPIO[0].tGPIOPort 				= GPIOA,					/* GPIO分组 */
	
	.tSPI.tGPIO[1].tGPIOInit.Pin 			= GPIO_PIN_7,				/* GPIO引脚 */
	.tSPI.tGPIO[1].tGPIOInit.Mode 			= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tSPI.tGPIO[1].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tSPI.tGPIO[1].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tSPI.tGPIO[1].tGPIOPort 				= GPIOA,					/* GPIO分组 */
	
	.tSPI.tGPIO[2].tGPIOInit.Pin 			= GPIO_PIN_6,				/* GPIO引脚 */
	.tSPI.tGPIO[2].tGPIOInit.Mode 			= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tSPI.tGPIO[2].tGPIOInit.Pull 			= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tSPI.tGPIO[2].tGPIOInit.Speed 			= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tSPI.tGPIO[2].tGPIOPort 				= GPIOA,					/* GPIO分组 */
};

/* AT24系列示例 */
tagAT24CXX_T tAT24CXX = 
{
	/* SCL线 */
	.tIIC.tIICSoft[0].tGPIOInit.Pin 		= GPIO_PIN_0,				/* GPIO引脚 */
	.tIIC.tIICSoft[0].tGPIOInit.Mode		= GPIO_MODE_OUTPUT_PP,		/* GPIO模式 */
	.tIIC.tIICSoft[0].tGPIOInit.Pull		= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tIIC.tIICSoft[0].tGPIOInit.Speed		= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tIIC.tIICSoft[0].tGPIOPort 			= GPIOA,					/* GPIO分组 */
	
	/* SDA线 */
	.tIIC.tIICSoft[1].tGPIOInit.Pin 		= GPIO_PIN_1,				/* GPIO引脚 */
	.tIIC.tIICSoft[1].tGPIOInit.Mode		= GPIO_MODE_INPUT,			/* GPIO模式 */
	.tIIC.tIICSoft[1].tGPIOInit.Pull		= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tIIC.tIICSoft[1].tGPIOInit.Speed		= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tIIC.tIICSoft[1].tGPIOPort 			= GPIOA,					/* GPIO分组 */
};

/* JY901S示例 */
tagJY901_T JY901S = 
{
	.tConfig.ucBaud 	= JY901_RXBAUD_9600,
	.tConfig.ucRate		= JY901_RX_0_5HZ,
	.tConfig.usType		= JY901_OUTPUT_ACCEL | JY901_OUTPUT_GYRO | JY901_OUTPUT_ANGLE | JY901_OUTPUT_MAG,

	.tUART.tUARTHandle.Instance 					= USART2,				/* STM32 串口设备 */
	.tUART.tUARTHandle.Init.BaudRate   				= 9600,					/* 串口波特率 */
	.tUART.tUARTHandle.Init.WordLength 				= UART_WORDLENGTH_8B,	
	.tUART.tUARTHandle.Init.StopBits   				= UART_STOPBITS_1,
	.tUART.tUARTHandle.Init.Parity     				= UART_PARITY_NONE,
	.tUART.tUARTHandle.Init.HwFlowCtl  				= UART_HWCONTROL_NONE,
	.tUART.tUARTHandle.Init.Mode       				= UART_MODE_TX_RX,
	.tUART.tUARTHandle.Init.OverSampling 			= UART_OVERSAMPLING_16,

	.tUART.tRxInfo.usDMARxMAXSize             		= 100,                	/* DMA接收缓冲区大小 大小保持在协议最长字节*2以上，确保缓存池一定能够稳定接收一个完整的数据帧*/

#if defined (STM32L4_SGA_ENABLE)
	.tUARTHandle.Init.OneBitSampling 				= UART_ONE_BIT_SAMPLE_DISABLE,
	.tUARTHandle.AdvancedInit.AdvFeatureInit 		= UART_ADVFEATURE_NO_INIT,
#endif
	
	.tUART.ucPriority								= 1,						/* 中断优先级 */
	.tUART.ucSubPriority							= 3,						/* 中断子优先级 */
	
    .tUART.tUartDMA.bRxEnable						= true,						/* DMA接收使能 */
	.tUART.tUartDMA.tDMARx.Instance					= DMA1_Channel6,
	.tUART.tUartDMA.tDMARx.Init.Direction			= DMA_PERIPH_TO_MEMORY,
	.tUART.tUartDMA.tDMARx.Init.PeriphInc			= DMA_PINC_DISABLE,
	.tUART.tUartDMA.tDMARx.Init.MemInc				= DMA_MINC_ENABLE,
	.tUART.tUartDMA.tDMARx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE,
	.tUART.tUartDMA.tDMARx.Init.MemDataAlignment	= DMA_MDATAALIGN_BYTE,
	.tUART.tUartDMA.tDMARx.Init.Mode				= DMA_CIRCULAR,
	.tUART.tUartDMA.tDMARx.Init.Priority			= DMA_PRIORITY_LOW,

	.tUART.tUartDMA.ucDMARxPriority					= 1,				/* DMA中断优先级 */
	.tUART.tUartDMA.ucDMARxSubPriority				= 1,				/* DMA中断子优先级 */
	
	
	.tUART.tGPIO[0].tGPIOInit.Pin 					= GPIO_PIN_2,				/* GPIO引脚 */
	.tUART.tGPIO[0].tGPIOInit.Mode 					= GPIO_MODE_AF_PP,			/* GPIO模式 */
	.tUART.tGPIO[0].tGPIOInit.Pull 					= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tUART.tGPIO[0].tGPIOInit.Speed 				= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tUART.tGPIO[0].tGPIOPort 						= GPIOA,					/* GPIO分组 */
	.tUART.tGPIO[0].ucAFMode						= NO_REMAP,					/* GPIO重映射 */
	
	.tUART.tGPIO[1].tGPIOInit.Pin 					= GPIO_PIN_3,				/* GPIO引脚 */
	.tUART.tGPIO[1].tGPIOInit.Mode 					= GPIO_MODE_INPUT,			/* GPIO模式 */
	.tUART.tGPIO[1].tGPIOInit.Pull 					= GPIO_NOPULL,				/* GPIO上下拉设置，是否需要上下拉看硬件 */
	.tUART.tGPIO[1].tGPIOInit.Speed 				= GPIO_SPEED_FREQ_HIGH,		/* GPIO速度 */	
	.tUART.tGPIO[1].tGPIOPort 						= GPIOA,					/* GPIO分组 */
	.tUART.tGPIO[1].ucAFMode						= NO_REMAP,					/* GPIO重映射 */
};

