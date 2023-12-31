#ifndef __OCD_FUNC_H_
#define __OCD_FUNC_H_

#include "drv_hal_conf.h"

typedef struct
{
	uint8_t *ucpAddr;
	uint32_t ulIndex;
}tag_StringInfo;

tag_StringInfo OCD_Function_Query_Sub(uint8_t *_ucpStrA, uint8_t *_ucpStrB);
void OCD_Function_Insert_Sub(uint8_t *_ucpStrA, uint8_t *_ucpStrB, uint16_t _usOffset);
uint16_t OCD_Function_Crc16_Modbus(uint8_t *_ucpMsg, uint16_t _usDataLen);
uint32_t OCD_StringToHex(uint8_t *_ucpStrA, uint8_t _ucLen);
uint8_t OCD_DecToHex(uint8_t _ucDec);
uint8_t OCD_HexToDec(uint8_t _ucHex);

#endif
