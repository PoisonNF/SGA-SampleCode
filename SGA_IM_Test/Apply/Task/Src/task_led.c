#include "task_led.h"
#include "config.h"

//ºìµÆÁÁ
void Task_LED_RedOn(void)
{
    Drv_GPIO_Reset(&LED_RED);
    Drv_GPIO_Set(&LED_GREEN);
    Drv_GPIO_Set(&LED_BLUE);
    printf("Red Led On!!!\r\n");
}

//ÂÌµÆÁÁ
void Task_LED_GreenOn(void)
{
    Drv_GPIO_Set(&LED_RED);
    Drv_GPIO_Reset(&LED_GREEN);
    Drv_GPIO_Set(&LED_BLUE);
    printf("Green Led On!!!\r\n");
}

//À¶µÆÁÁ
void Task_LED_BlueOn(void)
{
    Drv_GPIO_Set(&LED_RED);
    Drv_GPIO_Set(&LED_GREEN);
    Drv_GPIO_Reset(&LED_BLUE);
    printf("Blue Led On!!!\r\n");
}

//ËùÓÐµÆÏ¨Ãð
void Task_LED_AllOff(void)
{
    Drv_GPIO_Set(&LED_RED);
    Drv_GPIO_Set(&LED_GREEN);
    Drv_GPIO_Set(&LED_BLUE);

}

