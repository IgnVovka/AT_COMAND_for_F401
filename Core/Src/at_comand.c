/*
 * at_comand.c
 *
 *  Created on: Jul 20, 2024
 *      Author: vladi
 */
#include "at_comand.h"
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

extern struct my_struct par;
const uint32_t byte[12]={10,11,12,13,14,15,16,17,18,19,20,21};
volatile uint8_t flag=0;//флаг для чтения;
char readBuf[40];//буфер, где будут помещаться принятые байты
char writeBuf[120];//буфер для записи в терминал
uint8_t rxbyte;//переменная для приёма по одному байту
uint8_t i=0;//инкремент для readBuf
const char str_array[14][20]={
		"SPD",
		"LNOPEN",
		"LNHLOPEN",
        "CURERRLOCK1",
        "CURERRLOCK2",
        "CURERRDRIVE1",
        "CURERRDRIVE2",
        "CURERRDRIVE3",
        "CURERRDRIVE4",
        "CURERRTIME",
        "STOTIMELOCK",
        "STOTIMEDRIVE",
        "SAVEFLASH",
        "READFLASH"
    };//словарь
int s=sizeof(str_array)/sizeof(str_array[14]);//РАЗМЕР ДВУМЕРНОГО МАССИВА
int check (void)
{
    if(readBuf[0] !='A' || readBuf[1]!='T' || readBuf[2]!='+') return (-1);
    for(int j=0;j<s;j++)
    {
        if((strstr(readBuf,str_array[j]))!=NULL)
            return (j);
    }
    return (-1);
}
void SPD()
{
    if (readBuf[6]=='?' && readBuf[7]=='\r')
        sprintf(writeBuf, "%s\r\n", "Connection speed");//Выдать описание команды
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[6]=='=')//=
    {
        if (readBuf[7]=='?')//=?
            sprintf(writeBuf, "%s %d\r\n", "SPD:", par.val0); //выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[7]))
            {
                sscanf(&readBuf[7],"%d",&par.val0);//присвоить новое значение
                //test_struct.var3=sizeof(test_struct.var2[0]);
                //writeFlash(flash_addr);
                sprintf(writeBuf, "%s\r\n","Ok");
            }
            else
                sprintf(writeBuf, "%s\r\n", "Error");
         }
    }
}
void LNOPEN()
{
    if(readBuf[9]=='?'&& readBuf[10]=='\r')
        sprintf(writeBuf, "%s\r\n", "Full opening distance");//Выдать описание команды
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[9]=='=') //=
    {
        if (readBuf[10]=='?') //=?
            sprintf(writeBuf, "%s %d\r\n","LNOPEN:",par.val1);//выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[10]))
            {
                sscanf(&readBuf[10],"%d",&par.val1);//присвоить новое значение
                //test_struct.var3=sizeof(test_struct.var2[1]);
                //writeFlash(flash_addr+test_struct.var3);
                sprintf(writeBuf, "%s\r\n", "Ok");
            }
            else
                sprintf(writeBuf, "%s\r\n", "Error");
        }
    }
}
void LNHLOPEN()
{
    if(readBuf[11]=='?'&& readBuf[12]=='\r')//Выдать описание команды
        sprintf(writeBuf, "%s\r\n", "Incomplete opening distance");
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[11]=='=')//=
    {
        if (readBuf[12]=='?')//=?
            sprintf(writeBuf, "%s %d\r\n","LNHLOPEN:",par.val2);//выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[12]))
            {
                sscanf(&readBuf[12],"%d",&par.val2); //присвоить новое значение
                //test_struct.var3=sizeof(test_struct.var2[2]);
                sprintf(writeBuf, "%s\r\n", "Ok");
            }
            else
                sprintf(writeBuf, "%s\r\n", "Error");
        }
    }
}
void CURERRLOCK1()
{
    if(readBuf[14]=='?'&& readBuf[15]=='\r')//Выдать описание команды
        sprintf(writeBuf, "%s\r\n", "Emergency current value of the lock line 1");
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[14]=='=')//=
    {
        if (readBuf[15]=='?')//=?
            sprintf(writeBuf, "%s %d\r\n","CURERRLOCK1:",par.val3);//выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[15]))
            {
                sscanf(&readBuf[15],"%d",&par.val3);//присвоить новое значение
                //test_struct.var3=sizeof(test_struct.var2[3]);
                sprintf(writeBuf, "%s\r\n", "Ok");
            }
            else
                sprintf(writeBuf, "%s\r\n", "Error");
        }
    }
}
void CURERRLOCK2()
{
    if(readBuf[14]=='?'&& readBuf[15]=='\r')//Выдать описание команды
        sprintf(writeBuf, "%s\r\n", "Emergency current value of the lock line 2");
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[14]=='=')//=
    {
        if (readBuf[15]=='?')//=?
            sprintf(writeBuf, "%s %d\r\n","CURERRLOCK2:",par.val4);//выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[15]))
            {
                sscanf(&readBuf[15],"%d",&par.val4);//присвоить новое значение
                //test_struct.var3=sizeof(test_struct.var2[4]);
                sprintf(writeBuf, "%s\r\n", "Ok");
            }
            else
                printf(writeBuf, "%s\r\n", "Error");
        }
    }
}
void CURERRDRIVE1()
{
    if(readBuf[15]=='?'&& readBuf[16]=='\r')//Выдать описание команды
        sprintf(writeBuf, "%s\r\n", "Emergency current value of the window 1 drive circuit line");
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[15]=='=')//=
    {
        if (readBuf[16]=='?')//=?
            sprintf(writeBuf, "%s %d\r\n","CURERRDRIVE1:",par.val5);//выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[16]))
            {
                sscanf(&readBuf[16],"%d",&par.val5);//присвоить новое значение
                sprintf(writeBuf, "%s\r\n", "Ok");
            }
            else
                sprintf(writeBuf, "%s\r\n", "Error");
         }
    }
}
void CURERRDRIVE2()
{
    if(readBuf[15]=='?'&& readBuf[16]=='\r')//Выдать описание команды
        sprintf(writeBuf, "%s\r\n", "Emergency current value of the window 2 drive circuit line");
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[15]=='=')//=
    {
        if (readBuf[16]=='?')//=?
            sprintf(writeBuf, "%s %d\r\n","CURERRDRIVE2:",par.val6);//выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[16]))
            {
                sscanf(&readBuf[16],"%d",&par.val6);//присвоить новое значение
                sprintf(writeBuf, "%s\r\n", "Ok");
            }
            else
                sprintf(writeBuf, "%s\r\n", "Error");
        }
    }
}
void CURERRDRIVE3()
{
    if(readBuf[15]=='?'&& readBuf[16]=='\r')//Выдать описание команды
        sprintf(writeBuf, "%s\r\n", "Emergency current value of the window 3 drive circuit line");
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[15]=='=')//=
    {
        if (readBuf[16]=='?')//=?
            sprintf(writeBuf, "%s %d\r\n","CURERRDRIVE3:",par.val7);//выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[16]))
            {
                sscanf(&readBuf[16],"%d",&par.val7);//присвоить новое значение
                sprintf(writeBuf, "%s\r\n", "Ok");
            }
            else
                sprintf(writeBuf, "%s\r\n", "Error");
        }
    }
}
void CURERRDRIVE4()
{
    if(readBuf[15]=='?'&& readBuf[16]=='\r')//Выдать описание команды
        sprintf(writeBuf, "%s\r\n", "Emergency current value of the window 4 drive circuit line");
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[15]=='=')//=
    {
        if (readBuf[16]=='?')//=?
            sprintf(writeBuf, "%s %d\r\n","CURERRDRIVE4:",par.val8);//выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[16]))
            {
                sscanf(&readBuf[16],"%d",&par.val8);//присвоить новое значение
                sprintf(writeBuf, "%s\r\n", "Ok");
            }
            else
                sprintf(writeBuf, "%s\r\n", "Error");
        }
    }
}
void CURERRTIME()
{
    if(readBuf[13]=='?'&& readBuf[14]=='\r')//Выдать описание команды
        sprintf(writeBuf, "%s\r\n", "The holding time of the emergency current value of the drive circuit line");
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[13]=='=')//=
    {
        if (readBuf[14]=='?')//=?
            sprintf(writeBuf, "%s %d\r\n","CURERRTIME:",par.val9);//выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[14]))
            {
                sscanf(&readBuf[14],"%d",&par.val9);//присвоить новое значение
                sprintf(writeBuf, "%s\r\n", "Ok");
            }
            else
                sprintf(writeBuf, "%s\r\n", "Error");
        }
    }
}
void STOTIMELOCK()
{
    if(readBuf[14]=='?'&& readBuf[15]=='\r')//Выдать описание команды
        sprintf(writeBuf, "%s\r\n", "The time spent in the lock stop");
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[14]=='=')//=
    {
        if (readBuf[15]=='?')//=?
            sprintf(writeBuf, "%s %d\r\n","STOTIMELOCK:",par.val10);//выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[15]))
            {
                sscanf(&readBuf[15],"%d",&par.val10);//присвоить новое значение
                sprintf(writeBuf, "%s\r\n", "Ok");
            }
            else
                sprintf(writeBuf, "%s\r\n", "Error");
        }
    }
}
void STOTIMEDRIVE()
{
    if(readBuf[15]=='?'&& readBuf[16]=='\r')//Выдать описание команды
        sprintf(writeBuf, "%s\r\n", "The time spent in the stop of the chains");
    else
        sprintf(writeBuf, "%s\r\n", "Error");
    if (readBuf[15]=='=')//=
    {
        if (readBuf[16]=='?')//=?
            sprintf(writeBuf, "%s %d\r\n","STOTIMEDRIVE:",par.val11);//выдать текущее значение параметра
        else
        {
            if(isdigit(readBuf[16]))
            {
                sscanf(&readBuf[16],"%d",&par.val11);//присвоить новое значение
                sprintf(writeBuf, "%s\r\n", "Ok");
            }
            else
                sprintf(writeBuf, "%s\r\n", "Error");
        }
    }
}
void SAVEFLASH()
{
    if (readBuf[3]=='S' && readBuf[12]=='\r')
    {
        writeFlash(flash_addr);
        //writeFlash(0x0801F845);
        sprintf(writeBuf, "%s\r\n", " Flash updated!");
    }
    else
        sprintf(writeBuf, "%s\r\n", "Error");

}
void READFLASH()
{
    if (readBuf[3]=='R' && readBuf[12]=='\r')
    {
        uint32_t first_byte=readFlash(flash_addr);
        //sprintf(writeBuf, "%X\r\n", first_byte);
        if(first_byte==0xFFFFFFFF)
        {
            //sprintf(writeBuf, "%s\r\n", "First_byte==0xFF!");
            par.val0=byte[0];
            par.val1=byte[1];
            par.val2=byte[2];
            par.val3=byte[3];
            par.val4=byte[4];
            par.val5=byte[5];
            par.val6=byte[6];
            par.val7=byte[7];
            par.val8=byte[8];
            par.val9=byte[9];
            par.val10=byte[10];
            par.val11=byte[11];
            sprintf(writeBuf, "First byte=%X\r\n", (int)first_byte);
        }
        else
           sprintf(writeBuf, "First byte=%X\r\n", (int)first_byte);
    }
    else
        sprintf(writeBuf, "%s\r\n", "Error!");
}
uint8_t writeFlash (uint32_t addr)
{
	HAL_StatusTypeDef status;
	uint32_t structureSize = sizeof(par);          // замеряем размер структуры
	FLASH_EraseInitTypeDef FlashErase;                     // переменная для структуры, которая выполняет функцию стирания страницы
	uint32_t pageError = 0;                                // переменная для записи информации об ошибках в процессе стирания

	//__disable_irq();                                     // запрещаем прерывания
	HAL_FLASH_Unlock();									   //разблокировка FLASH
	FlashErase.TypeErase = FLASH_TYPEERASE_SECTORS;
	FlashErase.NbSectors = 1;
	FlashErase.Sector = FLASH_SECTOR_5;
	FlashErase.VoltageRange = VOLTAGE_RANGE_3;
	if (HAL_FLASHEx_Erase(&FlashErase, &pageError) != HAL_OK)// вызов функции стирания
	{
		HAL_FLASH_Lock();                                  // если не смог стереть, то закрыть память и вернуть ошибку
		return HAL_ERROR;
	}

    uint32_t *dataPtr = (uint32_t *)&par;          // создаем указатель на нашу структуру и записываем ее кусочками по 32 бита
	for (int i = 0; i < structureSize / 4; i++)            // 4 байта = 32 бита
    //for (int i = 0; i < structureSize; i++)
    {
		status += HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr, dataPtr[i]);
        addr += 4;                                         // сдвигаем адрес на 4 байта
        //status += HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, addr, dataPtr[i]);//не работает
        //addr ++;                                         // побайтово
    }
	//__enable_irq();                                      // включаем прерывания обратно
	HAL_FLASH_Lock();
	return status;
}
uint32_t readFlash (uint32_t addr)
{
	/*uint32_t structureSize = sizeof(test_struct);
	uint32_t *dataPtr = (uint32_t *)&test_struct;
	for (int i = 0; i < structureSize / 4; i++)
	{
		dataPtr[i] = *(__IO uint32_t*)addr;
		addr += 4;
	}*/
     return (*(__IO uint32_t*) addr);
}


