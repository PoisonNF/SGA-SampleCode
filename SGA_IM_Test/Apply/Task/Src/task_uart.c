#include "task_conf.h"
#include "task_uart.h"
#include "config.h"

#define DELAY(n) do{Drv_Delay_Ms(n*1000);}while(0)

uint8_t ReceNum;
uint8_t PCBuffer[100];
uint8_t SDcardStatus = 0; 	//SD卡状态标志位, 0:SD未插 1:SD卡存在

//串口数据解析，返回第二个指令值
static int8_t S_UartDataSort(void)
{
    memset(PCBuffer,0,100);

    ReceNum = Drv_Uart_Receive_DMA(&Uart1,PCBuffer);

    if(ReceNum)
    {
        printf("PCData: %s\r\n",PCBuffer);
        if(PCBuffer[0] == '@' && ReceNum != 1)
        {
            ReceNum = 0;
            return PCBuffer[1];
        }
    }
    return -1;
}

//监听来自PC的指令
void Task_PCUartListen(void)
{
    switch(S_UartDataSort())
    {
        //全部都进行测试
        case '0':
            Task_LED_RedOn();
            DELAY(1);
            Task_LED_GreenOn();
            DELAY(1);
            Task_LED_BlueOn();
            DELAY(1);
            Task_LED_AllOff();

            Task_DS1337_Test();
            DELAY(1);

            Task_TATFS_Test();
            DELAY(1);

            Task_AT24CXX_Test();
            DELAY(1);

            Task_JY901_Test();
            DELAY(1);

            printf("AUTO TEST END\r\n");
            break;

        //测试LED
        case '1':
            Task_LED_RedOn();
            DELAY(1);
            Task_LED_GreenOn();
            DELAY(1);
            Task_LED_BlueOn();
            DELAY(1);
            Task_LED_AllOff();
            printf("LED TEST END\r\n");
            break;

        //测试DS1337
        case '2':
            Task_DS1337_Test();
            printf("DS1337 TEST END\r\n");
            break;

        //测试TATFS
        case '3':
            if(SDcardStatus)
            {
                Task_TATFS_Test();
                printf("TATFS TEST END\r\n");
                break;
            }
            else
            {
                printf("SDcard Error\r\n");
                printf("TATFS TEST SKIP\r\n");
                break;
            }

        //测试AT24CXX
        case '4':
            Task_AT24CXX_Test();
            printf("AT24CXX TEST END\r\n");
            break;

        //测试JY901
        case '5':
            Task_JY901_Test();
            printf("JY901 TEST END\r\n");
            break;            
        
        default:
            break;
    }
}



