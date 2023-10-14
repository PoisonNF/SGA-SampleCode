#include "task_fatfs.h"
#include "config.h"

static uint8_t File_Name[] = "/test/example.txt";
static uint8_t Path_Name[] = "/test";
uint8_t sendBuffer[100] = "abcdefghijklmnopqrtsuvwxyz";
uint8_t receBuffer[100] = {0};
uint32_t sendNum = 0;
uint32_t receNum = 0;
uint32_t Offset = 0;
int8_t ret;

void Task_TATFS_Test(void)
{
    //创建文件夹
	ret = OCD_FATFS_CreateDir(&tFATFS,(char *)Path_Name);
    if(ret == FR_OK)
        printf("创建文件夹成功 %s\r\n",Path_Name);
    
    else if(ret == FR_EXIST)
        printf("文件夹已存在 %s\r\n",Path_Name);

    //循环三次
    for(int i = 0; i < 3; i++)
    {
        //在末尾写入数据
		if(OCD_FATFS_Write_End(&tFATFS, (char *)File_Name, sendBuffer, sizeof("abcdefghijklmnopqrtsuvwxyz") , &sendNum) == FR_OK)
			printf("写入%d个字节 数据为%s\r\n",sendNum,sendBuffer);

		Drv_Delay_Ms(100);

        //如果写入数据长度不为0
		if(sendNum != 0)
            //从偏移量处读取相同长度数据
			if(OCD_FATFS_Read_SpecifyIndex(&tFATFS, (char *)File_Name ,receBuffer,sendNum,Offset,&receNum) == FR_OK)
            {
                printf("从偏移量%d 读到%d个字节 数据为%s\r\n",Offset,receNum,receBuffer);
                //偏移量累加
                Offset += receNum;
            }
    }
    printf("\r\n");
}

