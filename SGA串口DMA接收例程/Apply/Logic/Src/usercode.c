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
    uint8_t num;        //用于记录接收到的数据字节数
	uint8_t buf[150];   //用于存放接收到的数据
    
	while(1)
	{
        //调用接收函数，将收到的数据存入buf中，同时返回num
        num = Drv_Uart_Receive_DMA(&demoUart,buf);
        
        //当接收到的数据字节数不为0，打印返还给PC
        if(num != 0)
            printf("%s",buf);
	}
}