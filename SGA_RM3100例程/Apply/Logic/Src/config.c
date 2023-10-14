#include "config.h"


/* GPIO句柄示例 */
tagGPIO_T demoGPIO[] =
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
tagUART_T demoUart = 
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

tagRM3100_T RM3100[4] = 
{
	[0]=
	{
		.bSPIEnable								= true,
		.tSPI.tSPIHandle.Instance 				= SPI1,
		.tSPI.tSPIHandle.Init.Mode 				= SPI_MODE_MASTER,
		.tSPI.tSPIHandle.Init.Direction 		= SPI_DIRECTION_2LINES,
		.tSPI.tSPIHandle.Init.DataSize 			= SPI_DATASIZE_8BIT,
		.tSPI.tSPIHandle.Init.CLKPolarity 		= SPI_POLARITY_LOW,
		.tSPI.tSPIHandle.Init.CLKPhase 			= SPI_PHASE_1EDGE,
		.tSPI.tSPIHandle.Init.NSS 				= SPI_NSS_SOFT,
		.tSPI.tSPIHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64,
		.tSPI.tSPIHandle.Init.FirstBit 			= SPI_FIRSTBIT_MSB,
		.tSPI.tSPIHandle.Init.TIMode 			= SPI_TIMODE_DISABLE,
		.tSPI.tSPIHandle.Init.CRCCalculation 	= SPI_CRCCALCULATION_DISABLE,
		.tSPI.tSPIHandle.Init.CRCPolynomial 	= 10,	
#if defined (STM32L4_SGA_ENABLE)
		.tSPI.tSPIHandle.Init.CRCLength 		= SPI_CRC_LENGTH_DATASIZE,
		.tSPI.tSPIHandle.Init.NSSPMode 			= SPI_NSS_PULSE_ENABLE,	
#endif
		/**SPI1 GPIO Configuration
		PA5     ------> SPI1_SCK
		PA6     ------> SPI1_MISO
		PA7     ------> SPI1_MOSI
		PC5     ------> SPI1_NSS
		*/
		.tSPI.tGPIO[0].tGPIOInit.Pin	= GPIO_PIN_5,
		.tSPI.tGPIO[0].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[0].tGPIOPort		= GPIOA,
		.tSPI.tGPIO[0].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[1].tGPIOInit.Pin 	= GPIO_PIN_6,
		.tSPI.tGPIO[1].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[1].tGPIOInit.Pull 	= GPIO_NOPULL,
		.tSPI.tGPIO[1].tGPIOPort		= GPIOA,
		.tSPI.tGPIO[1].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[2].tGPIOInit.Pin	= GPIO_PIN_7,
		.tSPI.tGPIO[2].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[2].tGPIOPort		= GPIOA,
		.tSPI.tGPIO[2].ucAFMode			= NO_REMAP,
		
		.tSPI.tGPIO[3].tGPIOInit.Pin	= GPIO_PIN_5,
		.tSPI.tGPIO[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSPI.tGPIO[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[3].tGPIOPort		= GPIOC,
		.tSPI.tGPIO[3].ucAFMode			= NO_REMAP,
	
	},
	[1]=
	{
		.bSPIEnable								= true,
		.tSPI.tSPIHandle.Instance 				= SPI2,
		.tSPI.tSPIHandle.Init.Mode 				= SPI_MODE_MASTER,
		.tSPI.tSPIHandle.Init.Direction 		= SPI_DIRECTION_2LINES,
		.tSPI.tSPIHandle.Init.DataSize 			= SPI_DATASIZE_8BIT,
		.tSPI.tSPIHandle.Init.CLKPolarity 		= SPI_POLARITY_LOW,
		.tSPI.tSPIHandle.Init.CLKPhase 			= SPI_PHASE_1EDGE,
		.tSPI.tSPIHandle.Init.NSS 				= SPI_NSS_SOFT,
		.tSPI.tSPIHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32,
		.tSPI.tSPIHandle.Init.FirstBit 			= SPI_FIRSTBIT_MSB,
		.tSPI.tSPIHandle.Init.TIMode 			= SPI_TIMODE_DISABLE,
		.tSPI.tSPIHandle.Init.CRCCalculation 	= SPI_CRCCALCULATION_DISABLE,
		.tSPI.tSPIHandle.Init.CRCPolynomial 	= 10,	
#if defined (STM32L4_SGA_ENABLE)
		.tSPI.tSPIHandle.Init.CRCLength 		= SPI_CRC_LENGTH_DATASIZE,
		.tSPI.tSPIHandle.Init.NSSPMode 			= SPI_NSS_PULSE_ENABLE,	
#endif
		/**SPI2 GPIO Configuration
		PB13     ------> SPI2_SCK
		PB14     ------> SPI2_MISO
		PB15     ------> SPI2_MOSI
		PD9     ------> SPI2_NSS
		*/
		.tSPI.tGPIO[0].tGPIOInit.Pin	= GPIO_PIN_13,
		.tSPI.tGPIO[0].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[0].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[0].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[1].tGPIOInit.Pin 	= GPIO_PIN_14,
		.tSPI.tGPIO[1].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[1].tGPIOInit.Pull 	= GPIO_NOPULL,
		.tSPI.tGPIO[1].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[1].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[2].tGPIOInit.Pin	= GPIO_PIN_15,
		.tSPI.tGPIO[2].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[2].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[2].ucAFMode			= NO_REMAP,
		
		.tSPI.tGPIO[3].tGPIOInit.Pin	= GPIO_PIN_9,
		.tSPI.tGPIO[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSPI.tGPIO[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[3].tGPIOPort		= GPIOD,
		.tSPI.tGPIO[3].ucAFMode			= NO_REMAP,
	
	},
	[2]=
	{
		.bSPIEnable								= true,
		.tSPI.tSPIHandle.Instance 				= SPI3,
		.tSPI.tSPIHandle.Init.Mode 				= SPI_MODE_MASTER,
		.tSPI.tSPIHandle.Init.Direction 		= SPI_DIRECTION_2LINES,
		.tSPI.tSPIHandle.Init.DataSize 			= SPI_DATASIZE_8BIT,
		.tSPI.tSPIHandle.Init.CLKPolarity 		= SPI_POLARITY_LOW,
		.tSPI.tSPIHandle.Init.CLKPhase 			= SPI_PHASE_1EDGE,
		.tSPI.tSPIHandle.Init.NSS 				= SPI_NSS_SOFT,
		.tSPI.tSPIHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32,
		.tSPI.tSPIHandle.Init.FirstBit 			= SPI_FIRSTBIT_MSB,
		.tSPI.tSPIHandle.Init.TIMode 			= SPI_TIMODE_DISABLE,
		.tSPI.tSPIHandle.Init.CRCCalculation 	= SPI_CRCCALCULATION_DISABLE,
		.tSPI.tSPIHandle.Init.CRCPolynomial 	= 10,	
#if defined (STM32L4_SGA_ENABLE)
		.tSPI.tSPIHandle.Init.CRCLength 		= SPI_CRC_LENGTH_DATASIZE,
		.tSPI.tSPIHandle.Init.NSSPMode 			= SPI_NSS_PULSE_ENABLE,	
#endif
	/**SPI3 GPIO Configuration
		PB3     ------> SPI3_SCK
		PB4     ------> SPI3_MISO
		PB5     ------> SPI3_MOSI
		PB7     ------> SPI3_NSS
		*/
		.tSPI.tGPIO[0].tGPIOInit.Pin	= GPIO_PIN_3,
		.tSPI.tGPIO[0].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[0].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[0].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[1].tGPIOInit.Pin 	= GPIO_PIN_4,
		.tSPI.tGPIO[1].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[1].tGPIOInit.Pull 	= GPIO_NOPULL,
		.tSPI.tGPIO[1].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[1].ucAFMode			= NO_REMAP,

		.tSPI.tGPIO[2].tGPIOInit.Pin	= GPIO_PIN_5,
		.tSPI.tGPIO[2].tGPIOInit.Mode 	= GPIO_MODE_AF_PP,
		.tSPI.tGPIO[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[2].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[2].ucAFMode			= NO_REMAP,
		
		.tSPI.tGPIO[3].tGPIOInit.Pin	= GPIO_PIN_7,
		.tSPI.tGPIO[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSPI.tGPIO[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSPI.tGPIO[3].tGPIOPort		= GPIOB,
		.tSPI.tGPIO[3].ucAFMode			= NO_REMAP,
	},
	[3]=
	{
		/**SPI Soft GPIO Configuration
		PE2     ------> SPI_SCK
		PE4     ------> SPI_MISO
		PE3     ------> SPI_MOSI
		PE1     ------> SPI_NSS 
		*/
		.bSPISoftEnable							= true,
		.tSoftSPI.tSPISoft[0].tGPIOInit.Pin		= GPIO_PIN_2,
		.tSoftSPI.tSPISoft[0].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSoftSPI.tSPISoft[0].tGPIOInit.Pull 	= GPIO_PULLUP,
		.tSoftSPI.tSPISoft[0].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSoftSPI.tSPISoft[0].tGPIOPort			= GPIOE,
		.tSoftSPI.tSPISoft[0].ucAFMode			= NO_REMAP,
		
		.tSoftSPI.tSPISoft[1].tGPIOInit.Pin		= GPIO_PIN_4,
		.tSoftSPI.tSPISoft[1].tGPIOInit.Mode 	= GPIO_MODE_INPUT,
		.tSoftSPI.tSPISoft[1].tGPIOInit.Pull 	= GPIO_PULLUP,
		.tSoftSPI.tSPISoft[1].tGPIOPort			= GPIOE,
		.tSoftSPI.tSPISoft[1].ucAFMode			= NO_REMAP,
		
		.tSoftSPI.tSPISoft[2].tGPIOInit.Pin		= GPIO_PIN_3,
		.tSoftSPI.tSPISoft[2].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSoftSPI.tSPISoft[2].tGPIOInit.Pull 	= GPIO_PULLUP,
		.tSoftSPI.tSPISoft[2].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSoftSPI.tSPISoft[2].tGPIOPort			= GPIOE,
		.tSoftSPI.tSPISoft[2].ucAFMode			= NO_REMAP,
		
		.tSoftSPI.tSPISoft[3].tGPIOInit.Pin		= GPIO_PIN_1,
		.tSoftSPI.tSPISoft[3].tGPIOInit.Mode 	= GPIO_MODE_OUTPUT_PP,
		.tSoftSPI.tSPISoft[3].tGPIOInit.Pull 	= GPIO_PULLUP,
		.tSoftSPI.tSPISoft[3].tGPIOInit.Speed 	= GPIO_SPEED_FREQ_HIGH,
		.tSoftSPI.tSPISoft[3].tGPIOPort			= GPIOE,
		.tSoftSPI.tSPISoft[3].ucAFMode			= NO_REMAP,
	},
};


