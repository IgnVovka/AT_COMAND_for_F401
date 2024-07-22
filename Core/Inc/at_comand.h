/*
 * at_comand.h
 *
 *  Created on: Jul 20, 2024
 *      Author: vladi
 */

#ifndef INC_AT_COMAND_H_//директива
#define INC_AT_COMAND_H_

#include <stdint.h>

#define flash_addr    0x08020000
struct
{
    int num0;
    int val0;
    //uint16_t siz1;
    int num1;
    int val1;

    //uint16_t siz2;
    int num2;
    int val2;

    //uint16_t siz3;
    int num3;
    int val3;

    //uint16_t siz4;
    int num4;
    int val4;

    //uint16_t siz5;
    int num5;
    int val5;

    //uint16_t siz6;
    int num6;
    int val6;

    //uint16_t siz7;
    int num7;
    int val7;

    //uint16_t siz8;
    int num8;
    int val8;

    //uint16_t siz9;
    int num9;
    int val9;

    //uint16_t siz10;
    int num10;
    int val10;

    //uint16_t siz11;
    int num11;
    int val11;

    //uint16_t siz12;
} test_struct;//структура для записи данных  в ячейку  памяти

const uint32_t byte[12];
volatile uint8_t flag;//флаг для чтения;
char readBuf[40];//буфер, где будут помещаться принятые байты
char writeBuf[120];//буфер для записи в терминал
uint8_t rxbyte;//переменная для приёма по одному байту
uint8_t i;//инкремент для readBuf
const char str_array[14][20];
int s;//РАЗМЕР ДВУМЕРНОГО МАССИВА

int check (void);

void SPD(void);
void LNOPEN(void);
void LNHLOPEN(void);
void CURERRLOCK1(void);
void CURERRLOCK2(void);
void CURERRDRIVE1(void);
void CURERRDRIVE2(void);
void CURERRDRIVE3(void);
void CURERRDRIVE4(void);
void CURERRTIME(void);
void STOTIMELOCK(void);
void STOTIMEDRIVE(void);
void SAVEFLASH(void);
void READFLASH(void);

uint8_t writeFlash (uint32_t);
uint32_t readFlash (uint32_t);

#endif /* INC_AT_COMAND_H_ */

