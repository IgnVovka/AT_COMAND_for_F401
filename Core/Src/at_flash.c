/*
 * at_flash.c
 *
 *  Created on: Jul 25, 2024
 *      Author: vladi
 */
#include "at_flash.h"
#include "at_comand.h"
#include "main.h"


uint8_t writeFlash(uint32_t addr)
{
	HAL_StatusTypeDef status;
	uint32_t structureSize = sizeof(par);// замеряем размер структуры
	FLASH_EraseInitTypeDef FlashErase; // переменная для структуры, которая выполняет функцию стирания страницы
	uint32_t pageError = 0; // переменная для записи информации об ошибках в процессе стирания

	//__disable_irq();// запрещаем прерывания
	HAL_FLASH_Unlock();//разблокировка FLASH
	FlashErase.TypeErase = FLASH_TYPEERASE_SECTORS;
	FlashErase.NbSectors = 1;
	FlashErase.Sector = FLASH_SECTOR_5;
	FlashErase.VoltageRange = VOLTAGE_RANGE_3;
	if (HAL_FLASHEx_Erase(&FlashErase, &pageError) != HAL_OK)// вызов функции стирания
	{
		HAL_FLASH_Lock(); // если не смог стереть, то закрыть память и вернуть ошибку
		return HAL_ERROR;
	}
	uint32_t *dataPtr = (uint32_t*) &par; // создаем указатель на нашу структуру и записываем ее кусочками по 32 бита
	for (int i = 0; i < structureSize / 4; i++)// 4 байта = 32 бита
	{
		status += HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr, dataPtr[i]);
		addr += 4;// сдвигаем адрес на 4 байта
		//status += HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, addr, dataPtr[i]);//не работает
		//addr ++;// побайтово
	}
	//__enable_irq();// включаем прерывания обратно
	HAL_FLASH_Lock();
	return status;
}
uint32_t readFlash(uint32_t addr)
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
